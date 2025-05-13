
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX_SIZE 5
typedef struct CircularQueue
{
    int arr[MAX_SIZE];
    int front;
    int rear;
}Circq;
void initialize(Circq *q)
{
    q->front=-1;
    q->rear=-1;
}
bool isFull(Circq* q)
{
    if((q->rear+1)%MAX_SIZE==q->front)
    {
     return true;
    }
    return false;
}
bool isEmpty(Circq* q)
{
    return q->front==-1;
}
void Enqueue(Circq* q,int value)
{
    if(isFull(q))
    {
     printf("\n Queue overflow.Can't insert.");
     return;
    }

    if(q->front==-1)
    {
      q->front=0;
    }
    q->rear=(q->rear+1)%MAX_SIZE;
    q->arr[q->rear]=value;
}
int Dequeue(Circq* q)
{
    if(isEmpty(q))
    {
     printf("\n Queue undeflow.Can't delete.");
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
    q->front=(q->front+1)%MAX_SIZE;
    }
    return element;
}
void Display(Circq * q)
{
    if(isEmpty(q))
    {
      printf("\n Queue is empty.");
      return;
    }
    int i=q->front;
    while(i!=q->rear)
    {
        printf("%d ",q->arr[i]);
        i=(i+1)%MAX_SIZE;
    }
    printf("%d ",q->arr[q->rear]);
}
int main()
{
    Circq q;
    initialize(&q);
    Enqueue(&q,20);
    Enqueue(&q,30);
    Enqueue(&q,40);
    Display(&q);

     while(!isEmpty(&q))
     {
        int element=Dequeue(&q);
        printf("\n %d is the element popped from the queue.",element);
     }
    return 0;
}