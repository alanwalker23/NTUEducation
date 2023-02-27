#include <stdio.h>
#include <stdlib.h>

#define MAX_N 120

typedef struct _btnode
{
    char id;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void buildTree(BTNode **node, char *preO, char *postO);
void inOrder(BTNode *cur);
void preOrder(BTNode *cur);
void postOrder(BTNode *cur);

int main()
{
    char preO[MAX_N];
    char postO[MAX_N];
    scanf("%s", preO);
    scanf("%s", postO);

    BTNode *root = NULL;
    buildTree(&root, preO, postO);
    if (root == NULL)
        printf("error\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    return 0;
}
void inOrder(BTNode *cur)
{
    if (cur == NULL)
        return;

    inOrder(cur->left);
    printf("%c", cur->id);
    inOrder(cur->right);
}
void preOrder(BTNode *cur)
{
    if (cur == NULL)
        return;

    printf("%c", cur->id);
    preOrder(cur->left);
    preOrder(cur->right);
}
void postOrder(BTNode *cur)
{
    if (cur == NULL)
        return;

    postOrder(cur->left);
    postOrder(cur->right);
    printf("%c", cur->id);
}

#include <string.h>
void buildTree(BTNode **node, char *preO, char *postO)
{
    // Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
    // Write your code here
    BTNode *root = (BTNode *)malloc(sizeof(BTNode));
    int length = strlen(preO);
    root->id = *preO;
    root->left = NULL;
    root->right = NULL;
    //printf("Current strlen of preO is %d\n", length);
    //printf("preO is %c postO is %c\n", *preO, *postO);
    //printf("Root node is %c\n", root->id);

    if (*preO == '\0' || length == 1)
    {
        *node = root;
        return;
    }

    *preO++;
    // if (length == 3)
    // {
    //     if (*preO == *postO)
    //     {
    //         printf("This works with %c and %c\n",*preO,*postO);
    //         root->left->id = *preO;
    //         *preO++;
    //         root->right->id = *preO;
    //         *node = root;
    //         printf("This works with %c and %c\n",*preO,*postO);
    //         return;
    //     }
    //     else
    //     {
    //         root->left->id = *preO;
    //         *preO++;
    //         BTNode *leftroot = (BTNode *)malloc(sizeof(BTNode));
    //         leftroot->id = *preO;
    //         leftroot->left = NULL;
    //         leftroot->right = NULL;
    //         root->left->left = leftroot;
    //         *node = root;
    //         return;
    //     }
    // }
    char leftnodehead = *preO;
    char rightnodehead = postO[length - 2];
    //printf("LNH - %c RNH - %c\n", leftnodehead, rightnodehead);

    // Size of strings
    int size = 0;
    char *temp = preO;
    if (leftnodehead == rightnodehead)
    {
        size = length - 1;
    }
    else
    {
        while (*temp != rightnodehead)
        {
            *temp++;
            size++;
        }
    }
    int rightsize = length - size - 1;
    //printf("Size of left string is %d right string %d\n", size, rightsize);
    char *leftpre = (char *)malloc(sizeof(char) * MAX_N);
    char *leftpost = (char *)malloc(sizeof(char) * MAX_N);
    char *rightpre = (char *)malloc(sizeof(char) * MAX_N);
    char *rightpost = (char *)malloc(sizeof(char) * MAX_N);
    // Populating the left string
    temp = preO;
    char *temp2 = postO;
    for (int i = 0; i < size; i++)
    {
        // printf("Temp is %c, temp2 is %c\n", *temp, *temp2);
        leftpre[i] = *temp;
        leftpost[i] = *temp2;
        *temp++;
        *temp2++;
    }
    leftpre[size] = '\0';
    leftpost[size] = '\0';
    // printf("Current temp and temp2 is %c and %c\n",*temp,*temp2);

    // Populating the right string
    for (int i = 0; i < rightsize; i++)
    {
        // printf("Temp is %c, temp2 is %c\n", *temp, *temp2);
        rightpre[i] = *temp;
        rightpost[i] = *temp2;
        *temp++;
        *temp2++;
    }
    rightpre[rightsize] = '\0';
    rightpost[rightsize] = '\0';
    //printf("leftpre is %s and leftpost is %s\n", leftpre, leftpost);
    //printf("rightpre is %s and rightpost is %s\n", rightpre, rightpost);
    // printf("Left string is %s, last char on it is %c\n", leftstring, leftstring[size - 1]);
    // printf("LNH - %c RNH - %c\n", leftnodehead, rightnodehead);
    // char *bruh = rightpre;
    // printf("Char is %c\n", *bruh);
    // while (*bruh != '\0')
    // {
    //     printf("%c ", *bruh);
    //     *bruh++;
    // }
    if (size != 0)
    {
        //printf("Building left note with %c\n\n", *leftpre);
        buildTree(&root->left, leftpre, leftpost);
    }
    if (rightsize != 0)
    {
        //printf("Building right note with %c\n\n", *rightpre);
        buildTree(&root->right, rightpre, rightpost);
    }
    *node = root;
    return;
}

/*
124567389ABC
56472BCA9831

Out
124567389ABC
56472BCA9831
546271BAC983
*/