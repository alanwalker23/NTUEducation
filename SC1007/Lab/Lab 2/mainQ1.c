#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _listnode
{
    char item;
    struct _listnode *next;
} ListNode;
typedef ListNode StackNode;
typedef ListNode QueueNode;

typedef struct _linkedlist
{
    int size;
    ListNode *head;
} Stack;

typedef struct _queue
{
    int size;
    ListNode *head;
    ListNode *tail;
} Queue;

// Prototypes of Interface functions for Stack structure
void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);
void deleteStack(Stack *sPtr);

// Prototypes of Interface functions for Queue structure
void enqueue(Queue *qPtr, char item);
int dequeue(Queue *qPtr);
char getFront(Queue q);
int isEmptyQueue(Queue q);
void deleteQueue(Queue *qPtr);

int palindrome(Queue *wordPtr);

int main()
{
    char item;
    Queue word;
    word.head = NULL;
    word.tail = NULL;
    word.size = 0;

    printf("Enter a string of characters, terminated by a newline:\n");
    while (1)
    {
        scanf("%c", &item);
        if (item == '\n')
            break;
        enqueue(&word, item);
    }

    printf("The string is ");
    printf("%s", palindrome(&word) ? "" : "not ");
    printf("a palindrome.\n");

    return 0;
}

void push(Stack *sPtr, char item)
{
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if (sPtr == NULL || sPtr->head == NULL)
    {
        return 0;
    }
    else
    {
        StackNode *temp = sPtr->head;
        sPtr->head = sPtr->head->next;
        free(temp);
        sPtr->size--;
        return 1;
    }
}

char peek(Stack s)
{
    return s.head->item;
}

int isEmptyStack(Stack s)
{
    if (s.size == 0)
        return 1;
    else
        return 0;
}

void deleteStack(Stack *sPtr)
{
    while (pop(sPtr))
        ;
}

void enqueue(Queue *qPtr, char item)
{
    QueueNode *newNode;
    newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->item = item;
    newNode->next = NULL;

    if (isEmptyQueue(*qPtr))
        qPtr->head = newNode;
    else
        qPtr->tail->next = newNode; // Can see it is sinkly linked

    qPtr->tail = newNode; // Change pointer of tail to newest node
    qPtr->size++;
}

int dequeue(Queue *qPtr)
{
    if (qPtr == NULL || qPtr->head == NULL)
    { // Queue is empty or NULL pointer
        return 0;
    }
    else
    {
        QueueNode *temp = qPtr->head;
        qPtr->head = qPtr->head->next;
        if (qPtr->head == NULL) // Queue is emptied
            qPtr->tail = NULL;

        free(temp);
        qPtr->size--;
        return 1;
    }
}

char getFront(Queue q)
{
    return q.head->item;
}

int isEmptyQueue(Queue q)
{
    if (q.size == 0)
        return 1;
    else
        return 0;
}
void deleteQueue(Queue *qPtr)
{
    while (dequeue(qPtr))
        ;
}

int palindrome(Queue *wordPtr)
{
    // Write your code here
    printf("\n");
    ListNode *cur = wordPtr->head;
    Stack checkList;
    checkList.head = NULL;
    checkList.size = 0;
    int logic = 0;
    int count = 0;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    cur = wordPtr->head;
    int half = count / 2;
    for (int i = 0; i < half; i++)
    {
        printf("ITEM IS %c\n",cur->item);
        push(&checkList,cur->item);
        cur = cur->next;
    }
    if (count % 2 != 0) // even
    {
        printf("Current value is %c\n",cur->item);
        cur = cur->next;
        printf("Changed to %c\n",cur->item);
    }
        
    ListNode *compare;
    compare = checkList.head;
    while (cur!=NULL)
    {
        if(cur->item!=compare->item)
            return 0;
        printf("Cur - %c\n",cur->item);
        cur = cur->next;
        printf("Compare - %c\n",compare->item);
        compare = compare->next;
    }
    logic=1;
    //printf("Current elem is %c\n", cur->next->item);
    printf("Count is %d\nLogic is %d\n", count,logic);
    return logic;
}
