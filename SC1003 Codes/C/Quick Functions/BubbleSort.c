#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5
/* //Attempt to bubble sort
Compare 2 elements, if 0>1, swap index
Need to iterate multiple times until no changes [change variable = 0]
*/
void swap(int *small,int *big);
int main()
{
    int array[] = {5,4,3,2,1};
    //int iteration = 0;
    //Print original order
    printf("Original Order: ");
    for (int i=0;i<MAX;i++) 
        printf("%d ",array[i]);
    printf("\n");
    
    for (int i=0;i<MAX-1;i++)
        for (int j=0;j<MAX-1-i;j++)
            if(array[j]>array[j+1])
            {
                swap(&array[j],&array[j+1]);
                //iteration++;
            }
    
    //Print new order
    printf("New Order: ");
    for (int i=0;i<MAX;i++) 
        printf("%d ",array[i]);
    printf("\n");
    //printf("Iterations: %d",iteration);
}
void swap(int *small,int *big)
{
    int temp = *small;
    *small = *big;
    *big = temp;
}