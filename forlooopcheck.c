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
  FILE *fp;
  char ch,lexeme[100][50],check[50];
  fp=fopen(argv[1],"r");
  int i=0,j=0,flag=0;
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
      int c=0,j=k+1;
      if(strcmp("(",lexeme[k+1])!=0)
      {
        flag=1;
        break;
      }
      j++;
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
    printf("Syntax correct\n");
  }
  else
  {
    printf("Syntax incorrect\n");
  }
  fclose(fp);
  return 0;
}
