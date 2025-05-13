
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 10
typedef struct 
{
    int arr[MAX_SIZE];
    int front;
    int rear;
}Queue;

bool isFull(Queue* q)
{
    if(q->rear==MAX_SIZE-1)
    {
        return true;
    }
    return false;
}
bool isEmpty(Queue* q)
{
    if(q->front == -1 && q->rear==-1)
    {
        return true;
    }
    return false;
}
void initialize(Queue *q)
{
    q->front=-1;
    q->rear=-1;
}
void enqueue(Queue *q,int value)
{
    if(isFull(q))
    {
        printf("\n Queue is Full.Can't insert in queue.");
        return;
    }
    if(isEmpty(q))
    {
       q->front=0;
    }
    q->arr[++q->rear]=value;
}

int Dequeue(Queue*q)
{
    if(isEmpty(q))
    {
        printf("\n Queue is Empty can't delete.");
        return -1;
    }
    int element=q->arr[q->front];
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

int top(Queue*q)
{
    if(isEmpty(q))
    {
        printf("\n Can't peek in queue .Queue is empty.");
        return -1;
    }
    return q->arr[q->front];
}

void Display(Queue* q)
{
    if(isEmpty(q))
    {
        printf("\n Can't peek in queue .Queue is empty.");
    }
    for(int i=q->front;i<=q->rear;i++)
    {
        printf("%d ",q->arr[i]);
    }
}
int main()
{
    Queue q;
    initialize(&q);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    
    Display(&q);
    while(!isEmpty(&q))
    {
        int element=Dequeue(&q);
        if(element!=-1)
        {
            printf("\n The element popped from queue is %d ",element);
             printf("\n The element at top  is %d ",top(&q));
        }
    }
    
    return 0;
}