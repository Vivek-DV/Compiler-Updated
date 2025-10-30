#include<stdio.h>
int main(int argc,char *argv[])
{
  if(argc!=2)
  {
    printf("Enter the file name\n");
  }
  char ch,c,stack[40];
  int top=-1,line=0,flag=0;
  
  FILE *fp=fopen(argv[1],"r");
  if(fp==NULL)
  {
    printf("Error opening file\n");
  }
  while((ch=fgetc(fp))!=EOF)
  {
    switch(ch)
    {
      case '\n':
        line++;
        break;
        
      case '(':
      case '{':
      case '[':
        stack[++top]=ch;
        break;
        
      case ')':
        if(top==-1)
        {
          printf("Open parenthesis missing at line %d\n",line);
        }
        else
        {
          c=stack[top--];
          if(c=='(');
          else
          {
            printf("Parenthesis mismatch fount at line %d. \n",line);
            flag=1;
          }
        }
        break;
        
      case'}':
        if(top==-1)
        {
          printf("Open parenthesis missing found at line %d\n",line);
        }
        else
        {
          c=stack[top--];
          if(c=='{');
          else
          {
            printf("Parenthesis mismatch found at line %d\n",line);
            flag=1;
          }
        }
        break;
        
      case ']':
        if(top==-1)
        {
          printf("Open parenthesis missing found at line %d\n",line);
        }
        else
        {
          c=stack[top--];
          if(c=='[');
          else
          {
          
            printf("Parenthesis mismatch found at line %d\n",line);
            flag=1;
        }
        break;
        defualt:
          break;
    }
  }
}
  if(top!=-1)
  {
    printf("Closing parenthesis missing at line %d\n",line);
  }
  if(!flag)
    printf("Syntax matched\n");
}
