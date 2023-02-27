#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* n)
{
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL; //Terminate the linked list (ends here)

    printList(head);
    return 0;
}


/*
#From Slides
struct _listnode
{
    int item;
    struct _listnode *next;
};
typedef struct _listnode ListNode;
int main(void)
{
    // static node
    ListNode static_node;
    static_node.data = 50;
    static_node.next = NULL;
    // dynamic node
    ListNode *dynamic_node = (ListNode *)malloc(sizeof(ListNode));
    dynamic_node->data = 50;
    dynamic_node->next = NULL;
    free(dynamic_node);
    return 0;
}
*/