#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 10

int HashTable[MAX];

void init()
{
    for(int i = 0; i < MAX; i++)
    {
        HashTable[i] = -1;
    }
}

int HashFunction(int key)
{
    return key % MAX;
}

bool isPrime(int num)
{
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

int findPrimeBelowMax()
{
    for (int i = MAX - 1; i >= 2; i--)
        if (isPrime(i))
            return i;
    return 2;
}

int secondHash(int key)
{
    int prime = findPrimeBelowMax();
    return prime - (key % prime);
}

void InsertUsingNormalHash(int key)
{
    int index = HashFunction(key);
    if (HashTable[index] == -1)
    {
        HashTable[index] = key;
    }
    else
    {
        printf("\nCollision occurred at index %d. Normal Hashing doesn't resolve it.\n", index);
    }
}

void InsertUsingLinearProbing(int key)
{
    int i = 0;
    int index = HashFunction(key);
    while (HashTable[(index + i) % MAX] != -1 && i < MAX)
    {
        i++;
    }
    if (i < MAX)
    {
        HashTable[(index + i) % MAX] = key;
    }
    else
    {
        printf("\nHash Table is Full (Linear Probing).\n");
    }
}

void InsertUsingQuadraticProbing(int key)
{
    int i = 0;
    int index = HashFunction(key);
    while (HashTable[(index + (i * i)) % MAX] != -1 && i < MAX)
    {
        i++;
    }
    if (i < MAX)
    {
        HashTable[(index + (i * i)) % MAX] = key;
    }
    else
    {
        printf("\nHash Table is Full (Quadratic Probing).\n");
    }
}

void InsertUsingDoubleProbing(int key)
{
    int i = 0;
    int index1 = HashFunction(key);
    int index2 = secondHash(key);

    while (HashTable[(index1 + (index2 * i)) % MAX] != -1 && i < MAX)
    {
        i++;
    }
    if (i < MAX)
    {
        HashTable[(index1 + (index2 * i)) % MAX] = key;
    }
    else
    {
        printf("\nHash Table is Full (Double Hashing).\n");
    }
}

void display()
{
    for (int i = 0; i < MAX; i++)
    {
        if (HashTable[i] != -1)
            printf("%d -> %d\n", i, HashTable[i]);
        else
            printf("%d -> \n", i);
    }
}

int main()
{
    init();

    InsertUsingNormalHash(15);
    InsertUsingNormalHash(25);

    InsertUsingLinearProbing(35);
    InsertUsingQuadraticProbing(45);
    InsertUsingDoubleProbing(55);

    display();
    return 0;
}
