#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5

//Structure Declaration
typedef struct
{
   int nameCardID;
   char personName[20];
   char companyName[20];
} NameCard;

//Function Declaration
void sort(NameCard *h, int size);
int getNamePos(int size, NameCard *h);
int compareStr(char *str1, char *str2);
//Main functions
void listNameCards(int size, NameCard *h);
int addNamecard(int size, NameCard *h);
int removeNameCard(int size, NameCard *h);
void getNameCard(int size, NameCard *h);

int main()
{
   int choice, size = 0;
   char dummychar;
   NameCard holder[MAX];

   printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM:\n");
   printf("1: listNameCards() \n");
   printf("2: addNameCard() \n");
   printf("3: removeNameCard() \n");
   printf("4: getNameCard() \n");
   printf("5: quit \n");
   do
   {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      scanf("%c", &dummychar);
      switch (choice)
      {
      case 1:
         listNameCards(size, holder);
         break;
      case 2:
         size = addNamecard(size, holder);
         break;
      case 3:
         size = removeNameCard(size, holder);
         break;
      case 4:
         getNameCard(size, holder);
         break;
      default:
         printf("Program terminating .....\n");
         break;
      }
   } while (choice < 5);
   return 0;
}

void sort(NameCard *h, int size)
{
   //Sorting through bubble sort
   NameCard temp;
   for (int i = 0; i < size - 1; i++)
   {
      for (int j = 0; j < size - 1 - i; j++)
      {
         if (h[j].nameCardID > h[j + 1].nameCardID)
         {
            temp = h[j];
            h[j] = h[j + 1];
            h[j + 1] = temp;
         }
      }
   }
}

int getNamePos(int size, NameCard *h)
{
   int i;
   char *p, target[20], dummy;
   printf("Enter personName:\n");
   fgets(target, 20, stdin);
   if (p = strchr(target, '\n'))
      *p = '\0';
   for (i = 0; i < size; i++)
   {
      if (compareStr((h + i)->personName, target) == 0)
      {
         return i;
      }
   }
   return -1;
}

int compareStr(char *str1, char *str2)
{
   int i, j = 0;
   i = strlen(str1);
   j = strlen(str2);
   if (i == j)
   {
      for (i = 0; str1[i] != '\0'; i++)
      {
         //Caps vs Nocaps is 32 away [Can also use stricmp to compare non-case sensitive]
         if (str1[i] - str2[i] == 32 || str1[i] - str2[i] == -32 || str1[i] - str2[i] == 0)
            continue;
         else
         {
            return -1;
         }
      }
      return 0;
   }
   return -1;
}

void listNameCards(int size, NameCard *h)
{
   printf("listNameCards():\n");
   if (size == 0)
   {
      printf("The name card holder is empty\n");
   }
   else
   {
      for (int i = 0; i < size; i++)
      {
         printf("nameCardID: %d\n", (h + i)->nameCardID);
         printf("personName: %s\n", (h + i)->personName);
         printf("companyName: %s\n", (h + i)->companyName);
      }
   }
}

int addNamecard(int size, NameCard *h)
{
   char *p, dummychar;
   int id;
   char name[20], company[20];
   printf("addNameCard():\n");
   printf("Enter nameCardID:\n");
   scanf("%d", &id);
   scanf("%c", &dummychar);
   printf("Enter personName:\n");
   fgets(name, 20, stdin);
   if (p = strchr(name, '\n'))
      *p = '\0';
   printf("Enter companyName:\n");
   fgets(company, 20, stdin);
   if (p = strchr(company, '\n'))
      *p = '\0';
   if (size == MAX)
   {
      printf("The name card holder is full\n");
      return size;
   }
   else
   {
      for (int i = 0; i < size; i++)
      {

         if ((h + i)->nameCardID == id)
         {
            printf("The nameCardID has already existed\n");
            return size;
         }
      }
   }
   NameCard newCard;
   newCard.nameCardID = id;
   strcpy(newCard.personName, name);
   strcpy(newCard.companyName, company);
   h[size] = newCard;
   size++;
   sort(h, size);
   printf("The name card has been added successfully\n");
   return size;
}

int removeNameCard(int size, NameCard *h)
{
   int position;
   printf("removeNameCard():\n");
   position = getNamePos(size, h);
   if (position == -1)
   {
      if (size == 0)
      {
         printf("The name card holder is empty\n");
         return size;
      }
      printf("The target person name is not in the name card holder\n");
      return size;
   }
   printf("The name card is removed\n");
   printf("nameCardID: %d\n", h[position].nameCardID);
   printf("personName: %s\n", h[position].personName);
   printf("companyName: %s\n", h[position].companyName);

   //Alternate Method
   /*
   printf("nameCardID: %d\n", (h + position)->nameCardID);
   printf("personName: %s\n", (h + position)->personName);
   printf("companyName: %s\n", (h + position)->companyName);
   */

   for (position; position < size - 1; position++)
   {
      h[position] = h[position + 1];
   }
   size--;
   return size;
}

void getNameCard(int size, NameCard *h)
{
   int position;
   printf("getNameCard():\n");
   position = getNamePos(size, h);
   if (position == -1)
   {
      printf("The target person name is not found\n");
   }
   else
   {
      printf("The target person name is found\n");
      printf("nameCardID: %d\n", (h + position)->nameCardID);
      printf("personName: %s\n", (h + position)->personName);
      printf("companyName: %s\n", (h + position)->companyName);
   }
}