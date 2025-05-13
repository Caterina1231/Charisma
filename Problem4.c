
#include<stdio.h>
#include<stdlib.h>

typedef struct CircularLLNode
{
    int data;
    struct CircularLLNode* next;
}Node;
//5 operations of a linked list
//1]Create,Insert,Delete,Display,reverse
Node* CreateNode(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void CreateCircularLL(Node** head)
{
    int n;
    printf("\n Enter the number of nodes you want in the linked list: ");
    scanf("%d",&n);
    Node* temp=NULL;
    for(int i=0;i<n;i++)
    {
        printf("\n Enter the data you want to insert for Node %d: ",i+1);
        int data;
        scanf("%d",&data);
        Node* newNode=CreateNode(data);
        if(*head==NULL)
        {
            *head=newNode;
            newNode->next=(*head);
            temp=*head;
        }
        else
        {
            temp->next=newNode;
            temp=temp->next;
        }
    }
    temp->next=*head;
}
void DisplayCircularLL(Node* head)
{
    Node* temp=head;
    do
    {
        printf("%d ->",temp->data);
        temp=temp->next;
    } while(temp!=head);
    printf("HEAD\n");
}

//3.Insert-3cases InsertAtFront.InsertAtEnd,InsertAtPosition
void InsertAtFront(Node** head,int data)
{
    Node* newNode=CreateNode(data);
    if(*head==NULL)
    {
      *head=newNode;
      newNode->next=(*head);
      return;
    }
    Node* temp=*head;
    while(temp->next!=(*head))
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=(*head);
    *head=newNode;
}
void InsertAtEnd(Node** head,int data)
{
    Node* newNode=CreateNode(data);
    if(*head==NULL)
    {
      *head=newNode;
      newNode->next=(*head);
      return;
    }
    Node* temp=*head;
    while(temp->next!=(*head))
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=(*head);
}

void InsertAtPosition(Node** head,int data,int position)
{
    Node* newNode=CreateNode(data);
    if(position==0 && *head==NULL)
    {
        *head=newNode;
        newNode->next=(*head);
        return ;
    }
    else if(position==0)
    {
        InsertAtFront(head,data);
        return;
    }
    Node* temp=*head;
    for(int i=0;i<position-1 ;i++)
    {
        temp=temp->next;
    }
        newNode->next=temp->next;
        temp->next=newNode;
}
//4.Delete
void DeleteFromFront(Node** head)
{
    if(*head==NULL)
    {
        printf("Can't delete.");
        return;
    }
    if((*head)->next==(*head))
    {
        free(*head);
        *head=NULL;
        return;
    }
    Node* temp=*head;
    while(temp->next!=(*head))
    {
        temp=temp->next;
    }
    temp->next=(*head)->next;
    Node* nodetodelete=(*head);
    (*head)=(*head)->next;
    free(nodetodelete);
}
void DeleteFromEnd(Node** head)
{
    if(*head==NULL)
    {
        printf("Can't delete.");
        return;
    }
    Node* temp=*head;
    if(temp->next==(*head))
    {
        free(temp);
        *head=NULL;
        return;
    }
    Node* prev=NULL;
    while(temp->next->next!=(*head))
    {
        temp=temp->next;
    }
    prev=temp->next;
    temp->next=(*head);
    free(prev);
}
void DeleteFromPosition(Node** head,int position)
{
    
    if(*head==NULL)
    {
        printf("Can't delete.");
        return;
    }
    if(position==0)
    {
        DeleteFromFront(head);
        return;
    }
    Node* temp=*head;
    for(int i=0;i<position-1 ;i++)
    {    
        temp=temp->next;
    }
    Node* nodetodelete=temp->next;
    temp->next=nodetodelete->next;
    free(nodetodelete);
    nodetodelete->next=NULL;
}

//5.Reverse
void ReverseCircularLL(Node** head)
{
    Node* prev=NULL;
    Node* curr=*head;
    Node* forward;
    do
    {
       forward=curr->next;
       curr->next=prev;
       prev=curr;
       curr=forward;
    }while(curr!=(*head));
    (*head)->next=prev;
    (*head)=prev;
}
int main()
{
    Node* head=NULL;
     
    CreateCircularLL(&head);
    DisplayCircularLL(head);

    InsertAtFront(&head,2);
    InsertAtFront(&head,6);
    InsertAtEnd(&head,4);
    InsertAtEnd(&head,8);
    InsertAtPosition(&head,7,2);
    DisplayCircularLL(head);

    DeleteFromFront(&head);
    DeleteFromEnd(&head);
    DeleteFromPosition(&head,1);
    DisplayCircularLL(head);

    ReverseCircularLL(&head);
    DisplayCircularLL(head);
    return 0;
}