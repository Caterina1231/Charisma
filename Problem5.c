#include<stdio.h>
#include<stdlib.h>

typedef struct SLLNode
{
float coefficient;
int exponent;
struct SLLNode* next;
}Node;

Node* insert(Node* start,float coefficient,int exponent)
{
    //Step 1:create new node
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->coefficient=coefficient;
    temp->exponent=exponent;
    temp->next=NULL;

    //Case 1:if greater exponent then insert at front
    if(start==NULL || exponent>start->exponent)
    {
        temp->next=start;
        return temp;
    }

    //Case 2:if lessser exponent 
    Node*p=start;
    Node*prev=NULL;
    while(p!=NULL && p->exponent > exponent)
    {
        prev=p;
        p=p->next;
    }

    //Case 3:if equal exponent
    if(p!=NULL && p->exponent==exponent)
    {
        p->coefficient+=temp->coefficient;
        free(temp);
    }
    else
    {
        temp->next=p;
        if(prev)
        {
            prev->next=temp;
        }
        else
        {
            start=temp;
        }
    }
    return start;
}
void Display(Node* s)
{
    Node* temp=s;
    while(temp!=NULL)
    {
        printf("%.1fx^%d",temp->coefficient,temp->exponent);
        if(temp->next!=NULL)
        {
            printf("+");
        }
        temp=temp->next;
    }
}
void AddPolynomials(Node* s1,Node* s2)
{
    Node* result=NULL;
    while(s1!=NULL)
    {
        result=insert(result,s1->coefficient,s1->exponent);
        s1=s1->next;
    }
    while(s2!=NULL)
    {
        result=insert(result,s2->coefficient,s2->exponent);
        s2=s2->next;
    }
    Display(result);
}
void MultiplyPolynomials(Node* s1,Node* s2)
{
    Node* result=NULL;
    while(s1!=NULL)
    {
        while(s2!=NULL)
        {
            result=insert(result,s1->coefficient*s2->coefficient,s1->exponent+s2->exponent);
            s2=s2->next;
        }
        s1=s1->next;
    }
    Display(result);
}
Node* create(Node* s)
{
    float coefficient;
     int exponent;
    int n;
    printf("\n Enter the number of terms you want in polynomial:");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("\n Enter the coefficient for term %d:",i+1);
        scanf("%f",&coefficient);

        printf("\n Enter the exponent for term %d:",i+1);
        scanf("%d",&exponent);

        s=insert(s,coefficient,exponent);
    }
    return s;
}

int main()
{
    Node* s1=NULL;
    Node* s2=NULL;

    s1=create(s1);
    s2=create(s2);

    printf("\n The first polynomial is:");
    Display(s1);

    printf("\n The second polynomial is:");
    Display(s2);

    printf("\n the addition of two polynomials is:");
    AddPolynomials(s1,s2);

    printf("\n the addition of two polynomials is:");
    MultiplyPolynomials(s1,s2);

    return 0;
}