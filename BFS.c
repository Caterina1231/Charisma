
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10

typedef struct GraphNode
{
   int vertex;
   int weight;
   struct GraphNode* next;
}Node;
int G[MAX][MAX];
int visited[MAX];
int visitedList[MAX];

Node* adjList[MAX];

typedef struct Queue
{
    int* arr;
    int front;
    int rear;
}queue;
void Enqueue(queue* q,int data)
{
    if(isFull(q))
    {
        printf("\n Queue overflow.");
    }
    if(q->front==-1)
    {
      q->front=0;
    }
    q->arr[++q->rear]=data;
}
int dequeue(queue*q)
{
     if(isEmpty(q))
    {
        printf("\n Queue overflow.");
    }
    int element=q->front;
    if(q->front==q->rear)
    {
      q->front=-1;
      q->rear=-1;
    }
    else
    {
        q->front++;
    }
    return element;
}
bool isFull(queue* q)
{
    if(q->rear==MAX-1)
    {
        return true;
    }
    return false;
}
bool isEmpty(queue* q)
{
    if(q->front==-1)
    {
        return true;
    }
    return false;
}
void BFS_Matrix(queue* q,int n)
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    printf("\n Enter start vertex.");
    int v;
    scanf("%d",&v);

    Enqueue(q,v);
    visited[v]=1;

    while(!isEmpty(q))
    {
        for(int i=0;i<n;i++)
    {
      v=dequeue(q);
      printf("%d ",v);
      if(visited[v]==0 && G[v][i]!=INT_MAX)
      {
        Enqueue(q,i);
        visited[i]=1;
      }
    }
}
}

void BFS_list(queue*q,int n)
{
    for(int i=0;i<n;i++)
    {
        visitedList[i]=0;
    }
    printf("\n Enter start vertex.");
    int v;
    scanf("%d",&v);

    Enqueue(q,v);
    visited[v]=1;


    while(!isEmpty(q))
    {
      Node* temp=adjList[v];
      while(temp!=NULL)
      {
      v=dequeue(q);
      if(visited[v]==0 )
      {
        Enqueue(q,temp->vertex);
        visited[temp->vertex]=1;
      }
      temp=temp->next;
    }
}
}
void create(int n)
{
     char ch;
do
{
   int u,v;
   printf("\n Enter Edge: %d %d",&u,&v);
   
   Node* newNode=(Node*)malloc(sizeof(Node));
   newNode->vertex=v;
   newNode->next=NULL;

   Node* temp=adjList[u];

  if(temp==NULL)
  {
    adjList[u]=newNode;
  }
  else
  {
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=newNode;
  }

  printf("\n Do you want to add more edges?");
  scanf("%c",&ch);

}while(ch=='Y'||ch=='y');
}


int main()
{
    printf("\n Enter number of vertices:");
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j]==0 && i!=j)
            {
                G[i][j]=INT_MAX;
            }
        }
        adjList[i]=NULL;
    }
    //way of creating adjList
    create(n);
    queue q;
    BFS_list(&q,n);
    BFS_Matrix(&q,n);
    return 0;
}