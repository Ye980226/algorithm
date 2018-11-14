#include <stdio.h>
#include <stdlib.h>
#define MAXSKIPLEVEL 5
struct ListNode
{
    int data;
    struct ListNode *next[1];
};
struct SkipList
{
    struct ListNode *header;
    int listLevel; //current level of list
};
struct SkipList list;
struct ListNode *insertElement(int data)
{
    int i, newLevel;
    struct ListNode *update[MAXSKIPLEVEL + 1];
    struct ListNode *temp;
    temp = list.header;
    for (i = list.listLevel; i >= 0; i--)
    {
        while (temp->next[i] != list.header && temp->next[i]->data < data)
            temp = temp->next[i];
        update[i] = temp;
    }
    temp = temp->next[0];
    if (temp != list.header && temp->data == data)
        return (temp);
    //determine level
    for (newLevel = 0; rand() < RAND_MAX / 2 && newLevel < MAXSKIPLEVEL; newLevel++)
        ;
    if (newLevel > list.listLevel)
    {
        for (i = list.listLevel + 1; i <= newLevel; i++)
            update[i] = list.header;
        list.listLevel = newLevel;
    }
    //make new node
    if ((temp = (ListNode *)malloc(sizeof(ListNode) + newLevel * sizeof(ListNode *))) == 0)
    {
        printf("insufficient memory (insertElement)\n");
    }
    temp->data = data;
    for (i = 0; i < newLevel; i++)
    { //update next links
        temp->next[i] = update[i]->next[i];
        update[i]->next[i] = temp;
    }
    return (temp);
}
//delete node containing data
void deleteElement(int data)
{
    return;
}
