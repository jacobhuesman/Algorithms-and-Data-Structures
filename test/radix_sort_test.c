#include <radix_sort.h>
#include <eval.h>

void radixSort_test()
{
	// Setup
	uint32_t unsorted[] = {40, 19, 21, 20, 50,  2};
	uint32_t expected[] = { 2, 19, 20, 21, 40, 50};
	uint32_t *sorted;
	CLONE_ARRAY(6, unsorted, sorted);
	
	// Test
	printf("\n" "radixSort_test:\n");
	radixSort(6, sorted, 2);
	PRINT_ARRAYS(6, sorted, expected);
	ASSERT_ARRAY_EQ(6, sorted, expected);
	
	free(sorted);
}

void main()
{
	printf("\nRunning %s\n", __FILE__);
	radixSort_test();
}