#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

BTNode *insertBTNode(BTNode *cur, int item);
void printBTNode(BTNode *root, int space, int left);
void deleteTree(BTNode **root);

int hasGreatGrandchild(BTNode *node);

int main()
{
    BTNode *root = NULL;
    int item;

    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while (scanf("%d", &item))
        root = insertBTNode(root, item);
    scanf("%*s");

    printf("The Binary Tree:\n");
    printBTNode(root, 0, 0);

    printf("The node(s) with great grandchild:\n");
    hasGreatGrandchild(root);
    printf("\n");

    deleteTree(&root);
    root = NULL;
    return 0;
}

BTNode *insertBTNode(BTNode *cur, int item)
{
    if (cur == NULL)
    {
        BTNode *node = (BTNode *)malloc(sizeof(BTNode));
        node->item = item;
        node->left = node->right = NULL;
        return node;
    }
    if (rand() % 2)
        cur->left = insertBTNode(cur->left, item);
    else
        cur->right = insertBTNode(cur->right, item);

    return cur;
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

int hasGreatGrandchild(BTNode *node)
{
    int l, r;

    // Calculate the height of each node in the tree
    // Print out (data stored in) node that has height > n

    if (node == NULL)
        return 0;

    l = hasGreatGrandchild(node->left);
    r = hasGreatGrandchild(node->right);
    printf("Current node %d left %d right %d\n",node->item,l,r);
    if (r > 2 || l > 2)
        printf("%d ", node->item);

    return l > r ? (l + 1) : (r + 1);
}

/*
70 31 93 14 73 94 7 23 67 99 25 43 56 88 77 95 a
*/