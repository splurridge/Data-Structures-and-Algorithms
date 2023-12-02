#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct node
{
    int data;
    struct node *link;
} *LIST;

typedef LIST Dictionary[SIZE];

// function prototypes
void initDictionary(Dictionary D);
int hash(int x);
void insertDictionary(Dictionary D, int x);
void deleteDictionary(Dictionary D, int x);
int isMember(Dictionary D, int x);
void display(Dictionary D, int x);

int main()
{

    Dictionary newDic;
    initDictionary(newDic);

    insertDictionary(newDic, 10);
    insertDictionary(newDic, 7);
    insertDictionary(newDic, 20);
    insertDictionary(newDic, 17);

    // deleteDictionary (newDic, 10);
    // deleteDictionary (newDic, 17);

    int retval = isMember(newDic, 20);

    insertDictionary(newDic, 30);
    insertDictionary(newDic, 40);
    insertDictionary(newDic, 50);

    display(newDic, 0); // print sub-group 0

    return 0;
}

void initDictionary(Dictionary D)
{
    int x;

    for (x = 0; x < SIZE; x++)
    {
        D[x] = NULL;
    }
}

int hash(int x)
{
    return (x % SIZE); // return digit in ones place
}

void insertDictionary(Dictionary D, int x)
{
    int hashval = hash(x);

    LIST temp = (LIST)malloc(sizeof(struct node));
    LIST *trav = &D[hashval];

    for (; (*trav) != NULL && (*trav)->data <= x; trav = &(*trav)->link)
    {
    }

    temp->data = x;
    temp->link = *trav;
    *trav = temp;
}

void deleteDictionary(Dictionary D, int x)
{
    int hashval = hash(x);
    LIST temp;
    LIST *trav;

    if (D[hashval] != NULL)
    {
        for (trav = &D[hashval]; (*trav) != NULL && (*trav)->data != x; trav = &(*trav)->link)
        {
        }

        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

int isMember(Dictionary D, int x)
{
    int hashval = hash(x);

    LIST trav;

    for (trav = D[hashval]; trav != NULL && trav->data != x; trav = trav->link)
    {
    }

    return (trav != NULL) ? 0 : 1;
}

void display(Dictionary D, int x)
{
    int hashval = hash(x);

    LIST trav;

    for (trav = D[hashval]; trav != NULL; trav = trav->link)
    {
        printf("%d ", trav->data);
    }
}