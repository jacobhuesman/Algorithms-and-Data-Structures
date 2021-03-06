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
	int i = 0;
	for (int i = 0; (k >> (4*i)) > 0; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			C[j] = 0;
		}
		for (int j = 0; j < n; j++)
		{
			C[(A[j] >> (4 * i)) % 16]++; // TODO potentially avoid modulo operator with bit shifts
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