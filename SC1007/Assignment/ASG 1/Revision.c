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
void push(ListNode **head_ref, int new_data);
void reverseKNodes(ListNode **head, int K);

int main()
{
    ListNode *head = NULL, *temp;
    int i = 0;
    int K = 0;

    scanf("%d", &K);

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

    reverseKNodes(&head, K);
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

void reverseKNodes(ListNode **head, int K)
{
    // Write your code here
    // Test case: 3 1 2 3 4 5 6 7 c
    if (K == 1 || *head == NULL)
        return;

    int count = 0;
    int logic = 0;
    int elements = 0;
    int newlistsize = 0;
    ListNode *currentNode = *head;
    ListNode *newCluster = NULL;
    ListNode *newList = NULL;
    ListNode *startNode = NULL;
    ListNode *start = (ListNode *)malloc(sizeof(ListNode));

    startNode = currentNode;
    while (currentNode != NULL)
    {
        printf("Loop %d\n", elements);
        if (count == K)
        {
            count = 0;
            newlistsize += K;
            // Reset newcluster
            if (logic == 0)
            {
                newList = newCluster;
                logic = 1;
            }
            else
            {
                printf("Size is %d\n", newlistsize);
                for (int i = 0; i < newlistsize - 1; i++)
                {
                    printf("NewList val %d is %d\n", i, newList->item);
                    newList = newList->next;
                }
                newList->next = newCluster;
            }
            newCluster = NULL;
        }
        push(&newCluster, currentNode->item);
        currentNode = currentNode->next;
        count++;
        elements++;
        // Check values within cluster
        ListNode *currentCluster = newCluster;
        while (currentCluster != NULL)
        {
            printf("CC value = %d\n", currentCluster->item);
            currentCluster = currentCluster->next;
        }
    }
    // newList to be populated with all the correct values reversed.
    while (newList != NULL)
    {
        printf("NewList val = %d\n", newList->item);
        newList = newList->next;
    }
}

/* Function to push a node */
void push(ListNode **head_ref, int new_data)
{
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->item = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void concatenate (ListNode *a, ListNode *b)
{
    
}
