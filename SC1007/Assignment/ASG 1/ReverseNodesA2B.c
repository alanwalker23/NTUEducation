#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    float item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);
void push(ListNode **head_ref, float new_data);
ListNode *reverseSegment(ListNode* head, int start, int end);

int main()
{
    ListNode *head = NULL, *temp;
	float f = 0.0;
	int S, E;

	scanf("%d %d",&S, &E);

	while (scanf("%f", &f)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = f;
	}
	temp->next = NULL;

	head = reverseSegment(head,S,E);
	printList(head);
	deleteList(&head);
	return 0;

}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%.2f ",head->item);
        head = head->next;
    }
    printf("\n");
}

void deleteList(ListNode **ptrHead){
    ListNode *cur = *ptrHead;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	*ptrHead=NULL;
}

ListNode *reverseSegment(ListNode* head, int start, int end)
{
// Write your code here
	if (start>end || end<start)
		return head;
	if (end==0 || end==start)
		return head;
	int check = 0;
    ListNode *quick = head;
    while (quick!=NULL)
    {
        check++;
        quick=quick->next;
    }
    //printf("Total elements is %d\n",check);
    if (end>=check || start>=check)
	{
        return head;
	}
	int count = 0;
    int logic = 0;
    int reversedElems = 0;
    int totalElems = 0;
    ListNode *current = head;
    ListNode *stop = NULL;
    ListNode *resume = NULL;
    ListNode *newList = NULL;
    ListNode *revList = NULL;
    while (current != NULL)
    {
        if (count == start)
        {
            logic += 1;
            stop = current;
            //printf("Stop at %f\n",stop->item);
        }
            
        if (count == end+1)
        {
            logic -= 1;
            resume = current;
            //printf("Resumed at %f\n",resume->item);
        }
            
        if (logic == 1)
        {
            push(&revList, current->item);
            reversedElems++;
        }
        //printf("Current value is %.2f\n", current->item);
        current = current->next;
        count++;
        totalElems++;
    }
    //If reversedElem == totalElem, return reversedlink.
    if (reversedElems==totalElems)
    {
        return revList;
    }

    /* ///FOR CHECKING!!!
    ListNode *checkRev = revList;
    while (checkRev!=NULL)
    {
        printf("Checkrev item %f\n",checkRev->item);
        checkRev = checkRev->next;
    } */
    //Add remaining elements from resume point
    ListNode *startNode = head;
    while (startNode!=NULL)
    {
        if (startNode==resume)
        {
            ListNode *addBehind = revList;
            while (addBehind->next!=NULL)
            {
                addBehind = addBehind->next;
            }
            addBehind->next = startNode;
        }
        startNode = startNode->next;
    }
    if (start==0)
        return revList;
    
    startNode = head;
    ListNode *addinf = revList;
    ListNode *nextNode = NULL;
    while (startNode!=NULL)
    {
        nextNode = startNode->next;
        //printf("Start from %f\n",startNode->item);
        if (nextNode==stop)
        {
            //printf("Insert behind %f\n",startNode->item);
            startNode->next = NULL;
            startNode->next = addinf;
            break;
        }
        startNode = startNode->next;
    }
    //printf("Total element is %d\nTotal reversed is %d\n",totalElems,reversedElems);
    /* while (head!=NULL)
    {
        printf("ReverseList has %.2f\n",head->item);
        head = head->next;
    }  */
    return head;
}


void push(ListNode **head_ref, float new_data)
{
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->item = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//TestCodes 2 4 1.1 1.2 1.3 1.4 1.5 1.6 c