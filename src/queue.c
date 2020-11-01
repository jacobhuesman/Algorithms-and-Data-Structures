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

#include <queue.h>
#include <stdio.h>
#include <stdlib.h>

Queue* buildQueue(int length)
{
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    Q->data = (int*)malloc(sizeof(int)*(length + 1));
    if (Q == NULL || Q->data == NULL)
    {
        printf("Unable to allocate memory\n");
        return NULL;
    }
    Q->length = length;
    Q->head = 0;
    Q->tail = 0;
}

void deleteQueue(Queue *Q)
{
    free(Q->data);
    free(Q);
}

int enqueue(Queue *Q, int x)
{
    // Check for overflow
    if (Q->head == Q->tail + 1 || 
       (Q->head == 0 && Q->tail == Q->length))
    {
        return QUEUE_ERROR;
    }
    // Enqueue element
    Q->data[Q->tail] = x;
    if (Q->tail == Q->length)
    {
        Q->tail = 0;
    }
    else
    {
        Q->tail++;
    }
    return 0;
}

int dequeue(Queue *Q)
{
    // Check for underflow
    if (Q->head == Q->tail)
    {
        return QUEUE_ERROR;
    }
    // Dequeue element
    int x = Q->data[Q->head];
    if (Q->head == Q->length)
    {
        Q->head = 0;
    }
    else
    {
        Q->head++;
    }
    return x;
}