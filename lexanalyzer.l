%{
#include<stdio.h>
#include<stdlib.h>
int line=1,sl_no=1;
FILE *fp;
%}
DIGIT [0-9]
ALPHA [a-zA-Z]
WS [ \t]
%%
{WS} {}
"\n" {line++;}
";" {fprintf(fp,"%d\t%s\tSemicolon\t%d\n",sl_no,yytext,line); sl_no++;}
"+"|"-"|"*"|"/" {fprintf(fp,"%d\t%s\tArithmetic op\t%d\n",sl_no,yytext,line); sl_no++;}
"<"|">"|"<="|">="|"!"|"!=" {fprintf(fp,"%d\t%s\tRelational op\t%d\n",sl_no,yytext,line); sl_no++;}
"=" {fprintf(fp,"%d\t%s\tAssignment op\t%d\n",sl_no,yytext,line); sl_no++;}
"void"|"printf"|"scanf"|"main"|"for"|"while"|"int"|"float"|"double"|"include"|"do" {fprintf(fp,"%d\t%s\tKeywords\t%d\n",sl_no,yytext,line); sl_no++;}
{DIGIT}+"."{DIGIT}+ {fprintf(fp,"%d\t%s\tFloating point number\t%d\n",sl_no,yytext,line); sl_no++;}
{ALPHA}({ALPHA}|{DIGIT})* {fprintf(fp,"%d\t%s\tIdentifiers\t%d\n",sl_no,yytext,line); sl_no++;}
{DIGIT}+ {fprintf(fp,"%d\t%s\tNumber\t%d\n",sl_no,yytext,line); sl_no++;}
"("|"{"|"[" {fprintf(fp,"%d\t%s\tOpening bracket\t%d\n",sl_no,yytext,line); sl_no++;}
")"|"}"|"]" {fprintf(fp,"%d\t%s\tClosing bracket\t%d\n",sl_no,yytext,line); sl_no++;}
"#"|"," {fprintf(fp,"%d\t%s\tSpecial op\t%d\n",sl_no,yytext,line); sl_no++;}
. {fprintf(fp,"%d\t%s\tUnrecognized\t%d\n",sl_no,yytext,line); sl_no++;}
%%
void main(int argc,char *argv[])
{
	yyin=fopen(argv[1],"r");
	fp=fopen(argv[2],"w");
	yylex();
}
int yywrap()
{
	return 1;
}
