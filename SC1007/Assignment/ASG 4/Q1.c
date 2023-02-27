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

BTNode *findLargestBST(BTNode *root)
{
    // Write your code here
    BTNode *Current = root;
    Queue allNodes;
    allNodes.head = NULL;
    allNodes.tail = NULL;
    allNodes.size = 0;
    enqueue(&allNodes, Current);

    Queue bigTree;
    bigTree.head = NULL;
    bigTree.tail = NULL;
    bigTree.size = 0;

    Queue deadTrees;
    deadTrees.head = NULL;
    deadTrees.tail = NULL;
    deadTrees.size = 0;

    Queue removeTrees;
    removeTrees.head = NULL;
    removeTrees.tail = NULL;
    removeTrees.size = 0;
    while (!isEmptyQueue(allNodes))
    {
        BTNode *cur = getFront(allNodes);
        printf("Node in queue is %d\n", cur->item);
        if (cur->left != NULL && cur->right != NULL)
        {
            enqueue(&bigTree, cur->left);
            enqueue(&bigTree, cur);
            enqueue(&bigTree, cur->right);
        }
        if (cur->left != NULL)
            enqueue(&allNodes, cur->left);
        if (cur->right != NULL)
            enqueue(&allNodes, cur->right);
        // Dead trees
        if (cur->left != NULL && cur->right == NULL)
            enqueue(&deadTrees, cur);
        if (cur->left == NULL && cur->right != NULL)
            enqueue(&deadTrees, cur);
        dequeue(&allNodes);
    }
    // while (!isEmptyQueue(bigTree))
    // {
    //     BTNode *check = getFront(bigTree);
    //     printf("Node in last queue is %d\n", check->item);
    //     dequeue(&bigTree);
    // }

    // Cull trees that are not BST
    while (!isEmptyQueue(deadTrees))
    {
        BTNode *dead = getFront(deadTrees);
        //printf("Node in dead queue is %d\n", dead->item);
        int logic = 1;
        int remove = 0;
        int position = -1;
        QueueNode *traverse = bigTree.head;
        QueueNode *lastNode = bigTree.tail;
        while (traverse != NULL)
        {
            position++;
            if (logic == 4)
                logic = 1;
            BTNode *inside = traverse->data;
            //printf("Value is %d\n", inside->item);
            if (remove != 0)
            {
                remove--;
                enqueue(&removeTrees, inside);
            }
            if (inside->item == dead->item)
            {
                // Found at end
                if (logic == 3)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        int times = -1;
                        QueueNode *remove = bigTree.head;
                        while (remove != NULL)
                        {
                            BTNode *insider = remove->data;
                            times++;
                            //printf("Time is %d, position is %d\n", times, position - 2 + i);
                            if (times == (position - 2 + i))
                            {
                                //printf("Added %d to removeTree\n",insider->item);
                                enqueue(&removeTrees, insider);
                            }
                            remove = remove->next;
                        }
                    }
                }
                if (logic == 1)
                {
                    enqueue(&removeTrees, inside);
                    remove = 2;
                }
                //printf("Found at %d\n", logic);
            }
            logic++;
            traverse = traverse->next;
        }
        dequeue(&deadTrees);
    }

    while (!isEmptyQueue(removeTrees))
    {
        BTNode *check = getFront(removeTrees);
        printf("Node in remove queue is %d\n", check->item);
        dequeue(&removeTrees);
    }

    while (!isEmptyQueue(bigTree))
    {
        BTNode *check = getFront(bigTree);
        printf("Node in last queue is %d\n", check->item);
        dequeue(&bigTree);
    }

    // // Ending
    // BTNode *check = getFront(bigTree);
    // return check;
}

/*
70 35 79 15 50 -1 99 18 -1 40 60 a
25 18 50 19 20 35 60 -1 15 18 25 21 40 55 70 -1 -1 -1 -1 -1 -1 25 a
*/