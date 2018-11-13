#include <stdio.h>
#include <stdlib.h>

struct CLLNode
{
    int data;
    struct CLLNode *next;
};
int CircularListLength(struct CLLNode *head)
{
    struct CLLNode *current = head;
    int count = 0;
    if (head == NULL)
        return 0;
    do
    {
        current = current->next;
        count++;
    } while (current != NULL);

    return count;
}
//Printing the Contents of a Circular Linked List
void PrintCircularListData(struct CLLNode *head)
{
    struct CLLNode *current = head;
    if (head == NULL)
        return;
    do
    {
        printf("%d", current->data);
        current = current->next;
    } while (current != head);
}

void InsertAtEndInCLL(struct CLLNode **head, int data)
{
    struct CLLNode *current = *head;
    struct CLLNode *newNode = (struct CLLNode *)(malloc(sizeof(struct CLLNode)));
    if (!newNode)
    {
        printf("Memory Error");
        return;
    }
    newNode->data = data;
    while (current->next != *head)
        current = current->next;
    newNode->next = newNode;
    if (*head == NULL)
        *head = newNode;
    else
    {
        newNode->next = *head;
        current->next = newNode;
    }
}
void InsertAtBeginInCLL(struct CLLNode **head, int data)
{
    struct CLLNode *current = *head;
    struct CLLNode *newNode = (struct CLLNode *)(malloc(sizeof(struct CLLNode)));
    if (!newNode)
    {
        printf("Memory Error");
        return;
    }
    newNode->data = data;
    while (current->next != *head)
        current = current->next;
    newNode->next = newNode;
    if (*head == NULL)
        *head = newNode;
    else
    {
        newNode->next = *head;
        current->next = newNode;
        *head = newNode;
    }
    return;
}
void DeleteLastNodeFromCLL(struct CLLNode **head)
{
    struct CLLNode *temp = *head, *current = *head;
    if (*head == NULL)
    {
        printf("List Empty");
        return;
    }
    while (current->next != *head)
    {
        temp = current;
        current = current->next;
    }
    temp->next = current->next;
    free(current);
    return;
}