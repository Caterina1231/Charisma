
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define MAX 10

int HashTable[MAX];

void init()
{
    for(int i=0;i<MAX;i++)
    {
        HashTable[i]=-1;
    }
}

int HashFunction(int key)
{
    return key%MAX;
}

int secondHash(int key)
{
    return 7-(key%7);
}

void InsertUsingLinearProbing(int key)
{
    int i=0;
    int index=HashFunction(key);
    while(HashTable[(index+i)%MAX]!=-1 && i<MAX )
    {
        i++;
    }
    if(i<MAX)
    {
      HashTable[(index+i)%MAX]=key;
    }
    else
    {
        printf("\n Hash Table is Full.");
    }
}

void InsertUsingQuadraticProbing(int key)
{
    int i=0;
    int index=HashFunction(key);
    while(HashTable[(index+(i*i))%MAX]!=-1 && i<MAX )
    {
        i++;
    }
    if(i<MAX)
    {
      HashTable[(index+(i*i))%MAX]=key;
    }
    else
    {
        printf("\n Hash Table is Full.");
    }
}

void InsertusingDoubleProbing(int key)
{
    int i=0;
    int index1=HashFunction(key);
    int index2=secondHash(key);

    while(HashTable[index1+(index2*i)%MAX]!=-1 && i<MAX )
    {
        i++;
    }
    if(i<MAX)
    {
      HashTable[index1+(index2*i)%MAX]=key;
    }
    else
    {
        printf("\n Hash Table is Full.");
    }
}
