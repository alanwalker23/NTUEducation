#include <stdio.h>
void printReverse1(int ar[], int size);
void printReverse2(int ar[], int size);
void reverseAr1D(int ar[], int size);
int main()
{
   int ar[80];
   int size, i;
       
   printf("Enter array size: \n");
   scanf("%d", &size);
   printf("Enter %d data: \n", size);
   for (i=0; i <= size-1; i++)
      scanf("%d", &ar[i]);
   printReverse1(ar, size);    
   printReverse2(ar, size);
   reverseAr1D(ar, size);
   printf("reverseAr1D(): ");
   if (size > 0) {
      for (i=0; i<size; i++)
         printf("%d ", ar[i]);
   }
   return 0;
}    
void printReverse1(int ar[], int size)  
{
    /* Write your code here – using index */
    printf("printReverse1(): ");
    for (int i=1;i<size+1;i++)
    {
        printf("%d ",ar[size-i]);
    }
    printf("\n");
}
void printReverse2(int ar[], int size)
{
/* Write your code here – using pointer */
    printf("printReverse2(): ");
    int *ar_ptr= ar;
    for (int i=1;i<size+1;i++)
    {
        printf("%d ",ar_ptr[size-i]);
    }
    printf("\n");
}
void reverseAr1D(int ar[ ], int size)
{
      /* Write your code here */
      int temp[size];
      for (int i=1;i<size+1;i++)
      {
          temp[i-1]= ar[size-i];
          //printf("%d",ar[i-1]);
          //printf("%d",temp[i]);
      }
      for (int i=0;i<size;i++)
      {
          ar[i]=temp[i];
      }
}