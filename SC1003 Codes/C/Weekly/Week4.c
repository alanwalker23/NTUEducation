#include <stdio.h>
#include <string.h>
#include <ctype.h>
//String is an array of characters
//Char constant "X" is single char
//String constant "X" comprises of "X" and "\0" <- Null char

void modify(char* str);
int main()   
{
    //char str[80], *p; // allocate memory
    //printf("Enter a string of text: \n");
    //fgets(str,80,stdin); if ( p=strchr(str,'\n') ) *p = '\0';
    
    //char *string="Potato";
    char old[20]="Does this work?";
    char *string = " ";
    string = old;
    modify(string); 
    //puts(str);
    printf("New String: %s",string);
    return 0;
}
void modify(char* str) 
{
    while (*str != '\0') 
    {
        *str = tolower(*str);
        str++;
        /*
        if (isupper(*str))
            *str = tolower(*str);
        else if (islower(*str))
            *str = toupper(*str);
        str++;
        */
    }  
}

/*
//Comparing Strings
char str1[20] = "This is string1";
char str2[20] = "This is string2";
char str3[20] = "String3";
char str4[20] = "This is string1";
int result1 = strcmp(str1,str2);
int result2 = strcmp(str1,str3);
int result3 = strcmp(str1,str4);
printf("Results of comparison %d\n",result1); //-1
printf("Results of comparison %d\n",result2); //1
printf("Results of comparison %d\n",result3); //0 (Equal strings)

*/

/*
int main()
{
    //Some forms of string declaration (character arrays) 
    //char str[] = "some text";
    //char str[10] = "yes"; //This array of char can hold up to 10
    //char str[4] = "four"; //Would not work as the null char is not included
    //char str[] = {'a','b','c','\0'}; //This returns str[] = "abc";
    //printf("String: %s\n", &str); <- abc
    //printf("String: %s\n", str); <- abc
    
    //Array vs Pointer declaration
    char array[] = "Array";
    char *ptr = "Pointer";
    printf("Array notation: %s\n", array);
    printf("Pointer notation: %s\n",ptr);
    //Notice that you are printing a singular character instead of string.
    printf("1st Element of Array: %c\n", array[0]);
    printf("1st Element of Pointer: %c\n",ptr[0]);
    //Difference between Array notation vs Pointer notation declaration
    //Array = Pointer Constant, Pointer = Pointer variable
    //++array; Does not work 
    ++ptr;
    printf("Pointer notation: %s\n",ptr);
    ptr++;
    printf("Pointer notation: %s\n",ptr);
    printf("Pointer notation: %c\n",ptr[0]);
    //array = ptr; Does not work
    ptr = array; 
    printf("Pointer notation: %s\n",ptr);
}
*/