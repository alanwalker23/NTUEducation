#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

typedef struct _queueNode
{
    BTNode *data;
    struct _queueNode *next;
} QueueNode;

typedef struct _queue
{
    int size;
    QueueNode *head;
    QueueNode *tail;
} Queue;

// Prototypes of Interface functions for Queue structure
void enqueue(Queue *qPtr, BTNode *data);
int dequeue(Queue *qPtr);
BTNode *getFront(Queue q);
int isEmptyQueue(Queue q);

BTNode *createNode(int item);
void printBTNode(BTNode *root, int space, int left);
void deleteTree(BTNode **root);

BTNode *findLargestBST(BTNode *root);

int main()
{
    BTNode *root = NULL;
    BTNode *temp = NULL;
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    int item;
    int flag = 1;
    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while (scanf("%d", &item))
    {
        if (root == NULL)
        {
            if (item != -1)
            {
                root = createNode(item);
                enqueue(&q, root);
            }
        }
        else
        {
            while (!isEmptyQueue(q))
            {
                temp = getFront(q);
                if (flag)
                {
                    if (item != -1)
                    {
                        temp->left = createNode(item);
                        enqueue(&q, temp->left);
                    }
                    flag = 0;
                    break;
                }
                else if (temp->right == NULL)
                {
                    if (item != -1)
                    {
                        temp->right = createNode(item);
                        enqueue(&q, temp->right);
                    }
                    dequeue(&q);
                    flag = 1;
                    break;
                }
                else
                    dequeue(&q);
            }
        }
    }
    scanf("%*s");
    printf("The input binary tree:\n");
    printBTNode(root, 0, 0);
    printf("\n");
    BTNode *BSTnode = findLargestBST(root);
    printf("The largest binary search subtree:\n");
    if (BSTnode)
        printBTNode(BSTnode, 0, 0);
    else
        printf("No BST\n");
    deleteTree(&root);

    return 0;
}

BTNode *createNode(int item)
{
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    node->item = item;
    node->left = node->right = NULL;
    return node;
}

void printBTNode(BTNode *root, int space, int left)
{
    if (root != NULL)
    {

        int i;
        for (i = 0; i < space - 1; i++)
            printf("|\t");

        if (i < space)
        {
            if (left == 1)
                printf("|---");
            else
                printf("|___");
        }

        printf("%d\n", root->item);

        space++;
        printBTNode(root->left, space, 1);
        printBTNode(root->right, space, 0);
    }
}

void deleteTree(BTNode **root)
{
    if (*root != NULL)
    {
        deleteTree(&((*root)->left));
        deleteTree(&((*root)->right));
        free(*root);
        *root = NULL;
    }
}
void enqueue(Queue *qPtr, BTNode *data)
{
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    newNode->data = data;
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

BTNode *getFront(Queue q)
{
    return q.head->data;
}

int isEmptyQueue(Queue q)
{
    if (q.size == 0)
        return 1;
    else
        return 0;
}

BTNode *prune(BTNode *root);
BTNode *findLargestBST(BTNode *root)
{
    if (root->left == NULL && root->right == NULL)
        return root;
    static int logic = 0;
    if (logic == 0)
    {
        logic++;
        root = prune(root);
    }
    BTNode *current = root;
    while (current->left->item == 0 || current->right->item == 0)
    {
        if (current->left->item == 0)
            current = current->right;
        if (current->right->item == 0)
            current = current->left;
    }
    return current;
}

BTNode *prune(BTNode *root)
{
    BTNode *current = root;

    // Both NULL
    if (current->left == NULL && current->right == NULL)
        return root;

    // Inproper tree
    if (current->left == NULL || current->right == NULL)
    {
        current->item = 0;
        return current;
    }

    // Check left
    if (current->left != NULL)
    {
        current->left = prune(current->left);
        printf("Left is %d current is %d\n",current->left->item,current->item);
        if (current->left->item > current->item)
        {
            current = NULL;
        }
        // if (current->right->item == 0)
        //     current = current->left;
    }
    if (current->right != NULL)
    {
        current->right = prune(current->right);
        printf("Right is %d current is %d\n",current->right->item,current->item);
        if (current->right->item < current->item)
        {
            current = NULL;
        }
        // if (current->right->item == 0)
        //     current = current->left;
    }
    return root;
}

/*
3 2 5 1 4 a
70 35 79 15 50 -1 99 18 -1 40 60 a
25 18 50 19 20 35 60 -1 15 18 25 21 40 55 70 -1 -1 -1 -1 -1 -1 25 a
*/