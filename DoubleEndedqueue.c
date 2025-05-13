
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
    if((q->front==0 && q->rear==MAX_SIZE-1)||(q->front==q->rear+1))
    {
        return true;
    }
    return false;
}
bool isEmpty(Queue* q)
{
    if(q->front == -1)
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
void InsertFromFront(Queue *q,int value)
{
    if(isFull(q))
    {
        printf("\n Can't insert from front.As queue is full.");
        return;
    }
    else if(q->front==-1)
    {
       q->front=0;
       q->rear=0;
    }
    else if(q->front==0)
    {
       q->front=MAX_SIZE-1;
    }
    else
    {
        q->front--;
    }
    q->arr[q->front]=value;
    printf("\n %d is the value inserted.",q->arr[q->front]);
}
void InsertFromRear(Queue *q,int value)
{
    if(isFull(q))
    {
        printf("\n Can't insert from rear.As queue is full.");
        return;
    }
    else if(q->rear==-1)
    {
       q->front=0;
       q->rear=0;
    }
    else if(q->rear==MAX_SIZE-1)
    {
       q->rear=0;
    }
    else
    {
        q->rear++;
    }
    q->arr[q->rear]=value;
    printf("\n %d is the value inserted.",q->arr[q->rear]);
}
void DeleteFromFront(Queue *q)
{
    if(isEmpty(q))
    {
        printf("\n Can't delete from front.As queue is empty.");
        return;
    }
    int value=q->arr[q->front];
     if(q->front==q->rear)
    {
       q->front=-1;
       q->rear=-1;
    }
    else if(q->front==MAX_SIZE-1)
    {
       q->front=0;
    }
    else
    {
        q->front++;
    }
    printf("\n %d is the value popped.",value);
}
void DeleteFromRear(Queue *q)
{
    if(isEmpty(q))
    {
        printf("Can't delete from front.As queue is empty.");
        return;
    }
     int value=q->arr[q->rear];
    if(q->front==q->rear)
    {
       q->front=-1;
       q->rear=-1;
    }
    else if(q->rear==0)
    {
       q->rear=MAX_SIZE-1;
    }
    else
    {
        q->rear--;
    }
    printf("\n %d is the value popped.",value);
}
void Display(Queue* q)
{
    if(isEmpty(q))
    {
        printf("\n Can't peek in queue .Queue is empty.");
    }
    int i=q->front;
    while(true)
    {
        printf("%d ",q->arr[i]);
        if(i==q->rear)
        {
            break;
        }
        i=(i+1)%MAX_SIZE;
    }
}
int main()
{
    Queue q;
    initialize(&q);
    InsertFromFront(&q,20);
    InsertFromRear(&q,30);
    InsertFromFront(&q,40);
    InsertFromRear(&q,60);
    Display(&q);
    DeleteFromFront(&q);
    DeleteFromRear(&q);
    return 0;
}