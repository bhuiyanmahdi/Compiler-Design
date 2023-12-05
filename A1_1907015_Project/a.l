%{
    #include "a.tab.h"
    
%}

digit [0-9]
letter [a-zA-Z_]
id {letter}({letter}|{digit})*
number ({digit})+
ws [ \t\n]
delim ({ws})*
gap [ \t\n]*


headerfile {gap}[#]contain[<][a-z]+[.][h][>]['\n']
intmain {gap}int{gap}main\(\){gap}[{]['\n']
single_comment {gap}[*][*].*['\n']




%%

{delim} {}

{headerfile} {return HEADERFILE;}
{intmain} {return MAINSTART;}
{single_comment} {return SINGLE_LINE_COMMENT;}

"int" {return INT;}
"float" {return FLOAT;}
"if" {return IF;}
"else" {return ELSE;}
"show" {return SHOW;}
"loop" {return LOOP;}
"func" {return FUNC;}
"return" {return RETURN;}
"prime" {return PRIME;}
"factorial" {return FACTORIAL;}
"sin" {return SIN;}
"cos" {return COS;}
"tan" {return TAN;}
"input" {return INPUT;}
"=" {return '=';}
"(" {return '(';}
")" {return ')';}
"{" {return '{';}
"}" {return '}';}
"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
";" {return ';';}
"," {return ',';}
"#" {return '#';}
"." {return DOT;}
"<=" {return '<=';}
">=" {return '>=';}
"<" {return '<';}
">" {return '>';}

"##" {return HASH_HASH;}
{id} { yylval.stringValue = strdup(yytext); return ID;}
{number} {yylval.intValue = atoi(yytext); return NUM;}
[0-9]+\.[0-9]+ {yylval.floatValue = atof(yytext); return FLOAT;}


%%
int yywrap()
{
    return 1;
}