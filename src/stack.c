#include <stack.h>
#include <stdlib.h>

Stack* createStack(int size)
{
    Stack *S = (Stack*)malloc(sizeof(Stack));
    S->size = size;
    S->data = (int32_t*)malloc(sizeof(int32_t)*size);
    S->top = -1;
    return S;
}

bool stackEmpty(Stack *S)
{
    return (S->top == -1) ? true : false;
}

int push(Stack *S, int x)
{
    if (S->top >= S->size - 1)
    {
        return STACK_ERROR;
    }
    S->data[++S->top] = x;
    return 0;
}

int pop(Stack *S)
{
    if (stackEmpty(S))
    {
        return STACK_ERROR;
    }
    else
    {
        return S->data[S->top--];
    }
}