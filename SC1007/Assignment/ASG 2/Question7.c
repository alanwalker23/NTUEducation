#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

enum ExpType
{
    OPT,
    OPERAND
};

typedef struct _queueNode
{
    int item;
    enum ExpType type;
    struct _queueNode *next;
} QueueNode;

typedef struct _queue
{
    int size;
    QueueNode *head;
    QueueNode *tail;
} Queue;

void enqueue(Queue *qptr, int item, enum ExpType type);
int dequeue(Queue *qPtr);
QueueNode *getFront(Queue q);
int isEmptyQueue(Queue q);

void expressionQ(char *infix, Queue *qPtr);
void printExpQ(Queue *qPtr);

int main()
{
    char infix[SIZE];
    scanf("%[^\n]%*c", infix);

    Queue inExpQ;
    inExpQ.head = NULL;
    inExpQ.tail = NULL;
    inExpQ.size = 0;

    expressionQ(infix, &inExpQ);
    printf("Output:\n");
    printExpQ(&inExpQ);

    return 0;
}

void enqueue(Queue *qPtr, int item, enum ExpType type)
{
    QueueNode *newNode;
    newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->item = item;
    newNode->type = type;
    newNode->next = NULL;

    if (isEmptyQueue(*qPtr))
        qPtr->head = newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}
int dequeue(Queue *qPtr)
{
    if (qPtr == NULL || qPtr->head == NULL)
        return 0;
    else
    {
        QueueNode *temp = qPtr->head;
        qPtr->head = qPtr->head->next;

        if (qPtr->head == NULL)
            qPtr->tail = NULL;

        free(temp);
        qPtr->size--;
        return 1;
    }
}

QueueNode *getFront(Queue q)
{
    return q.head;
}

int isEmptyQueue(Queue q)
{
    if (q.size == 0)
        return 1;
    else
        return 0;
}

void printExpQ(Queue *qPtr)
{
    if (qPtr == NULL)
        return;

    QueueNode *temp = NULL;
    temp = getFront(*qPtr);

    while (temp != NULL)
    {
        if (temp->type == OPERAND)
            printf(" %d ", temp->item);
        else
            printf(" %c ", (char)(temp->item));
        dequeue(qPtr);
        temp = getFront(*qPtr);
    }
    printf("\n");
}

void expressionQ(char *infix, Queue *qPtr)
{
    // Write your code here
    char *string = infix;
    int size = strlen(string);
    // printf("Size is %d\n",size);
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        // printf("Current element is %c\n", string[i]);
        if (string[i] >= '0' && string[i] <= '9')
        {
            num *= 10;
            int newDigit = 0;
            char c = string[i];
            sscanf(&c, "%d", &newDigit);
            num += newDigit;
        }
        else
        {
            if (num != 0)
            {
                printf("Num is %d\n", num);
                enqueue(qPtr, num, OPERAND);
                num = 0;
            }
            enqueue(qPtr, string[i], OPT);
        }
    }
    if (num != 0)
    {
        printf("Num is %d\n", num);
        enqueue(qPtr, num, OPERAND);
        num = 0;
    }
}