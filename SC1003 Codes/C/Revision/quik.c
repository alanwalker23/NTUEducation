#include <stdio.h>
#include <string.h>

int main()
{
    char string1[10] = "potato";
    char string2[10] = "program";
    char *string3;
    printf("String1 - %s,string2 - %s\n",string1,string2);
    string3 = strcpy(string1+strlen(string1)/2,string2);
    printf("String1 - %s,string2 - %s\n",string1,string2);
}