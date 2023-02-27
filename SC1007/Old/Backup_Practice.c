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
    int count = 1;
    int logic = 0;
    int elements = 0;
    ListNode *currentNode = *head;
    ListNode *newCluster = NULL;
    ListNode *newList = NULL;
    ListNode *startNode = NULL;
    ListNode *start = (ListNode *)malloc(sizeof(ListNode));
    // DO NOT NEED
    // start->item = currentNode->item;
    // start->next = (*head);
    // printf("Start val is %d\n",start->item);
    startNode = currentNode;
    while (currentNode != NULL)
    {
        printf("Current - %d\n", currentNode->item);
        push(&newCluster, currentNode->item);
        if (count == K)
        {
            if (logic == 0)
            {
                **head = *newCluster;
                logic++;
            }
            else
            {
                ListNode *CurrentCluster = *head;
                for (int i = 0; i < K - 1; i++)
                {
                    CurrentCluster = CurrentCluster->next;
                }
                CurrentCluster->next = newCluster;
            }
            start = *head;
            /* while (start != NULL)
            {
                printf("Val = %d\n", start->item);
                start = start->next;
            } */
            startNode = currentNode;
            newCluster = NULL;
            count = 0;
            elements += K;
        }
        // DONE
        // printf("StartNode %d\n",startNode->item);
        count++;
        currentNode = currentNode->next;
    }

    // Test case: 3 1 2 3 4 5 6 7 8 c
    newList = start;
    for (int i = 0; i < elements-1; i++)
    {
        printf("Newlist item = %d\n", newList->item);
        newList = newList->next;
    }
    startNode = startNode->next;
    newList->next = startNode;
    **head = *start;
    /*
    while (newCluster != NULL)
    {
        printf("New cluster - %d\n", newCluster->item);
        newCluster = newCluster->next;
    }
    */

    // This portion is to append the ending nodes that were not changed.
    /* ListNode *lastElem = *head;
    for (int i = 0; i < K - 1; i++)
    {
        printf("ELEMENTS ARE %d\n", lastElem->item);
        lastElem = lastElem->next;
    }
    startNode = startNode->next;
    printf("start node - %d\n", startNode->item);
    lastElem->next = startNode;
    printf("Total elements = %d\n", elements); */
    
    
    
    /*
    while (lastElem != NULL)
    {
        printf("ELEMENTS ADJUSTED %d\n", lastElem->item);
        lastElem = lastElem->next;
    } */
    /* for (int i = 0; i < K - 1; i++)
    {

        // printf("StartNode value %d\n",startNode->item);

        //start = startNode;
        //start = start->next;
    } */
    // Test case: 3 1 2 3 4 5 6 7 8 c
}

/* Function to push a node */
void push(ListNode **head_ref, int new_data)
{
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->item = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
