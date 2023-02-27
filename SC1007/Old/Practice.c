#include <string.h>
#include <stdio.h>

typedef struct _listnode
{
    int item;
    struct _listnode *next;
} ListNode;
typedef ListNode StackNode;
typedef ListNode QueueNode;

typedef struct _linkedlist
{
    int size;
    StackNode *head;
} LinkedList, Stack;

typedef struct _queue
{
    int size;
    QueueNode *head;
    QueueNode *tail;
} Queue;

// Prototypes of Interface functions for Stack structure
void push(Stack *sPtr, int item);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void deleteStack(Stack *sPtr);

// Prototypes of Interface functions for Queue structure
void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void deleteQueue(Queue *qPtr);