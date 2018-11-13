#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;
void Hanoi(char A, char B, char C, int n)
{
    if (n == 1)
    {
        printf("%c->%c\n", A, B);
    }
    else
    {
        Hanoi(A, B, C, n - 1);
        Hanoi(B, C, A, n - 1);
        Hanoi(A, B, C, 1);
        Hanoi(C, B, A, n - 1);
        Hanoi(B, A, C, n - 1);
        Hanoi(B, C, A, 1);
        Hanoi(A, B, C, n - 1);
        Hanoi(B, C, A, n - 1);
    }
}
int isArrayInSortedOrder(int A[], int n)
{
    if (n == 1)
        return 1;
    return (A[n - 1] < A[n - 2]) ? 0 : isArrayInSortedOrder(A, n - 1)
}
int main()
{
    Hanoi('A', 'B', 'C', 3);
    system("pause");

    return 0;
}