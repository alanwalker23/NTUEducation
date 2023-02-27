#include <stdio.h>
#include <math.h>
#define CONSTANT_NAME "potato"
#define CONSTANT_VALUE 15

int main()
{
    printf("%s\n", CONSTANT_NAME);
    printf("%d\n", CONSTANT_VALUE);
    const char name[] = "kiwi";
    const float fixnumber = 25;
    printf("%s\n", name);
    printf("%f\n", fixnumber);
    printf("%.2f\n", fixnumber);
    //Both will return error due to nature of constant
    //name[1] = "potato";
    //number = 35;

    /* 
    //incremental operators ++/--
    //If used before, effect take place then run, else increase after run
    int value = 10;
    printf("%d\n",value); //Returns 10
    printf("%d\n",++value); //Returns 11
    printf("%d\n",value++); //Returns 11
    printf("%d\n",value); //Returns 12
    */

    /*
    //Data type conversion [3 types]
    int num1 = (int)2.7 + (int)3.5; //Does not round up, changes value to 2 and 3 respectively
    printf("%d\n",num1); //Returns 5 (Explicit Conversion)
    float num2 = 2 + 3.5; //Converts the 2 to 2.0 
    printf("%f\n",num2); //Returns 5.5 (Arithmetic Conversion)
    int num3 = 2.6 + 3.6; //Converts the result 6.2 to int 6 
    printf("%d\n",num3); //Returns 6 (Assignment Conversion)
    */

    /*
    //Typical Mathematical Library functions
    //Take note pow and sqrt both return FLOAT values. Hence explicit conversion required
    int negativeNumber = -10;
    int number = 16;
    printf("The absolute value of %d is %d\n",negativeNumber,abs(negativeNumber));
    printf("The square root of %d is %d\n",number,(int)sqrt(number));
    printf("%d to the power of %d is %d\n",4,2,(int)pow(4,2));
    */

    /*
    //Scanf to scan multiple input thru whitespace seperation
    int num1;
    int num2;
    printf("Enter 2 number:\n");
    scanf("%d %d",&num1,&num2); //Can enter in 2 lines or in 1 line
    printf("The numbers are %d and %d respectively\n",num1,num2);
    */
    

    //Boolean checker (Any non-zero number returns True)
    int num = -10;
    printf("The boolean value of %d is ",num);
    printf("%s",num?"true":"false");

    int *ptr;
    int number = 10;
    *ptr = number;
    printf("The value of ptr is %d, the address of ptr is %d",*ptr,ptr);
    

}