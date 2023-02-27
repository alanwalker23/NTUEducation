#include <stdio.h>

//Question 4
int main()
{
    float x, result = 1 , newx = 1;
    int count = 1;
    printf("Enter x:\n");
    scanf("%f",&x);
    for (int i=1;i<=10;i++)
    {
        count *=i;
        newx*=x;
        result+=(newx/count);
    }
    printf("Result = %.2f",result);
}

  
/*
//Question 3
int height,check;
printf("Enter the height:\n");
scanf("%d",&height);
for (int i = 1;i<=height;i++)
{
    for (int j=1;j<=i;j++)
    {
        check = i%3;
        if(check==0)
        {
            printf("%d",3);
        }
        else
        {
            printf("%d",i%3);
        }
    }
    printf("\n");
}

//Question 2
int lines,count;
float inputs,average;

printf("Enter number of lines:");
scanf("%d",&lines);
for (int i=1;i<=lines;i++)
{
    printf("Enter line %d (end with -1):\n",i);
    while (inputs!= -1)
    {
        scanf("%f",&inputs);
        average+=inputs;
        count+=1;
    }
    average = (average+1)/(float)(count-1);
    printf("Average = %.2f\n",average);
    count = inputs = average = 0;
}

//Question 1 [Reference Solution]
int studentNum = 0, mark;
printf("Enter Student ID: \n");
scanf("%d", &studentNum);
while (studentNum != -1)  
{
    printf("Enter Mark: ");
    scanf("%d", &mark);
    if (mark >= 75)
        printf("Grade = A\n");
    else if (mark >= 65)
    printf("Grade = B\n"); 
    else if (mark >= 55)
        printf("Grade = C\n");
    else if (mark >= 45)
        printf("Grade = D\n");
    else  
        printf("Grade = F\n");
    printf("Enter Student ID: ");
    scanf("%d", &studentNum);      
}
return 0;


int studentNum = 0, mark;
printf("Enter Student ID: \n");
scanf("%d", &studentNum);
while (studentNum != -1)
{
    printf("Enter Mark: \n");
    scanf("%d",&mark);
    switch((mark+5)/10)  
    {
        case(10):
        case(9):
        case(8):
            printf("Grade = A\n");
            break;
        case(7):
            printf("Grade = B\n");
            break;
        case(6):
            printf("Grade = C\n");
            break;
        case(5):
            printf("Grade = D\n");
            break;
        default:
            printf("Grade = F\n");
            break;                      
    }
    printf("Enter Student ID: \n");
    scanf("%d", &studentNum);
}
*/