#include <stack.h>
#include <stdlib.h>

Stack* createStack(int size)
{
    Stack *S = (Stack*)malloc(sizeof(Stack));
    S->size = size;
    S->top = -1;
    S->data = (int*)malloc(sizeof(int)*size);
    return S;
}

void deleteStack(Stack *S)
{
    free(S->data);
    free(S);
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