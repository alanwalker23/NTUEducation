#include <string.h>
#include <stdio.h>

char *searched(char *string, char ch);
int main()
{
    char string[20];
    char ch;
    char *p;
    printf("Enter a string:\n");
    fgets(string, sizeof(string), stdin);
    if (p = strchr(string, '\n'))
        *p = '\0';
    printf("Enter a search char:\n");
    scanf("%c", &ch);
    printf("Result: %s",searched(string,ch));
}

char *searched(char *string, char ch)
{
    int count = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ch)
        {
            count++;
        }
    }
    if (count == 0)
        return "Null";

    char *result;
    printf("Instances %d\n",count);
    for (int j = 0; j < count; j++)
    {
        printf("%d\n",j);
        result[j] = ch;
    }
    return result;
}