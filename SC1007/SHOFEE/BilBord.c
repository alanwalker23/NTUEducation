#include <stdio.h>
#include <stdlib.h>

int findTallest(int *ptr, int size);
int main()
{
    int *ptr;
    int n, i;

    // printf("Enter number of elements:");
    scanf("%d", &n);
    // printf("Entered number of elements: %d\n", n);

    // Dynamically allocate memory using malloc()
    ptr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; ++i)
    {
        int size = 0;
        scanf("%d", &size);
        ptr[i] = size;
    }
    int check = 0;

    // Sort all elements within array
    for (int i = 0; i < n; ++i)
    {

        for (int j = i + 1; j < n; ++j)
        {

            if (ptr[i] > ptr[j])
            {

                check = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = check;
            }
        }
    }

    int output = findTallest(ptr,n);
    //Ending portion
    return 0;
}

int findTallest(int *ptr, int size)
{
    int sum = 0;
    //printf("The elements of the array are: ");
    for (int i = 0; i < size; ++i)
    {
        sum += ptr[i];
        printf("%d ", ptr[i]);
    }
    putchar('\n');
    printf("Total is %d\n",sum);
    if (sum%2==0)
    {
        int target = sum/2;
        int list1 = 0;
    }
    return 0;
}
