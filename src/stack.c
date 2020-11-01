/*
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

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