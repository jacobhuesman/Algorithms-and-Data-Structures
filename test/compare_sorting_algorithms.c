#include <merge_sort.h>
#include <insertion_sort.h>
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
    
    // Sort with insertion sort
    int *insertion_sorted;
    clock_t insertion_start, insertion_end;
    cloneArray(unsorted, &insertion_sorted, size);
    insertion_start = clock();
    insertionSort(insertion_sorted, size);
    insertion_end = clock();
    
    // Sort with merge sort
    int *merge_sorted;
    clock_t merge_start, merge_end;
    cloneArray(unsorted, &merge_sorted, size);
    merge_start = clock();
    mergeSort(merge_sorted, 0, size - 1);
    merge_end = clock();
    
    // Display results
    //PRINT_ARRAYS(insertion_sorted, merge_sorted, size);
    ASSERT_ARRAY_EQ(insertion_sorted, merge_sorted, size);
    double insertion_time = ((double)(insertion_end - insertion_start)) / CLOCKS_PER_SEC;
    double merge_time = ((double)(merge_end - merge_start)) / CLOCKS_PER_SEC;
    printf("insertionSort time = %f, mergeSort time = %f\n", insertion_time, merge_time);
    
    return 0;
}