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
void InfixtoPostfix(char* exp)
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
            while(top!=-1 && prec(ch)<=prec(stack[top]))
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
    printf("\n %s",result);
}
int main()
{
     char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
     InfixtoPostfix(exp);
    return 0;
}

