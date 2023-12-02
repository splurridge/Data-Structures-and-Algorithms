#include <stdio.h>
#include <stdlib.h>

#define VH_MAX 0XFF
#define MAX 0xA

typedef struct
{
    char FN[24], LN[16], MI;
} nametype;

typedef struct
{
    char ID[10];
    nametype name;
    char course[8];
    int yrLevel;
} studRec;

/* Definition of virtual heap */
typedef struct
{
    studRec stud;
    int link; // -1 if not pointing to say CBnode
} CBnode;

typedef struct
{
    CBnode heap[VH_MAX];
    int avail;
} *Vheap; // virtual heap

/* Definition of Cursor List */
typedef int CursorList;

/* Definition of ArrayList */
typedef struct node
{
    studRec data[MAX];
    int studCtr;
} *ArrayList;

int insertCList(ArrayList list, int num)
{
    if (list == NULL || list->studCtr >= MAX)
    {
        return -1; // Invalid list or list is full
    }

    int i = list->studCtr - 1;

    // Modify this comparison based on the specific field of studRec
    while (i >= 0 && list->data[i].yrLevel > num)
    {
        list->data[i + 1] = list->data[i];
        i--;
    }

    list->data[i + 1].yrLevel = num; // Assuming yrLevel is the field to be sorted
    list->studCtr++;

    return list->studCtr;
}

int main()
{
    // Example usage of insertCList

    ArrayList myList = (ArrayList)malloc(sizeof(struct node));
    if (myList == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Initializing the list
    myList->studCtr = 0;

    // Inserting elements (numbers) into the sorted ArrayList
    printf("Number of elements after each insertion:\n");
    printf("Initial count: %d\n", insertCList(myList, 5));
    printf("After inserting 3: %d\n", insertCList(myList, 3));
    printf("After inserting 8: %d\n", insertCList(myList, 8));
    printf("After inserting 1: %d\n", insertCList(myList, 1));
    printf("After inserting 6: %d\n", insertCList(myList, 6));

    free(myList);

    return 0;
}
