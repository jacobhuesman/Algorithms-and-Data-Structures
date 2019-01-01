#include <queue.h>
#include <eval.h>

void buildQueue_test()
{
    printf("\n" "buildQueue_test:\n");
    Queue *Q = buildQueue(10);
    ASSERT(Q->length == 10);
    ASSERT(Q->head == 0);
    ASSERT(Q->tail == 0);
    deleteQueue(Q);
}

void enqueue_test()
{
    printf("\n" "enqueue_test:\n");
    Queue *Q = buildQueue(3);
    ASSERT(Q->tail == 0);
    ASSERT(Q->head == 0);
    ASSERT(enqueue(Q, 10) != QUEUE_ERROR);
    ASSERT(Q->tail == 1);
    ASSERT(Q->head == 0);
    ASSERT(enqueue(Q, 20) != QUEUE_ERROR);
    ASSERT(Q->tail == 2);
    ASSERT(Q->head == 0);
    ASSERT(enqueue(Q, 30) != QUEUE_ERROR);
    ASSERT(Q->tail == 3);
    ASSERT(Q->head == 0);
    ASSERT(enqueue(Q, 40) == QUEUE_ERROR); 
    ASSERT(Q->tail == 3);
    ASSERT(Q->head == 0);
    deleteQueue(Q);
}

void dequeue_test()
{
    printf("\n" "dequeue_test:\n");
    Queue *Q = buildQueue(3);
    ASSERT(enqueue(Q, 10) != QUEUE_ERROR);
    ASSERT(enqueue(Q, 20) != QUEUE_ERROR);
    ASSERT(enqueue(Q, 30) != QUEUE_ERROR);
    ASSERT(Q->tail == 3);
    ASSERT(Q->head == 0);
    ASSERT(dequeue(Q) == 10);
    ASSERT(Q->tail == 3);
    ASSERT(Q->head == 1);
    ASSERT(dequeue(Q) == 20);
    ASSERT(Q->tail == 3);
    ASSERT(Q->head == 2);
    ASSERT(dequeue(Q) == 30);
    ASSERT(Q->tail == 3);
    ASSERT(Q->head == 3);
    ASSERT(dequeue(Q) == QUEUE_ERROR);
    deleteQueue(Q);
}

void enqueue_dequeue_test()
{
    printf("\n" "enqueue_dequeue_test:\n");
    Queue *Q = buildQueue(3);
    ASSERT(enqueue(Q, 10) != QUEUE_ERROR);
    ASSERT(enqueue(Q, 20) != QUEUE_ERROR);
    ASSERT(dequeue(Q) == 10);
    ASSERT(dequeue(Q) == 20);
    ASSERT(dequeue(Q) == QUEUE_ERROR);
    ASSERT(Q->tail == 2);
    ASSERT(Q->head == 2);
    ASSERT(enqueue(Q, 30) != QUEUE_ERROR);
    ASSERT(enqueue(Q, 40) != QUEUE_ERROR);
    ASSERT(enqueue(Q, 50) != QUEUE_ERROR);
    ASSERT(enqueue(Q, 60) == QUEUE_ERROR);
    ASSERT(Q->tail == 1);
    ASSERT(Q->head == 2);
    deleteQueue(Q);
}

void main()
{
    printf("\n" "Running: %s\n", __FILE__);
    buildQueue_test();
    enqueue_test();
    dequeue_test();
    enqueue_dequeue_test();
    printf("\n");
}