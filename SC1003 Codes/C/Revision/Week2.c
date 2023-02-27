#include <stdio.h>

int main()
{
    int num = 5;
    int *ptr = &num;
    printf("ptr pointing to %d\n", *ptr);
    printf("Address of num is at %d\n", &num);
    printf("ptr address of num at %d\n", ptr);
    printf("ptr address %d\n", &ptr);

    //To change value of pointer and num;
    //ptr += 1; //Doing this changes the value of ptr but not num
    *ptr += 1; //Doing this changes both the value of ptr and num.
    //Another method of doing above is
    (*ptr)++; 
    printf("New value of num is %d\n", num);
    printf("New value of *ptr is %d\n", *ptr);
    printf("Address of num is at %d\n", &num);
    printf("ptr address of num at %d\n", ptr);
    printf("ptr address %d\n", &ptr);

    //Change ptr value through changing num value
    num = 10;
    printf("New value of num is %d\n", num);
    printf("New value of *ptr is %d\n", *ptr);
    printf("Address of num is at %d\n", &num);
    printf("ptr address of num at %d\n", ptr);

    //Changing the num through ptr
    *ptr = 15;
    //num = *ptr; //This line is redundant. Since the ptr changes value, so will the number
    printf("New value of num is %d\n", num);
    printf("New value of *ptr is %d\n", *ptr);
    printf("Address of num is at %d\n", &num);
    printf("ptr address of num at %d\n", ptr);

    //Given ptr2, make it unlinked.
    int num2 = 10;
    int *ptr2 = &num2;
    printf("Value of num2 (%d) with pointer2 (%d)\n",num2,*ptr2);
    ptr2 = ptr; //Changes the direction of where pointer 2 is pointing to
    //if *ptr2 = *ptr, the value of num2 will also change to 15 due to ptr's value.
    printf("pointer2 now changed to (%d)\n",*ptr2);
    printf("Value of num2 (%d) with pointer2 (%d)\n",num2,*ptr2);

    *ptr2 = 30;
    printf("The value of num1 is %d and ptr is %d and ptr2 is %d",num,*ptr,*ptr2);
}