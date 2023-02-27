#include <stdio.h>
#include <string.h>
#define MAX 3
struct book {
    char title[40];
    char author[20];
    float value;
}; //bkRecord2 ={"Why","John",10}; Possible to define structs here

//Defining an array for book
struct book books[MAX]={
        {"Who","Tom",10},
        {"What","Jerry",5},
        {"When","Lel",5},
    };

int main()
{
    //Below prints all elements of array of structure book
    for (int i=0;i<MAX;i++)
    {
        printf("Title: %s\tAuthor: %s\tValue: %d\n",books[i].title,books[i].author,books[i].value);
    }
}

/*
//User based input to construct structure Book
char *p;
struct book bkRecord;
struct book bkRecord3;
bkRecord3 = bkRecord2;
printf("Book title: ");
fgets(bkRecord.title,40,stdin);
if (p=strchr(bkRecord.title,'\n')) *p = '\0';
printf("Author: ");
fgets(bkRecord.author, 20, stdin);
if ( p=strchr(bkRecord.author,'\n') ) *p = '\0';
printf("Value: ");
scanf("%f", &bkRecord.value);  //note: & is needed here
printf("%s by %s: $%.2f\n", bkRecord.title, bkRecord.author,
bkRecord.value);
printf("%s by %s: $%.2f\n", bkRecord2.title, bkRecord2.author,
bkRecord2.value);
printf("%s by %s: $%.2f\n", bkRecord3.title, bkRecord3.author,
bkRecord3.value);
return 0;    

*/