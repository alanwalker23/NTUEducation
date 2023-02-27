#include <stdio.h>
#include <string.h>

int main()
{
    char vowels[5] = "aeiou";
    char *str = "pat";
    char string[5];
    strcpy(string,str);
    char *ret; 
    ret = strpbrk(string,vowels);
    if(ret)
        printf("TEst");
}