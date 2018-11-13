// struct ListNode
// {
//     int data;
//     ListNode *prev;
//     ListNode *next;
// };
// struct LinkedBlock
// {
//     struct LinkedBlock *next;
//     struct ListNode *head;
//     int nodeCount;
// };
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int blockSize; //max number of nodes in a block
struct ListNode
{
    struct ListNode *next;
    int value;
};
struct LinkedBlock
{
    struct LinkedBlock *next;
    struct ListNode *head;
    int nodeCount;
};
struct LinkedBlock *blockHead;
//create an empty block
struct LinkedBlock *newLinkedBlock()
{
    struct LinkedBlock *block = (struct LinkedBlock *)malloc(sizeof(struct LinkedBlock));
    block->next = NULL;
    block->head = NULL;
    block->nodeCount = 0;
    return block;
}
//create a node
struct ListNode *newListNode(int value)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->next = NULL;
    temp->value = value;
    return temp;
}
void searchElement(int k, struct LinkedBlock **fLinkedBlock, struct ListNode **fListNode)
{
    //find the block
    int j = (k + blockSize - 1) / blockSize; //k-th node is in the j-th block
    struct LinkedBlock *p = blockHead;
    while (--j)
    {
        p = p->next;
    }
    *fLinkedBlock = p;
    //find the node
    struct ListNode *q = p->head;
    k = k % blockSize;
    if (k == 0)
        k = blockSize;
    k = p->nodeCount + 1 - k;
    while(k--){
        q = q->next;
    }
    *fListNode = q;
}
//start shift operation from block *p
void shift(struct LinkedBlock*A){
    struct LinkedBlock *B;
    struct ListNode *temp;
    while(A->nodeCount>blockSize){
        if(A->next==NULL){
            
        }
    }
}