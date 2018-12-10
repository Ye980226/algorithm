### Problem

Reverse a singly linked list.

Example:

```c++
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
```

### Answer

```c

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *p = head;     //p指向头结点，为了重新构建反转链表
    struct ListNode *node = NULL;  //node用来存储前一个的节点，即下一个节点的p->next;
    struct ListNode *p_rev = NULL; //存储剩下的链表，最后还给p
    if (head == NULL)
    {
        return NULL;
    }
    while (p->next)
    {
        p_rev = p->next; //除第一个节点以外剩下的节点，交给p_rev
        p->next = node;  //把node接到p的链表上
        node = p;        //然后把node变成了p
        p = p_rev;       //把剩下的节点又交给p，以此循环
    }
    p->next = node;
    return p;
```

反转链表是基本操作，最后一个p->next别忘了指向node，不然会造成断链。
时间复杂度是O(1)
