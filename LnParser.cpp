// This file was automatically generated by EbnfStudio; don't modify it!
#include "LnParser.h"
using namespace Ln;

static inline bool FIRST_Luon(int tt) {
	return tt == Tok_MODULE;
}

static inline bool FIRST_number(int tt) {
	return tt == Tok_integer || tt == Tok_real;
}

static inline bool FIRST_qualident(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_identdef(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_ConstDeclaration(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_ConstExpression(int tt) {
	switch(tt){
	case Tok_TRUE:
	case Tok_Tilde:
	case Tok_string:
	case Tok_integer:
	case Tok_hexstring:
	case Tok_hexchar:
	case Tok_FALSE:
	case Tok_NIL:
	case Tok_Minus:
	case Tok_Lbrace:
	case Tok_Lpar:
	case Tok_Plus:
	case Tok_NOT:
	case Tok_real:
	case Tok_ident:
		return true;
	default: return false;
	}
}

static inline bool FIRST_TypeDeclaration(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_type(int tt) {
	switch(tt){
	case Tok_PROCEDURE:
	case Tok_ARRAY:
	case Tok_Lpar:
	case Tok_PROC:
	case Tok_RECORD:
	case Tok_Lbrack:
	case Tok_ident:
	case Tok_HASHMAP:
		return true;
	default: return false;
	}
}

static inline bool FIRST_NamedType(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_ArrayType(int tt) {
	return tt == Tok_ARRAY || tt == Tok_Lbrack;
}

static inline bool FIRST_length(int tt) {
	switch(tt){
	case Tok_TRUE:
	case Tok_Tilde:
	case Tok_string:
	case Tok_integer:
	case Tok_hexstring:
	case Tok_hexchar:
	case Tok_FALSE:
	case Tok_NIL:
	case Tok_Minus:
	case Tok_Lbrace:
	case Tok_Lpar:
	case Tok_Plus:
	case Tok_NOT:
	case Tok_real:
	case Tok_ident:
		return true;
	default: return false;
	}
}

static inline bool FIRST_DictType(int tt) {
	return tt == Tok_HASHMAP;
}

static inline bool FIRST_RecordType(int tt) {
	return tt == Tok_RECORD;
}

static inline bool FIRST_BaseType(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_FieldList(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_IdentList(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_enumeration(int tt) {
	return tt == Tok_Lpar;
}

static inline bool FIRST_constEnum(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_VariableDeclaration(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_designator(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_selector(int tt) {
	return tt == Tok_Lpar || tt == Tok_Lbrack || tt == Tok_Dot;
}

static inline bool FIRST_ExpList(int tt) {
	switch(tt){
	case Tok_TRUE:
	case Tok_Tilde:
	case Tok_string:
	case Tok_integer:
	case Tok_hexstring:
	case Tok_hexchar:
	case Tok_FALSE:
	case Tok_NIL:
	case Tok_Minus:
	case Tok_Lbrace:
	case Tok_Lpar:
	case Tok_Plus:
	case Tok_NOT:
	case Tok_real:
	case Tok_ident:
		return true;
	default: return false;
	}
}

static inline bool FIRST_expression(int tt) {
	switch(tt){
	case Tok_TRUE:
	case Tok_Tilde:
	case Tok_string:
	case Tok_integer:
	case Tok_hexstring:
	case Tok_hexchar:
	case Tok_FALSE:
	case Tok_NIL:
	case Tok_Minus:
	case Tok_Lbrace:
	case Tok_Lpar:
	case Tok_Plus:
	case Tok_NOT:
	case Tok_real:
	case Tok_ident:
		return true;
	default: return false;
	}
}

static inline bool FIRST_relation(int tt) {
	switch(tt){
	case Tok_Eq:
	case Tok_Geq:
	case Tok_Lt:
	case Tok_Leq:
	case Tok_IN:
	case Tok_Gt:
	case Tok_IS:
	case Tok_Hash:
		return true;
	default: return false;
	}
}

static inline bool FIRST_SimpleExpression(int tt) {
	switch(tt){
	case Tok_TRUE:
	case Tok_Tilde:
	case Tok_string:
	case Tok_integer:
	case Tok_hexstring:
	case Tok_hexchar:
	case Tok_FALSE:
	case Tok_NIL:
	case Tok_Minus:
	case Tok_Lbrace:
	case Tok_Lpar:
	case Tok_Plus:
	case Tok_NOT:
	case Tok_real:
	case Tok_ident:
		return true;
	default: return false;
	}
}

static inline bool FIRST_AddOperator(int tt) {
	return tt == Tok_Minus || tt == Tok_Plus || tt == Tok_OR;
}

static inline bool FIRST_term(int tt) {
	switch(tt){
	case Tok_TRUE:
	case Tok_Tilde:
	case Tok_string:
	case Tok_integer:
	case Tok_hexstring:
	case Tok_hexchar:
	case Tok_FALSE:
	case Tok_NIL:
	case Tok_Lbrace:
	case Tok_Lpar:
	case Tok_NOT:
	case Tok_real:
	case Tok_ident:
		return true;
	default: return false;
	}
}

static inline bool FIRST_MulOperator(int tt) {
	switch(tt){
	case Tok_Star:
	case Tok_AND:
	case Tok_DIV:
	case Tok_Amp:
	case Tok_MOD:
	case Tok_Slash:
		return true;
	default: return false;
	}
}

static inline bool FIRST_literal(int tt) {
	switch(tt){
	case Tok_TRUE:
	case Tok_string:
	case Tok_integer:
	case Tok_hexstring:
	case Tok_hexchar:
	case Tok_FALSE:
	case Tok_NIL:
	case Tok_real:
		return true;
	default: return false;
	}
}

static inline bool FIRST_constructor(int tt) {
	return tt == Tok_Lbrace || tt == Tok_ident;
}

static inline bool FIRST_component(int tt) {
	switch(tt){
	case Tok_TRUE:
	case Tok_Tilde:
	case Tok_string:
	case Tok_integer:
	case Tok_hexstring:
	case Tok_hexchar:
	case Tok_FALSE:
	case Tok_NIL:
	case Tok_Minus:
	case Tok_Lbrace:
	case Tok_Lpar:
	case Tok_NOT:
	case Tok_Plus:
	case Tok_Lbrack:
	case Tok_real:
	case Tok_ident:
		return true;
	default: return false;
	}
}

static inline bool FIRST_factor(int tt) {
	switch(tt){
	case Tok_TRUE:
	case Tok_Tilde:
	case Tok_string:
	case Tok_integer:
	case Tok_hexstring:
	case Tok_hexchar:
	case Tok_FALSE:
	case Tok_NIL:
	case Tok_Lbrace:
	case Tok_Lpar:
	case Tok_NOT:
	case Tok_real:
	case Tok_ident:
		return true;
	default: return false;
	}
}

static inline bool FIRST_variableOrFunctionCall(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_statement(int tt) {
	switch(tt){
	case Tok_REPEAT:
	case Tok_RETURN:
	case Tok_LOOP:
	case Tok_EXIT:
	case Tok_FOR:
	case Tok_IF:
	case Tok_CASE:
	case Tok_ident:
	case Tok_WHILE:
		return true;
	default: return false;
	}
}

static inline bool FIRST_assignmentOrProcedureCall(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_StatementSequence(int tt) {
	switch(tt){
	case Tok_REPEAT:
	case Tok_RETURN:
	case Tok_LOOP:
	case Tok_EXIT:
	case Tok_FOR:
	case Tok_IF:
	case Tok_CASE:
	case Tok_ident:
	case Tok_WHILE:
		return true;
	default: return false;
	}
}

static inline bool FIRST_IfStatement(int tt) {
	return tt == Tok_IF;
}

static inline bool FIRST_ElsifStatement(int tt) {
	return tt == Tok_ELSIF;
}

static inline bool FIRST_ElseStatement(int tt) {
	return tt == Tok_ELSE;
}

static inline bool FIRST_CaseStatement(int tt) {
	return tt == Tok_CASE;
}

static inline bool FIRST_Case(int tt) {
	switch(tt){
	case Tok_TRUE:
	case Tok_Tilde:
	case Tok_string:
	case Tok_integer:
	case Tok_hexstring:
	case Tok_hexchar:
	case Tok_FALSE:
	case Tok_NIL:
	case Tok_Minus:
	case Tok_Lbrace:
	case Tok_Lpar:
	case Tok_Plus:
	case Tok_NOT:
	case Tok_real:
	case Tok_ident:
		return true;
	default: return false;
	}
}

static inline bool FIRST_CaseLabelList(int tt) {
	switch(tt){
	case Tok_TRUE:
	case Tok_Tilde:
	case Tok_string:
	case Tok_integer:
	case Tok_hexstring:
	case Tok_hexchar:
	case Tok_FALSE:
	case Tok_NIL:
	case Tok_Minus:
	case Tok_Lbrace:
	case Tok_Lpar:
	case Tok_Plus:
	case Tok_NOT:
	case Tok_real:
	case Tok_ident:
		return true;
	default: return false;
	}
}

static inline bool FIRST_LabelRange(int tt) {
	switch(tt){
	case Tok_TRUE:
	case Tok_Tilde:
	case Tok_string:
	case Tok_integer:
	case Tok_hexstring:
	case Tok_hexchar:
	case Tok_FALSE:
	case Tok_NIL:
	case Tok_Minus:
	case Tok_Lbrace:
	case Tok_Lpar:
	case Tok_Plus:
	case Tok_NOT:
	case Tok_real:
	case Tok_ident:
		return true;
	default: return false;
	}
}

static inline bool FIRST_label(int tt) {
	switch(tt){
	case Tok_TRUE:
	case Tok_Tilde:
	case Tok_string:
	case Tok_integer:
	case Tok_hexstring:
	case Tok_hexchar:
	case Tok_FALSE:
	case Tok_NIL:
	case Tok_Minus:
	case Tok_Lbrace:
	case Tok_Lpar:
	case Tok_Plus:
	case Tok_NOT:
	case Tok_real:
	case Tok_ident:
		return true;
	default: return false;
	}
}

static inline bool FIRST_WhileStatement(int tt) {
	return tt == Tok_WHILE;
}

static inline bool FIRST_RepeatStatement(int tt) {
	return tt == Tok_REPEAT;
}

static inline bool FIRST_ForStatement(int tt) {
	return tt == Tok_FOR;
}

static inline bool FIRST_LoopStatement(int tt) {
	return tt == Tok_LOOP;
}

static inline bool FIRST_ExitStatement(int tt) {
	return tt == Tok_EXIT;
}

static inline bool FIRST_procedure(int tt) {
	return tt == Tok_PROCEDURE || tt == Tok_PROC;
}

static inline bool FIRST_ProcedureType(int tt) {
	return tt == Tok_PROCEDURE || tt == Tok_PROC;
}

static inline bool FIRST_ProcedureDeclaration(int tt) {
	return tt == Tok_PROCEDURE || tt == Tok_PROC;
}

static inline bool FIRST_ProcedureHeading(int tt) {
	return tt == Tok_PROCEDURE || tt == Tok_PROC;
}

static inline bool FIRST_Receiver(int tt) {
	return tt == Tok_Lpar;
}

static inline bool FIRST_block(int tt) {
	return tt == Tok_BEGIN;
}

static inline bool FIRST_ProcedureBody(int tt) {
	switch(tt){
	case Tok_VAR:
	case Tok_PROCEDURE:
	case Tok_CONST:
	case Tok_PROC:
	case Tok_TYPE:
	case Tok_BEGIN:
		return true;
	default: return false;
	}
}

static inline bool FIRST_DeclarationSequence(int tt) {
	return tt == Tok_VAR || tt == Tok_PROCEDURE || tt == Tok_CONST || tt == Tok_PROC || tt == Tok_TYPE;
}

static inline bool FIRST_ReturnStatement(int tt) {
	return tt == Tok_RETURN;
}

static inline bool FIRST_FormalParameters(int tt) {
	return tt == Tok_Lpar;
}

static inline bool FIRST_ReturnType(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_FPSection(int tt) {
	return tt == Tok_VAR || tt == Tok_IN || tt == Tok_ident;
}

static inline bool FIRST_FormalType(int tt) {
	switch(tt){
	case Tok_PROCEDURE:
	case Tok_ARRAY:
	case Tok_Lpar:
	case Tok_PROC:
	case Tok_RECORD:
	case Tok_Lbrack:
	case Tok_ident:
	case Tok_HASHMAP:
		return true;
	default: return false;
	}
}

static inline bool FIRST_module(int tt) {
	return tt == Tok_MODULE;
}

static inline bool FIRST_ImportList(int tt) {
	return tt == Tok_IMPORT;
}

static inline bool FIRST_import(int tt) {
	return tt == Tok_ident;
}

static inline bool FIRST_MetaActuals(int tt) {
	return tt == Tok_Lpar;
}

static inline bool FIRST_MetaParams(int tt) {
	return tt == Tok_Lpar;
}

static inline bool FIRST_MetaSection(int tt) {
	return tt == Tok_CONST || tt == Tok_TYPE || tt == Tok_ident;
}

void Parser::RunParser() {
	errors.clear();
	next();
	Luon();
}

void Parser::next() {
	cur = la;
	la = scanner->next();
	while( la.d_type == Tok_Invalid ) {
		errors << Error(la.d_val, la.d_lineNr, la.d_colNr, la.d_sourcePath);
		la = scanner->next();
	}
}

Token Parser::peek(int off) {
	if( off == 1 )
		return la;
	else if( off == 0 )
		return cur;
	else
		return scanner->peek(off-1);
}

void Parser::invalid(const char* what) {
	errors << Error(QString("invalid %1").arg(what),la.d_lineNr, la.d_colNr, la.d_sourcePath);
}

bool Parser::expect(int tt, bool pkw, const char* where) {
	if( la.d_type == tt) { next(); return true; }
	else { errors << Error(QString("'%1' expected in %2").arg(tokenTypeString(tt)).arg(where),la.d_lineNr, la.d_colNr, la.d_sourcePath); return false; }
}

static inline void dummy() {}

void Parser::Luon() {
	module();
}

void Parser::number() {
	if( la.d_type == Tok_integer ) {
		expect(Tok_integer, false, "number");
	} else if( la.d_type == Tok_real ) {
		expect(Tok_real, false, "number");
	} else
		invalid("number");
}

void Parser::qualident() {
	if( ( peek(2).d_type == Tok_Dot )  ) {
		expect(Tok_ident, false, "qualident");
		expect(Tok_Dot, false, "qualident");
	}
	expect(Tok_ident, false, "qualident");
}

void Parser::identdef() {
	expect(Tok_ident, false, "identdef");
	if( la.d_type == Tok_Star || la.d_type == Tok_Minus ) {
		if( la.d_type == Tok_Star ) {
			expect(Tok_Star, false, "identdef");
		} else if( la.d_type == Tok_Minus ) {
			expect(Tok_Minus, false, "identdef");
		} else
			invalid("identdef");
	}
}

void Parser::ConstDeclaration() {
	identdef();
	expect(Tok_Eq, false, "ConstDeclaration");
	ConstExpression();
}

void Parser::ConstExpression() {
	expression();
}

void Parser::TypeDeclaration() {
	identdef();
	expect(Tok_Eq, false, "TypeDeclaration");
	type();
}

void Parser::type() {
	if( FIRST_NamedType(la.d_type) ) {
		NamedType();
	} else if( FIRST_ArrayType(la.d_type) ) {
		ArrayType();
	} else if( FIRST_DictType(la.d_type) ) {
		DictType();
	} else if( FIRST_RecordType(la.d_type) ) {
		RecordType();
	} else if( FIRST_ProcedureType(la.d_type) ) {
		ProcedureType();
	} else if( FIRST_enumeration(la.d_type) ) {
		enumeration();
	} else
		invalid("type");
}

void Parser::NamedType() {
	qualident();
}

void Parser::ArrayType() {
	if( la.d_type == Tok_ARRAY ) {
		expect(Tok_ARRAY, true, "ArrayType");
		if( FIRST_length(la.d_type) ) {
			length();
		}
		expect(Tok_OF, true, "ArrayType");
		type();
	} else if( la.d_type == Tok_Lbrack ) {
		expect(Tok_Lbrack, false, "ArrayType");
		if( FIRST_length(la.d_type) ) {
			length();
		}
		expect(Tok_Rbrack, false, "ArrayType");
		type();
	} else
		invalid("ArrayType");
}

void Parser::length() {
	ConstExpression();
}

void Parser::DictType() {
	expect(Tok_HASHMAP, true, "DictType");
	NamedType();
	expect(Tok_OF, true, "DictType");
	type();
}

void Parser::RecordType() {
	expect(Tok_RECORD, true, "RecordType");
	if( la.d_type == Tok_Lpar ) {
		expect(Tok_Lpar, false, "RecordType");
		BaseType();
		expect(Tok_Rpar, false, "RecordType");
	}
	while( FIRST_FieldList(la.d_type) ) {
		FieldList();
		if( la.d_type == Tok_Semi ) {
			expect(Tok_Semi, false, "RecordType");
		}
	}
	expect(Tok_END, true, "RecordType");
}

void Parser::BaseType() {
	NamedType();
}

void Parser::FieldList() {
	IdentList();
	expect(Tok_Colon, false, "FieldList");
	type();
}

void Parser::IdentList() {
	identdef();
	while( la.d_type == Tok_Comma || FIRST_identdef(la.d_type) ) {
		if( la.d_type == Tok_Comma ) {
			expect(Tok_Comma, false, "IdentList");
		}
		identdef();
	}
}

void Parser::enumeration() {
	expect(Tok_Lpar, false, "enumeration");
	constEnum();
	expect(Tok_Rpar, false, "enumeration");
}

void Parser::constEnum() {
	expect(Tok_ident, false, "constEnum");
	if( la.d_type == Tok_Eq ) {
		expect(Tok_Eq, false, "constEnum");
		ConstExpression();
	}
	while( la.d_type == Tok_Comma || la.d_type == Tok_ident ) {
		if( la.d_type == Tok_Comma ) {
			expect(Tok_Comma, false, "constEnum");
		}
		expect(Tok_ident, false, "constEnum");
	}
}

void Parser::VariableDeclaration() {
	IdentList();
	expect(Tok_Colon, false, "VariableDeclaration");
	type();
}

void Parser::designator() {
	qualident();
	while( FIRST_selector(la.d_type) ) {
		selector();
	}
}

void Parser::selector() {
	if( la.d_type == Tok_Dot ) {
		expect(Tok_Dot, false, "selector");
		expect(Tok_ident, false, "selector");
	} else if( la.d_type == Tok_Lbrack ) {
		expect(Tok_Lbrack, false, "selector");
		expression();
		expect(Tok_Rbrack, false, "selector");
	} else if( la.d_type == Tok_Lpar ) {
		expect(Tok_Lpar, false, "selector");
		if( FIRST_ExpList(la.d_type) ) {
			ExpList();
		}
		expect(Tok_Rpar, false, "selector");
	} else
		invalid("selector");
}

void Parser::ExpList() {
	expression();
	while( la.d_type == Tok_Comma || FIRST_expression(la.d_type) ) {
		if( la.d_type == Tok_Comma ) {
			expect(Tok_Comma, false, "ExpList");
		}
		expression();
	}
}

void Parser::expression() {
	SimpleExpression();
	if( FIRST_relation(la.d_type) ) {
		relation();
		SimpleExpression();
	}
}

void Parser::relation() {
	if( la.d_type == Tok_Eq ) {
		expect(Tok_Eq, false, "relation");
	} else if( la.d_type == Tok_Hash ) {
		expect(Tok_Hash, false, "relation");
	} else if( la.d_type == Tok_Lt ) {
		expect(Tok_Lt, false, "relation");
	} else if( la.d_type == Tok_Leq ) {
		expect(Tok_Leq, false, "relation");
	} else if( la.d_type == Tok_Gt ) {
		expect(Tok_Gt, false, "relation");
	} else if( la.d_type == Tok_Geq ) {
		expect(Tok_Geq, false, "relation");
	} else if( la.d_type == Tok_IN ) {
		expect(Tok_IN, false, "relation");
	} else if( la.d_type == Tok_IS ) {
		expect(Tok_IS, true, "relation");
	} else
		invalid("relation");
}

void Parser::SimpleExpression() {
	if( la.d_type == Tok_Plus || la.d_type == Tok_Minus ) {
		if( la.d_type == Tok_Plus ) {
			expect(Tok_Plus, false, "SimpleExpression");
		} else if( la.d_type == Tok_Minus ) {
			expect(Tok_Minus, false, "SimpleExpression");
		} else
			invalid("SimpleExpression");
	}
	term();
	while( FIRST_AddOperator(la.d_type) ) {
		AddOperator();
		term();
	}
}

void Parser::AddOperator() {
	if( la.d_type == Tok_Plus ) {
		expect(Tok_Plus, false, "AddOperator");
	} else if( la.d_type == Tok_Minus ) {
		expect(Tok_Minus, false, "AddOperator");
	} else if( la.d_type == Tok_OR ) {
		expect(Tok_OR, true, "AddOperator");
	} else
		invalid("AddOperator");
}

void Parser::term() {
	factor();
	while( FIRST_MulOperator(la.d_type) ) {
		MulOperator();
		factor();
	}
}

void Parser::MulOperator() {
	if( la.d_type == Tok_Star ) {
		expect(Tok_Star, false, "MulOperator");
	} else if( la.d_type == Tok_Slash ) {
		expect(Tok_Slash, false, "MulOperator");
	} else if( la.d_type == Tok_DIV ) {
		expect(Tok_DIV, true, "MulOperator");
	} else if( la.d_type == Tok_MOD ) {
		expect(Tok_MOD, true, "MulOperator");
	} else if( la.d_type == Tok_Amp ) {
		expect(Tok_Amp, false, "MulOperator");
	} else if( la.d_type == Tok_AND ) {
		expect(Tok_AND, true, "MulOperator");
	} else
		invalid("MulOperator");
}

void Parser::literal() {
	if( FIRST_number(la.d_type) ) {
		number();
	} else if( la.d_type == Tok_string ) {
		expect(Tok_string, false, "literal");
	} else if( la.d_type == Tok_hexstring ) {
		expect(Tok_hexstring, false, "literal");
	} else if( la.d_type == Tok_hexchar ) {
		expect(Tok_hexchar, false, "literal");
	} else if( la.d_type == Tok_NIL ) {
		expect(Tok_NIL, true, "literal");
	} else if( la.d_type == Tok_TRUE ) {
		expect(Tok_TRUE, true, "literal");
	} else if( la.d_type == Tok_FALSE ) {
		expect(Tok_FALSE, true, "literal");
	} else
		invalid("literal");
}

void Parser::constructor() {
	if( FIRST_NamedType(la.d_type) ) {
		NamedType();
	}
	expect(Tok_Lbrace, false, "constructor");
	if( FIRST_component(la.d_type) ) {
		component();
		while( la.d_type == Tok_Comma || FIRST_component(la.d_type) ) {
			if( la.d_type == Tok_Comma ) {
				expect(Tok_Comma, false, "constructor");
			}
			component();
		}
	}
	expect(Tok_Rbrace, false, "constructor");
}

void Parser::component() {
	if( ( peek(1).d_type == Tok_ident && peek(2).d_type == Tok_Colon )  ) {
		expect(Tok_ident, false, "component");
		expect(Tok_Colon, false, "component");
		expression();
	} else if( la.d_type == Tok_Lbrack ) {
		expect(Tok_Lbrack, false, "component");
		expression();
		expect(Tok_Rbrack, false, "component");
		expect(Tok_Colon, false, "component");
		expression();
	} else if( FIRST_expression(la.d_type) ) {
		expression();
		if( la.d_type == Tok_2Dot ) {
			expect(Tok_2Dot, false, "component");
			expression();
		}
	} else
		invalid("component");
}

void Parser::factor() {
	if( ( ( peek(1).d_type == Tok_Lbrace || peek(1).d_type == Tok_ident && peek(2).d_type == Tok_Lbrace ) )  ) {
		constructor();
	} else if( FIRST_literal(la.d_type) ) {
		literal();
	} else if( FIRST_variableOrFunctionCall(la.d_type) ) {
		variableOrFunctionCall();
	} else if( la.d_type == Tok_Lpar ) {
		expect(Tok_Lpar, false, "factor");
		expression();
		expect(Tok_Rpar, false, "factor");
	} else if( la.d_type == Tok_Tilde || la.d_type == Tok_NOT ) {
		if( la.d_type == Tok_Tilde ) {
			expect(Tok_Tilde, false, "factor");
		} else if( la.d_type == Tok_NOT ) {
			expect(Tok_NOT, true, "factor");
		} else
			invalid("factor");
		factor();
	} else
		invalid("factor");
}

void Parser::variableOrFunctionCall() {
	designator();
}

void Parser::statement() {
	if( FIRST_assignmentOrProcedureCall(la.d_type) ) {
		assignmentOrProcedureCall();
	} else if( FIRST_IfStatement(la.d_type) ) {
		IfStatement();
	} else if( FIRST_CaseStatement(la.d_type) ) {
		CaseStatement();
	} else if( FIRST_LoopStatement(la.d_type) ) {
		LoopStatement();
	} else if( FIRST_ExitStatement(la.d_type) ) {
		ExitStatement();
	} else if( FIRST_ReturnStatement(la.d_type) ) {
		ReturnStatement();
	} else if( FIRST_WhileStatement(la.d_type) ) {
		WhileStatement();
	} else if( FIRST_RepeatStatement(la.d_type) ) {
		RepeatStatement();
	} else if( FIRST_ForStatement(la.d_type) ) {
		ForStatement();
	} else
		invalid("statement");
}

void Parser::assignmentOrProcedureCall() {
	designator();
	if( la.d_type == Tok_ColonEq ) {
		expect(Tok_ColonEq, false, "assignmentOrProcedureCall");
		expression();
	}
}

void Parser::StatementSequence() {
	while( FIRST_statement(la.d_type) ) {
		statement();
		while( la.d_type == Tok_Semi ) {
			expect(Tok_Semi, false, "StatementSequence");
		}
	}
}

void Parser::IfStatement() {
	expect(Tok_IF, true, "IfStatement");
	expression();
	expect(Tok_THEN, true, "IfStatement");
	StatementSequence();
	while( FIRST_ElsifStatement(la.d_type) ) {
		ElsifStatement();
	}
	if( FIRST_ElseStatement(la.d_type) ) {
		ElseStatement();
	}
	expect(Tok_END, true, "IfStatement");
}

void Parser::ElsifStatement() {
	expect(Tok_ELSIF, true, "ElsifStatement");
	expression();
	expect(Tok_THEN, true, "ElsifStatement");
	StatementSequence();
}

void Parser::ElseStatement() {
	expect(Tok_ELSE, true, "ElseStatement");
	StatementSequence();
}

void Parser::CaseStatement() {
	expect(Tok_CASE, true, "CaseStatement");
	expression();
	expect(Tok_OF, true, "CaseStatement");
	if( FIRST_Case(la.d_type) ) {
		Case();
	}
	while( la.d_type == Tok_Bar ) {
		expect(Tok_Bar, false, "CaseStatement");
		Case();
	}
	if( la.d_type == Tok_ELSE ) {
		expect(Tok_ELSE, true, "CaseStatement");
		StatementSequence();
	}
	expect(Tok_END, true, "CaseStatement");
}

void Parser::Case() {
	CaseLabelList();
	expect(Tok_Colon, false, "Case");
	StatementSequence();
}

void Parser::CaseLabelList() {
	LabelRange();
	while( la.d_type == Tok_Comma || FIRST_LabelRange(la.d_type) ) {
		if( la.d_type == Tok_Comma ) {
			expect(Tok_Comma, false, "CaseLabelList");
		}
		LabelRange();
	}
}

void Parser::LabelRange() {
	label();
	if( la.d_type == Tok_2Dot ) {
		expect(Tok_2Dot, false, "LabelRange");
		label();
	}
}

void Parser::label() {
	ConstExpression();
}

void Parser::WhileStatement() {
	expect(Tok_WHILE, true, "WhileStatement");
	expression();
	expect(Tok_DO, true, "WhileStatement");
	StatementSequence();
	expect(Tok_END, true, "WhileStatement");
}

void Parser::RepeatStatement() {
	expect(Tok_REPEAT, true, "RepeatStatement");
	StatementSequence();
	expect(Tok_UNTIL, true, "RepeatStatement");
	expression();
}

void Parser::ForStatement() {
	expect(Tok_FOR, true, "ForStatement");
	expect(Tok_ident, false, "ForStatement");
	expect(Tok_ColonEq, false, "ForStatement");
	expression();
	expect(Tok_TO, true, "ForStatement");
	expression();
	if( la.d_type == Tok_BY ) {
		expect(Tok_BY, true, "ForStatement");
		ConstExpression();
	}
	expect(Tok_DO, true, "ForStatement");
	StatementSequence();
	expect(Tok_END, true, "ForStatement");
}

void Parser::LoopStatement() {
	expect(Tok_LOOP, true, "LoopStatement");
	StatementSequence();
	expect(Tok_END, true, "LoopStatement");
}

void Parser::ExitStatement() {
	expect(Tok_EXIT, true, "ExitStatement");
}

void Parser::procedure() {
	if( la.d_type == Tok_PROCEDURE ) {
		expect(Tok_PROCEDURE, true, "procedure");
	} else if( la.d_type == Tok_PROC ) {
		expect(Tok_PROC, true, "procedure");
	} else
		invalid("procedure");
}

void Parser::ProcedureType() {
	procedure();
	if( la.d_type == Tok_Hat ) {
		expect(Tok_Hat, false, "ProcedureType");
	}
	if( FIRST_FormalParameters(la.d_type) ) {
		FormalParameters();
	}
}

void Parser::ProcedureDeclaration() {
	ProcedureHeading();
	if( ( ( peek(1).d_type == Tok_EXTERN || peek(1).d_type == Tok_Semi ) && ( peek(2).d_type == Tok_EXTERN || peek(2).d_type == Tok_ident ) )  ) {
		if( la.d_type == Tok_Semi ) {
			expect(Tok_Semi, false, "ProcedureDeclaration");
		}
		expect(Tok_EXTERN, true, "ProcedureDeclaration");
		if( la.d_type == Tok_ident ) {
			expect(Tok_ident, false, "ProcedureDeclaration");
		}
	} else if( la.d_type == Tok_INLINE || la.d_type == Tok_INVAR || la.d_type == Tok_Semi || FIRST_ProcedureBody(la.d_type) || la.d_type == Tok_END ) {
		if( la.d_type == Tok_INLINE || la.d_type == Tok_INVAR ) {
			if( la.d_type == Tok_INLINE ) {
				expect(Tok_INLINE, true, "ProcedureDeclaration");
			} else if( la.d_type == Tok_INVAR ) {
				expect(Tok_INVAR, true, "ProcedureDeclaration");
			} else
				invalid("ProcedureDeclaration");
		}
		if( la.d_type == Tok_Semi ) {
			expect(Tok_Semi, false, "ProcedureDeclaration");
		}
		if( FIRST_ProcedureBody(la.d_type) ) {
			ProcedureBody();
		} else if( la.d_type == Tok_END ) {
			expect(Tok_END, true, "ProcedureDeclaration");
		} else
			invalid("ProcedureDeclaration");
	} else
		invalid("ProcedureDeclaration");
}

void Parser::ProcedureHeading() {
	procedure();
	if( FIRST_Receiver(la.d_type) ) {
		Receiver();
	}
	identdef();
	if( FIRST_FormalParameters(la.d_type) ) {
		FormalParameters();
	}
}

void Parser::Receiver() {
	expect(Tok_Lpar, false, "Receiver");
	expect(Tok_ident, false, "Receiver");
	expect(Tok_Colon, false, "Receiver");
	expect(Tok_ident, false, "Receiver");
	expect(Tok_Rpar, false, "Receiver");
}

void Parser::block() {
	expect(Tok_BEGIN, true, "block");
	StatementSequence();
}

void Parser::ProcedureBody() {
	DeclarationSequence();
	block();
	expect(Tok_END, true, "ProcedureBody");
	expect(Tok_ident, false, "ProcedureBody");
}

void Parser::DeclarationSequence() {
	while( la.d_type == Tok_CONST || la.d_type == Tok_TYPE || la.d_type == Tok_VAR || FIRST_ProcedureDeclaration(la.d_type) ) {
		if( la.d_type == Tok_CONST ) {
			expect(Tok_CONST, true, "DeclarationSequence");
			while( FIRST_ConstDeclaration(la.d_type) ) {
				ConstDeclaration();
				if( la.d_type == Tok_Semi ) {
					expect(Tok_Semi, false, "DeclarationSequence");
				}
			}
		} else if( la.d_type == Tok_TYPE ) {
			expect(Tok_TYPE, true, "DeclarationSequence");
			while( FIRST_TypeDeclaration(la.d_type) ) {
				TypeDeclaration();
				if( la.d_type == Tok_Semi ) {
					expect(Tok_Semi, false, "DeclarationSequence");
				}
			}
		} else if( la.d_type == Tok_VAR ) {
			expect(Tok_VAR, true, "DeclarationSequence");
			while( FIRST_VariableDeclaration(la.d_type) ) {
				VariableDeclaration();
				if( la.d_type == Tok_Semi ) {
					expect(Tok_Semi, false, "DeclarationSequence");
				}
			}
		} else if( FIRST_ProcedureDeclaration(la.d_type) ) {
			ProcedureDeclaration();
			if( la.d_type == Tok_Semi ) {
				expect(Tok_Semi, false, "DeclarationSequence");
			}
		} else
			invalid("DeclarationSequence");
	}
}

void Parser::ReturnStatement() {
	expect(Tok_RETURN, true, "ReturnStatement");
	if( FIRST_expression(la.d_type) ) {
		expression();
	}
}

void Parser::FormalParameters() {
	expect(Tok_Lpar, false, "FormalParameters");
	if( FIRST_FPSection(la.d_type) ) {
		FPSection();
		while( ( ( ( peek(1).d_type == Tok_ident || peek(1).d_type == Tok_IN || peek(1).d_type == Tok_VAR ) || peek(1).d_type == Tok_Semi && ( peek(2).d_type == Tok_ident || peek(2).d_type == Tok_IN || peek(2).d_type == Tok_VAR ) ) )  ) {
			if( la.d_type == Tok_Semi ) {
				expect(Tok_Semi, false, "FormalParameters");
			}
			FPSection();
		}
		if( la.d_type == Tok_Semi || la.d_type == Tok_2Dot ) {
			if( la.d_type == Tok_Semi ) {
				expect(Tok_Semi, false, "FormalParameters");
			}
			expect(Tok_2Dot, false, "FormalParameters");
		}
	}
	expect(Tok_Rpar, false, "FormalParameters");
	if( la.d_type == Tok_Colon ) {
		expect(Tok_Colon, false, "FormalParameters");
		ReturnType();
	}
}

void Parser::ReturnType() {
	NamedType();
}

void Parser::FPSection() {
	if( la.d_type == Tok_VAR || la.d_type == Tok_IN ) {
		if( la.d_type == Tok_VAR ) {
			expect(Tok_VAR, false, "FPSection");
		} else if( la.d_type == Tok_IN ) {
			expect(Tok_IN, false, "FPSection");
		} else
			invalid("FPSection");
	}
	expect(Tok_ident, false, "FPSection");
	while( la.d_type == Tok_Comma || la.d_type == Tok_ident ) {
		if( la.d_type == Tok_Comma ) {
			expect(Tok_Comma, false, "FPSection");
		}
		expect(Tok_ident, false, "FPSection");
	}
	expect(Tok_Colon, false, "FPSection");
	FormalType();
}

void Parser::FormalType() {
	type();
}

void Parser::module() {
	expect(Tok_MODULE, true, "module");
	expect(Tok_ident, false, "module");
	if( FIRST_MetaParams(la.d_type) ) {
		MetaParams();
	}
	if( la.d_type == Tok_Semi ) {
		expect(Tok_Semi, false, "module");
	}
	while( FIRST_ImportList(la.d_type) || FIRST_DeclarationSequence(la.d_type) ) {
		if( FIRST_ImportList(la.d_type) ) {
			ImportList();
		} else if( FIRST_DeclarationSequence(la.d_type) || la.d_type == Tok_PROC || la.d_type == Tok_VAR || la.d_type == Tok_END || la.d_type == Tok_BEGIN || la.d_type == Tok_CONST || la.d_type == Tok_IMPORT || la.d_type == Tok_TYPE || la.d_type == Tok_PROCEDURE ) {
			DeclarationSequence();
		} else
			invalid("module");
	}
	if( FIRST_block(la.d_type) ) {
		block();
	}
	expect(Tok_END, true, "module");
	expect(Tok_ident, false, "module");
	if( la.d_type == Tok_Dot ) {
		expect(Tok_Dot, false, "module");
	}
}

void Parser::ImportList() {
	expect(Tok_IMPORT, true, "ImportList");
	import();
	while( la.d_type == Tok_Comma || FIRST_import(la.d_type) ) {
		if( la.d_type == Tok_Comma ) {
			expect(Tok_Comma, false, "ImportList");
		}
		import();
	}
	if( la.d_type == Tok_Semi ) {
		expect(Tok_Semi, false, "ImportList");
	}
}

void Parser::import() {
	if( ( peek(1).d_type == Tok_ident && peek(2).d_type == Tok_ColonEq )  ) {
		expect(Tok_ident, false, "import");
		expect(Tok_ColonEq, false, "import");
	}
	expect(Tok_ident, false, "import");
	while( la.d_type == Tok_Dot ) {
		expect(Tok_Dot, false, "import");
		expect(Tok_ident, false, "import");
	}
	if( FIRST_MetaActuals(la.d_type) ) {
		MetaActuals();
	}
}

void Parser::MetaActuals() {
	expect(Tok_Lpar, false, "MetaActuals");
	ConstExpression();
	while( la.d_type == Tok_Comma || FIRST_ConstExpression(la.d_type) ) {
		if( la.d_type == Tok_Comma ) {
			expect(Tok_Comma, false, "MetaActuals");
		}
		ConstExpression();
	}
	expect(Tok_Rpar, false, "MetaActuals");
}

void Parser::MetaParams() {
	expect(Tok_Lpar, false, "MetaParams");
	MetaSection();
	while( la.d_type == Tok_Semi || FIRST_MetaSection(la.d_type) ) {
		if( la.d_type == Tok_Semi ) {
			expect(Tok_Semi, false, "MetaParams");
		}
		MetaSection();
	}
	expect(Tok_Rpar, false, "MetaParams");
}

void Parser::MetaSection() {
	if( la.d_type == Tok_TYPE || la.d_type == Tok_CONST ) {
		if( la.d_type == Tok_TYPE ) {
			expect(Tok_TYPE, false, "MetaSection");
		} else if( la.d_type == Tok_CONST ) {
			expect(Tok_CONST, false, "MetaSection");
		} else
			invalid("MetaSection");
	}
	expect(Tok_ident, false, "MetaSection");
	while( ( ( peek(1).d_type == Tok_Comma || peek(1).d_type == Tok_ident ) && peek(2).d_type == Tok_ident )  ) {
		if( la.d_type == Tok_Comma ) {
			expect(Tok_Comma, false, "MetaSection");
		}
		expect(Tok_ident, false, "MetaSection");
	}
	if( la.d_type == Tok_Colon ) {
		expect(Tok_Colon, false, "MetaSection");
		NamedType();
	}
}

