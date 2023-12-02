#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef int SET[SIZE];

void initSET(SET A);
void insert(SET A, int n);
void deleteMem(SET A, int n);
void populateA(SET A);
void populateB(SET B);
void display(SET A);

int isMember(SET A, int n);
SET *unionSet(SET A, SET B);
SET *intersection(SET A, SET B);
SET *difference(SET A, SET B);
int isSubset(SET A, SET B);

int main()
{
    SET A, B;
    initSET(A);
    initSET(B);
    populateA(A);
    populateB(B);

    display(A);
    display(B);

    printf("\n");

    SET *U = unionSet(A, B);
    SET *I = intersection(A, B);
    SET *D = difference(A, B);

    display(*U);
    display(*I);
    display(*D);

    printf("\n");

    printf("%d ", isMember(A, 1));
    printf("%d ", isSubset(A, B));
    deleteMem(A, 9);
    printf("%d ", isMember(A, 2));
    printf("%d ", isSubset(A, B));
}

void initSET(SET A)
{
    for (int i = 0; i < SIZE; i++)
    {
        A[i] = 0;
    }
}

void insert(SET A, int n)
{
    if (n >= 0 && n < SIZE)
    {
        A[n] = 1;
    }
}

void deleteMem(SET A, int n)
{
    if (n >= 0 && n < SIZE)
    {
        A[n] = 0;
    }
}

void populateA(SET A)
{
    int num[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        insert(A, num[i]);
    }
}

void populateB(SET B)
{
    int num[] = {2, 4, 6, 8, 10};
    for (int i = 0; i < 5; i++)
    {
        insert(B, num[i]);
    }
}

void display(SET A)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (A[i] == 1)
            printf("%d", i);
    }
    printf("\n");
}

int isMember(SET A, int n)
{
    return A[n];
}

SET *unionSet(SET A, SET B)
{
    SET *C = (SET *)calloc(1, sizeof(SET));
    if (C != NULL)
    {
        for (int i = 0; i < SIZE; i++)
        {
            (*C)[i] = A[i] | B[i];
        }
    }
    return C;
}

SET *intersection(SET A, SET B)
{
    SET *C = (SET *)calloc(1, sizeof(SET));
    if (C != NULL)
    {
        for (int i = 0; i < SIZE; i++)
        {
            (*C)[i] = A[i] & B[i];
        }
    }
    return C;
}

SET *difference(SET A, SET B)
{
    SET *C = (SET *)calloc(1, sizeof(SET));
    if (C != NULL)
    {
        for (int i = 0; i < SIZE; i++)
        {
            (*C)[i] = A[i] & ~B[i];
        }
    }
    return C;
}

int isSubset(SET A, SET B)
{
    int i;
    for (i = 0; i < SIZE && (A[i] & ~B[i]) == 0; i++)
    {
    }
    return (i == SIZE) ? 1 : 0;
}