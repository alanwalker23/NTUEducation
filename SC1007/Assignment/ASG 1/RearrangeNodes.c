#include <stdio.h>
#include <stdlib.h>

struct _listNode
{
    int item;
    struct _listNode *next;
};
typedef struct _ listNode ListNode;

typedef struct _linkedList
{
    ListNode *head;
    int size;
} LinkedList;

void printList(LinkedList ll);
void deleteList(LinkedList *llptr);
void append(ListNode **head_ref, int new_data);
LinkedList rearrange(LinkedList ll);

int main()
{
    LinkedList ll;

    ll.head = NULL;
    ll.size = 0;
    ListNode *temp;

    int i = 0;

    while (scanf("%d", &i))
    {
        if (ll.head == NULL)
        {
            ll.head = (ListNode *)malloc(sizeof(ListNode));
            temp = ll.head;
        }
        else
        {
            temp->next = (ListNode *)malloc(sizeof(ListNode));
            temp = temp->next;
        }
        temp->item = i;
        ll.size++;
    }
    temp->next = NULL;

    ll = rearrange(ll);
    isCircular(ll.head)
        printList(ll);
    deleteList(&ll);
    return 0;
}

void printList(LinkedList ll)
{
    ListNode *temp = ll.head;

    while (temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}
void deleteList(LinkedList *llptr)
{
    ListNode *cur = llptr->head;
    ListNode *temp;
    while (cur != NULL)
    {
        temp = cur->next;
        free(cur);
        cur = temp;
    }
    llptr->head = NULL;
    llptr->size = 0;
}

LinkedList rearrange(LinkedList ll)
{
    // Write your code here
    if (ll.size == 1)
        return ll;
    ListNode *start = ll.head;
    ListNode *left = NULL;
    ListNode *right = NULL;
    ListNode *list1 = NULL;
    int size = ll.size;
    int firsthalf = size / 2;
    int count = 0;
    // printf("Firsthalf = %d\n",firsthalf);
    while (start != NULL)
    {
        // printf("Value - %d\n",start->item);
        /* code */
        if (count < firsthalf)
            append(&left, start->item);
        else
            append(&right, start->item);
        start = start->next;
        count++;
    }

    ListNode *leftPtr = left;
    ListNode *rightPtr = right;
    for (int i = 0; i < firsthalf; i++)
    {
        append(&list1, rightPtr->item);
        append(&list1, leftPtr->item);
        rightPtr = rightPtr->next;
        leftPtr = leftPtr->next;
    }
    if (size % 2 != 0)
    {
        append(&list1, rightPtr->item);
    }

    count = 0;
    left = NULL;
    right = NULL;
    while (list1 != NULL)
    {
        if (count < firsthalf)
            append(&left, list1->item);
        else
            append(&right, list1->item);
        list1 = list1->next;
        count++;
    }

    leftPtr = left;
    rightPtr = right;
    list1 = NULL;
    for (int i = 0; i < firsthalf; i++)
    {
        append(&list1, leftPtr->item);
        append(&list1, rightPtr->item);
        rightPtr = rightPtr->next;
        leftPtr = leftPtr->next;
    }
    if (size % 2 != 0)
    {
        append(&list1, rightPtr->item);
    }

    LinkedList newList;
    newList.head = list1;
    newList.size = size;
    return newList;
}

void append(ListNode **head_ref, int new_data)
{
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    ListNode *last = *head_ref;
    new_node->item = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}
