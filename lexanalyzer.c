#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(int argc,char *argv[])
{
  int line=1,slno=1;
  char lexeme[50],ch,ch1;
  FILE *fp1,*fp2;
  char keyword[30][10]={"void","int","main","printf","scanf","stdio","FILE","argc","argv","fprintf","while","for","float","char","if","else"};
  if(argc!=3){
    printf("Insufficient arguments\n");
    return 1;
  }
  fp1=fopen(argv[1],"r");
  fp2=fopen(argv[2],"w");
  if(fp1==NULL||fp2==NULL){
    printf("Error opening file\n");
    return 1;
  }
  fprintf(fp2,"Sl No\tLexeme\tToken\tLine No\n");
  while((ch=fgetc(fp1))!=EOF)
  {
    if(ch==' '||ch=='\t')
    {
      continue;
    }
    else if(ch=='\n')
    {
      line++;
    }
    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
    {
      fprintf(fp2,"%d\t%c\tArithmetic op\t%d\n",slno++,ch,line);
    }
    else if(ch=='('||ch=='{'||ch=='[')
    {
      fprintf(fp2,"%d\t%c\tOpening bracket\t%d\n",slno++,ch,line);
    }
    else if(ch==')'||ch=='}'||ch==']')
    {
      fprintf(fp2,"%d\t%c\tClosing bracket\t%d\n",slno++,ch,line);
    }
    else if(ch==','||ch=='$'||ch=='#'||ch=='.'||ch==':')
    {
      fprintf(fp2,"%d\t%c\tSpecial symbol\t%d\n",slno++,ch,line);
    }
    else if(ch=='=')
    {
      ch1=fgetc(fp1);
      if(ch=='=')
      {
        fprintf(fp2,"%d\t%c%c\tRelational op\t%d\n",slno++,ch,ch1,line);
      }
    }
    else if(ch==';')
    {
      fprintf(fp2,"%d\t%c\tSemi-colon\t%d\n",slno++,ch,line);
    }
    else if(ch=='<'||ch=='>'||ch=='!')
    {
      ch1=fgetc(fp1);
      if(ch=='=')
      {
        fprintf(fp2,"%d\t%c%c\tRelational op\t%d\n",slno++,ch,ch1,line);
      }
      else
      {
        fprintf(fp2,"%d\t%c\tRelational op\t%d\n",slno++,ch,line);
      }
    }
    else if(isdigit(ch))
    {
      int i=0,flag=0;
      lexeme[i++]=ch;
      do{
        ch1=fgetc(fp1);
        if(ch1=='.') flag=1;
        lexeme[i++]=ch1;
      }while(isdigit(ch1)||ch1=='.');
      lexeme[i-1]='\0';
      ungetc(ch1,fp1);
      
      if(flag==1)
        fprintf(fp2,"%d\t%s\tFloating point\t%d\n",slno++,lexeme,line);
        
      else 
        fprintf(fp2,"%d\t%s\tNumber\t%d\n",slno++,lexeme,line);
    }
    
    else if(isalpha(ch))
    {
      int i=0,flag=0;
      lexeme[i++]=ch;
      do{
        ch1=fgetc(fp1);
        if(isalpha(ch1)||isdigit(ch1))
        {
          lexeme[i++]=ch1;
        }
        else
          break;
      }while(1);
      lexeme[i]='\0';
      ungetc(ch1,fp1);
      
      for(int a=0;a<16;a++)
      {
        if(strcmp(lexeme,keyword[a])==0)
        {
          flag=1;
          break;
        }
      }
      if(flag==1)
        fprintf(fp2,"%d\t%s\tKeyword\t%d\n",slno++,lexeme,line);
        
      else
        fprintf(fp2,"%d\t%s\tIdentifier\t%d\n",slno++,lexeme,line);
    }
    else
    {
      fprintf(fp2,"%d\t%c\tUnrecognized\t%d\n",slno++,ch,line);
    }
  }
  fclose(fp1);
  fclose(fp2);
  printf("Lexical analysis completed\nTokens written to file %s\n",argv[2]);
}
