#include <bubble_sort.h>
#include <insertion_sort.h>
#include <merge_sort.h>
#include <quick_sort.h>
#include <randomized_quick_sort.h>
#include <heap.h>
#include <eval.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // Read in trial size
    int size = 1e5;
    if (argc > 1)
    {
        size = atoi(argv[1]);
    }
    printf("Trial size = %i\n", size);
    
    // Create array of random numbers
    int unsorted[size];
    for (int i = 0; i < size; i++)
    {
        unsorted[i] = rand();
    }
    
    // Sort with bubble sort
    int *bubble_sorted;
    clock_t bubble_start, bubble_end;
    cloneArray(size, unsorted, &bubble_sorted);
    bubble_start = clock();
    //bubbleSort(bubble_sorted, size);
    bubble_end = clock();
    
    // Sort with insertion sort
    int *insertion_sorted;
    clock_t insertion_start, insertion_end;
    cloneArray(size, unsorted, &insertion_sorted);
    insertion_start = clock();
    //insertionSort(insertion_sorted, size);
    insertion_end = clock();
    
    // Sort with merge sort
    int *merge_sorted;
    clock_t merge_start, merge_end;
    cloneArray(size, unsorted, &merge_sorted);
    merge_start = clock();
    mergeSort(merge_sorted, 0, size - 1);
    merge_end = clock();
    
    // Sort with heap sort
    int *heap_sorted;
    clock_t heap_start, heap_end;
    cloneArray(size, unsorted, &heap_sorted);
    heap_start = clock();
    heapSort(size, heap_sorted);
    heap_end = clock();
    
    // Sort with quick sort
    int *quick_sorted;
    clock_t quick_start, quick_end;
    cloneArray(size, unsorted, &quick_sorted);
    quick_start = clock();
    quickSort(size, quick_sorted);
    quick_end = clock();
    
    // Sort with randomized quick sort
    int *randomizedQuick_sorted;
    clock_t randomizedQuick_start, randomizedQuick_end;
    cloneArray(size, unsorted, &randomizedQuick_sorted);
    randomizedQuick_start = clock();
    randomizedQuickSort(size, randomizedQuick_sorted);
    randomizedQuick_end = clock();
    
    // Display results
    //PRINT_ARRAYS(insertion_sorted, merge_sorted, size);
    ASSERT_ARRAY_EQ(size, bubble_sorted, insertion_sorted);
    ASSERT_ARRAY_EQ(size, insertion_sorted, merge_sorted);
    ASSERT_ARRAY_EQ(size, merge_sorted, heap_sorted);
    ASSERT_ARRAY_EQ(size, heap_sorted, quick_sorted);
    ASSERT_ARRAY_EQ(size, quick_sorted, randomizedQuick_sorted);
    double bubble_time = ((double)(bubble_end - bubble_start)) / CLOCKS_PER_SEC;
    double insertion_time = ((double)(insertion_end - insertion_start)) / CLOCKS_PER_SEC;
    double merge_time = ((double)(merge_end - merge_start)) / CLOCKS_PER_SEC;
    double heap_time = ((double)(heap_end - heap_start)) / CLOCKS_PER_SEC;
    double quick_time = ((double)(quick_end - quick_start)) / CLOCKS_PER_SEC;
    double randomizedQuick_time = ((double)(randomizedQuick_end - randomizedQuick_start)) / CLOCKS_PER_SEC;

    printf("n = %i, bubbleSort = %f, insertionSort = %f, mergeSort = %f, heapSort = %f, quickSort = %f, randomizedQuickSort = %f\n", size, bubble_time, insertion_time, merge_time, heap_time, quick_time, randomizedQuick_time);
    
    // Stats
    // n = 100000, bubbleSort = 34.312000, insertionSort = 8.109000, 
    // mergeSort = 0.016000, heapSort = 0.031000, quickSort = 0.016000

    
    free(bubble_sorted);
    free(insertion_sorted);
    free(merge_sorted);
    free(heap_sorted);
    free(quick_sorted);
    free(randomized_quick_sorted);
    
    return 0;
}