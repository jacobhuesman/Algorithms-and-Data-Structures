#ifndef HEAP_H
#define HEAP_H

#define PARENT(i) (i >> 2)
#define LEFT(i) (i << 2)
#define RIGHT(i) ((i << 2) + 1)

void maxHeapify(int size, int *A, int i);

#endif // HEAP_H