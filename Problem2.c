#include<stdio.h>
#include<stdlib.h>

typedef struct SLLNode
{
    int data;
    struct SLLNode* next;
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
void CreateSLL(Node** head)
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
            temp=temp->next;
        }
    }
}
void DisplaySLL(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ->",temp->data);
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
     if(temp==NULL||temp->next==NULL)
        {
            printf("\n Invalid range.");
            return;
        }
   
    if(temp!=NULL)
    {
        newNode->next=temp->next;
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
    *head=temp->next;
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
        free(temp);
        *head=NULL;
        return;
    }
    Node* prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
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
    free(nodetodelete);
    nodetodelete->next=NULL;

}

//5.Reverse
void ReverseSLL(Node** head)
{
    Node* prev=NULL;
    Node* curr=*head;
    Node* forward;

    while(curr!=NULL)
    {
       forward=curr->next;
       curr->next=prev;
       prev=curr;
       curr=forward;
    }
    *head=prev;
}
int main()
{
    Node* head=NULL;
     
    CreateSLL(&head);
    DisplaySLL(head);

    InsertAtFront(&head,2);
    InsertAtFront(&head,6);
    InsertAtEnd(&head,4);
    InsertAtEnd(&head,8);
    InsertAtPosition(&head,7,2);
    DisplaySLL(head);

    DeleteFromFront(&head);
    DeleteFromEnd(&head);
    DeleteFromPosition(&head,1);
    DisplaySLL(head);

    ReverseSLL(&head);
    DisplaySLL(head);
    return 0;
}