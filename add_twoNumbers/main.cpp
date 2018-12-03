#include <stdio.h>

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
        ListNode *head;
        ListNode *q = new ListNode((l1->val + l2->val) % 10);
        l1 = l1->next;
        l2 = l2->next;
        head = q;
        static int val = (l1->val + l2->val) / 10;
        for (; l1 || l2;)
        {
            if (l1 && l2)
            {
                q->next = new ListNode((l1->val + l2->val + val) % 10);
                val = (l1->val + l2->val + val) / 10;
                q = q->next;
                printf("%d\n", q->val);
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1)
            {
                q->next = new ListNode((l1->val + val) % 10);
                val = (l1->val + val) / 10;
                q = q->next;
                printf("%d\n", q->val);
                val = 0;
                l1 = l1->next;
            }
            else if (l2)
            {
                q->next = new ListNode((l2->val + val) % 10);
                val = (l2->val + val) / 10;
                q = q->next;
                printf("%d\n", q->val);
                val = 0;
                l2 = l2->next;
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
        printf("%d\n",L->val);
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
    // showList(l1);
    // showList(l2);
    Solution s = Solution();
    ListNode *L = s.addTwoNumbers(l1, l2);
    showList(L);
    return 0;
}
