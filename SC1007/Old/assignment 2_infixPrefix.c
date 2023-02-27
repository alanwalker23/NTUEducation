#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000 //The size of the array

enum ExpType {OPT,OPERAND};

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

typedef struct _listnode
{
    int  item;
    enum ExpType type;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item,enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);


void in2PreLL(char* infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExp);

#include <strings.h>
int main()
{
    char infix[SIZE];

    //printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c",infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;


    in2PreLL(infix, &inExpLL);

    printExpLL(inExpLL);

    removeAllNodes(&inExpLL);
    return 0;
}

void printExpLL(LinkedList inExpLL)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    while(temp!= NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item);
        else
            printf(" %c ",(char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if(newNode==NULL) exit(0);

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head=newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr) {
    if(LLPtr==NULL || LLPtr->size==0){
        return 0;
    }
    else{
       ListNode *temp = LLPtr->head;
       LLPtr->head = LLPtr->head->next;

       free(temp);
       LLPtr->size--;
       return 1;
    }
}

int isEmptyLinkedList (LinkedList ll) {
    if(ll.size==0) return 1;
    else return 0;
}

void removeAllNodes(LinkedList *LLPtr)
{
	while(deleteNode(LLPtr));
}

void push(Stack *sPtr, char item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}


void in2PreLL(char* infix, LinkedList *inExpLL)
{
  //Write your code here
    Stack s;
    s.head = NULL;
    s.size = 0;
    int i, len=strlen(infix), tempint=-1;
    int count=0, num=0, j=1;
    int b=0;
    char infixRev[len];

    for (int a=len-1;a>=0;a--)
    {
        //printf("a=%c ",infix[a]);
        if (infix[a]=='(')
            infixRev[b]=')';
        else if (infix[a]==')')
            infixRev[b]='(';
        else
            infixRev[b]=infix[a];
        b++;
    }

    //printf("\ninfix:%s", infixRev);

    for (i=0; i<len; i++){
            //printf("i=%d",i);
        if (infixRev[i] == '('){
            if (tempint!=-1){
                insertNode(inExpLL, tempint, OPERAND);
                tempint=-1;
                count=0;
            }
            push(&s, infixRev[i]);
        }

        else if (infixRev[i] == ')'){
            if (tempint!=-1){
                insertNode(inExpLL, tempint, OPERAND);
                tempint=-1;
                count=0;
            }
            while (peek(s)!= '('){
                    //printf("loop1");
                insertNode(inExpLL, peek(s), OPT);
                pop(&s);
            }
            pop(&s);
        }

        else if (infixRev[i] == '+' || infixRev[i] == '-'){
            //printf("died");
            if (tempint!=-1){
                insertNode(inExpLL, tempint, OPERAND);
                tempint=-1;
                count=0;
            }
            if (isEmptyStack(s)==0){
            //should be else?
            if (peek(s) == '*' || peek(s) == '/'){
                //printf("peek %c", peek(s));
                insertNode(inExpLL, peek(s), OPT);
                pop(&s);
            }
            }
            //printf("dint die");
            push(&s, infixRev[i]);
        }

        else if (infixRev[i] == '*' || infixRev[i] == '/'){
            if (tempint!=-1){
                insertNode(inExpLL, tempint, OPERAND);
                tempint=-1;
                count=0;
            }
            push(&s, infixRev[i]);
        }

        else{
          //printf("infixRev[i]=%c ",infixRev[i]-'0');
            if (tempint==-1){
                tempint = infixRev[i]-'0';
                count++;
            }
            else if (tempint!=-1){
                num = infixRev[i]-'0';
                while (j<=count){
                    num = num*10;
                    j++;
                }
                j=1;
                tempint = tempint + num;
                count++;
            }
        }
    }

    if (tempint!=-1){
        insertNode(inExpLL, tempint, OPERAND);
    }

    while (isEmptyStack(s) !=1){
            //printf("Loop2");
        insertNode(inExpLL, peek(s), OPT);
        pop(&s);
    }
}
