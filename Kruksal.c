
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define MAX 10

int G[MAX][MAX];
int parent[MAX];

typedef struct GraphNode
{
    int vertex;
    int weight;
    struct GraphNode* next;
}Node;

Node* adjList[MAX];
int findparent(int i)
{
    while(parent[i])
    {
        i=parent[i];
    }
    return i;
}

int unionset(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}

void addEdgeList(int startvertex,int endvertex,int weight)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->vertex=endvertex;
    newNode->weight=weight;
    newNode->next=adjList[startvertex];
    adjList[startvertex]=newNode;
}

void DisplayAdjacencyList(int n)
{
    for(int i=0;i<n;i++)
    {
      Node* temp=adjList[i];
      printf("%d ->",i);
      while(temp!=NULL)
      {
        printf("%d,(weight=%d) ",temp->vertex,temp->weight);
        temp=temp->next;
      }
      printf("NULL\n");
    }
}
int main()
{
    int n,numberofedges=0,minimumcost=0,min;
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);
    printf("\n Enter the adjacency Matrix:");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j]==0)
            {
                G[i][j]=INT_MAX;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        adjList[i]=NULL;
        parent[i]=0;
    }
    int a=-1,b=-1,u=-1,v=-1;
    printf("\n The edges are in spanning tree are:");
    while(numberofedges<n-1)
    {
        int min=INT_MAX;
       for(int i=0;i<n;i++)
       {
          for(int j=0;j<n;j++)
          {
            if(G[i][j]<min)
            {
               min=G[i][j];
               a=i;
               b=j;
            }
          }
       }
       u=findparent(a);
       v=findparent(b);

       if(unionset(u,v))
       {
        printf("\n edge %d->%d,weight=%d",a,b,min);
        minimumcost+=min;
        numberofedges++;
       addEdgeList(a,b,min);
       addEdgeList(b,a,min);
       }
       G[a][b]=G[b][a]=INT_MAX;
    }

    printf("\n The minimum cost of the spanning tree is %d",minimumcost);
    DisplayAdjacencyList(n);
    return 0;
}