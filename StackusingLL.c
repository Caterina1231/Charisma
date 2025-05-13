#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct StackLL 
{
    int data;
    struct StackLL* next;
}Node;

Node* createNode(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    if(!newNode)
    {
        printf("Memory allocation failed");
        return NULL;
    }
    newNode->next=NULL;
    return newNode;
}
int insertAtHead(Node** head,int data)
{
    Node* newNode=createNode(data);
    if(!newNode)
    {
        return -1;
    }
    if((*head)==NULL)
    {
        *head=newNode;
        return 0;
    }
    newNode->next=*head;
    *head=newNode;
    return 0;
}
bool isEmpty(Node**stack)
{
    return *stack==NULL;
}
int deleteHead(Node** head)
{
    Node* temp=(*head);
    (*head)=(*head)->next;
    int element=temp->data;
    free(temp);
    return element;
}
void push(Node** head,int data)
{
    if(insertAtHead(head,data))
    {
      printf("Stack overflow");
      return;
    }
}
int Pop(Node** head)
{
    if(isEmpty(head))
    {
        printf("Stack underflow.");
        return -1;
    }
    return deleteHead(head);
}
int top(Node** head)
{
    return (*head)->data;
}
int main()
{
    Node* stack=NULL;

    push(&stack,2);
    printf("\n The element in the stack is:%d",top(&stack));
    push(&stack,3);
    printf("\n The element in the stack is:%d",top(&stack));
    push(&stack,4);
    printf("\n The element in the stack is:%d",top(&stack));

    while(!isEmpty(&stack))
    {
    int element=Pop(&stack);
    printf("\n The element popped from stack is %d",element);
    }

    return 0;
}