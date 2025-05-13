#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX_SIZE 10
typedef struct BSTnode
{
    int data;
    struct BSTnode* left;
    struct BSTnode* right;
}Node;
   Node* arr[MAX_SIZE];
   int front=-1;
   int rear=-1;
void initilaize()
{
   front=-1;
   rear=-1;
}
bool isFull()
{
    if(rear==MAX_SIZE-1)
    {
        return true;
    }
    return false;
}
bool isEmpty(q)
{
    if(front == -1 && rear==-1)
    {
        return true;
    }
    return false;
}
void enqueue(Node* dataNode)
{
    if(isFull())
    {
        printf("\n Queue is Full.Can't insert in queue.");
        return;
    }
    if(isEmpty())
    {
       front=0;
    }
    arr[++rear]=dataNode;
}
Node* Dequeue()
{
    if(isEmpty())
    {
        printf("\n Queue is Empty can't delete.");
        return NULL;
    }
    Node* element=arr[front];
    if(front==rear)
    {
      front=-1;
      rear=-1;
    }
    else
    {
        front++;
    }
    return element;
}

void levelOrderwisedisplay(Node* root)
{
    Enqueue(root);
    while(!isEmpty())
    {
      Node* curr=arr[front];
      if(curr==NULL)
      {
         printf("\n");
         enqueue(NULL);
      }
      else
      {
         break;
      }
      printf("%d",curr->data);
      if(curr->left!=NULL)
      {
         enqueue(curr->left);
      }
      if(curr->right!=NULL)
      {
         enqueue(curr->left);
      }
    }
}
int findHeightoftree(Node* root)
{
   if(root==NULL)
   {
      return 0;
   }
   int leftheight=findHeightoftree(root->left);
   int rightheight=findHeightoftree(root->right);
   return (leftheight>rightheight?leftheight:rightheight);
}
void DisplayLeafNodes(Node* root)
{
   if(root==NULL)
   {
      return;
   }
   if(root->left==NULL && root->right==NULL)
   {
      printf("%d ",root->data);
   }
   DisplayLeafNodes(root->left);
   DisplayLeafNodes(root->right);
}
Node* createNode(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//1.Insert
Node* insertNonRecursive(Node* root,int value)
{
     if(root==NULL)
     {
        return createNode(value);
     }
     Node* parent;
     Node* temp=root;
     while(temp!=NULL)
     {
        parent=temp;
        if(value<parent->data)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
     }
     if(value<parent->data)
     {
        parent->left=createNode(value);
     }
     else
     {
        parent->right=createNode(value);
     }
     return root;
}
Node* insertRecursive(Node* root,int value)
{
     if(root==NULL)
     {
        return createNode(value);
     }
     Node* parent;
     Node* temp=root;
     while(temp!=NULL)
     {
        parent=temp;
        if(value<parent->data)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
     }
     if(value<parent->data)
     {
        parent->left=createNode(value);
     }
     else
     {
        parent->right=createNode(value);
     }
     return root;
}
Node* findMinimum(Node* root)
{
   while(root!=NULL && root->left!=NULL)
   {
      root=root->left;
   }
   return root;
}

//2.Delete
Node* deleteNode(Node* root,int key)
{
   if(root==NULL)
   {
      return root;
   }

   if(key<root->data)
   {
     root->left=deleteNode(root->left,key);
   }
   else if(key>root->data)
   {
      root->right=deleteNode(root->right,key);
   }
   else
   {
      if(root->left==NULL && root->right==NULL)
      {
         free(root);
         return NULL;
      }
      else if(root->left==NULL)
      {
         Node* temp=root->right;
         free(root);
         return temp;
      }
       else if(root->right==NULL)
      {
         Node* temp=root->left;
         free(root);
         return temp;
      }
      else
      {
         Node* temp=findMinimum(root->right);
         root->data=temp->data;
         root->right=deleteNode(root->right,temp->data);
      }
   }
   return root;
}

//3.Mirror Image
void MirrorImage(Node* root)
{
   MirrorImage(root->left);
   MirrorImage(root->right);

   Node* temp=root->left;
   root->left=root->right;
   root->right=temp;
}
int main()
{
    Node* root=NULL;
    root=insertNonRecursive(root,20);
    root=insertNonRecursive(root,10);
    root=insertNonRecursive(root,60);
    root=insertNonRecursive(root,9);
    root=insertNonRecursive(root,15);

    deleteNode(15);
    deleteNode(10);
    
    return 0;
}