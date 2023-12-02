#include <stdio.h>

#define MAX 20

typedef struct
{
    int data;
    int next;
} STACK;

typedef struct
{
    STACK Nodes[MAX];
    int avail;
} VHeap;

// virtual heap operations
void initVirtualHeap(VHeap *VH);
void initialize(int *S);
int allocSpace(VHeap *VH);
void deallocSpace(VHeap *VH, int cell);

// stack operations
int top(VHeap VH, int S);
void pop(VHeap *VH, int *S);
void push(VHeap *VH, int *S, int elem);
int isEmpty(int S);
void insertLast(VHeap *VH, int *S, int elem);
void display(VHeap *VH, int *S);

int main()
{
}

void initVirtualHeap(VHeap *VH)
{
    VH->avail = 0;
    for (int i = 0; i < MAX; i++)
    {
        VH->Nodes[i].next = i + 1;
    }
    VH->Nodes[MAX - 1].next = -1; // initializes the "next" of the last Node to be -1
}

void initialize(int *S)
{
    *S = -1; // Initializes an empty Stack
}

int allocSpace(VHeap *VH)
{
    int i = VH->avail;
    if (VH != -1)
    {
        VH->avail = VH->Nodes[i].next;
        VH->Nodes[i].next = -1;
    }
    return i;

    /**
     * this function allocates and returns available space from the Virtual Heap
     * by updating the avail and marking the allocated space as used.
     **/
}

void deallocSpace(VHeap *VH, int cell)
{
    if (cell >= 0 && cell < MAX)
    {
        VH->Nodes[cell].next = VH->avail;
        VH->avail = cell;
    }

    /**
     * this function deallocates a space in the Virtual Heap by updating the next field
     * of the node and updating the avail to the deallocated cell, making
     * it available for subsequent allocations.
     **/
}

int top(VHeap VH, int S)
{
    return VH.Nodes[S].data;
}

void pop(VHeap *VH, int *S)
{
    if (*S != -1)
    {
        int temp = *S;
        *S = VH->Nodes[temp].next;
        deallocSpace(VH, temp);
    }
}

void push(VHeap *VH, int *S, int elem)
{
    int temp = allocSpace(VH);
    if (temp != -1)
    {
        VH->Nodes[temp].data = elem;
        VH->Nodes[temp].next = *S;
        *S = temp;
    }
}
