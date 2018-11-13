#include <stdio.h>
#include <stdlib.h>
//Main Linked Lists Operations
//Insert :inserts an element into the list
//Delete:removes and returns the specified position element from the list
// Auxiliary Linked Lists Operations
// • Delete List : removes all elements of the list(disposes the list)
// • Count : returns the number of elements in the list
// • Find nth node from the end of the list
struct ListNode
{
    int data;
    struct ListNode *next;
};
//Traversing the Linked List
int ListLength(struct ListNode *head)
{
    struct ListNode *current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
//Singly Lineked List Insertion
void InsertInLinkedList(struct ListNode **head, int data, int position)
{
    int k = 0;
    struct ListNode *p, *q, *newNode;
    newNode = (ListNode *)malloc(sizeof(struct ListNode));
    if (!newNode)
    {
        printf("Memory Error");
        return;
    }
    newNode->data = data;
    p = *head;
    //Inserting at the beginning
    if (position == 0)
    {
        newNode->next = p;
        *head = newNode;
    }
    else
    {
        //Traverse the list until the position where we want to insert
        while ((p != NULL) && (k < position))
        {
            k++;
            q = p;
            p = p->next;
        }
        q->next = newNode;
        newNode->next = p;
    }
}
//Singly Linked List Deletion
void DeleteNodeFromLinkedList(struct ListNode **head, int position)
{
    int k = 0;
    struct ListNode *p, *q;
    if (*head == NULL)
    {
        printf("List Empty");
        return;
    }
    p = *head;
    /*from the beginning*/
    if (position == 0)
    {
        *head = (*head)->next;
        free(p);
        return;
    }
    else
    {
        //Traverse the list until arriving at the position from which we want to delete
        while ((p != NULL) && (k < position))
        {
            k++;
            q = p;
            p = p->next;
        }
        if (p == NULL) //At the end
            printf("Position does not exist.");
        else
        {
            q->next = p->next;
            free(p);
        }
    }
}
//Deleting Singly Linked List
void DeleteLinkedList(struct ListNode **head)
{
    struct ListNode *auxilaryNode, *iterator;
    iterator = *head;
    while (iterator)
    {
        auxilaryNode = iterator->next;
        free(iterator);
        iterator = auxilaryNode;
    }
    *head = NULL;
}
