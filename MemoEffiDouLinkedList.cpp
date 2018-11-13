//Memory Efficient Double Linked List
struct ListNode
{
    int data;
    ListNode *ptrdiff; //pointer to previous node ⊕ pointer to next node.(exclusive-or)异或
};
/*
To find the answer to this question let us consider the properties of ⊕:
    X ⊕ X=0
    X ⊕ 0 = X
    X ⊕ Y = Y ⊕ X (symmetric)
    (X ⊕ Y) ⊕ Z = X ⊕ (Y ⊕ Z) (transitive)  
For the example above, let us assume that we are at C node and want to move to B. We know that C’s ptrdiff is defined as B ⊕ D. If we want to move to B, performing ⊕ on C’s ptrdiff with D would give B. This is due to the fact that
(B ⊕ D) ⊕ D = B(since, D ⊕ D= 0)
Similarly, if we want to move to D, then we have to apply ⊕ to C’s ptrdiff with B to give D.
(B ⊕ D) ⊕ B = D (since, B © B=0)
From the above discussion we can see that just by using a single pointer, we can move back and forth. A memory-efficient implementation of a doubly linked list is possible with minimal compromising of timing efficiency.
*/

