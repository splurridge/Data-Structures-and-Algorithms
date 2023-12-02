// August 16, 2023
// insertEnd function

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *link;
} *LIST;

void insertEnd(LIST *A, char B);

int main()
{

    char data1 = 'A';
    char data2 = 'F';
    char data3 = 'G';
    char data4 = 'S';
    char data5 = 'S';

    LIST L = NULL;

    insertEnd(&L, data1);
    insertEnd(&L, data2);
    insertEnd(&L, data3);
    insertEnd(&L, data4);
    insertEnd(&L, data5);

    LIST trav;

    for (trav = L; trav != NULL; trav = trav->link)
    {
        printf("%c ", trav->data);
    }
    return 0;
}

void insertEnd(LIST *A, char B)
{
    LIST *trav;
    for (trav = A; (*trav) != NULL && (*trav)->data != B; trav = &(*trav)->link)
    {
    }
    if ((*trav) == NULL)
    {
        *trav = (LIST)malloc(sizeof(struct node));
    }
    if ((*trav) != NULL)
    {
        (*trav)->data = B;
        (*trav)->link = NULL;
    }
}