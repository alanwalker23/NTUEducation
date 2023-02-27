#include <stdio.h>
#include <string.h>
#include <ctype.h>
void reverse(char *s);
int main()
{
    char line[132], *p;
    fgets(line, 132, stdin);
    if ( p=strchr(line,'\n') ) *p = '\0';
    while (strcmp(line, "exit") !=0) 
    {
        reverse(line);
        printf("%s\n", line);
        fgets(line, 132, stdin);
        if ( p=strchr(line,'\n') ) *p = '\0';
    }
}
//Change original string to be reversed
void reverse(char *s)
{
    int len=strlen(s),count=0;
    char newStr[len];
    for (int i=len-1;i>=0;i--) //len-1 to remove the null char '\0'
    {
        newStr[count]=s[i];
        //printf("Element: %c\n",s[i]);
        count++;
    }
    //printf("newStr: %s\n",newStr);
    newStr[count]='\0';
    strcpy(s,newStr);
}


//Prints a reversed string but original string not affected
/*
void reverse(char *s)
{
    int len=strlen(s);
    for (int i=len;i>=0;i--)
    {
        printf("%c",s[i]);
    }
    printf("\n");
}
*/