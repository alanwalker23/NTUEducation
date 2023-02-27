#include <stdio.h>

int factorial(int num);
int sum(int num);

int main()
{
    int num;
    printf("Enter a number: \n");
    scanf("%d", &num);
    printf("The factorial of %d! is %d\n", num, factorial(num));
    printf("The sum of all numbers up to %d is %d\n", num, sum(num));
}

int factorial(int num)
{
    if (num != 0)
    {
        return (num * factorial(num - 1));
    }
    else
        return (1);
}

int sum(int num)
{
    if ((num == 1) || (num == 0))
        return 1;
    else
        return (num + sum(num - 1));
}