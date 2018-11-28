#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 10
struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};
struct ArrayStack *CreateStack()
{
    struct ArrayStack *S = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
    if (!S)
        return NULL;
    S->capacity = MAXSIZE;
    S->top = -1;
    S->array = (int *)malloc(S->capacity * sizeof(int));
    if (S->array)
        return NULL;
    return S;
}
int IsEmptyStack(struct ArrayStack *S)
{
    return (S->top == -1);
}
int IsFullStack(struct ArrayStack *S)
{
    return (S->top == S->capacity - 1);
}
void Push(struct ArrayStack *S, int data)
{
    if (IsFullStack(S))
        printf("Stack Overflow");
    else
        S->array[++S->top] = data;
}
int Pop(struct ArrayStack *S)
{
    if (IsEmptyStack(S))
    {
        printf("Stack is Empty");
        return __INT16_MAX__;
    }
    else
        return (S->array[S->top--]);
}
void DeleteStack(struct ArrayStack *S)
{
    if (S)
    {
        if (S->array)
            free(S->array);
        free(S);
    }
}