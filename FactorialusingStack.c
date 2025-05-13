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

int FindFactorial(int* stack,int* top,int n)
{
    for(int i=1;i<=n;i++)
    {
        PushStack(stack,i,top,n);
    }
    int factorialanswer=1;
    while(!stackisEmpty(top))
    {
    int fact=PopStack(stack,top);
    factorialanswer=factorialanswer*fact;
    }
    return factorialanswer;
}
int main() {
    printf("Enter the number for which u want to find factorial:");
    int n;
    scanf("%d",&n);
    int top=-1;
    
    int* stack=(int*)malloc(n*sizeof(int));
    int factorial=FindFactorial(stack,&top,n);
    printf("The factorial of %d is %d.",n,factorial);
    free(stack);
    return 0;
}
