#include <stack.h>
#include <eval.h>

void createStack_test()
{
    printf("\n" "createStack_test:\n");
    Stack *S = createStack(10);
    ASSERT(S->size == 10);
    ASSERT(S->top == -1);
}

void stackEmpty_test()
{
    printf("\n" "stackEmpty_test:\n");
    Stack *S = createStack(10);
    ASSERT(stackEmpty(S) == true);
    push(S, 1);
    ASSERT(stackEmpty(S) == false);
    pop(S);
    ASSERT(stackEmpty(S) == true);
}

void push_test()
{
    printf("\n" "push_test:\n");
    Stack *S = createStack(2);
    ASSERT(S->top == -1);
    ASSERT(push(S, 100) != STACK_ERROR);
    ASSERT(S->top == 0);
    ASSERT(push(S, 200) != STACK_ERROR);
    ASSERT(S->top == 1);
    ASSERT(push(S, 300) == STACK_ERROR);
    ASSERT(S->top == 1);    
}

void pop_test()
{
    printf("\n" "pop_test:\n");
    Stack *S = createStack(10);
    ASSERT(S->top == -1);
    ASSERT(push(S, 100) != STACK_ERROR);
    ASSERT(S->top == 0);
    ASSERT(push(S, 200) != STACK_ERROR);
    ASSERT(S->top == 1);
    ASSERT(push(S, 300) != STACK_ERROR);
    ASSERT(S->top == 2);
    ASSERT(pop(S) == 300);
    ASSERT(S->top == 1);
    ASSERT(pop(S) == 200);
    ASSERT(S->top == 0);
    ASSERT(pop(S) == 100);
    ASSERT(S->top == -1);
    ASSERT(pop(S) == STACK_ERROR);
    ASSERT(S->top == -1); 
}

void main()
{
    printf("\nRunning %s\n", __FILE__);
    createStack_test();
    stackEmpty_test();
    push_test();
    pop_test();
    printf("\n");
}