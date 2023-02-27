#include <stdio.h>
#include <stdlib.h>

typedef struct _dbllistnode
{
  int item;
  struct _dbllistnode *next;
  struct _dbllistnode *pre;
} CDblListNode;

typedef struct _dbllinkedlist
{
  int size;
  CDblListNode *head;
} CDblLinkedList;

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value);
void deleteList(CDblLinkedList *ptrCDLL);
void printList(CDblLinkedList CDLL);

int numMountainPairs(CDblLinkedList CDLL);

int main()
{
  CDblLinkedList himalayas;
  himalayas.head = NULL;
  himalayas.size = 0;

  int item;
  int i, cases;
  int numP;
  scanf("%d", &cases);
  for (i = 0; i < cases; i++)
  {
    while (scanf("%d", &item))
      insertNode_AtFront(&himalayas, item);
    scanf("%*s");

    numP = numMountainPairs(himalayas);
    printList(himalayas);
    printf("%d Pairs.\n", numP);

    deleteList(&himalayas);
  }
  return 0;
}

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value)
{
  // create a new node
  CDblListNode *newNode;
  newNode = (CDblListNode *)malloc(sizeof(CDblListNode));
  newNode->item = value;

  if (ptrCDLL->size == 0) // first node
  {
    newNode->next = newNode;
    newNode->pre = newNode;
    ptrCDLL->head = newNode;
  }
  else
  {
    newNode->next = ptrCDLL->head;
    newNode->pre = ptrCDLL->head->pre;

    newNode->pre->next = newNode; // update last node next link;
    ptrCDLL->head->pre = newNode;

    ptrCDLL->head = newNode;
  }
  ptrCDLL->size++;
}

void printList(CDblLinkedList CDLL)
{

  if (CDLL.head == NULL)
    return;

  CDblListNode *temp = CDLL.head;
  printf("Current List: ");

  while (temp->next != CDLL.head)
  {
    printf("%d ", temp->item);
    temp = temp->next;
  }
  printf("%d\n", temp->item);
}

void deleteList(CDblLinkedList *ptrCDLL)
{
  if (ptrCDLL->head == NULL)
    return;
  CDblListNode *cur = ptrCDLL->head;
  CDblListNode *temp;

  while (cur->next != ptrCDLL->head)
  {
    temp = cur->next;
    free(cur);
    cur = temp;
  }

  free(cur);
  ptrCDLL->head = NULL;
  ptrCDLL->size = 0;
}

typedef struct unique
{
  CDblListNode *itemfirst;
  CDblListNode *itemsecond;
  struct unique *next;
  int size;
} unique;

int numMountainPairs(CDblLinkedList CDLL)
{
  // Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

  // Write your code here
  CDblListNode *temp, *middle, *start, *adder;
  unique *newNode, *head, *tempforu, *doublechecker;
  int counter = 0, i, j, k, m, first = 0, duplicate = 0;
  temp = CDLL.head;
  start = CDLL.head;
  adder = CDLL.head;
  for (i = 0; i < CDLL.size; i++)
  {
    counter++;
  }
  // printf("Start item: %d\n",CDLL.head->item);
  temp = temp->next;
  middle = temp;
  temp = temp->next;
  if (CDLL.size == 0)
  {
    return 0;
  }
  else if (CDLL.size == 1)
  {
    return 0;
  }
  else if (CDLL.size == 2)
  {
    return 1;
  }
  else if (CDLL.size == 3)
  {
    return 3;
  }

  for (j = 0; j < CDLL.size; j++)
  {
    printf("Iteration %d\n", j);

    if (start->item >= middle->item)
    {
      for (k = 0; k < CDLL.size - 3; k++)
      {
        if (temp->item >= middle->item)
        {
          printf("Added!\n");

          if (first == 0)
          {
            printf("Added first start: %d\n", start->item);
            printf("Added first temp: %d\n", temp->item);
            head = (unique *)malloc(sizeof(unique));
            head->itemfirst = start;
            head->itemsecond = temp;
            head->size = 1;
            tempforu = head;
            counter++;
            first++;
          }
          else
          {
            printf("Checking %d\n", start->item);
            printf("Checking %d\n", temp->item);
            doublechecker = head;
            while (doublechecker != NULL)
            {
              if ((doublechecker->itemfirst == start && doublechecker->itemsecond == temp) || (doublechecker->itemfirst == temp && doublechecker->itemsecond == start))
              {
                printf("Duplicate detected\n");
                duplicate = 1;
              }
              doublechecker = doublechecker->next;
            }
            if (duplicate == 0)
            {
              tempforu->next = (unique *)malloc(sizeof(unique));
              tempforu = tempforu->next;
              tempforu->itemfirst = start;
              tempforu->itemsecond = temp;
              head->size++;
              counter++;
            }
            else
            {
              duplicate = 0;
            }
          }

          if (temp->item > middle->item)
          {
            middle = temp;
            temp = temp->next;
          }
          else
          {
            temp = temp->next;
          }
        }
        else
        {
          temp = temp->next;
        }
      }
    }

    start = start->next;
    middle = start->next;
    temp = middle->next;
  }

  int answer = 0;
  answer = CDLL.size + head->size;

  return answer;

  printList(CDLL);
}

// for(m=0;m<CDLL.size;m++)
// {
//   if(m==0)
//     {
//       printf("Added first\n");
//       head=(unique*) malloc(sizeof(unique));
//       head->itemfirst = adder;
//       head->itemsecond = adder->next;
//       adder = adder->next;
//       adder = adder->next;
//       head->size ++;
//       head->size ++;
//       tempforu = head;
//       counter++;
//     }
//   else
//   {
//     tempforu->next = (unique*) malloc(sizeof(unique));
//     tempforu = tempforu->next;
//     tempforu->itemfirst = start;
//     tempforu->itemsecond = temp;
//     head->size ++;
//     counter++;
//   }
// }

// else if(start->item == middle->item)
// {
//   for(k=0;k<CDLL.size-3;k++)
//     {
//       if(temp->item>middle->item)
//       {
//         printf("Added equal!\n");

//         if(first==0)
//         {
//             printf("Added equal first start: %d\n",start->item);
//             printf("Added equal first temp: %d\n",temp->item);
//             head=(unique*) malloc(sizeof(unique));
//             head->itemfirst = start;
//             head->itemsecond = temp;
//             head->size = 1;
//             tempforu = head;
//             counter++;
//             first++;
//         }
//       else
//       {
//         printf("Equal Checking %d\n",start->item);
//         printf("Equal Checking %d\n",temp->item);
//         doublechecker = head;
//         while(doublechecker!=NULL)
//         {
//           if((doublechecker->itemfirst==start && doublechecker->itemsecond == temp)||(doublechecker->itemfirst == temp && doublechecker->itemsecond == start))
//           {
//             printf("Duplicate detected\n");
//             duplicate = 1;
//           }
//           doublechecker = doublechecker->next;
//         }
//         if(duplicate==0)
//         {
//           tempforu->next = (unique*) malloc(sizeof(unique));
//           tempforu = tempforu->next;
//           tempforu->itemfirst = start;
//           tempforu->itemsecond = temp;
//           head->size ++;
//           counter++;
//         }
//         else
//         {
//           duplicate = 0;
//         }

//       }

//       middle = temp;
//       temp = temp->next;

//       }
//       else
//       {
//         temp = temp->next;
//       }

//     }

// }

// while(prelast!=last)
// {
//   printf("Hello\n");
//   prelast = prelast->next;
// }

// for(j=0;j<CDLL.size;j++)
// {
//   printf("Iteration: %d\n",j);

//   if(start->next!=last)
//   {
//   while(prelast!=last)
//   {
//     printf("Entered\n");
//     // prelast = prelast->next;
//     if(start->item>=middle->item)
//     {
//       if(temp->item>middle->item)
//       {
//         counter++;
//         printf("bigger temp: %d\n",middle->item);
//         middle = temp;
//         temp = temp->next;
//         prelast = prelast->next;
//       }
//       else if(temp->item==middle->item)
//       {
//         counter++;
//         printf("same middle: %d\n",middle->item);
//         temp = temp->next;
//         prelast = prelast->next;
//       }
//       else
//       {
//         prelast = prelast->next;
//         temp = temp->next;
//       }
//     }
//     // else if(start->item>=backmiddle->item)
//     // {
//     //   if(backmiddle->item<backtemp->item)
//     //   {
//     //     printf("stored backmiddle\n");
//     //     counter++;
//     //     backtemp = backtemp->pre;
//     //     backmiddle = backmiddle->pre;
//     //   }
//     //   else if(start->next==backtemp)
//     //   {
//     //     break;
//     //   }
//     // }

//     else
//     {
//       // while(backtemp!=prelast)
//       // {
//       // if(start->item>=backmiddle->item)
//       // {
//       //   if(backtemp->item>=backmiddle->item)
//       //   {
//       //     counter++;
//       //     backtemp = backtemp->pre;
//       //     backmiddle = backmiddle->pre;
//       //   }
//       //   else
//       //   {
//       //     backtemp = backtemp->pre;
//       //     backmiddle = backmiddle->pre;
//       //   }
//       // }
//       // else
//       // {
//       //   break;
//       // }
//       // }
//       break;
//     }

//   }
//   }
//   else
//   {
//     break;
//   }

//   // while((start->item>=backmiddle->item)&&(start->next!=backtemp))
//   //   {
//   //     if(backmiddle->item<=backtemp->item)
//   //     {
//   //       printf("stored backmiddle\n");
//   //       counter++;
//   //       backtemp = backtemp->pre;
//   //       backmiddle = backmiddle->pre;
//   //     }
//   //     else if(start->next==backtemp)
//   //     {
//   //       break;
//   //     }
//   //   }

//   start = start->next;
//   middle = start->next;
//   prelast = middle;
//   temp = middle->next;
//   // backmiddle = backmiddle->next;
//   // backtemp = backtemp->next;

// }
