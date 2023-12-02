#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

// DATATYPE DEFINITION

typedef struct
{
    char arr[MAX];
    int count;
} LIST;

typedef LIST *ListPtr;

// INITIALIZATION

ListPtr initializeList()
{
    ListPtr L = (ListPtr)malloc(sizeof(LIST));
    L->count = 0;
    return L;
}

// OPERATIONS

void insertElement(ListPtr L, char elem)
{
    if (L->count < MAX)
    {
        L->arr[L->count] = elem;
        L->count++;
    }
}

bool isMember(ListPtr L, char elem)
{
    for (int i = 0; i < L->count; i++)
    {
        if (L->arr[i] == elem)
        {
            return true;
        }
    }
    return false;
}

void displayList(ListPtr L)
{
    for (int i = 0; i < L->count; i++)
    {
        printf("%c ", L->arr[i]);
    }
    printf("\n");
}

int main()
{
    ListPtr L = initializeList();

    insertElement(L, 'H');
    insertElement(L, 'O');
    insertElement(L, 'P');
    insertElement(L, 'E');

    displayList(L);

    isMember(L, 'O');

    return 0;
}
