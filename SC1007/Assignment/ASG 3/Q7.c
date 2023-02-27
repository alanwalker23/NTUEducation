#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode
{
    int nodeV;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

typedef struct _queuenode
{
    BTNode *node;
    struct _queuenode *next;
} QueueNode;

typedef struct _queue
{
    int size;
    QueueNode *head;
    QueueNode *tail;
} Queue;

void printBTNode(BTNode *root, int space, int left);
// Prototypes of Interface functions for Queue structure
void enqueue(Queue *qPtr, BTNode *node);
int dequeue(Queue *qPtr);
BTNode *getFront(Queue q);
int isEmptyQueue(Queue q);

int twoNodesCost(BTNode *node, int nodeV1, int nodeV2);

int main()
{
    BTNode *root = (BTNode *)malloc(sizeof(BTNode));

    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    BTNode *node;
    enqueue(&q, root);

    int nodeV;
    char opL, opR;

    while (!isEmptyQueue(q))
    {
        scanf("%d %c %c", &nodeV, &opL, &opR);
        node = getFront(q);
        dequeue(&q);
        node->nodeV = nodeV;

        if (opL != '@')
        {
            node->left = (BTNode *)malloc(sizeof(BTNode));
            enqueue(&q, node->left);
        }
        else
            node->left = NULL;
        if (opR != '@')
        {
            node->right = (BTNode *)malloc(sizeof(BTNode));
            enqueue(&q, node->right);
        }
        else
            node->right = NULL;
    }

    int v1, v2;
    scanf("%d %d", &v1, &v2);
    int cost = twoNodesCost(root, v1, v2);

    printBTNode(root, 0, 0);

    printf("Distance is %d\n", cost);
    return 0;
}

void enqueue(Queue *qPtr, BTNode *node)
{
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    newNode->node = node;
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
    return q.head->node;
}

int isEmptyQueue(Queue q)
{
    if (q.size == 0)
        return 1;
    else
        return 0;
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

        printf("%d\n", root->nodeV);

        space++;
        printBTNode(root->left, space, 1);
        printBTNode(root->right, space, 0);
    }
}

BTNode *findLCA(BTNode *root, int n1, int n2);
int twoNodesCost(BTNode *node, int nodeV1, int nodeV2)
{
    // Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
    // Write your code here
    if (nodeV1 == nodeV2)
        return nodeV1;

    //static int logic = 0;
    int value = 0;
    printf("Node value is %d and ", node->nodeV);
    printf("value is %d\n", value);
    static int logic = 0;
    BTNode *temp;
    if (logic==0)
        temp = findLCA(node,nodeV1,nodeV2);
    logic++;
    if (temp->nodeV == nodeV1 || temp->nodeV == nodeV2)
    {
        printf("Value is increased by %d\n", temp->nodeV);
        value += temp->nodeV;
        // if (logic == 0)
        //     logic+=1;
        // else
        return value;
    }
    if (node->left != NULL)
        value += twoNodesCost(node->left, nodeV1, nodeV2);

    if (node->right != NULL)
        value += twoNodesCost(node->right, nodeV1, nodeV2);

    if (value != 0)
    {
        value += temp->nodeV;
        printf("Value is increased by %d\n", temp->nodeV);
    }

    return value;
}

//What if I added LCA and just subtract the path on route
//Currently returns when 1 is found, not both. Mayb static to track if both found?
/*
1 a a
2 a a
3 a @
4 a a
7 @ @
8 a @
5 @ @
6 @ @
9 @ @
5 7
*/

BTNode *findLCA(BTNode *root, int n1, int n2)
{

    /* Base Condition */
    if (root == NULL)
    {
        return NULL;
    }

    /* if root is equal to either n1 and n2 then root is LCA. */
    if (root->nodeV == n1 || root->nodeV == n2)
    {
        return root;
    }
    else
    {
        /* Search for LCA in left sub tree  */
        BTNode *left = findLCA(root->left, n1, n2);
        /* Search for LCA in right sub tree  */
        BTNode *right = findLCA(root->right, n1, n2);

        /* If one node is found in left sub tree and another in
         right sub tree than root is Least common ancestor */
        if (left && right)
        {
            return root;
        }
        /* If both nodes are in left sub tree
         that left is the lca  otherwise right */
        if (left)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}