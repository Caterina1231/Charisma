
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 5

int G[MAX][MAX];
int parent[MAX];
int set[MAX];
int key[MAX];

typedef struct GraphNode
{
    int vertex;
    int weight;
    struct GraphNode* next;
}Node;

Node* adjList[MAX];

void addEdgeList(int startvertex,int endvertex,int weight)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->vertex=endvertex;
    newNode->weight=weight;
    newNode->next=adjList[startvertex];
    adjList[startvertex]=newNode;
}
int FindMinimumKey(int n)
{
    int min=INT_MAX;
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(set[i]==0 && key[i]<min)
        {
            min=key[i];
            index=i;
        }
    }
    return index;
}
void primsAdjacencyMatrix(int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=0;
        set[i]=0;
        key[i]=INT_MAX;
    }

    parent[0]=-1;
    key[0]=0;

    for(int i=0;i<n-1;i++)
    {
         int u=FindMinimumKey(n);
         set[u]=1;

         for(int j=0;j<n;j++)
         {
             if(G[u][j]!=INT_MAX && set[j]!=1 && G[u][j]<key[j] )
            {
                key[j]=G[u][j];
                parent[j]=u;
            }
            }
    }
    for(int i=1;i<n;i++)
    {
    printf("\n edge %d -> %d ,%d",parent[i],i,G[i][parent[i]]);
    }
}
void primsAdjacencyList(int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=0;
        set[i]=0;
        key[i]=INT_MAX;
    }

    parent[0]=-1;
    key[0]=0;

    for(int i=0;i<n-1;i++)
    {
         int u=FindMinimumKey(n);
         set[u]=1;

        Node* temp=adjList[u];
        while(temp!=NULL)
        {
             if(temp->weight!=INT_MAX && set[temp->vertex]!=1 && temp->weight<key[temp->vertex] )
            {
                key[temp->vertex]=temp->weight;
                parent[temp->vertex]=u;
            }
            temp=temp->next;
            }
    }
    for(int i=1;i<n;i++)
    {
    printf("\n edge %d -> %d ,%d",parent[i],i,key[i]);
    }
}
int main()
{
    int n;
    printf("\n Enter number of vertices:");
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

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(G[i][j]!=INT_MAX && i!=j)
            {
            addEdgeList(i,j,G[i][j]);
            }
        }
    }

    printf("\n Prims using Adjacency Matrix:");
    primsAdjacencyMatrix(n);

    printf("\n Prims using Adjacency List:");
    primsAdjacencyList(n);

    return 0;
}