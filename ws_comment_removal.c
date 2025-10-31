#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
  if(argc!=3)
  {
    printf("Error expected 2 arguments\n");
    exit(1);
  }
  FILE *fp1=fopen(argv[1],"r");
  FILE *fp2=fopen(argv[2],"w");
  
  if(fp1==NULL||fp2==NULL)
  {
    printf("Error opening file\n");
    exit(1);
  }
  
  char ch,ch1,c1,c2,x;
  
  while((ch=fgetc(fp1)!=EOF))
  {
    if(ch=='\n'||ch=='\t'||ch==' ')
    {
      continue;
    }
    else if(ch=='/')
    {
      ch1=fgetc(fp1);
      if(ch1=='/')
      {
        while(x=fgetc(fp1)!='\n');
      }
      else if(ch1=='*')
      {
        while((c1=fgetc(fp1))!=EOF)
        {
          if(c1=='*')
          {
            c2=fgetc(fp1);
            if(c2=='/')
              break;
            else 
              ungetc(c2,fp1);
          }
        }
      }
      else
      {
        fputc(ch,fp2);
        ungetc(ch1,fp1);
      }
    }
    else
    {
      fputc(ch,fp2);
    }
  }
  fclose(fp1);
  fclose(fp2); 
}
