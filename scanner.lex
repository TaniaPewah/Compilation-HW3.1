%{

#include <stdio.h>

#include "parser.hpp"
#include "parser.tab.hpp"
#include "output.hpp"

int yyerror(char const*);

%}

%option yylineno
%option noyywrap
whitespace		([\t\n ])
line_break		(\r\n|\r|\n)
id                      ([a-zA-Z][a-zA-Z0-9]*)
num                     (0|[1-9][0-9]*)
string                  (\"([^\n\r\"\\]|\\[rnt\"\\])+\")
comment                 (\/\/[^\r\n]*[\r|\n|\r\n]?)

%%

void                    { yylval =  new TypeNode(VOID_TYPE, yylineno); return VOID; }
int                     { yylval =  new TypeNode(INT_TYPE, yylineno); return INT; }
byte                    { yylval =  new TypeNode(BYTE_TYPE, yylineno); return BYTE; }
b                       { yylval =  new Node(yylineno); return B; }
bool                    { yylval =  new TypeNode(BOOL_TYPE, yylineno); return BOOL; }
and                     { yylval =  new BinopNode(yylineno, AND_OP); return AND; }
or                      { yylval =  new BinopNode(yylineno, OR_OP); return OR; }
not                     { yylval =  new BinopNode(yylineno, NOT_OP); return NOT; }
true                    { yylval =  new Node(yylineno); return TRUE; }
false                   { yylval =  new Node(yylineno); return FALSE; }
return                  { yylval =  new Node(yylineno); return RETURN; }
if                      { yylval =  new Node(yylineno); return IF; }
else                    { yylval =  new Node(yylineno); return ELSE; }
while                   { yylval =  new Node(yylineno); return WHILE; }
break                   { yylval =  new Node(yylineno); return BREAK; }
continue                { yylval =  new Node(yylineno); return CONTINUE; }
enum                    { yylval =  new Node(yylineno); return  ENUM; }
\;                      { yylval =  new Node(yylineno); return SC; }
\,                      { yylval =  new Node(yylineno); return COMMA; }
\(                      { yylval =  new Node(yylineno); return LPAREN; }
\)                      { yylval =  new Node(yylineno); return RPAREN; }
\{                      { yylval =  new Node(yylineno); return LBRACE; }
\}                      { yylval =  new Node(yylineno); return RBRACE; }
\=\=                    { yylval =  new RelopNode(yylineno); return EQUAL; }
\!\=                    { yylval =  new RelopNode(yylineno); return NOTEQUAL; }
\<                      { yylval =  new RelopNode(yylineno); return LESS; }
\>                      { yylval =  new RelopNode(yylineno); return GREATER; }
\<\=                    { yylval =  new RelopNode(yylineno); return LESSEQUAL; }
\>\=                    { yylval =  new RelopNode(yylineno); return GREATEREQUAL; }
\+                      { yylval =  new BinopNode(yylineno, ADD_OP); return ADD; }
\-                      { yylval =  new BinopNode(yylineno, SUB_OP); return SUB; }
\*                      { yylval =  new BinopNode(yylineno, MUL_OP); return MUL; }
\/                      { yylval =  new BinopNode(yylineno, DIV_OP); return DIV; }
\=                      { yylval =  new AssignNode(yylineno); return ASSIGN; }
{id}                    { yylval =  new IdNode(yytext, yylineno); return ID; }
{num}                   { yylval =  new NumNode(yytext, yylineno); return NUM; }
{string}                { yylval =  new StringNode(yytext, yylineno); return STRING; }
{line_break}            ;
{whitespace}            ;
{comment}               ;
.                       { output::errorLex(yylineno); exit(0); }

%%

int yyerror(char const* message)
{
    output::errorSyn(yylineno);
    exit(0);
}
