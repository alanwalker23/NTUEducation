#include <stdio.h>
#include <string.h>

void compareStr(char *str1, char *str2)
{
    int i, j = 0;
    i = strlen(str1);
    j = strlen(str2);
    if (i == j)
    {
        for (i = 0; str1[i] != '\0'; i++)
        {
            //Caps vs Nocaps is 32 away [Can also use stricmp to compare non-case sensitive]
            if (str1[i] - str2[i] == 32 || str1[i] - str2[i] == -32 || str1[i] - str2[i] == 0)
                continue;
            else
            {
                printf("The two strings are different.\n");
                return;
                //return -1;
            }
        }
        printf("The two strings are the same.");
        return;
        //return 0;
    }
    printf("The two strings are different.\n");
    //return -1;
}

int main()
{
    char *p;
    char string1[20];
    char string2[20];
    printf("Enter 1st string: ");
    fgets(string1, 20, stdin);
    if (p = strchr(string1, '\n'))
        *p = '\0';
    printf("Enter 2nd string: ");
    fgets(string2, 20, stdin);
    if (p = strchr(string2, '\n'))
        *p = '\0';
    compareStr(string1,string2);
}