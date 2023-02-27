#include <stdio.h>
void swapMinMax1D(int ar[], int size);
int main()
{
    int ar[50], i, size;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i = 0; i < size; i++)
        scanf("%d", ar + i);
    swapMinMax1D(ar, size);
    printf("swapMinMax1D(): ");
    for (i = 0; i < size; i++)
        printf("%d ", *(ar + i));
    return 0;
}
void swapMinMax1D(int ar[], int size)
{
    /* Write your code here */
    int max = ar[0];
    int min = ar[0];
    int minp,maxp;
    for (int i = 0; i < size; i++)
    {
        if (ar[i] >= max)
        {
            max = ar[i];
            maxp = i;
        }

        if (ar[i] <= min)
        {
            min = ar[i];
            minp = i;
        }
    }
    ar[minp]=max;
    ar[maxp]=min;
}