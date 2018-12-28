#ifndef HEAP_H
#define HEAP_H

#define PARENT(i) (((i + 1) >> 1) - 1)
#define LEFT(i)   (((i + 1) << 1) - 1)
#define RIGHT(i)  ( (i + 1) << 1     )

void maxHeapify(int size, int *A, int i);
void buildMaxHeap(int size, int *A);

#endif // HEAP_H