#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 // The size of the array

enum ExpType
{
    OPT,
    OPERAND
};

typedef struct _stackNode
{
    char item;
    struct _stackNode *next;
} StackNode;

typedef struct _stack
{
    int size;
    StackNode *head;
} Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

typedef struct _listnode
{
    int item;
    enum ExpType type;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist
{
    int size;
    ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item, enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList(LinkedList ll);

void in2PreLL(char *infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExp);

int main()
{
    char infix[SIZE];

    // printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c", infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    in2PreLL(infix, &inExpLL);

    printExpLL(inExpLL);

    removeAllNodes(&inExpLL);
    return 0;
}

void printExpLL(LinkedList inExpLL)
{
    ListNode *temp = NULL;
    temp = inExpLL.head;
    while (temp != NULL)
    {
        if (temp->type == OPERAND)
            printf(" %d ", temp->item);
        else
            printf(" %c ", (char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type)
{
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if (newNode == NULL)
        exit(0);

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head = newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr)
{
    if (LLPtr == NULL || LLPtr->size == 0)
    {
        return 0;
    }
    else
    {
        ListNode *temp = LLPtr->head;
        LLPtr->head = LLPtr->head->next;

        free(temp);
        LLPtr->size--;
        return 1;
    }
}

int isEmptyLinkedList(LinkedList ll)
{
    if (ll.size == 0)
        return 1;
    else
        return 0;
}

void removeAllNodes(LinkedList *LLPtr)
{
    while (deleteNode(LLPtr))
        ;
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

int Priority(char c);
void in2PreLL(char *infix, LinkedList *inExpLL)
{
    // Write your code here
    //  Write your code here
    //  Reverse all elements
    LinkedList Elements;
    Elements.head = NULL;
    Elements.size = 0;
    int i = 0;
    int num = 0;
    // infix = "(1-2/3)*(1/5-7)";
    // infix = "12((2+1)(3+1))";
    //  To hit +  1212  *  /  *  -  2134  -  2345  89  7890  5676  4568;
    //  infix = "99+(88-77)*(66/(55-44)+33)";
    //  To hit  +  99  *  -  88  77  +  /  66  -  55  44  33
    char *string = infix;
    while (string[i] != '\0')
    {
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
                insertNode(&Elements, num, OPERAND);
                num = 0;
            }
            if (string[i] != ' ')
                insertNode(&Elements, string[i], OPT);
        }
        i++;
    }
    if (num != 0) // Add last number
    {
        insertNode(&Elements, num, OPERAND);
        num = 0;
    }

    LinkedList Final;
    Final.head = NULL;
    Final.size = 0;
    Stack Operators;
    Operators.head = NULL;
    Operators.size = 0;
    ListNode *current = Elements.head;
    while (current != NULL)
    {
        if (current->type == OPERAND)
        {
            insertNode(&Final, current->item, OPERAND);
        }
        else
        {
            if (current->item == ')')
                push(&Operators, current->item);
            else if (current->item == '(')
            {
                while (!isEmptyStack(Operators) && peek(Operators) != ')')
                {
                    insertNode(&Final, peek(Operators), OPT);
                    pop(&Operators);
                }
                pop(&Operators); // Remove leftover bracket
            }
            else
            {
                while (!isEmptyStack(Operators) && Priority(current->item) < Priority(peek(Operators)))
                {
                    insertNode(&Final, peek(Operators), OPT);
                    pop(&Operators);
                }
                push(&Operators, current->item);
            }
        }
        current = current->next;

        // // Check Operator list
        // StackNode *cstack = Operators.head;
        // printf("Items in stack: ");
        // while (cstack != NULL)
        // {
        // 	printf("%c", cstack->item);
        // 	cstack = cstack->next;
        // }
        // putchar('\n');
    }
    while (!isEmptyStack(Operators))
    {
        insertNode(&Final, peek(Operators), OPT);
        pop(&Operators);
    }

    // //Checking
    // ListNode *check = Final.head;
    // while (check!=NULL)
    // {
    // 	printf("%d   ",check->type);
    // 	check = check->next;
    // }
    *inExpLL = Final;
}

int Priority(char c)
{
    // Lowest -,+,*,/,() Highest
    int value = 0;
    if (c == '-' || c == '+')
        value = 1;
    else if (c == '*' || c == '/')
        value = 2;
    else
        value = -1;
    return value;
}
//99+(88-77)*(66/(55-44)+33)