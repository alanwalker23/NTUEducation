#include <stdio.h>
#include <string.h>

int main()
{
    //String builder
    char *string1 = "potato";
    //Create a string in array notation using sizeof other string
    //This allows for string builder.
    char string2[sizeof(string1)];
    for (int i=0;i<strlen(string1);i++)
    {
        string2[i]='a';
    }
    printf("%s",string1);
    printf("%s",string2);
    if (string1)
    {
        printf("STRING 1 WORKS");
    }
    string1 = "dope";
    printf("%s",string1);
    printf("%c",string1[0]);
    printf("STRING 1 WORKS");
}