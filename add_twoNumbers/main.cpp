#include <stdio.h>
#include <c++/3.4.5/iostream>

using namespace std;
struct ListNode
{
    long val;
    ListNode *next;
    ListNode(long x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        long *a = ListTolong(l1, sizeof(l1) / sizeof(*l1));
        long *b = ListTolong(l2, sizeof(l2) / sizeof(*l2));
        // printf("a:%d\n", a);
        // printf("b:%d\n", b);

        return longToList(a, sizeof(a) / sizeof(*a), b, sizeof(b) / sizeof(*b));
    }
    long *ListTolong(ListNode *l1, long size)
    {
        ListNode *p = l1;
        // long result = 0;
        long i = 0;
        long *result = (long *)malloc(sizeof(long) * size);
        while (i < size)
        {
            printf("p->val:%d\n", p->val);
            // result += i * p->val;
            // i = i * 10;
            result[i] = p->val;
            p = p->next;
            i++;
        }
        return result;
    }
    ListNode *longToList(long *a, long size_a, long *b, long size_b)
    {
        ListNode *head;
        ListNode *q = new ListNode((a[0] + b[0]) % 10);
        head = q;
        long i = i;
        for (; i < size_a || i < size_b; i++)
        {
            if (i < size_a && i < size_b)
            {
                q->next = new ListNode(a[i] + b[i] + (a[i - 1] + b[i - 1]) / 10);
                q = q->next;
                printf("%d", q->val);
            }
            else if (i < size_a)
            {
                q->next = new ListNode(a[i]);
                q = q->next;
                printf("%d", q->val);
            }
            else if (i < size_b)
            {
                q->next = new ListNode(b[i]);
                q = q->next;
                printf("%d", q->val);
            }
            else
                return head;
        }
    }
};
ListNode *initList(long *array, int size)
{
    ListNode *head = new ListNode(array[0]);
    ListNode *p = head;
    for (long i = 1; i < size; i++)
    {
        p->next = new ListNode(array[i]);
        p = p->next;
    }
    return head;
}
void showList(ListNode *L)
{
    while (L)
    {
        printf("%d\n", L->val);
        L = L->next;
    }
}
int main()
{
    long array1[] = {9};
    long array2[] = {1, 9, 9, 9, 9, 9, 9, 9};
    // printf("%d", sizeof(array2));
    ListNode *l1 = initList(array1, sizeof(array1) / sizeof(*array1));
    ListNode *l2 = initList(array2, sizeof(array2) / sizeof(*array2));
    showList(l1);
    showList(l2);
    Solution s = Solution();
    ListNode *L = s.addTwoNumbers(l1, l2);
    showList(L);
    return 0;
}
