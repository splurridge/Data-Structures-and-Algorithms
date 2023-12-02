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

Studrec deleteID(int ID, StudList *list)
{
    Studrec delID;
    StudList prev = NULL;
    for (StudList current = *list; current != NULL; prev = current, current = current->link)
    {
        if (current->stud.ID == ID)
        {
            delID = current->stud;
            if (prev == NULL)
            {
                *list = current->link;
            }
            else
            {
                prev->link = current->link;
            }
            free(current);
        }
    }
    return delID;
}

Studrec deleteID(int ID, StudList *list) {
    StudList current, node = NULL;
    Studrec delID;
    for (current = *list; current != NULL; node = current, current = current->link) {
        if (current->stud.ID == ID) {
            delID = current->stud;
            if (node == NULL) {
                *list = current->link;
            } else {
                node->link = current->link;
            }
            free(current);
        }
    }
    return delID;
}

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
    insertUniqueFront(3, "Johnson", "Adam", 'M', "MATH101", 1, &list);

    // Delete element by ID and get the deleted element
    Studrec deleted = deleteID(2, &list);

    // Display the deleted element (or indicate if not found)
    if (deleted.ID != -1)
    {
        printf("Deleted Element - ID: %d, Name: %s %s %c, Course: %s, Year Level: %d\n",
               deleted.ID, deleted.FN, deleted.LN,
               deleted.MI, deleted.course, deleted.yearLevel);
    }
    else
    {
        printf("Element with ID %d not found.\n", 2);
    }

    // Display the updated list
    for (StudList trav = list; trav != NULL; trav = trav->link)
    {
        printf("ID: %d, Name: %s %s %c, Course: %s, Year Level: %d\n",
               trav->stud.ID, trav->stud.FN, trav->stud.LN,
               trav->stud.MI, trav->stud.course, trav->stud.yearLevel);
    }

    // Free allocated memory
    while (list != NULL)
    {
        StudList temp = list;
        list = list->link;
        free(temp);
    }

    return 0;
}