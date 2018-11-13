#include <stdio.h>
#include <stdlib.h>
struct DLLNode
{
    int data;
    struct DLLNode *next;
    struct DLLNode *prev;
};
void DLLInsert(struct DLLNode **head, int data, int position)
{
    int k = 0;
    struct DLLNode *temp, *newNode;
    newNode = (struct DLLNode *)malloc(sizeof(struct DLLNode));
    if (!newNode)
    {
        printf("Memory Error");
        return;
    }
    newNode->data = data;
    if (position == 0)
    {
        newNode->next = *head;
        newNode->prev = NULL;
        if (*head)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    temp = *head;
    while ((k < position - 1) && temp->next != NULL)
    {
        temp = temp->next;
        k++;
    }
    if (k != position)
    {
        printf("Desired position does not exist\n");
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
    return;
}

void DLLDelete(struct DLLNode **head, int position)
{
    struct DLLNode *temp, *temp2;
    temp = *head;
    int k = 0;
    if (*head == NULL)
    {
        printf("List is empty");
        return;
    }
    if (position == 0)
    {
        *head = (*head)->next;

        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }
    while ((k < position) && temp->next != NULL)
    {
        temp = temp->next;
        k++;
    }
    if (k != position - 1)
    {
        printf("Desired position does not exist\n");
    }
    temp2 = temp->prev;       //找到前一个Node
    temp2->next = temp->next; //把前一个Node指向后一个Node
    if (temp->next)
        temp->next->prev = temp2; //把后一个Node指向前一个Node
    free(temp);                   //释放该Node
    return;
}
