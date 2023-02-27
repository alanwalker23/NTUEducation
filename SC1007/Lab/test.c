#include <stdio.h>

int main(void)
{
    int row = 5;
    int column;
    while (row >= 1)
    {
        column = row;
        while (column > 0)
        {
            printf("%s", "<");
            --column;
        }
        printf("\n");
        --row;
    }
}