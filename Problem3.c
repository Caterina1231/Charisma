
#include<stdio.h>
#include<stdlib.h>

typedef struct DLLNode
{
    int data;
    struct DLLNode* prev;
    struct DLLNode* next;
}Node;
//5 operations of a linked list
//1]Create,Insert,Delete,Display,reverse
Node* CreateNode(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
void CreateDLL(Node** head)
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
            temp=*head;
        }
        else
        {
            temp->next=newNode;
            newNode->prev=temp;
            temp=temp->next;
        }
    }
}
void DisplayDLL(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d <->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

//3.Insert-3cases InsertAtFront.InsertAtEnd,InsertAtPosition
void InsertAtFront(Node** head,int data)
{
    Node* newNode=CreateNode(data);
    if(*head==NULL)
    {
      *head=newNode;
      return;
    }
    newNode->next=*head;
    (*head)->prev=newNode;
    *head=newNode;
}
void InsertAtEnd(Node** head,int data)
{
    Node* newNode=CreateNode(data);
    if(*head==NULL)
    {
      *head=newNode;
      return;
    }
    Node* temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void InsertAtPosition(Node** head,int data,int position)
{
    if(position==0)
    {
        InsertAtFront(head,data);
        return;
    }
    Node* temp=*head;
    Node* newNode=CreateNode(data);
    for(int i=0;i<position-1 && temp!=NULL;i++)
    {
        temp=temp->next;
    }
     if(temp==NULL)
        {
            printf("\n Invalid range.");
            return;
        }
   
    if(temp!=NULL)
    {
        newNode->next=temp->next;
        newNode->prev=temp;
        if(temp->next!=NULL)
        {
        temp->next->prev=newNode;
        }
        temp->next=newNode;
    }
}
//4.Delete
void DeleteFromFront(Node** head)
{
    if(*head==NULL)
    {
        printf("Can't delete.");
        return;
    }
    Node* temp=*head;
    *head=(*head)->next;
    if(*head!=NULL)
    {
    (*head)->prev=NULL;
    }
    temp->next=NULL;
    free(temp);
}
void DeleteFromEnd(Node** head)
{
    if(*head==NULL)
    {
        printf("Can't delete.");
        return;
    }
    Node* temp=*head;
    if(temp->next==NULL)
    {
        *head=NULL;
        free(temp);
        return;
    }
    //Node* previous=NULL;
    while(temp->next!=NULL)
    {
      //  previous=temp;
        temp=temp->next;
    }
     temp->prev->next=NULL;
    free(temp);
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
    for(int i=0;i<position-1 && temp!=NULL;i++)
    {    
        temp=temp->next;
    }
     if(temp==NULL||temp->next==NULL)
        {
            printf("\n Invalid range.");
            return;
        }
    Node* nodetodelete=temp->next;
    temp->next=nodetodelete->next;
    if(nodetodelete->next!=NULL)
    {
    nodetodelete->next->prev=temp;
    }
    nodetodelete->prev=NULL;
    nodetodelete->next=NULL;
    free(nodetodelete);
}

//5.Reverse
void ReverseDLL(Node** head)
{
    Node* previous=NULL;
    Node* curr=*head;
    Node* forward;

    while(curr!=NULL)
    {
       forward=curr->next;
       curr->next=previous;
       curr->prev=forward;
       previous=curr;
       curr=forward;
    }
    *head=previous;
}
int main()
{
    Node* head=NULL;
     
    CreateDLL(&head);
    DisplayDLL(head);

    InsertAtFront(&head,2);
    InsertAtFront(&head,6);
    InsertAtEnd(&head,4);
    InsertAtEnd(&head,8);
    InsertAtPosition(&head,7,2);
    DisplayDLL(head);

    DeleteFromFront(&head);
    DeleteFromEnd(&head);
    DeleteFromPosition(&head,1);
    DisplayDLL(head);

    ReverseDLL(&head);
    DisplayDLL(head);
    return 0;
}