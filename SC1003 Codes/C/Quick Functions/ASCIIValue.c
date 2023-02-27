#include <stdio.h>

int main()
{
    char c;
    printf("Enter character: ");
    scanf("%c",&c);
    int ascii = (int) c;
    printf("The ASCII value of %c is %d",c,ascii);
}