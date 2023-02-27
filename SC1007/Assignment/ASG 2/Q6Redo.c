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

typedef struct Checker
{
    CDblListNode *item1;
    CDblListNode *item2;
    struct Checker *next;
    int size;
} Checker;

int numMountainPairs(CDblLinkedList CDLL)
{
    CDblListNode *head = CDLL.head;
    CDblListNode *backup = CDLL.head;
    CDblListNode *current = NULL;
    int count = CDLL.size;
    int i = 0;
    int minheight = 0; 
    int ldirection = 0, rdirection = 0;

    if (CDLL.head == NULL || CDLL.size <2)
        return 0;
    else if (CDLL.size == 2)
        return 1;
    else if (CDLL.size == 3)
        return 3;
    
    while (i < CDLL.size - 1)
    {
        i++;
        head = head->next;
        backup = backup->next;
    }
    backup = backup->pre;

    do
    {
        if (head != backup->next && backup->pre != head)
        {
            if (head->item < backup->item)
                minheight = head->item;
            else
                minheight = backup->item;
            current = head->pre;
            while (head != current && current != backup)
            {
                if (current->item <= minheight)
                    ldirection = 1;
                else
                {
                    ldirection = 0;
                    break;
                }
                current = current->pre;
            }
            current = head->next;
            while (head != current && backup != current)
            {
                if (current->item <= minheight)
                    rdirection = 1;
                else
                {
                    rdirection = 0;
                    break;
                }
                current = current->next;
            }
            if (ldirection == 1 || rdirection == 1)
                count++;
        }
        if (CDLL.head == backup)
        {
            head = head->pre;
            backup = head;
        }
        backup = backup->pre;
    } while (head != CDLL.head);
    return count;
}