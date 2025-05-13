
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
int prec(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
char* InfixtoPostfix(char* exp)
{
    int length=strlen(exp);
    char*result=(char*)malloc(length+1*sizeof(char));
    char*stack=(char*)malloc(length*sizeof(char));
    int j=0;
    int top=-1;
    for(int i=0;i<length;i++)
    {
        char ch=exp[i];
        if(isalnum(ch))
        {
          result[j++]=ch;
        }
        else if(ch=='(')
        {
            stack[++top]=ch;
        }
        else if(ch==')')
        {
            while(top!=-1 && stack[top]!='(')
            {
                result[j++]=stack[top--];
            }
            top--;
        }
        else 
        {
            while(top!=-1 &&( prec(ch)<prec(stack[top])||prec(ch)==prec(stack[top])&&(ch!='^')))
            {
                result[j++]=stack[top--];
            }
        stack[++top]=ch;
        }

    }
    while(top!=-1 )
    {
        result[j++]=stack[top--];
    }
    result[j]='\0';
    //printf("\n %s",result);
    return result;
}
void reverse(char* exp)
{
    int i=0;
    int length=strlen(exp);
    int j=length-1;
    while(i<j)
    {
        char temp=exp[i];
        exp[i]=exp[j];
        exp[j]=temp;
        i++;
        j--;
    }
}
void InfixtoPrefix(char* exp)
{
    reverse(exp);
    int length=strlen(exp);
    for(int i=0;i<length;i++)
    {
        if(exp[i]=='(')
        {
            exp[i]=')';
        }
        else if(exp[i]==')')
        {
            exp[i]='(';
        }
    }
    char* postfix=InfixtoPostfix(exp);
    reverse(postfix);
    printf("\n%s",postfix);
}
int main()
{
     char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
     InfixtoPrefix(exp);
    return 0;
}