#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* //Attempt to bubble sort
Compare 2 elements, if 0>1, swap index
Need to iterate multiple times until no changes [change variable = 0]
*/
int main()
{
    int array[] = {1,2,3,4,5};
    for (int i=0;i<=5;i++)
    {
        printf("Element %d: %d\n",i,array[i]);
    }
}