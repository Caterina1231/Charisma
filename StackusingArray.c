#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 100
typedef struct
{
    int arr[MAX_SIZE];
    int top;
}Stack;

void initialize(Stack* stack)
{
   stack->top=-1;
}

bool isFull(Stack* stack)
{
    return stack->top==MAX_SIZE-1;
}

bool isEmpty(Stack* stack)
{
    return stack->top==-1;
}

void Push(Stack* stack,int data)
{
    if(isFull(stack))
    {
        printf("Stack overflow.");
        return ;
    }
    stack->arr[++stack->top]=data;
}

int Pop(Stack* stack)
{
    if(isFull(stack))
    {
        printf("Stack underflow.");
        return -1;
    }
    int element=stack->arr[stack->top];
    stack->top--;
    return element;
}
int top(Stack* stack)
{
  return stack->arr[stack->top];
}
int main()
{
    Stack stack;
    Push(&stack,2);
    printf("\nThe top of the stack is:%d",top(&stack));
    Push(&stack,3);
    printf("\nThe top of the stack is:%d",top(&stack));
    Push(&stack,4);
    printf("\nThe top of the stack is:%d",top(&stack));

    while(!isEmpty(&stack))
    {
        int element=Pop(&stack);
        if(element==-1)
        {
            printf("The stack is empty.Can't pop");
        }
        if(element!=-1 && stack.top!=-1)
        {
        printf("\nThe element popped from the stack is %d",element);
        }
    }
    return 0;
}