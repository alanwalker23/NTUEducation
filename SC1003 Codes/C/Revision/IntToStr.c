#include <stdio.h>
#include <string.h>
int main()
{
    char result[50];
    int num = 23;
    sprintf(result, "%d", num);
    printf("\n The string for the num is %s",result);
}