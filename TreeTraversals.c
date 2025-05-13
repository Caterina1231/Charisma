
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10

typedef struct BTreeNode
{
    int data;
    struct BTreeNode* left;
    struct BTreeNode* right;
}Btree;

Btree* stack[MAX];
int top=-1;
Btree* peek()
{
    return stack[top];
}
bool isFull()
{
    return top==MAX-1;
}
bool isEmpty()
{
    return top==-1;
}
void push_stack(Btree* data)
{
    if(isFull())
    {
        printf("\n Stack overflow.Can't insert.");
    }
    stack[++top]=data;
}
Btree* pop_Stack()
{
    if(isEmpty())
    {
        printf("\n Stack undeflow.Can't delete.");
    }
    Btree* element =stack[top--];
    return element;
}
Btree* createNode(int data)
{
    Btree* newNode=(Btree*)malloc(sizeof(Btree));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
}

void Preorder(Btree* root)
{
    if(root==NULL)
    {
        return;
    }
    Btree* ptr=root;
    push_stack(ptr);

    while(!isEmpty())
    {
        ptr=pop_Stack();

        printf("%d ",ptr->data);

        if(ptr->right!=NULL)
        {
            push_stack(ptr->right);
        }
        if(ptr->left!=NULL)
        {
            push_stack(ptr->left);
        }
    }
}
void Inorder(Btree* root)
{
    if(root==NULL)
    {
        return;
    }
    Btree* ptr=root;
    while(!isEmpty()||ptr!=NULL)
    {
      if(ptr!=NULL)
      {
        push_stack(ptr);
        ptr=ptr->left;
      }
      else
      {
      ptr=pop_Stack();
      printf("%d ",ptr->data);

      ptr=ptr->right;
      }
    }
}

void PostOrder(Btree* root)
{
    if(root==NULL)
    {
        return;
    }
    Btree* ptr=root;
    Btree* lastvisited=NULL;
    while(!isEmpty()||ptr!=NULL)
    {
       if(ptr!=NULL)
      {
        push_stack(ptr);
        ptr=ptr->left;
      }
      else
      {
        Btree* peekNode=peek();
        if(peekNode->right!=NULL && lastvisited!=peekNode->right)
        {
            ptr=peekNode->right;
        }
        else
        {
            printf("%d ",peekNode->data);
            lastvisited=pop_Stack();
        }
      } 
    }
}
int main()
{
    Btree*root=NULL;
    root=createNode(50);
    root->left=createNode(40);
    root->right=createNode(60);
    root->left->left=createNode(30);
    root->left->left->left=createNode(25);
    root->left->left->left->left=createNode(20);

    root->left->left->right=createNode(35);
    root->left->left->right->left=createNode(33);
    root->left->left->right->right=createNode(36);
    root->right->right=createNode(70);
    root->right->right->left=createNode(65);
    root->right->right->right=createNode(80);

    printf("\n The Preorder traversal is:");
    Preorder(root);

    printf("\n The Inorder traversal is:");
    Inorder(root);

     printf("\n The Porostder traversal is:");
    PostOrder(root);
    return 0;
}

