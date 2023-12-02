#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} *STACK;

void initializeStack(STACK *S);
void push(STACK *S, int n);
void pop(STACK *S);
int top(STACK S);
int isEmpty(STACK S);
void display(STACK *S);

int main()
{
    STACK S;
    initializeStack(&S);

    push(&S, 1);
    push(&S, 2);
    push(&S, 3);

    display(&S);

    pop(&S);
    printf("\n");
    display(&S);
    return 0;
}

void initializeStack(STACK *S)
{
    *S = NULL;
}

void push(STACK *S, int n)
{
    STACK temp;
    temp = (STACK)malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->data = n;
        temp->link = *S;
        *S = temp;
    }
}

void pop(STACK *S)
{
    if (*S != NULL)
    {
        STACK temp;
        temp = *S;
        *S = (*S)->link;
        free(temp);
    }
}

int top(STACK S)
{
    return S->data;
}

int isEmpty(STACK S)
{
    return (S != NULL) ? 0 : 1;
}

void display(STACK *S)
{
    STACK temp;
    int n;
    initializeStack(&temp);
    while (isEmpty(*S) == 0)
    {
        n = top(*S);
        printf("%d ", n);
        pop(S);
        push(&temp, n);
    }
    while (isEmpty(temp) == 0)
    {
        n = top(temp);
        pop(&temp);
        push(S, n);
    }
}