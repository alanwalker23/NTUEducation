#include <stdio.h>
#include <string.h>
#define INIT_VALUE -1000
int palindrome(char *str);
int main()
{
   char str[80], *p;
   int result = INIT_VALUE;

   printf("Enter a string: \n");
   fgets(str, 80, stdin);
   if (p = strchr(str, '\n'))
      *p = '\0';
   result = palindrome(str);
   if (result == 1)
      printf("palindrome(): A palindrome\n");
   else if (result == 0)
      printf("palindrome(): Not a palindrome\n");
   else
      printf("An error\n");
   return 0;
}
int palindrome(char *str)
{
   /* Write your code here */
   int check = strlen(str) / 2;
   int count = 0;
   int end = strlen(str);
   for (int i = 0; i < check; i++)
   {
      //printf("First char %c\n",str[i]);
      //printf("Last char %c\n",str[end-i-1]);
      if (str[i] == str[end - i - 1])
      {
         count++;
      }
   }
   if (count == check)
   {
      return 1;
   }
   else
      return 0;
}