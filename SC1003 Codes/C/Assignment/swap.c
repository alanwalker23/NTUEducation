#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int nameCardID;
    char personName[20];
} NameCard;

void swap(NameCard *h);
void swapaway(NameCard *h);
int main()
{
    NameCard holder[5];
    NameCard input1 = {5, "John"};
    NameCard input2 = {4, "Tinker"};
    NameCard input3 = {3, "Tide"};
    NameCard input4 = {2, "Mag"};
    NameCard input5 = {1, "Potm"};
    holder[0] = input1;
    holder[1] = input2;
    holder[3] = input3;
    holder[4] = input4;
    holder[5] = input5;
    printf("ID: %d\n", holder[0].nameCardID);
    printf("Name: %s\n", holder[0].personName);
    swap(holder);
    printf("ID: %d\n", holder[0].nameCardID);
    printf("Name: %s\n", holder[0].personName);
    swapaway(holder);
    printf("ID: %d\n", holder[0].nameCardID);
    printf("Name: %s\n", holder[0].personName);
}

void swap(NameCard *h)
{
    NameCard temp;
    if (h[0].nameCardID > h[1].nameCardID)
    {
        temp = h[0];
        h[0] = h[1];
        h[1] = temp;
    }
}

void swapaway(NameCard *h)
{
    h[0] = h[1];
    h[1] = h[2];
}