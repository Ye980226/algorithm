///insertion sort
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int lengthOfList(struct ListNode *head)
{
    int i = 0;
    while (head)
    {
        head = head->next;
        i++;
    }
    return i;
}
struct ListNode *insertionSortList(struct ListNode *head)
{
    struct ListNode *p = head;
    struct ListNode *q;
    int j = 0;
    int length = lengthOfList(head);
    for (int i = 0; i < length; i++)
    {
        // printf("j:%d\n",j++);
        q = p;

        // printf("pre:p->val:%d\n",p->val);
        // printf("q->val:%d\n",q->val);
        int k = 0;
        while (q && q->next)
        {
            // printf("k:%d\n",k++);
            // printf("1:p->val:%d",p->val);
            if ((q->val) > (q->next->val))
            {
                int temp = q->val;
                q->val = q->next->val;
                // printf("2:p->val:%d",p->val);
                q->next->val = temp;
            }
            q = q->next;
            // printf("post:p->val:%d\n",p->val);
            // printf("post:q->val:%d\n",q->val);
        }
        // printf("***************\n");
    }
    return head;
}

///quicksort
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
struct ListNode *GetPartion(struct ListNode *pBegin, struct ListNode *pEnd)
{
    int val = pBegin->val;
    struct ListNode *p = pBegin;
    struct ListNode *q = p->next;

    while (q != pEnd)
    {
        if (q->val < val)
        {
            p = p->next;
            swap(&p->val, &q->val);
        }

        q = q->next;
    }
    swap(&p->val, &pBegin->val);
    return p;
}
void QuickSort(struct ListNode *pBeign, struct ListNode *pEnd)
{
    if (pBeign != pEnd)
    {
        struct ListNode *partion = GetPartion(pBeign, pEnd);
        QuickSort(pBeign, partion);
        QuickSort(partion->next, pEnd);
    }
}
struct ListNode *insertionSortList(struct ListNode *head)
{
    QuickSort(head, NULL);
    return head;
}