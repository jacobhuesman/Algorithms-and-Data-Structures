#include <radix_sort.h>
#include <counting_sort.h>

/* Pseudocode:
 * Radix-Sort(A,d)
 *     for i = 1 to default
 *         use a stable sort to sort array A on digit i
 */
 // This implementation uses counting sort as stable sort
void radixSort(int n, uint32_t *A, int k)
{
	uint32_t B[n];
	uint32_t C[16];
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			C[j] = 0;
		}
		for (int j = 0; j < n; j++)
		{
			C[(A[j] >> (4 * i)) % 16]++;
			//C[(A[j] << ) >> (4 * i)]++;
		}
		for (int j = 1; j < 16; j++)
		{
			C[j] += 
			C[j - 1];
		}
		for (int j = n - 1; j >= 0; j--)
		{
			int A_imod = (A[j] >> (4 * i)) % 16;
			B[C[A_imod] - 1] = A[j];
			C[A_imod] = C[A_imod] - 1;
		}
		for (int j = 0; j < n; j++)
		{
			A[j] = B[j];
		}
	}
}