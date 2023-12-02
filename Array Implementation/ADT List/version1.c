#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef enum
{
    TRUE,
    FALSE
} boolean;

typedef struct
{
    char arr[MAX];
    int count;
} LIST;

void initializeList(LIST *L)
{
    L->count = 0;
}

void insertElement(LIST *L, char elem)
{
    if (L->count < MAX)
    {
        L->arr[L->count] = elem;
        L->count++;
    }
}

// int deleteElem(LIST *L, char elem)
// {
//     int index = isMember(L, elem); // Pass L, not &L
//     if (index != -1)
//     {
//         for (int i = index; i < L->count - 1; i++)
//         {
//             L->arr[i] = L->arr[i + 1];
//         }
//         L->count--;
//     }
//     return 0; // Return a value to indicate success
// }

bool isMember(LIST *L, char elem)
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

void displayList(LIST *L)
{
    for (int i = 0; i < L->count; i++)
    {
        printf("%c ", L->arr[i]);
    }
    printf("\n");
}

int main()
{
    LIST L;
    initializeList(&L);

    insertElement(&L, 'H');
    insertElement(&L, 'O');
    insertElement(&L, 'P');
    insertElement(&L, 'E');

    // deleteElem(&L, 'O');

    displayList(&L);

    int check = isMember(&L, 'O');
    printf("%d", check);

    return 0;
}
