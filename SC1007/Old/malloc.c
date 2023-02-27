#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    double *item;
    char *string;
    item = (double *)malloc(10 * sizeof(double));
    string = (char *)malloc(10 * sizeof(char));
    for (i = 0; i < 10; i++)
    {
        scanf("%lf", &item[i]);
    }
    scanf("%*c");
    i = 0;
    char *stringP = string;
    while (i++ < 9)
        scanf("%c", stringP++);
    *stringP = '\0';
    printf("%s\n", string);
    double *itemP = item;
    for (i = 0; i < 10; i++, itemP++)
        printf("%.2lf ", *itemP);
    printf("\n");
    free(item);
    free(string);
    return 0;
}
