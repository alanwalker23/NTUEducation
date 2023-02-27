#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int nameCardID;
    char personName[20];
} NameCard;

//void swap(NameCard *h);
void putoff(NameCard *h);
int main()
{
    NameCard holder[5];
    NameCard input1 = {5, "John"};
    NameCard input2 = {4, "Tinker"};
    NameCard input3 = {3, "Tide"};
    holder[0] = input1;
    holder[1] = input2;
    holder[2] = input3;
    printf("ID: %d\n", holder[0].nameCardID);
    printf("Name: %s\n", holder[0].personName);
    putoff(holder);
    printf("ID: %d\n", holder[0].nameCardID);
    printf("Name: %s\n", holder[0].personName);
}

void putoff(NameCard *h)
{
    h[0] = h[1];
    h[1] = h[2];
}