/*
* Copyright 2024 Rochus Keller <mailto:me@rochus-keller.ch>
*
* This file is part of the Luon parser/compiler library.
*
* The following is the license that applies to this copy of the
* library. For a license to use the library under conditions
* other than those described here, please email to me@rochus-keller.ch.
*
* GNU General Public License Usage
* This file may be used under the terms of the GNU General Public
* License (GPL) versions 2.0 or 3.0 as published by the Free Software
* Foundation and appearing in the file LICENSE.GPL included in
* the packaging of this file. Please review the following information
* to ensure GNU General Public Licensing requirements will be met:
* http://www.fsf.org/licensing/licenses/info/GPLv2.html and
* http://www.gnu.org/copyleft/gpl.html.
*/

// Adopted from the Oberon+ IDE

#include "LnLjRuntime.h"
#include <LjTools/Engine2.h>
#include "LnRowCol.h"
#include "LnProject.h"
#include "LnLjbcGen.h"
#include <QFile>
#include <QDir>
#include <QBuffer>
#include <QtDebug>
#include <QTime>
#include <QApplication>
#include <lua.hpp>
using namespace Ln;

static void printLoadError(Lua::Engine2* lua, const QByteArray& what)
{
    Lua::Engine2::ErrorMsg msg = Lua::Engine2::decodeRuntimeMessage(lua->getLastError());
    QString str;
    if( msg.d_line )
    {
        if( RowCol::isPacked(msg.d_line) )
            str = QString("%1:%2: %3").arg(RowCol::unpackRow(msg.d_line)).arg(RowCol::unpackCol(msg.d_line))
                    .arg(msg.d_message.constData());
    }else
        str = msg.d_message;
    qCritical() << "error loading" << what << str.toUtf8().constData();
}

static void loadLuaLib( Lua::Engine2* lua, const QByteArray& name, bool run = false )
{
    QFile lib( QString(":/runtime/%1.lua").arg(name.constData()) );
    if( !lib.open(QIODevice::ReadOnly) )
        qCritical() << "cannot find" << name;
    int res = 0;
    if( run )
        res = lua->addSourceLib( lib.readAll(), name );
    else
        res = lua->addPreloadLib( lib.readAll(), name );
    if( !res )
        printLoadError( lua, name );
}

static bool preloadLib( Project* pro, const QByteArray& name )
{
    QFile f( QString(":/runtime/%1.luon" ).arg(name.constData() ) );
    if( !f.open(QIODevice::ReadOnly) )
    {
        qCritical() << "unknown preload" << name;
        return false;
    }
    pro->addPreload(name, f.readAll());
    return true;
}

LjRuntime::LjRuntime(QObject*p):QObject(p), d_jitEnabled(true),d_buildErrors(false)
{
    d_pro = new Project(this);

    d_lua = new Lua::Engine2(this);
    Lua::Engine2::setInst(d_lua);
    prepareEngine();
}

bool LjRuntime::compile(bool doGenerate)
{
    d_byteCode.clear();
    if( d_pro->useBuiltInOakwood() )
    {
        preloadLib(d_pro,"In");
        preloadLib(d_pro,"Out");
        preloadLib(d_pro,"Files");
        preloadLib(d_pro,"Input");
        preloadLib(d_pro,"Math");
        preloadLib(d_pro,"Strings");
        preloadLib(d_pro,"DateTime");
        // preloadLib(d_pro,"XYPlane");
    }
    const quint32 errCount = d_pro->getErrors().size();
    const QTime start = QTime::currentTime();
    if( !d_pro->parse() )
        return false;
    qDebug() << "recompiled in" << start.msecsTo(QTime::currentTime()) << "[ms]";
    if( doGenerate )
        generate();
    return errCount == d_pro->getErrors().size();
}

bool LjRuntime::run()
{
    if( !compile(true) )
        return false;

    if( !loadLibraries() )
        return false;

    QStringList args = d_pro->getArguments();
    lua_createtable(d_lua->getCtx(), args.size(), 0 );
    const int t = lua_gettop(d_lua->getCtx());
    for( int i = 0; i < args.size(); i++ )
    {
        const QByteArray arg = args[i].simplified().toUtf8();
        lua_pushinteger(d_lua->getCtx(), i + 1);
        lua_pushstring(d_lua->getCtx(), arg.constData());
        lua_settable(d_lua->getCtx(), t );
    }
    lua_setglobal(d_lua->getCtx(), "arg");


    if( !loadBytecode() )
        return false;

    return executeMain();
}

bool LjRuntime::loadLibraries()
{
    if( d_pro->useBuiltInOakwood() )
    {
        loadLuaLib(d_lua,"_In");
        loadLuaLib(d_lua,"_Out");
        loadLuaLib(d_lua,"_Files");
        loadLuaLib(d_lua,"_Input");
        loadLuaLib(d_lua,"_Math");
        loadLuaLib(d_lua,"_Strings");
        loadLuaLib(d_lua,"_DateTime");
    }

    const QString root = d_pro->getWorkingDir(true);
    // TODO Obs::Files::setFileSystemRoot(root);
    return true;
}

bool LjRuntime::loadBytecode()
{
    if( d_byteCode.isEmpty() )
    {
        qWarning() << "nothing to load";
        return true;
    }

    Project::ModProc main = d_pro->getMain();
    bool hasErrors = false;
    try
    {
        for( int i = 0; i < d_byteCode.size(); i++ )
        {
            ModuleData md = d_byteCode[i].first->data.value<ModuleData>();
            const QByteArray name = md.fullName;
            if( md.metaActuals.isEmpty() && !d_byteCode[i].first->hasSubs && main.first.isEmpty() )
            {
                qDebug() << "running module" << name;
                // modules at the root of the import tree are directly loaded and executed, unless
                // there is an explicit main module/procedure, in which case the latter is the root
                // and all other modules are loaded via "require".
                // the order of d_byteCode also reflects the import dependencies
                // we cannot just call addSourceLib here, because we also have to call "$begin";
                // that's why we first preload the module and then load it using LUON_require
                if( !d_lua->addPreloadLib( d_byteCode[i].second, name ) )
                {
                    printLoadError(d_lua,name);
                    hasErrors = true;
                }
                const QByteArray code = "LUON_require('" + name + "')";
                if( !d_lua->executeCmd(code, "loader") )
                    hasErrors = true;
            }else
            {
                qDebug() << "preloading module" << name;
                // generic module instances or imported modules are just referenced so the client of the module
                // can load it via require and only then the instance is run for the first time.
                // this assures that the module table of the client is present when the generic
                // instance, which depends on this table, is run.
                if( !d_lua->addPreloadLib( d_byteCode[i].second, name ) )
                {
                    printLoadError(d_lua,name);
                    hasErrors = true;
                }
            }
            if( d_lua->isAborted() )
            {
                return true;
            }
        }
    }catch(...)
    {
        hasErrors = true;
        qCritical() << "LuaJIT crashed"; // doesn't help if the JIT crashes!
    }

    return !hasErrors;
}

bool LjRuntime::executeMain()
{
    Project::ModProc main = d_pro->getMain();
    if( main.first.isEmpty() )
    {
        Q_ASSERT( main.second.isEmpty() ); // we either need module or module.proc
        return true; // nothing to do
    }

    QByteArray src;
    QTextStream out(&src);

    // out << "require('LUON')" << endl; // was already called at this time
    out << "local " << main.first << " = LUON_require('" << main.first << "')" << endl;
    if( !main.second.isEmpty() )
        out << main.first << "." << main.second << "()" << endl;
    out.flush();
    return d_lua->executeCmd(src,"terminal");
}

bool LjRuntime::restartEngine()
{
    if( !d_lua->restart() )
        return false;
    prepareEngine();
    d_lua->setJit(d_jitEnabled);
    return true;
}

QByteArray LjRuntime::findByteCode(Declaration* m) const
{
    for( int i = 0; i < d_byteCode.size(); i++ )
    {
        if( d_byteCode[i].first == m )
            return d_byteCode[i].second;
    }
    return QByteArray();
}

QByteArray LjRuntime::findByteCode(const QByteArray& name) const
{
    for( int i = 0; i < d_byteCode.size(); i++ )
    {
        Declaration* d = d_byteCode[i].first;
        ModuleData md = d->data.value<ModuleData>();
        if( md.fullName == name )
            return d_byteCode[i].second;
    }
    return QByteArray();
}

LjRuntime::BytecodeList LjRuntime::findAllByteCodesOfPath(const QString& filePath) const
{
    BytecodeList res;
    for( int i = 0; i < d_byteCode.size(); i++ )
    {
        QByteArray moduleName = filePath.toUtf8();
        ModuleData md = d_byteCode[i].first->data.value<ModuleData>();
        if( md.source == filePath || d_byteCode[i].first->name == moduleName || md.fullName == moduleName )
            res.append(d_byteCode[i]);
    }
    return res;
}

bool LjRuntime::saveBytecode(const QString& outPath, const QString& suffix) const
{
    QDir dir(outPath);
    if( !dir.exists() && !dir.mkpath(outPath) )
    {
        qCritical() << "cannot create directory for writing bytecode files" << outPath;
        return false;
    }
    for( int i = 0; i < d_byteCode.size(); i++ )
    {
        QString path = dir.absoluteFilePath(d_byteCode[i].first->name + suffix);
        QFile out(path);
        if( !out.open(QIODevice::WriteOnly) )
        {
            qCritical() << "cannot open file for writing bytecode" << path;
            return false;
        }
        out.write(d_byteCode[i].second);
    }
    return true;
}

void LjRuntime::setJitEnabled(bool on)
{
    d_jitEnabled = on;
    d_lua->setJit(on);
}

void LjRuntime::generate()
{
    QList<Declaration*> mods = d_pro->getDependencyOrder();
    d_byteCode.clear();
    d_buildErrors = false;

    const quint32 errCount = d_pro->getErrors().size();
    foreach( Declaration* m, mods )
        LjbcGen::allocateModuleSlots(m);
    foreach( Declaration* m, mods )
        generate(m);

    d_buildErrors = d_pro->getErrors().size() != errCount;
}

void LjRuntime::generate(Declaration* m)
{
    //Q_ASSERT( m && m->isFullyInstantiated() );
    //qDebug() << "generating" << m->getName();
    QBuffer buf;
    buf.open(QIODevice::WriteOnly);
    LjbcGen gen;
    if( !gen.translate(m, &buf, false ) )
    {
        foreach( const LjbcGen::Error& e, gen.getErrors() )
            d_pro->addError(e.path,e.pos,e.msg);
    }
    buf.close();
    d_byteCode << qMakePair(m,buf.buffer());
}

extern "C" {
void PAL_setIdle(void (*tick)() );
void PAL2_setIdle(void (*tick)() );

static void tick()
{
    QApplication::processEvents(QEventLoop::AllEvents);
    QApplication::flush();
}

}

void LjRuntime::prepareEngine()
{
    lua_pushcfunction( d_lua->getCtx(), Lua::Engine2::TRAP );
    lua_setglobal( d_lua->getCtx(), "TRAP" );
#ifdef QT_GUI_LIB_
    Obs::Display::install(d_lua->getCtx());
#endif
    d_lua->addStdLibs();
    d_lua->addLibrary(Lua::Engine2::PACKAGE);
    d_lua->addLibrary(Lua::Engine2::IO);
    d_lua->addLibrary(Lua::Engine2::BIT);
    d_lua->addLibrary(Lua::Engine2::JIT);
    d_lua->addLibrary(Lua::Engine2::FFI);
    d_lua->addLibrary(Lua::Engine2::OS);
    // d_lua->setJit(false); // must be called after addLibrary! doesn't have any effect otherwise
    loadLuaLib( d_lua, "LUON", true );
    QDir::setCurrent(QFileInfo(d_pro->getProjectPath()).path());
#ifdef HAVE_SDL
    PAL_setIdle(tick);
    PAL2_setIdle(tick);
#endif
}

