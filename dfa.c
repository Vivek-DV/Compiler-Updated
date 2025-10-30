#include<stdio.h>
#include<string.h>
int main()
{
  int n,inp_n,final[20],trans[20][20],f_n;
  char alpha[20],input[20];
  printf("Enter the number of states:\n");
  scanf("%d",&n);
  printf("Enter the number of input alphabets:\n");
  scanf("%d",&inp_n);
  printf("Enter the input alphabets:\n");
  scanf("%s",alpha);
  printf("Enter the transitions:\n");
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<inp_n;j++)
    {
      printf("From state %d on alphabet %c: ",i,alpha[j]);
      scanf("%d",&trans[i][j]);
    }
  }
  printf("Enter the number of final states:\n");
  scanf("%d",&f_n);
  for(int i=0;i<f_n;i++)
  {
    scanf("%d",&final[i]);
  }
  printf("Enter the input string('exit' for exit the loop)\n");
  scanf("%s",input);
  do{
    int i=0,current_state=0;
    while(input[i]!='\0')
    {
      int char_match=-1;
      for(int j=0;j<inp_n;j++)
      {
        if(alpha[j]==input[i])
        {
          char_match=j;
          break;
        }
      }
      if(char_match==-1)
      {
        printf("Invalid input alphabets\n");
        return 1;
      }
      else
      {
        current_state=trans[current_state][char_match];
        char_match=-1;
      }
      i++;
    }
    int accepted=-1;
    for(int j=0;j<f_n;j++)
    {
      if(final[i]==current_state)
      {
        printf("String accepted\n");
        accepted=1;
      }
    }
    if(accepted!=1)
      printf("String rejected\n");
    printf("Enter the input string('exit' for exit the loop)\n");
    scanf("%s",input);  
  }while(strcmp(input,"exit")!=0);
}

