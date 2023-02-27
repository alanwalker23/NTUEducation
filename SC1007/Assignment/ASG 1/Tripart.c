#include <stdio.h>
#include <stdlib.h>

struct _listNode
{
    int item;
    struct _listNode *next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);
void append(ListNode **head_ref, int new_data);
void triPartition(ListNode **head, int pivot);

int main()
{
    ListNode *head = NULL, *temp;
    int i = 0;
    int pivot = 0;

    scanf("%d", &pivot);

    while (scanf("%d", &i))
    {
        if (head == NULL)
        {
            head = (ListNode *)malloc(sizeof(ListNode));
            temp = head;
        }
        else
        {
            temp->next = (ListNode *)malloc(sizeof(ListNode));
            temp = temp->next;
        }
        temp->item = i;
    }
    temp->next = NULL;

    triPartition(&head, pivot);
    printList(head);
    deleteList(&head);

    return 0;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->item);
        head = head->next;
    }
    printf("\n");
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

void triPartition(ListNode **head, int pivot)
{

    // Write your code here
    ListNode *lesser = NULL;
    ListNode *greater = NULL;
    ListNode *current = *head;
    ListNode *final = NULL;
    int count = 0;

    while (current!=NULL)
    {
        if (current->item<pivot)
            append(&lesser,current->item);
        else if (current->item>pivot)
            append(&greater,current->item);
        else
            count++;
        current = current->next;
    }

    //Check portion
    while (lesser!=NULL)
    {
        printf("Left - %d\n",lesser->item);
        append(&final,lesser->item);
        lesser = lesser->next;
    }
    printf("Count is %d\n",count);
    for (int i=0;i<count;i++)
    {
        append(&final,pivot);
    }
        while (greater!=NULL)
    {
        printf("Right - %d\n",greater->item);
        append(&final,greater->item);
        greater = greater->next;
    }
    
    /* //Check final list
    ListNode *checkList = final;
    while (checkList!=NULL)
    {
        printf("Final list value - %d\n",checkList->item);
        checkList = checkList->next;
    } */
    **head = *final;
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
// 5 8 1 5 5 5 7 2 a