#ifndef STACK_H
#define STACK_H

#include <limits.h>
#include <stdbool.h>

#define STACK_ERROR INT_MIN

typedef struct
{
    int size;
    int top;
    int *data;
} Stack;

Stack* createStack(int size);
void deleteStack(Stack *S);
bool stackEmpty(Stack *S);
int push(Stack *S, int x);
int pop(Stack *S);


#endif // STACK_H