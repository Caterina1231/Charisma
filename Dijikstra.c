
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 10

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
void DisplayGraph(int sourcevertex,int distances[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\n The distance from the source vertex %d is %d ",sourcevertex,distances[i]);
    }
}
int findMinimumKeyVertex(int distances[],int visited[],int n)
{
    int minweight=INT_MAX;
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0 && distances[i]<minweight)
        {
            minweight=distances[i];
            index=i;
        }
    }
    return index;
}
void DijikstraAdjacencyMatrix(int G[MAX][MAX],int n)
{
    int visited[MAX];
    int distance[MAX];

    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        distance[i]=INT_MAX;
    }

    int sourcevertex;
    printf("\n Enter the source vertex.");
    scanf("%d",&sourcevertex);
    distance[sourcevertex]=0;

    for(int i=0;i<n-1;i++)
    {
        int u=findMinimumKeyVertex(distance,visited,n);
        visited[u]=1;

        for(int j=0;j<n;j++)
        {
            if(visited[j]!=1 && G[u][j]!=INT_MAX && distance[u]!=INT_MAX && distance[j]>distance[u]+G[u][j])
            {
                   distance[j]=distance[u]+G[u][j];
            }
        }
    }
    DisplayGraph(sourcevertex,distance,n);
}
void DijikstraAdjacencyList(int G[MAX][MAX],int n)
{
    int visited[MAX];
    int distance[MAX];

    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        distance[i]=INT_MAX;
    }

    int sourcevertex;
    printf("\n Enter the source vertex.");
    scanf("%d",&sourcevertex);
    distance[sourcevertex]=0;

    for(int i=0;i<n-1;i++)
    {
        int u=findMinimumKeyVertex(distance,visited,n);
        visited[u]=1;

        Node* p=adjList[u];
        while(p!=NULL)
        {
            if(visited[p->vertex]!=1 && G[u][p->vertex]!=INT_MAX && distance[u]!=INT_MAX && distance[p->vertex]>distance[u]+G[u][p->vertex])
            {
                   distance[p->vertex]=distance[u]+G[u][p->vertex];
            }
            p=p->next;
        }
    }
    DisplayGraph(sourcevertex,distance,n);
}
int main()
{
    int G[MAX][MAX];
    printf("\n Enter the number of vertices in the graph.");
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
    }

    for(int i=0;i<n;i++)
    {
        adjList[i]=NULL;
    }

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(i!=j && G[i][j]!=0)
        {
        addEdgeList(i,j,G[i][j]);
        }
      }
    }

    DijikstraAdjacencyMatrix(G,n);
    DijikstraAdjacencyList(G,n);
    return 0;
}