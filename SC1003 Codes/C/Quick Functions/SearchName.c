#include <stdio.h>
#include <string.h>

int FindName(char ar[4][10],char *tar);
void FindNamev2(char ar[4][10]);
int main()   
{
   char array[4][10] = {"Potato","Boi","Gurl","Dota"};
   printf("1st element: %s\n",array[0]);
   char *target = "Dota";
   FindNamev2(array);
}

int FindName(char ar[4][10],char *tar)
{
    int i,found=0;
    for (i=0;i<=4;i++)
    {
        //printf("Element: %s\n",ar[i]);
        if (strcmp(tar,ar[i])==0)
       {
           found = i;
           break;
       } 
    }
    if (found != 0) 
        return found;
    else 
    {
        printf("User not found\n");   
        return -1;
    } 
}

void FindNamev2(char ar[4][10])
{
    char target[10], *p;
    printf("Enter search name: ");
    fgets(target, 10, stdin);   
      if (p=strchr(target,'\n')) *p = '\0';
    printf("Search for %s",target);
}

//Converts the string to small letters
void formatName(char *str)
{
   while (*str != '\0')
   {
      *str = tolower(*str);
      str++;
   }
}

/*
Additional stuff
Another form of array declar
//char *array = {"Potato","Boi","Gurl","Dota"}; 
//printf("Number of elements: %d\n",strlen(array));
//printf("Position of %s: %d\n",target,FindName(array,target));
//printf("Position of %s: %d\n",target,FindNamev2(array));

*/