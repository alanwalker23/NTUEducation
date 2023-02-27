#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int bottom_up_dp(int n, int *s, int *v, int C)
{
    int i, w;
    int K[n + 1][C + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= C; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (s[i-1] <= w)
                K[i][w] = max(K[i - 1][w], K[i - 1][w - s[i - 1]] + v[i]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<C;j++)
        {
            printf("%d ",K[i][j]);
        }
        putchar('\n');
    }
    return K[n][C];
}

int main()
{
    int n, C;
    int function;
    int *s;
    int *v;
    int i, j;
    printf("Enter the number of items n:\n");
    scanf("%d", &n);
    printf("Enter the capacity C:\n");
    scanf("%d", &C);
    s = (int *)malloc(sizeof(int) * (n + 1));
    v = (int *)malloc(sizeof(int) * (n + 1));

    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &s[i]);

    printf("Enter the values of items (as a list, separate by spacing:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    printf("The maximum value is: %d \n", bottom_up_dp(n, s, v, C));
}