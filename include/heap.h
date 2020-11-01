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

#ifndef HEAP_H
#define HEAP_H

#define PARENT(i) (((i + 1) >> 1) - 1)
#define LEFT(i)   (((i + 1) << 1) - 1)
#define RIGHT(i)  ( (i + 1) << 1     )

void maxHeapify(int size, int *A, int i);
void buildMaxHeap(int size, int *A);
void heapSort(int size, int *A);
int heapMaximum(int *A);
int heapExtractMax(int *size, int *A);
void heapIncreaseKey(int size, int *A, int i, int key);
void maxHeapInsert(int *size, int **A, int key);

#endif // HEAP_H