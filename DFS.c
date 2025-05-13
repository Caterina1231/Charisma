
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define MAX 10

int G[MAX][MAX];
int visitedMatrix[MAX];

struct Node
{
    int vertex;
    struct Node* next;
};
struct Node* adjList[MAX];
int visitedList[MAX];
typedef struct stack
{
    int* arr;
    int top;
}Stack;
void Enqueue(Stack* s,int data)
{
    if(isFull(s))
    {
        printf("\n Queue overflow.");
    }
    s->arr[++s->top]=data;
}
int dequeue(Stack *s)
{
     if(isEmpty(s))
    {
        printf("\n Queue overflow.");
    }
    int element=s->top;
    return element;
}
bool isFull(Stack* s)
{
    if(s->top==MAX-1)
    {
        return true;
    }
    return false;
}
bool isEmpty(Stack * s)
{
    if(s->top==-1)
    {
        return true;
    }
    return false;
}

void DFSMatrix(Stack* s,int start,int n)
{
    printf("\n Adjacency Matrix using DFS:");
    push(start);
    visitedMatrix[start]=1;

    while(!isEmpty(s))
    {
      int element=pop();
      printf("%d ",element);
      for(int i=n-1;i>=0;i--)
      {
        if(visitedMatrix[i]!=1 && G[element][i]!=INT_MAX)
        {
        push(i);
        visitedMatrix[i]=1;
        }
      }
    }
}

void DFSList(Stack* s,int start,int n)
{
    printf("\n Adjacency Matrix using DFS:");
    push(start);
    visitedList[start]=1;

    while(!isEmpty(s))
    {
      int element=pop();
      printf("%d ",element);
      struct Node* temp=adjList[element];
      while(temp!=NULL)
      {
        if(visitedList[temp->vertex]!=1)
        {
        push(temp->vertex);
        visitedList[temp->vertex]=1;
        }
        temp=temp->next;
      }
    }
}
int main()
{
    return 0;
}