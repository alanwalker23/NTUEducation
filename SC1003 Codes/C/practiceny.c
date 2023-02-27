#include <stdio.h>

int main()
{
    int index, max, numArray[5];
    int *ptr;
    ptr = numArray;
    printf("%d\n", ptr);
    printf("Enter 3 numbers: \n");
    for (index = 0; index < 3; index++)
        scanf("%d", ptr++);
    // Find maximum from array data

    //Notice that current iteration of ptr is at ptr=3
    //The value ptr=3 corresponds to the address of element 3 of numArray
    printf("%d\n", ptr);
    printf("%d\n", &numArray[3]);
    ptr = numArray;
    printf("%d\n", ptr);
    max = *ptr;
    for (index = 0; index < 3; index++)
    {
        if (*ptr > max)
            max = *ptr;
        ptr++;
    }
    printf("max is %d.\n", max);
    return 0;
}