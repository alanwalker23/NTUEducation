#include <stdio.h>

int calculate(int *array, int size); //Changes the 1st row into an array pointer
void mixmax(int *array,int size); //Calculate all element fast
int main()
{
    //Create a 2-d matrix with size entered based on user input
    //Find max of each row and compute min of calculated max (min of max)
    int row, col;
    
    printf("Enter row size:\n");
    scanf("%d", &row);
    printf("Enter col size:\n");
    scanf("%d", &col);
    int matrix[row][col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            printf("Enter [%d][%d] value: ", i, j);
            scanf("%d", &matrix[i][j]);
            //printf("Value of %d entered into [%d][%d]\n", matrix[i][j], i, j);
        }
    int rowValues[row];
    for (int i=0;i<row;i++)
        rowValues[i]=calculate(matrix[i],col);
    int min = rowValues[0];
    for (int j=0;j<row;j++)
    {
        printf("%d\n",rowValues[j]);
        if (min>rowValues[j])
            min = rowValues[j];
    }
    printf("The min value of the maxes is %d",min);
}

int calculate(int *array, int size)
{
    int rMax, cMin;
    rMax = 0;
    for (int i=0;i<size;i++)
    {
        int num = *array;
        if((num)>rMax)
            rMax = num;
        *array++;
    }
    //printf("Row max value is %d\n",rMax);
    return rMax;
}

void mixmax(int *array,int size)
{
    for (int i=0;i<size;i++)
        printf("Value of element %d is %d\n",i,*array++);
}