#include <stdio.h>
#include <math.h>
#define MAXSIZE 10
 
void main()
{
    float x[MAXSIZE];
    int  i, n;
    float average, variance, std_deviation, sum = 0, sum1 = 0;
 
    printf("Enter the value of N \n");
    scanf("%d", &n);
    printf("Enter %d real numbers \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    /*  Compute the sum of all elements */
    for (i = 0; i < n; i++)
    {
        sum = sum + x[i];
    }
    average = sum / (float)n;
    /*  Compute  variance  and standard deviation  */
    for (i = 0; i < n; i++)
    {
        sum1 = sum1 + pow((x[i] - average), 2);
    }
    variance = sum1 / (float)n;
    std_deviation = sqrt(variance);
    printf("Average of all elements = %.2f\n", average);
    printf("variance of all elements = %.2f\n", variance);
    printf("Standard deviation = %.2f\n", std_deviation);
}




/*

int num;
printf("Enter a positive integer: ");
scanf("%d", &num);
for(int i = 0; i<num; i++)
{
    //printf("%d\n", i*2);
    printf("%d\n", i*10+5);
    printf("%d\n", (i*10+5)/10);
    //Returns 1 for 15 and 2 for 25
    //Does not show the remainder or float since both are integers.
}


int main()
{
    int i,j,l = 0;
    for (i=1;i<=100;i++)
    {
        for (j=1;j<=i;j++)
        {
            for (l=1;l<=i;l++)
            {
                if (pow(i,2)==pow(j,2)+pow(l,2))
                {
                    printf("Found Pythagorean triplet: (%d,%d,%d)\n",i,j,l);
                }   
            }
        }
    }
    return 0;
}
*/

/*
for i in range(101):
    for j in range(i):
        for l in range(i):
            if i**2==j**2+l**2:
                print("Found Pythagorean triplet: ({},{},{})".format(i,j,l))
*/

    /*
    int num, count, sum = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    for(count = 1; count <= num; ++count)
    {
        sum += count;
    }
    printf("Sum = %d", sum);
    return 0;
    
    
for i in range(101):
    for j in range(i):
        for l in range(i):
            if i**2==j**2+l**2:
                print("Found Pythagorean triplet: ({},{},{})".format(i,j,l))
    */
