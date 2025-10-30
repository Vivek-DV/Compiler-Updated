#include<stdio.h>
int j=0;
char input[20];

int E();
int E1();
int T();
int T1();
int F();

int main()
{
  printf("Enter input string:\n");
  scanf("%s",input);
  
  if(E()==1&&input[j]=='\0')
  {
    printf("String accepted\n");
  }
  else
  {
    printf("Rejected \t error at %c\n",input[j]);
  }
  return 0;
}

int E()
{
  if(T()==1)
  {
    if(E1()==1)
    {
      printf("Expanding E->TE1\n");
      return 1;
    }
    else 
      return 0;
  }
  else
    return 0;
}

int E1()
{
  if(input[j]=='+')
  {
    printf("Consuming +\n");
    j++;
    
    if(T()==1)
    {
      if(E1()==1)
      {
        printf("Expanding E1->+TE1\n");
        return 1;
      }
      else 
        return 0;
    }
    else 
      return 0;
  }
  else
  {
    printf("Expanding E1->e\n");
    return 1;
  }
}

int T()
{
  if(F()==1)
  {
    if(T1()==1)
    {
      printf("Expanding T->FT1\n");
      return 1;
    }
    else
      return 0;
  }
  else 
    return 0;
}

int T1()
{
  if(input[j]=='*')
  {
    printf("Consuming *\n");
    j++;
    if(F()==1)
    {
      if(T1()==1)
      {
        printf("Expanding T1->*FT1\n");
        return 1;
      }
      else 
        return 0;
    }
    else  
      return 0;
  }
  else
  {
    printf("Expanding T1->e\n");
    return 1;
  }
}

int F()
{
  if(input[j]=='(')
  {
    printf("Expanding F->(E)\n");
    printf("Consuming (\n");
    j++;
    if(E()==1)
    {
      if(input[j]==')')
      {
        printf("Consuming )\n");
        j++;
        return 1;
      }
      else 
        return 0;
    }
    else 
      return 0;
  }
  else if(input[j]=='i')
  {
    printf("Consuming id\n");
    j++;
    printf("Expanding F->id\n");
    return 1;
  }
  else
    return 0;
}

