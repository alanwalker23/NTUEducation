#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200 // The number digit limitation

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode; // You should not change the definition of BTNode

typedef struct _node
{
    BTNode *item;
    struct _node *next;
} StackNode;

typedef struct _stack
{
    int size;
    StackNode *head;
} Stack;

void deleteTree(BTNode **root);

void createExpTree(BTNode **root, char *prefix);
void printTree(BTNode *node);
void printTreePostfix(BTNode *node);
double computeTree(BTNode *node);

void push(Stack *sPtr, BTNode *item);
int pop(Stack *sPtr);
BTNode *peek(Stack s);
int isEmptyStack(Stack s);

int main()
{
    char prefix[SIZE];
    BTNode *root = NULL;

    // printf("Enter an prefix expression:\n");
    gets(prefix);

    createExpTree(&root, prefix);

    // printf("The Infix Expression:\n");
    printTree(root);
    printf("\n");
    // printf("The Postfix (Reverse Polish) Expression:\n");
    printTreePostfix(root);
    printf("\n");
    // printf("Answer ");
    printf("%.2f\n", computeTree(root));
    deleteTree(&root);
    return 0;
}

void push(Stack *sPtr, BTNode *item)
{
    // printf("Item added is %d\n", item->item);
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

BTNode *peek(Stack s)
{
    // printf("Item is %d\n",s.head->item->item);
    return s.head->item;
}

int isEmptyStack(Stack s)
{
    if (s.size == 0)
        return 1;
    else
        return 0;
}

void deleteTree(BTNode **root)
{
    BTNode *temp;
    if (*root != NULL)
    {
        temp = (*root)->right;
        deleteTree(&((*root)->left));
        free(*root);
        *root = NULL;
        deleteTree(&temp);
    }
}

void createExpTree(BTNode **root, char *prefix)
{
    // Write your code here
    // Take prefix, convert to infix and postfix
    Stack operands;
    operands.head = NULL;
    operands.size = 0;
    int length = strlen(prefix);
    if (length == 0)
        return;
    int num = 0;
    int place = 1;
    for (int i = length - 1; i >= 0; i--)
    {
        if (prefix[i] >= '0' && prefix[i] <= '9')
        {
            int newDigit = 0;
            char c = prefix[i];
            sscanf(&c, "%d", &newDigit);
            newDigit *= place;
            place *= 10;
            num += newDigit;
        }
        else
        {
            if (num != 0)
            {
                // printf("Number is %d\n", num);
                BTNode *newNode = (BTNode *)malloc(sizeof(BTNode));
                newNode->item = num;
                newNode->left = NULL;
                newNode->right = NULL;
                // printf("newnode num is %d\n",newNode->item);
                // printf("Operand size is %d\n", operands.size);
                push(&operands, newNode);
                // printf("Operand size is %d\n", operands.size);
                // printf("newnode num is %d\n", newNode->item);
                BTNode *check = peek(operands);
                // printf("All values of BTNode check is %d %p %p\n", check->item, check->left, check->right);
                place = 1;
                num = 0;
            }
            if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/')
            {
                BTNode *operator=(BTNode *) malloc(sizeof(BTNode));
                int value = (int)prefix[i]; // Below 48 ASCII value = operator
                operator->item = value;
                operator->left = peek(operands);
                pop(&operands);
                operator->right = peek(operands);
                pop(&operands);
                push(&operands, operator);
            }
        }
    }

    // To view the tree created
    BTNode *check = operands.head->item;
    // printf("Root is %d\n", check->item);
    // printf("Left is %d\n", check->left->item);
    // printf("Right is %d\n",check->right->item);
    // BTNode *final = operands.head->item;
    // **root = *final;
    // printTree(check);
    // putchar('\n');
    // printTreePostfix(check);
    *root = check;
}

void printTree(BTNode *node)
{
    // Write your code here
    if (node == NULL)
        return;
    else
    {
        printTree(node->left);
        if(node->left==NULL && node->right==NULL)
            printf("%d ", node->item);
        else
            printf("%c ", node->item);
        printTree(node->right);
    }
}

void printTreePostfix(BTNode *node)
{
    // Write your code here
    if (node == NULL)
    {
        return;
    }
    else
    {
        printTreePostfix(node->left);
        printTreePostfix(node->right);
        if(node->left==NULL && node->right==NULL)
            printf("%d ", node->item);
        else
            printf("%c ", node->item);
    }
}

double eval(double first, double second, int op)
{
    char op_char = (char)op;
    if (op_char == '*')
        return first * second;
    if (op_char == '/')
        return first / second;
    if (op_char == '+')
        return first + second;
    if (op_char == '-')
        return first - second;
}

double computeTree(BTNode *node)
{
    // Write your code here
    // Given the tree, find output value
    if (node->left == NULL && node->right == NULL)
        return node->item;
    return eval(computeTree(node->left), computeTree(node->right), node->item);
}
