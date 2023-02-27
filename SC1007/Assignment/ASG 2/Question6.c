#include <stdio.h>
#include <stdlib.h>

typedef struct _dbllistnode
{
	int item;
	struct _dbllistnode *next;
	struct _dbllistnode *pre;
} CDblListNode;

typedef struct _dbllinkedlist
{
	int size;
	CDblListNode *head;
} CDblLinkedList;

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value);
void deleteList(CDblLinkedList *ptrCDLL);
void printList(CDblLinkedList CDLL);

int numMountainPairs(CDblLinkedList CDLL);

int main()
{
	CDblLinkedList himalayas;
	himalayas.head = NULL;
	himalayas.size = 0;

	int item;
	int i, cases;
	int numP;
	scanf("%d", &cases);
	for (i = 0; i < cases; i++)
	{
		while (scanf("%d", &item))
			insertNode_AtFront(&himalayas, item);
		scanf("%*s");

		numP = numMountainPairs(himalayas);
		printList(himalayas);
		printf("%d Pairs.\n", numP);

		deleteList(&himalayas);
	}
	return 0;
}

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value)
{
	// create a new node
	CDblListNode *newNode;
	newNode = (CDblListNode *)malloc(sizeof(CDblListNode));
	newNode->item = value;

	if (ptrCDLL->size == 0) // first node
	{
		newNode->next = newNode;
		newNode->pre = newNode;
		ptrCDLL->head = newNode;
	}
	else
	{
		newNode->next = ptrCDLL->head;
		newNode->pre = ptrCDLL->head->pre;

		newNode->pre->next = newNode; // update last node next link;
		ptrCDLL->head->pre = newNode;

		ptrCDLL->head = newNode;
	}
	ptrCDLL->size++;
}

void printList(CDblLinkedList CDLL)
{

	if (CDLL.head == NULL)
		return;

	CDblListNode *temp = CDLL.head;
	printf("Current List: ");

	while (temp->next != CDLL.head)
	{
		printf("%d ", temp->item);
		temp = temp->next;
	}
	printf("%d\n", temp->item);
}

void deleteList(CDblLinkedList *ptrCDLL)
{
	if (ptrCDLL->head == NULL)
		return;
	CDblListNode *cur = ptrCDLL->head;
	CDblListNode *temp;

	while (cur->next != ptrCDLL->head)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}

	free(cur);
	ptrCDLL->head = NULL;
	ptrCDLL->size = 0;
}

int mutual(CDblListNode *node);
int redundant(CDblListNode *check);
int numMountainPairs(CDblLinkedList CDLL)
{
	// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
	// Write your code here
	// printf("CDLL size is %d\n",CDLL.size);
	if (CDLL.size < 2)
		return 0;
	if (CDLL.size == 2)
		return 1;
	int pairs = CDLL.size;
	int dups = 0;
	CDblListNode *current = CDLL.head;
	for (int i = 0; i < CDLL.size; i++)
	{
		pairs += mutual(current);
		dups += redundant(current);
		current = current->next;
	}
	// printf("Dups found %d\n", dups);
	dups /= 2;
	pairs -= dups;
	return pairs;
}

int mutual(CDblListNode *start)
{
	// Return 1 if possible to pair, else 0.
	int possible = 0;
	int pairs = 0;
	CDblListNode *current = start;
	// printf("\nStart at %d\n", current->item);
	CDblListNode *left = start->pre;
	CDblListNode *right = start->next;
	current = current->next;
	while (current != start)
	{
		if (current == left)
		{
			current = current->next;
			continue;
		}
		else if (current == right)
		{
			current = current->next;
			continue;
		}
		else if (current->item < start->item)
		{
			current = current->next;
			continue;
		}
		// The only variables that can enter is when current >= start
		// Start 2, currently 4. 4 is bigger than 2 so need to see if can reach
		// Need to go left/right till current == start
		// If possible to reach start, possible +1.
		// Swing right first
		CDblListNode *temp = start;
		while (temp != current)
		{
			if (temp->next == current)
			{
				// printf("Left Pair is %d and %d\n", start->item, current->item);
				possible++;
				break;
			}
			else if (start->item >= temp->next->item)
				temp = temp->next;
			else
			{
				break;
			}
		}
		// Swing left this time, check if possible alr done
		if (possible == 0)
		{
			temp = start;
			while (temp != current)
			{
				if (temp->pre == current)
				{
					// printf("Right Pair is %d and %d\n", start->item, current->item);
					possible++;
					break;
				}
				else if (start->item >= temp->pre->item)
					temp = temp->pre;
				else
					break;
			}
		}
		if (possible != 0)
		{
			possible = 0;
			pairs += 1;
		}
		// printf("Current item %d\n", current->item);
		current = current->next;
	}
	// printf("Last item before head is %d\n", current->pre->item);
	// printf("Pairs found with %d is %d\n", start->item, pairs);
	return pairs;
}

int redundant(CDblListNode *check)
{
	int duplicates = 0;
	CDblListNode *current = check;
	CDblListNode *left = check->pre;
	CDblListNode *right = check->next;
	current = current->next;
	while (current != check)
	{
		if (current == left)
		{
			current = current->next;
			continue;
		}
		else if (current == right)
		{
			current = current->next;
			continue;
		}
		if (current->item == check->item)
		{
			if (mutual(current) != 0)
			{
				// printf("Duplicate found %d\n", check->item);
				duplicates++;
			}
		}
		current = current->next;
	}
	return duplicates;
}

/*
//
1 2 3 4 5 a --> 7 pairs
5 2 2 4 3 a --> 8 pairs
5 4 4 4 3 2 1 5 1 a --> 18 pairs
4 2 5 6 2 1 5 a --> 11 pairs
5 4 6 6 4 a --> 7 pairs
5 4 6 6 6 4 a --> 9 pairs
*/