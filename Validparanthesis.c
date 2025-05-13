#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100


bool stackisFull(int* top,int length)
{
    if((*top)==length-1)
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

void PushStack(char* stack,char data,int* top,int length)
{
    if(stackisFull(top,length))
    {
        printf("Can't push into stack.Stack is FULL.");
    }
    else
    {
        (*top)++;
        stack[*top]=data;
    }
}
char PopStack(char* stack,int* top)
{
    if(stackisEmpty(top))
    {
        return '\0';
    }
    else
    {
        char element=stack[*top];
        top--;
        return element;
    }
}

bool checkisValidParanthesis(char* stack,int* top,char* str,int length)
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            PushStack(stack,str[i],top,length);
        }
        else if(str[i]==')' || str[i]=='}' || str[i]==']')
        {
        char topofstack=PopStack(stack,top);
        
        if(str[i]==')' && topofstack!='(' || str[i]==']' && topofstack!='[' || str[i]=='}' && topofstack!='{')
        {
            return false;
        }
        }
        i++;
    }
    return true;
}
int main() {
    printf("Enter a string:");
    char str[MAX];
    scanf("%[^\n]s",str);
    
    int top=-1;
    int length=strlen(str);
    char* stack=(char*)malloc(length*sizeof(char));
    
    bool isValid=checkisValidParanthesis(stack,&top,str,length);
    if(isValid)
    {
        printf("%s is a Valid Paranthesis string.",str);
    }
    else
    {
        printf("%s is not a Valid Paranthesis string.",str);
    }
    free(stack);
    return 0;
}
