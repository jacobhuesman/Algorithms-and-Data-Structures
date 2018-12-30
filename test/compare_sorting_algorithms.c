#include <bubble_sort.h>
#include <insertion_sort.h>
#include <merge_sort.h>
#include <quick_sort.h>
#include <randomized_quick_sort.h>
#include <counting_sort.h>
#include <heap.h>
#include <eval.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // Read in trial size
    int size = 1e6;
    if (argc > 1)
    {
        size = atoi(argv[1]);
    }
    printf("Trial size = %i\n", size);
    
    // Create array of random numbers
	int k = 1000;
    int unsorted[size];
    for (int i = 0; i < size; i++)
    {
        unsorted[i] = rand() % (k + 1);
    }
    
    // Sort with bubble sort
    int *bubble_sorted;
    clock_t bubble_start, bubble_end;
    CLONE_ARRAY(size, unsorted, bubble_sorted);
    bubble_start = clock();
    //bubbleSort(bubble_sorted, size);
    bubble_end = clock();
    
    // Sort with insertion sort
    int *insertion_sorted;
    clock_t insertion_start, insertion_end;
    CLONE_ARRAY(size, unsorted, insertion_sorted);
    insertion_start = clock();
    //insertionSort(insertion_sorted, size);
    insertion_end = clock();
    
    // Sort with merge sort
    int *merge_sorted;
    clock_t merge_start, merge_end;
    CLONE_ARRAY(size, unsorted, merge_sorted);
    merge_start = clock();
    mergeSort(merge_sorted, 0, size - 1);
    merge_end = clock();
    
    // Sort with heap sort
    int *heap_sorted;
    clock_t heap_start, heap_end;
    CLONE_ARRAY(size, unsorted, heap_sorted);
    heap_start = clock();
    heapSort(size, heap_sorted);
    heap_end = clock();
    
    // Sort with quick sort
    int *quick_sorted;
    clock_t quick_start, quick_end;
    CLONE_ARRAY(size, unsorted, quick_sorted);
    quick_start = clock();
    quickSort(size, quick_sorted);
    quick_end = clock();
    
    // Sort with randomized quick sort
    int *randomized_quick_sorted;
    clock_t randomized_quick_start, randomized_quick_end;
    CLONE_ARRAY(size, unsorted, randomized_quick_sorted);
    randomized_quick_start = clock();
    randomizedQuickSort(size, randomized_quick_sorted);
    randomized_quick_end = clock();
	
	// Sort with counting sort
    int *counting_sorted;
    clock_t counting_start, counting_end;
    CLONE_ARRAY(size, unsorted, counting_sorted);
    counting_start = clock();
    countingSort(size, counting_sorted, k);
    counting_end = clock();
    
    // Display results
    //PRINT_ARRAYS(insertion_sorted, merge_sorted, size);
    ASSERT_ARRAY_EQ(size, bubble_sorted, insertion_sorted);
    ASSERT_ARRAY_EQ(size, insertion_sorted, merge_sorted);
    ASSERT_ARRAY_EQ(size, merge_sorted, heap_sorted);
    ASSERT_ARRAY_EQ(size, heap_sorted, quick_sorted);
    ASSERT_ARRAY_EQ(size, quick_sorted, randomized_quick_sorted);
	ASSERT_ARRAY_EQ(size, randomized_quick_sorted, counting_sorted);
    double bubble_time = ((double)(bubble_end - bubble_start)) / CLOCKS_PER_SEC;
    double insertion_time = ((double)(insertion_end - insertion_start)) / CLOCKS_PER_SEC;
    double merge_time = ((double)(merge_end - merge_start)) / CLOCKS_PER_SEC;
    double heap_time = ((double)(heap_end - heap_start)) / CLOCKS_PER_SEC;
    double quick_time = ((double)(quick_end - quick_start)) / CLOCKS_PER_SEC;
    double randomized_quick_time = ((double)(randomized_quick_end - randomized_quick_start)) / CLOCKS_PER_SEC;
	double counting_time = ((double)(counting_end - counting_start)) / CLOCKS_PER_SEC;

    printf("n = %i, bubbleSort = %f, insertionSort = %f, mergeSort = %f, heapSort = %f, quickSort = %f, randomizedQuickSort = %f, countingSort = %f\n", size, bubble_time, insertion_time, merge_time, heap_time, quick_time, randomized_quick_time, counting_time);
    
    // Stats
    // n = 1000000, bubbleSort = 2578.859375, 
	// insertionSort = 619.812500, mergeSort = 0.171875, 
	// heapSort = 0.250000, quickSort = 1.750000, 
	// randomizedQuickSort = 1.781250, countingSort = 0.015625

    
    free(bubble_sorted);
    free(insertion_sorted);
    free(merge_sorted);
    free(heap_sorted);
    free(quick_sorted);
    free(randomized_quick_sorted);
    
    return 0;
}