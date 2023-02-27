#include <stdio.h>
#include <stdlib.h>

int findTallest(int *ptr, int size, int tallest);
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
    // Print the elements of the array
    int other = 0;
    int count = 1;
    int tallest = ptr[n - count];
    while (count!=n)
    {
        other = findTallest(ptr,n,tallest);
        count++;
        if (other==tallest)
            break;
        tallest = ptr[n - count];
    }
    // for (i = 0; i < n; ++i)
    // {
    //     if (other != tallest)
    //         other += ptr[i];
    // }

    //Ending portion
    if (other == tallest)
        printf("%d\n", other);
    else
        printf("0");
    return 0;
}

int findTallest(int *ptr, int size, int tallest)
{
    int sum = 0;
    //printf("The elements of the array are: ");
    for (int i = 0; i < size; ++i)
    {
        sum += ptr[i];
        if (sum==tallest)
        {
            //printf("Tallest possible is %d\n",tallest);
            return tallest;
        }
        printf("%d, ", ptr[i]);
    }
    return 0;
}
