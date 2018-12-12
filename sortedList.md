#### problem
Sort a linked list using insertion sort.

![Insertion-sort-example-300px.gif](Insertion-sort-example-300px.gif)
A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
```c

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
```

```c
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
    //在快排里交换两个元素，head的指向啥的都不修改，但是地址上的元素已经修改。
    QuickSort(head, NULL);
    return head;
}
```
插入排序是遍历整个链表，拿到每一个元素不断向后移，直到遇到NULL暂停，在后移过程中，如果遇到比自己小的数，就交换两个数字，直到遍历完整个链表。

快速排序是用递归实现，这里使用第一个元素作为pivot，GetPartion函数将比pivot小和大的分成两组，不断地递归分成小和大的两组，小的在左边，大的在右边。
