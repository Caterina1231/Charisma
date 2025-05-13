#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
bool stackisFull(int* top,int n)
{
    if((*top)==n-1)
    {
        return true;
    }
    return false;
}
bool stackisEmpty(int* top)
{
    if((*top)==-1)
    {
        return true;
    }
    return false;
}

void PushStack(int* stack,int data,int* top,int n)
{
    if(stackisFull(top,n))
    {
        printf("Can't push into stack.Stack is FULL.");
    }
    else
    {
        (*top)++;
        stack[*top]=data;
    }
}
int PopStack(int* stack,int* top)
{
    if(stackisEmpty(top))
    {
        return 0;
    }
    else
    {
        int element=stack[*top];
        (*top)--;
        return element;
    }
}
void StackReversalandprintfibonacci(int* stack,int* top,int n)
{
    int* stackreverse=(int*)malloc(n*sizeof(int));
    int* top2=(int*)malloc(sizeof(int));;
    *top2=-1;
    while(!stackisEmpty(top))
    {
        int element=PopStack(stack,top);
        PushStack(stackreverse,element,top2,n);
    }
    printf("The fibonacci series using stack is:\n");
    while((*top2)!=-1)
    {
        int element=PopStack(stackreverse,top2);
        printf("%d ",element);
    }
    free(stackreverse);
    free(top2);
}
void FindFibonacci(int* stack,int* top,int n)
{
    int a=0;
    int b=1;
    PushStack(stack,a,top,n);
    PushStack(stack,b,top,n);
    int sum=0;
    while(!stackisFull(top,n))
    {
     sum=0;
    int p=*top;
    int element=stack[p];
    sum+=element;
    (p)--;
    sum+=stack[p];
    PushStack(stack,sum,top,n);
    }
    StackReversalandprintfibonacci(stack,top,n);
}
int main() {
    printf("Enter the number of terms of fibonacci series:");
    int n;
    scanf("%d",&n);
    int top=-1;
    
    int* stack=(int*)malloc(n*sizeof(int));
    FindFibonacci(stack,&top,n);
    free(stack);
    return 0;
}
