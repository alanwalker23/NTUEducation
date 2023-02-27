#include <stdio.h>

int findPartiion(int arr[], int n)
{
    int sum = 0;
    int i, j;

    // Calculate sum of all elements
    for (i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return 0;

    //bool part[sum / 2 + 1][n + 1];

    // initialize top row as true
    for (i = 0; i <= n; i++)
        part[0][i] = 1;

    // initialize leftmost column, except part[0][0], as 0
    for (i = 1; i <= sum / 2; i++)
        part[i][0] = 0;

    // Fill the partition table in bottom up manner
    for (i = 1; i <= sum / 2; i++)
    {
        for (j = 1; j <= n; j++)
        {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j] || part[i - arr[j - 1]][j - 1];
        }
    }
    return part[sum / 2][n];
}

// Driver code
int main()
{
    int arr[] = {3, 1, 1, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    printf("%d\n",findPartiion(arr, n));
    getchar();
    return 0;
}
