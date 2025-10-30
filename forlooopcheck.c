#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc,char *argv[])
{
  if(argc!=2)
  {
    printf("Enter the filename\n");
    return 1;
  }
  FILE *fp=fopen(argv[1],"r");
  char ch,lexeme[100][50],check[30];
  int i=0,j=0,flag=0;
  if(fp==NULL)
    printf("Error opening file\n");
    
   while((ch=fgetc(fp))!=EOF)
   {
    if(isalnum(ch))
    {
      while(isalnum(ch))
      {
        lexeme[i][j++]=ch;
        ch=fgetc(fp);
      }
      lexeme[i][j]='\0';
      i++;
      j=0;
      ungetc(ch,fp);
    }
    else
    {
      lexeme[i][j++]=ch;
      lexeme[i][j]='\0';
      i++;
      j=0;
    }
   }
   
   printf("Lexemes:\n");
   for(int k=0;k<i;k++)
   {
      printf("%s\n",lexeme[k]);
   }
   for(int k=0;k<i;k++)
   {
    if(strcmp("for",lexeme[k])==0)
    {
      int c=0,j=k;
      strcpy(check,lexeme[j++]);
      while(strcmp(check,")")!=0)
      {
        if(strcmp(check,";")==0)
        {
          c++;
        }
        strcpy(check,lexeme[j++]);
      }
      if(c!=2)
      {
        flag=1;
      }
    }
   }
   if(flag==0)
   {
    printf("Syntax corrected\n");
   }
   else
    printf("Syntax incorrect\n");
}
