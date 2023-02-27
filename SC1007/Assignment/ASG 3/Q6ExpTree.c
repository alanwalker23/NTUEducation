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
    //Test push pop and peek
    
    Stack s;
    s.head = NULL;
    s.size = 0;
    
    BTNode *new1 = (BTNode *)malloc(sizeof(BTNode));
    printf("Hello1");
    int num = 5;
    new1->item = num;
    printf("Hello0");
    
    
    new1->left = NULL;
    new1->right = NULL;
    
    BTNode *new2 = (BTNode *)malloc(sizeof(BTNode));
    new2->item = 3;
    new2->left = NULL;
    new2->right = NULL;
    printf("Hello2");
    BTNode *new = (BTNode *)malloc(sizeof(BTNode));
    new->item = 1;
    new->left = new1;
    new->right = new2;
    printf("Hello3");
    printf("NewNode added has value %d address %p\n",new->item,new);
    printf("NewNode added has left value %d address %p\n",new->left->item,new->left);
    printf("NewNode added has right %d address %p\n",new->right->item,new->right);

    push(&s,new);
    BTNode *check = peek(s);
    printf("Check values are %d %p %p\n",check->item,check->left,check->right);
}

void printTree(BTNode *node)
{
    // Write your code here
}

void printTreePostfix(BTNode *node)
{
    // Write your code here
}

double computeTree(BTNode *node)
{
    // Write your code here
}
