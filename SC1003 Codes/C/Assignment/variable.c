#include <stdio.h>
#include <string.h>
int compareStr(char *str1, char *str2);
int main()
{
    char *str1 = "this is stricmp";
    char *str2 = "ThIs Is StRiCmP";
    int check = compareStr(str1,str2);
    printf("%d",check);
}

int compareStr(char *str1, char *str2)
{
    int i, j = 0;
    i = strlen(str1);
    j = strlen(str2);
    if (i == j)
    {
        for (i = 0; str1[i] != '\0'; i++)
        {
            if (str1[i] - str2[i] == 32 || str1[i] - str2[i] == -32 || str1[i] - str2[i] == 0)
                continue;
            else
            {
                return -1;
            }
        }
        return 0;
    }
    return -1;
}