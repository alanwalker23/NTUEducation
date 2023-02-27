#include <stdio.h>
#define SIZE 3
int main()
{

    /*
    //Create a 2-dimensional array with 2 array of 3 arrays [2 row 3 col]
    //Explore if calling index [3] returns the 4th element (2nd row 1st col)
    int array[2][3] = {{1,3,5},{2,4,6}};
    printf("The value of array is %d\n",array);
    for (int i=0;i<2;i++)
    {
        //If we try to call array[row] without the [col], undefined behaviour
        //printf("The value of index [%d] in array is %d\n",i,array[0][i]);
        //printf("The value of index [%d] in array is %d\n\n",i+3,array[1][i]);
        printf("The value of (array+%d) is %d\n",i,array+i);
        printf("The value of *(array+%d) is %d\n",i,*(array+i));
        printf("The value of array[%d] is %d\n",i,array[i]);
        printf("The value of *array[%d] is %d\n",i,*array[i]);
        printf("The value of (array[%d]+1) is %d\n",i,array[i]+1);
        printf("The value of *(array[%d]+1) is %d\n\n",i,*(array[i]+1));
        //To call an element with a 2d array, use array[m][n] == *( *(array+m) +n)
    }

    //Traverse the whole array regardless of row and col
    int *ptr = *array;
    for (int j=0;j<6;j++)
    {
        printf("%d\t",*ptr++);
    }
    */
    /*
    //Create an array and use pointers to populate and later find max value
    int array[SIZE];
    int *arr_ptr;
    // = array;
    arr_ptr = array;
    int max = 0;
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter number %d:\n",i+1);
        scanf("%d",arr_ptr++);
    }
    arr_ptr = array;
    printf("2rd number entered was %d\n",array[1]);
    for (int j=0;j<SIZE;j++)
    {
        printf("Element %d is %d\n",j+1,*(array+j));
        if (*(array+j)>max)
            max = *(array+j);
    }
    printf("Highest element entered is %d\n",max);
    */


    /*
    //Using Pointer constants to traverse a list
    int array[3] = {1,2,3};
    int i = 0;
    printf("Value of element at index 1 - %d\n",&array[0]);
    printf("Value of element at index 1 - %d\n",array+0);
    printf("Value of element at index 1 - %d\n",array[i]); //Can also write as array[0]
    printf("Value of element at index 1 - %d\n",*(array+i));
    //Explicit usage of pointer
    int *arr_ptr;
    arr_ptr = array; //arr_ptr points to array which is technically address of array[0]
    //Hence value of arr_ptr is array[0]
    printf("Address of array pointer %d\n",arr_ptr);
    printf("Value of array pointer %d\n",*arr_ptr);
    arr_ptr = &array[1];
    printf("Address of array pointer %d\n",arr_ptr);
    printf("Value of array pointer %d\n",*arr_ptr);
    arr_ptr +=1;
    printf("Address of array pointer %d\n",arr_ptr);
    printf("Value of array pointer %d\n",*arr_ptr);
    arr_ptr--;
    printf("Address of array pointer %d\n",arr_ptr);
    printf("Value of array pointer %d\n",*arr_ptr);
    */
    /*
    //Understanding size of elements vs array
    //Understanding addressing used in arrays
    int number = 30;
    int array[3] = {1,2,number}; //Array is a pointer constant.
    printf("Size of number is %d\n",sizeof(number));
    printf("Size of array is %d\n",sizeof(array)); //Basically each int takes up 4 byte, 3 elements of int = 3x4bytes=12bytes
    printf("Address of array - %d\n",&array);
    printf("Address of array[0] - %d\n",&array[0]);
    printf("Address of array[1] - %d\n",&array[1]);
    printf("Address of array[2] - %d\n",&array[2]);
    printf("Value of array by itself is %d which is address of array\n",array);
    printf("Value of array[2] is %d and number is %d\n",array[2],number);
    printf("Address of number - %d\n",&number); 
    //Note that even thought array[2] and number have the same value, they have diff address since call by value not reference
    */

    /*
    //Exploring arrays and their additional features
    int number1 = 20;
    int number2;
    int array[3] = {1,number1,number2};
    number2 = 30;
    //array[2] = number2; [To fix the value and change array[1] --> 30 instead of 16]
    int num = 60;
    int potato = 50;
    //Will print 1 due to index
    printf("Value of element at index 0 - %d\n",array[0]); 
    //Prints 20 as number1 was defined before and the pointer of index is at the number1 which has a value
    printf("Value of element at index 1 - %d\n",array[1]); 
    //Prints 16 or any random int value as number 2 has no value when the array was initialized
    printf("Value of element at index 2 - %d\n",array[2]); 
    //Prints 40 or any random int value as it is an element out of the array. For some reason it prints the last defined variable (in system)
    printf("Value of element at index 3 - %d\n",array[3]);
    */
}