#include <stdio.h>

#define MAX 5

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} QUEUE;

void initializeQueue(QUEUE *Q);
void enqueue(QUEUE *Q, int elem);
void dequeue(QUEUE *Q);
int front(QUEUE Q);
int isEmpty(QUEUE Q);
void display(QUEUE *Q);

int main()
{
    QUEUE Q;
    initializeQueue(&Q);

    enqueue(&Q, 1);
    enqueue(&Q, 2);
    enqueue(&Q, 3);

    display(&Q);

    dequeue(&Q);
    printf("\n");
    display(&Q);
}

void initializeQueue(QUEUE *Q)
{
    Q->front = 0;
    Q->rear = -1;
}

void enqueue(QUEUE *Q, int elem)
{
    if (Q->front == (Q->rear + 2) % MAX)
        printf("Queue is full.");
    Q->rear = (Q->rear + 1) % MAX;
    Q->data[Q->rear] = elem;
}

void dequeue(QUEUE *Q)
{
    if (Q->front == (Q->rear + 1) % MAX)
        printf("Queue is empty.");
    Q->front = (Q->front + 1) % MAX;
}

int front(QUEUE Q)
{
    return Q.data[Q.front];
}

int isEmpty(QUEUE Q)
{
    return (Q.front == (Q.rear + 1) % MAX) ? 1 : 0;
}

void display(QUEUE *Q)
{
    int i;
    for (i = Q->front; i != (Q->rear + 1) % MAX; i = (i + 1) % MAX)
    {
        printf("%d ", Q->data[i]);
    }
}
