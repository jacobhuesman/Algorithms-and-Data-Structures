#include <counting_sort.h>

void countingSort(int n, int *A, int k)
{
	int B[n];
	int C[k + 1];
	for (int i = 0; i <= k; i++)
	{
		C[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		C[A[i]]++;
	}
	for (int i = 1; i <= k; i++)
	{
		C[i] += C[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		B[C[A[i]] - 1] = A[i];
		C[A[i]] = C[A[i]] - 1;
	}
	for (int i = 0; i < n; i++)
	{
		A[i] = B[i];
	}
}