#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} *Node;

typedef struct
{
    Node front;
    Node rear;
} QUEUE;

void initializeQueue(QUEUE *Q);
int isEmpty(QUEUE Q);
void enqueue(QUEUE *Q, int elem);
void dequeue(QUEUE *Q);
int front(QUEUE Q);
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
    Q->front = NULL;
    Q->rear = NULL;
}

int isEmpty(QUEUE Q)
{
    return (Q.front == NULL) ? 1 : 0;
}

void enqueue(QUEUE *Q, int elem)
{
    Node temp = (Node)malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->data = elem;
        temp->next = NULL;

        if (isEmpty(*Q) ? (Q->front = temp) : (Q->rear->next = temp))
        {
            Q->rear = temp;
        }
    }
}

void dequeue(QUEUE *Q)
{
    Node temp;
    if (!isEmpty(*Q))
    {
        temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
    }
    if (isEmpty(*Q))
    {
        Q->rear = NULL;
    }
}

int front(QUEUE Q)
{
    if (isEmpty(Q) == 0)
        return Q.front->data;
    return -1;
}

void display(QUEUE *Q)
{
    Node current = Q->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}
