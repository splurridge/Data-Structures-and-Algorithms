#include <stdio.h>

#define MAX 20

typedef struct
{
    int elem[MAX];
    int top;
} STACK;

void initializeStack(STACK *S);
void push(STACK *S, int n);
int pop(STACK *S);
int isFull(STACK S);
int isEmpty(STACK S);
void display(STACK S);

int main()
{
    STACK S;
    initializeStack(&S);

    push(&S, 1);
    push(&S, 2);
    push(&S, 3);

    display(S); // Display the stack

    int poppedValue = pop(&S);
    if (poppedValue != -1)
    {
        printf("\nPopped: %d\n", poppedValue);
    }
    display(S); // Display the modified stack

    return 0;
}

void initializeStack(STACK *S)
{
    S->top = -1;
}

void push(STACK *S, int n)
{
    if (isFull(*S))
    {
        printf("Stack is full.\n");
    }
    else
    {
        S->elem[++(S->top)] = n;
    }
}

int pop(STACK *S)
{
    if (isEmpty(*S))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return S->elem[(S->top)--];
}

int isFull(STACK S)
{
    return (S.top == MAX - 1) ? 1 : 0;
}

int isEmpty(STACK S)
{
    return (S.top == -1) ? 1 : 0;
}

void display(STACK S)
{
    if (isEmpty(S))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack: ");
        for (int i = 0; i <= S.top; i++)
        {
            printf("%d ", S.elem[i]);
        }
        printf("\n");
    }
}
