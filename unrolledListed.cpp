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
    while (k--)
    {
        q = q->next;
    }
    *fListNode = q;
}
//start shift operation from block *p
void shift(struct LinkedBlock *A)
{
    struct LinkedBlock *B;
    struct ListNode *temp;
    while (A->nodeCount > blockSize)
    { //if this block still have to shift
        if (A->next == NULL)
        { //read the end. A little different
            A->next = newLinkedBlock();
            B = A->next;
            temp = A->head->next;
            A->head->next = A->head->next->next;
            temp->next = B->head->next;
            B->head->next = temp;
            B->head = temp;
            A->nodeCount--;
            B->nodeCount++;
        }
        A = B;
    }
}
void addElement(int k, int x)
{
    struct ListNode *p, *q;
    struct LinkedBlock *r;
    if (!blockHead)
    { //initial,first node and block
        blockHead->head = newListNode(x);
        blockHead->head->next = blockHead->head;
        blockHead->nodeCount++;
    }
    else
    {
        if (k == 0)
        { //special case for k=0
            p = blockHead->head;
            q = p->next;
            p->next = newListNode(x);
            p->next->next = q;
            blockHead->head = p->next;
            blockHead->nodeCount++;
            shift(blockHead);
        }
        else
        {
            searchElement(k, &r, &p);
            q = p;
            while (q->next != p)
                q = q->next;
            q->next = newListNode(x);
            q->next->next = p;
            r->nodeCount++;
            shift(r);
        }
    }
}
int searchElement(int k)
{
    struct ListNode *p;
    struct LinkedBlock *q;
    searchElement(k, &q, &p);
    return p->value;
}
int testUnRolledLinkedList()
{
    int tt = clock();
    int m, i, k, x;
    char cmd[10];
    scanf("%d", &m);
    blockSize = (int)(sqrt(m - 0.001)) + 1;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &k, &x);
        addElement(k, x);
    }
    if (strcmp(cmd, "add") == 0)
    {
        scanf("%d %d", &k, &x);
        addElement(k, x);
    }
    else if (strcmp(cmd, "search") == 0)
    {
        scanf("%d", &k);
        printf("%d\n", searchElement(k));
    }
    else
    {
        fprintf(stderr, "Wrong Input\n");
    }
    return 0;
}