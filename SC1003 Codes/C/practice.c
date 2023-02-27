#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
int main()
{
    NameCard nc1;
    nc1.nameCardID = 100;
    strcpy(nc1.personName, "Name");
    strcpy(nc1.companyName, "Company");
    printf("Namecard %d",nc1.nameCardID);
    return 0;
}*/

/* ADD NAME CARD PORTION OF ASSIGNMENT
   scanf("%d", &((h + size)->nameCardID));
   scanf("%c", &dummychar);
   printf("Enter personName:\n");
   fgets((h + size)->personName, 20, stdin);
   if (p = strchr((h + size)->personName, '\n'))
      *p = '\0';
   printf("Enter companyName:\n");
   fgets((h + size)->companyName, 20, stdin);
   if (p = strchr((h + size)->companyName, '\n'))
      *p = '\0';
*/

typedef struct
{
    char name[20]; // a string
    int telno;     // an integer with 5 digits
} PhoneBk;

void change(char **str);
int readin(PhoneBk *pb);
void printPB(PhoneBk *pb, int size);
void sort(PhoneBk *pb, int size);
int main()
{
    //Understanding pointers
    int size = 0;
    PhoneBk *s[3];
    size = readin(s);
    printPB(s, size);
    sort(s, size);
    printPB(s, size);
    //size = readin(s);
    //printf("Size: %d",size);
    /*
    char str[20] = "Patrick";
    char *newStr = "John";
    printf("%s\n",str);
    printf("%s\n",newStr);
    newStr = str;
    printf("%s\n",newStr);
    newStr = "STEWARD";
    printf("%s\n",newStr);
    change(&newStr);
    printf("%s\n",newStr);
    */
}

int readin(PhoneBk *pb)
{
    /* Write your code here */
    int count = 0;
    char *p, dummychar;
    while (1)
    {
        printf("Enter name: ");
        fgets((pb + count)->name, 20, stdin);
        if (p = strchr((pb + count)->name, '\n'))
            *p = '\0';
        if (strcmp((pb + count)->name, "#") == 0)
            break;
        printf("Enter tel: ");
        scanf("%d", &((pb + count)->telno));
        scanf("%c", &dummychar);
        count++;
    }
    return count;
}

void printPB(PhoneBk *pb, int size)
{
    /* Write your code here */
    for (int i = 0; i < size; i++)
    {
        //One method of printing
        printf("Name: %s\n", (pb + i)->name);
        printf("Telno: %d\n", (pb + i)->telno);
        /*Alternate method of printing
        printf("Name: %s\n",pb->name);
        printf("Telno: %d\n",pb->telno);
        pb++;*/
    }
}

void sort(PhoneBk *pb, int size)
{
    PhoneBk index1;
    PhoneBk index2;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
        }
    }
}

void change(char **str)
{
    *str = "LEMON";
}
//#define INIT_VALUE -1000
//int findAr1D(int size, int ar[], int target);
/*
int main()   
{
   char ar[5][20]; //Create an array with 5 elements of len 20
   char array[4][10] = {"Potato","Boi","Gurl","Dota"};
   printf("1st element: %s\n",array[0]);
   char *target = "Gurl";
   //printf("Number of elements: %d\n",strlen(array));
   int found = 0,i;
   for (i=0;i<=4;i++)
   {
       if (strcmp(target,array[i])==0)
       {
           found = 1;
           break;
       } 
   }
   if (found == 1)
       {
           printf("Position of %s at %d\n",target,i);
       }
       else printf("User not found\n");  
   //*
   int size, i, target, result = INIT_VALUE;
   printf("Enter array size: \n");
   scanf("%d", &size);   
   printf("Enter %d data: \n", size);
   for (i=0; i<=size-1; i++)   
      scanf("%d", &ar[i]);
   printf("Enter the target number: \n");
   scanf("%d", &target);    
   result = findAr1D(size, ar, target);
   if (result == -1)
      printf("findAr1D(): Not found\n");
   else  
      printf("findAr1D(): %d", result); 
   return 0;//End here*
}
int findAr1D(int size, int ar[], int target)     
{
   for (int i = 0;i<size;i++)
   {
       if(ar[i]==target)
       {
           return i;
       }       
   }
   return -1;
}
*/
/*
Week 10 (Week 3 of C)
//Finding maximum of a range of numbers
int index, max, numArray[5];
int *ptr;
ptr = numArray;
printf("%d\n",ptr);
printf("Enter 3 numbers: \n");
for (index = 0; index < 3; index++)
scanf("%d", ptr++);
// Find maximum from array data

//Notice that current iteration of ptr is at ptr=3
//The value ptr=3 corresponds to the address of element 3 of numArray
printf("%d\n",ptr);
printf("%d\n",&numArray[3]);
ptr = numArray;
printf("%d\n",ptr);
max = *ptr;
for (index = 0; index < 3; index++) {
if (*ptr > max)
max = *ptr;
ptr++;
}
printf("max is %d.\n", max);
return 0;


//Pointer constants as a way to parse codes
int index,max,numAr[5];
printf("Enter 5 nums");
for(index = 0 ;index<5;index++)
{
    scanf("%d",numAr+index);
    //printf("%d",numAr+index); --> numAr + index is an address of the value
}
max = *numAr;
for(index = 1; index<5;index++)
{
    if(*(numAr+index)>max)
        max = *(numAr+index);
}
printf("Max value is %d\n",max);
return 0;


//Calling Values of Array
#define MTHS 12 [Goes to header]
int days[MTHS]={0,1,2,3,4,5,6,7,8,9};
int *day_ptr;
day_ptr = days;
printf("Pointing to current element of %d\n",*day_ptr);
day_ptr = &days[3];
printf("Pointing to current element of %d\n",*day_ptr);
day_ptr +=3;
printf("Pointing to current element of %d\n",*day_ptr);


Week 9 (Week 2 of C)
# Declare and initialize an int variable
int var = 1;
# Declare a pointer to int
int *ptr;
void height (float *h);
int main()
{
    float a;
    float *aptr;
    a = 5.0;
    aptr = &a;
    printf("a: %d\n",a);
    printf("*aptr: %f\n",*aptr);
    printf("&aptr: %f\n",&aptr);
    //aptr != *aptr;
    height(aptr);    
    printf("*aptr: %f\n",*aptr);
}

void height (float *h)
{
    scanf("%f",&*h);
}


int main( void )
{   

    //Memory allocation
    int a;
    int *aptr;
    a = 5;
    aptr = &a;
    printf("a: %d\n",a);
    printf("&a: %d\n",&a);
    printf("aptr: %d\n",aptr);
    printf("*aptr: %d\n",*aptr);
    printf("&aptr: %d\n",&aptr);
    printf("&*aptr: %d\n",&*aptr);
    return 0;



    int x,y,z;
    printf("Enter 3 different values: ");
    scanf("%d %d %d", &x,&y,&z);
    printf("x = %d, y = %d, z = %d", x,y,z);
    //Take note for such inputs
    //Can key in 1 2 3 (with spaces) to parse respective values
    //If entering 1 by 1, it is also possible
    



    char choice;   int num1, num2, result;
    printf("Enter your choice (A, S or M) => ");
    scanf("%c", &choice);
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    if ( (choice == 'a')  || (choice == 'A'))     
    {
        result = num1 + num2;
        printf(" %d + %d = %d\n", num1,num2,result);
    }
    else if ((choice == 's')  || (choice == 'S'))
    {
        result = num1 - num2;
        printf(" %d ‐ %d = %d\n", num1,num2,result);
    }
    else if ((choice == 'm')  || (choice == 'M'))
    {
        result = num1 * num2;
        printf(" %d * %d = %d\n", num1,num2,result);
    }      
    else printf("Not one of the proper choices.\n");
    return 0;




    char ch, ch1, ch2;
    putchar('1');
    putchar(ch='a');
    putchar('\n');
    printf("%c%c\nEnter char:", 49, ch);
    //Whatever is in input, only takes the first 2 char 
    //Type abc will get ch1 = a, ch2 = b.
    ch1 = getchar();
    ch2 = getchar();
    printf("Char 1: %c\nChar 2: %c\n", ch1, ch2);
    return 0;
   

    
    float j,k;
    int l;
    int num;

    j = 2.2;
    k = 4.3;
    l = 1;
    //Base case
    printf("%.2f\n",j+k);
    //Explicit Conversion (both float are converted to int)
    printf("%d\n",(int)j+(int)k);
    //Arithmetic Conversion [2.2 + 1 --> 2.2 + 1.0 --> 3.2]
    j = j+l;
    printf("%.2f\n",j);
    //Assignmnet Conversion [3.2+4.3 --> 7.5 --> 7]
    num = j+k;
    printf("%d\n",num);
}

//When changing pointer value or original value, both variables will reflect the change

*/