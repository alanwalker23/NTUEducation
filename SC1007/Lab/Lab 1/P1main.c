#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int item;
    struct _listnode *next;
} ListNode;

int moveMaxToFront(ListNode **ptrHead);

void printList(ListNode *cur);
ListNode *findNode(ListNode *cur, int index);
int insertNode(ListNode **ptrHead, int index, int item);
void deleteList(ListNode **ptrHead);
int removeNode(ListNode **ptrHead, int index);

int main()
{
    ListNode *head = NULL;
    int size = 0;
    int item;
    int index;

    printf("Enter a list of numbers, terminated by any non-digit character: \n");
    while (scanf("%d", &item))
        if (insertNode(&head, size, item))
            size++;
    scanf("%*s");

    printList(head);

    printf("Before moveMaxToFront() is called:\n");
    index = moveMaxToFront(&head);

    printf("After moveMaxToFront() was called:\n");
    printf("The original index of the node with the largest value: %d.\n", index);
    printList(head);

    deleteList(&head);
    return 0;
}

void printList(ListNode *cur)
{
    printf("Current List: ");
    while (cur != NULL)
    {
        printf("%d ", cur->item);
        cur = cur->next;
    }
    printf("\n");
}

ListNode *findNode(ListNode *cur, int index)
{
    if (cur == NULL || index < 0)
        return NULL;
    while (index > 0)
    {
        cur = cur->next;
        if (cur == NULL)
            return NULL;
        index--;
    }
    return cur;
}

int insertNode(ListNode **ptrHead, int index, int item)
{
    ListNode *pre, *newNode;
    // If empty list or inserting first node, update head pointer
    if (index == 0)
    {
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = *ptrHead;
        *ptrHead = newNode;
        return 1;
    }
    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    else if ((pre = findNode(*ptrHead, index - 1)) != NULL)
    {
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = pre->next;
        pre->next = newNode;
        return 1;
    }
    return 0;
}

void deleteList(ListNode **ptrHead)
{
    ListNode *cur = *ptrHead;
    ListNode *temp;
    while (cur != NULL)
    {
        temp = cur->next;
        free(cur);
        cur = temp;
    }
    *ptrHead = NULL;
}

int moveMaxToFront(ListNode **ptrHead)
{
    ListNode *current = *ptrHead;
    int max = current->item;
    int position = -1;
    while (current!=NULL)
    {
        if (current->item>max)
        {
            max = current->item;
        }
        position++;
        current = current->next;
    }
    ListNode *temp = *ptrHead;
    for (int i = 0;i<position-1;i++)
    {
        temp = temp->next;
    }
    printf("Temp located at %d\n",temp->item);
    ListNode *newHead = temp->next;
    temp->next = temp->next->next;
    newHead->next = (*ptrHead);
    (*ptrHead) = newHead;
    return position;
}

/*
0 -5 1 2 7 a
*/
