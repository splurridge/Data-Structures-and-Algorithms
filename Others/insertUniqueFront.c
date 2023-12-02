#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int ID;
    char LN[16], FN[24], MI; // Lastname, Firstname, Middle Initial
    char course[8];
    int yearLevel;
} Studrec;

typedef struct node
{
    Studrec stud;
    struct node *link;
} *StudList; // Definition of the List

void insertUniqueFront(int newID, char newLN[], char newFN[], char newMI, char newCourse[], int newYrLevel, StudList *list)
{
    StudList trav, temp;
    for (trav = *list; trav != NULL && trav->stud.ID != newID; trav = trav->link)
    {
    }
    temp = (StudList)malloc(sizeof(struct node));
    temp->stud.ID = newID;
    strcpy(temp->stud.LN, newLN);
    strcpy(temp->stud.FN, newFN);
    temp->stud.MI = newMI;
    strcpy(temp->stud.course, newCourse);
    temp->stud.yearLevel = newYrLevel;
    temp->link = *list;
    *list = temp;
}

int main()
{
    StudList list = NULL; // Initialize an empty list

    // Example usage
    insertUniqueFront(1, "Doe", "John", 'M', "CS101", 2, &list);
    insertUniqueFront(2, "Smith", "Jane", 'F', "ENG202", 3, &list);
    insertUniqueFront(1, "Doe", "James", 'M', "MATH101", 1, &list); // This should not be inserted

    // Display the list
    for (StudList current = list; current != NULL; current = current->link)
    {
        printf("ID: %d, Name: %s %s %c, Course: %s, Year Level: %d\n",
               current->stud.ID, current->stud.FN, current->stud.LN,
               current->stud.MI, current->stud.course, current->stud.yearLevel);
    }

    // Free allocated memory
    for (StudList current = list; current != NULL;)
    {
        StudList temp = current;
        current = current->link;
        free(temp);
    }

    return 0;
}
