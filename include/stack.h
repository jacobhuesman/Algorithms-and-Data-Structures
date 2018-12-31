#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <stdbool.h>

#define STACK_ERROR INT32_MIN

typedef struct
{
    int32_t size;
    int32_t *data;
    int32_t top;
} Stack;

Stack* createStack(int size);
bool stackEmpty(Stack *stack);
int push(Stack *stack, int x);
int pop(Stack *stack);


#endif // STACK_H