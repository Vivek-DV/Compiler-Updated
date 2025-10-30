%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define YYSTYPE douoble
%}
%token NUMBER
%left '+''-'
%left '*''/'
%right UMINUS
%%
L:L'\n' {printf("Resullt: %lf\n"); exit(0);}
;
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|'-'E %prec UMINUS {$$=$2;}
|'('E')' {$$=$2;}
|NUMBER {$$=$1;}
;
%%
void main()
{
	printf("Enter the expression\n");
	yyparse();
}
yylex()
{
	char ch;
	ch=getchar();
	if(isdigit(ch))
	{
		ungetc(ch,stdin);
		scanf("%lf",&yylval);
		return NUMBER;
	}
	else
		return ch;
}
yyerror()
{
	printf("Invalid expression:\n");
	exit(0);
}
