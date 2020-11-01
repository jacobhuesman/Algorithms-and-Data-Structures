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