#include <stdio.h>
#include <string.h>

int main()
{
    char *string1 = "potato";
    char *string2 = "dog";
    
    char string3[10] = "pot";
    char string4[10] = "lol";
    
    printf("String3 1char is %c\n",string3[9]);
    
    char arr[][5] = {"cat","tat","mat"};
    printf("String ar[1] - %s, first char - %c\n",arr[0],arr[0][0]);
    printf("String ar[1] - %s, first char - %c\n",*(arr+0),*(*(arr+0)+0));
    printf("String 1 - %c \tString 3 - %c\n",*(string1+0),string3[0]);
    
    printf("String 1 - %s \tString 2 - %s\n",string1,string2);
    printf("String 3 - %s \t\tString 4 - %s\n",string3,string4);
    putchar('\n');
    
    /*
    //strcat and strncat [Concatenate]
    strcat(string3,string4);
    printf("[strcat()]CODE - strcat(string3,string4)\n");
    printf("Changes value of string3 from \"pot\" to \"%s\" (string3 (pot) and string4 (%s) combined)\n",string3,string4);
    
    strncat(string3,string4,2);
    printf("[strncat()]CODE - strncat(string3,string4,2)\n");
    printf("Changes value of string3 to %s (string3 (potlol) and 1st 2 char from string4 (%s) combined)\n",string3,string4);
    putchar('\n');
    


    
    //Finding first and last occurance of a letter and returning string after that specific letter position
    //strchr --> First instance strrchr --> Last instance
    //Retrieves leftover string from 1st instance of specified character c (other param)
    //Takes 1st occurance
    char letter = 'l';
    char *ret = strchr(string3,letter);
    printf("[strchr()]CODE - char *ret = strchr(string1,letter)\n");
    printf("String after 1st instance of 'l' in %s is %s(ret)\n",string3,ret);
    ret = strrchr(string3,letter);
    printf("[strrchr()]CODE - ret = strrchr(string1,letter)\n");
    printf("String after LAST instance of 'l' in %s is %s(ret)\n",string3,ret);
    putchar('\n');
    

    //Finding substring of a 
    //strstr is similar to strchr but instead of searching for 1st instance of char it looks for a string
    strcat(string3,string4);
    strncat(string3,string4,2);
    printf("String3 - %s\tString4 - %s\n",string3,string4);
    ret = strstr(string3,string4);
    printf("The substring of %s in %s is %s\n",string4,string3,ret);
    putchar('\n');

    //strcmp
    int difference = strcmp(string1,"potato");
    printf("The difference between \"potato\" and string1(%s) is %d\n",string1,difference);
    difference = strcmp(string1,"POTATO");
    printf("The difference between \"POTATO\" and string1(%s) is %d\n",string1,difference);
    
    difference = strncmp(string1,"poTATO",2);
    printf("The difference between first 2 of \"poTATO\" and string1(%s) is %d\n",string1,difference);
    difference = strncmp(string1,"poTATO",3);
    printf("The difference between first 3 of \"poTATO\" and string1(%s) is %d\n",string1,difference);
    putchar('\n');

    //strcpy ONLY works on array denotion, non-pointer
    //strcpy works on string[10] not *string
    printf("String3 - %s\tString4 - %s\n",string3,string4);
    strcpy(string3,string4);
    printf("String3 - %s\tString4 - %s\n",string3,string4);
    
    printf("String3 - %s reset to pot\n",string3);
    strcpy(string3,"pot");
    strncpy(string3,string4,2);
    printf("String3 - %s\tString4 - %s\n",string3,string4);

    //Change values of string 3 and 4
    strcpy(string3,"potatoz");
    strcpy(string4,"cckbrain");
    printf("String3 - %s\tString4 - %s\n",string3,string4);
    ret = strpbrk(string3,string4);
    printf("First matching char: %c\n",*ret);
    */
}