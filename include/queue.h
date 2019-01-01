#ifndef QUEUE_H
#define QUEUE_H

#include <limits.h>
#include <stdbool.h>

#define QUEUE_ERROR INT_MIN

typedef struct 
{
    int length;
    int head;
    int tail;
    int *data;
} Queue;

Queue* buildQueue(int length);
void deleteQueue(Queue *Q);
int enqueue(Queue *Q, int x);
int dequeue(Queue *Q);

#endif // QUEUE_H