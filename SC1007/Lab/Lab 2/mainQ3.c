#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 // The limit of expression length

typedef struct _stackNode
{
    double item;
    struct _stackNode *next;
} StackNode;

typedef struct _stack
{
    int size;
    StackNode *head;
} Stack;

void push(Stack *sPtr, double item);
int pop(Stack *sPtr);
double peek(Stack s);
int isEmptyStack(Stack s);

double exePostfix(char *);

int main()
{
    char postfix[SIZE];

    printf("Enter a postfix expression:\n");
    scanf("%[^\n]%*c", postfix);

    printf("The answer is %.2lf.\n", exePostfix(postfix));

    return 0;
}

void push(Stack *sPtr, double item)
{
    StackNode *newNode;
    newNode = (StackNode *)malloc(sizeof(StackNode));
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

double peek(Stack s)
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

double exePostfix(char *postfix)
{
    // Write your code here
    Stack s;
    s.head = NULL;
    s.size = 0;

    while (*postfix != '\0')
    {
        char cur = *postfix;
        if (cur == '+' || cur == '-' || cur == '/' || cur == '*')
        {
            char opr1 = peek(s);
            pop(&s);
            char opr2 = peek(s);
            pop(&s);
            printf("%c and %c\n", opr2, opr1);
            // switch (cur)
            // {
            // case '+':
            //     push(&s, opr2 + opr1);
            //     break;
            // case '-':
            //     push(&s, opr2 - opr1);
            //     break;
            // case '/':
            //     push(&s, opr2 / opr1);
            //     break;
            // case '*':
            //     push(&s, opr2 * opr1);
            //     break;
            // default:
            //     printf("Error!");
            // }
        }
        push(&s, *postfix);
        *postfix++;
    }
    return peek(s);
}

// 987-654-/3+*+

/*
double opr1 = peek(s) - '0';
            pop(&s);
            double opr2 = peek(s) - '0';
            pop(&s);
            printf("%f and %f\n", opr2, opr1);
            switch (cur)
            {
                case '+':
                    push(&s,opr2+opr1);
                    break;
                case '-':
                    push(&s,opr2-opr1);
                    break;
                case '/':
                    push(&s,opr2/opr1);
                    break;
                case '*':
                    push(&s,opr2*opr1);
                    break;
                default:
                    printf("Error!");
            }
*/