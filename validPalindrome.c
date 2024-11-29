#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char top = -1;

void push(int value)
{
  top++;
  stack[top] = value;
}

char pop()
{
  char value = stack[top];
  top--;
  return value;
}

bool isPalindrome(char * s)
{
  int length = strlen(s);
  char string[MAX];
  int j = 0;
  for(int i = 0; i < length; i++)
  {
   if(*s == ' ' || *s == ':' || *s == ',')
   {
     push(*s);
   }
  else
   {
     char popped = pop();
     if (isupper(popped))
     {
       char str = tolower(popped);
       string[j] = str;
     }
     else
     {
       string[j] = popped;
     }
     j++;
   }
  }
  string[length] = '\0';
  for(int i =0; i < length/2; i++)
  {
    if(string[i] != string[length - i -1])
    {
      return false;
    }
  }
return true;
}

int main(void)
{
  char string[MAX];
  printf("Enter the string:");
  scanf("%[^\n]%*c", string);
  printf("%s", string);
  bool blah = isPalindrome(string);
  if(blah)
  {
  printf("TRUE");
  }
  else
  {
  printf("FALSE");  
  }
  return 0;
}
