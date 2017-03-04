%{
include <stdio.h>
%}

%start Program
%token _assignop
%token _or
%token _and
%token _equal _notequal
%token _less _lessequal _greater _greaterequal
%token _plus _minus
%token _multiplication _division _mod
%right _not _minus
%token _leftbracket _rightbracket _period
%token _void _id _leftparen _rightparen _doubleconstant _stringconstant _leftbrace _rightbrace _semicolon _boolean _double _int _string _class _implements
%token _if _else _break _class _extends _false _for _newarray _println _readln _return _while _comma _period _leftparen _rightparen _intconstant _doubleconstant _stringconstant _booleanconstant 
%%

Program : Decls
	;

/* Left-recursion */
Decls : Decl
	  | Decls Decl
	  ;

Decl : VariableDecl 
	 | FunctionDecl 
	 | ClassDecl 
	 | InterfaceDecl
	 ;

VariableDecls : /* zero */
	 | VariableDecls VariableDecl
	 ;

VariableDecl : Variable _semicolon
	 ;

Variable : Type _id
	 ;

Type : _int 
	 | _double 
	 | _boolean 
	 | _string 
	 | Type "[]"  
	 | _id
	 ;

FunctionDecl : Type _id "(" Formals ")" StmtBlock 
	 | _void _id "(" Formals ")" StmtBlock
	 ;

Formals : Variables
	 | /* epsilon */
	 ;

/* Left-recursion */
Variables : Variable
	 | Variables "," Variable
	 ;

ClassDecl : _class _id "<" _extends _id ">" "<" _implements ids ">" "{" Fields "}"
	 ;
Fields : /* zero */
	 | Fields Field
	 ;

Field : VariableDecl
	 | FunctionDecl
	 ;

ids : _id
	| ids"," _id
	;

InterfaceDecl : interface _id "{" Prototypes "}"
	 ;

Prototypes : /* zero */
	 | Prototypes Prototype
	 ;

Prototype : Type _id "(" Formals ")" _semicolon
	 | _void _id "(" Formals ")" _semicolon
	 ;

StmtBlock : "{" VariableDecls Stmts "}"
	 ;

Stmts : /* zero */
	 | Stmts Stmt
	 ;

Stmt : "<" Expr ">" _semicolon
	 | IfStmt
	 | WhileStmt 
	 | ForStmt 
	 | BreakStmt 
	 | ReturnStmt 
	 | PrintStmt 
	 | StmtBlock
	 ;

IfStmt : _if "(" Expr ")" Stmt "<" else Stmt ">"
	 ;


WhileStmt : _while "(" Expr ")" Stmt
	 ;

ForStmt : _for "(" "<" Expr ">" _semicolon Expr _semicolon "<" Expr ">" ")" Stmt
	 ;

BreakStmt : _break _semicolon
	 ;

ReturnStmt : return "<" Expr ">" _semicolon
	 ;

PrintStmt : println "(" Exprs ")" _semicolon
	 ;

Exprs : Expr
	 | Exprs"," Expr
	 ;	 

Expr : Lvalue "=" Expr 
	 | Constant 
	 | Lvalue 
	 | Call 
	 | "(" Expr ")" 
	 | Expr "+" Expr 
	 | Expr "–" Expr 
	 | Expr "*" Expr 
	 | Expr "/" Expr 
	 | Expr "%" Expr 
	 | "-" Expr 
	 | Expr "<"  Expr 
	 | Expr "<=" Expr 
	 | Expr ">" Expr 
	 | Expr ">=" Expr 
	 | Expr "==" Expr 
	 | Expr "!=" Expr 
	 | Expr "&&" Expr 
	 | Expr "||" Expr 
	 | "!" Expr
	 | readln"()" 
	 | _newarray "(" _intconstant "," Type ")"
	 ;

Lvalue : id 
	 | Lvalue "[" Expr "]"  
	 | Lvalue "." _id
	 ;

Call : id "(" Actuals ")" 
	 | _id "." _id "(" Actuals ")"
	 ;

Actuals : /* Epsilon */ 
	 : Exprs
	 ;
	 
Constant ":" _intconstant 
	 | _doubleconstant 
	 | _stringconstant 
	 | _booleanconstant
	 ;
%%
