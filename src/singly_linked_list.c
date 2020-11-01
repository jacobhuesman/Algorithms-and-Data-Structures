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

#include <stdio.h>
#include <stdlib.h>

// Unit testing framework
#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_RESET   "\x1b[0m"
#define PASS(FORMAT, ...) printf("[" ANSI_GREEN "PASS" ANSI_RESET "] " FORMAT, ##__VA_ARGS__);
#define FAIL(FORMAT, ...) printf("[" ANSI_RED   "FAIL" ANSI_RESET "] " FORMAT, ##__VA_ARGS__);
#define ASSERT(ASSERTION)       \
{                               \
    if (ASSERTION)              \
    {                           \
        PASS(#ASSERTION "\n");  \
    }                           \
    else                        \
    {                           \
        FAIL(#ASSERTION "\n");  \
    }                           \
}

// Definitions and implementation
#define bool int
#define true 1
#define false 0

typedef int* Element;

typedef struct
{
    void *next;
    Element *data;
} Link;

typedef struct
{
    Link *start;
    Link *end;
    int size;
} SLL;

// Adds an element after the specified current element
void addElementAfter(SLL *list, Element current_element, Element new_element)
{
    // Check if list is empty
    if (list->start == NULL)
    {
        list->start = malloc(sizeof(Link));
        list->end = list->start;
        list->size = 1;
    }
    // Check if link exists in list
    bool found = false;
    Link *current = list->start;
    for (int i = 0; i < list->size; i++)
    {
       if (current == current_element)
       {
            found = true;
            break;
       }
    }
    
    if (!found)
    {
        return false;
    }
}


// Test cases
void test_suite_1()
{
    printf("\nTest suite 1:\n");
    ASSERT(5 == 1 + 4);
    ASSERT(5 == 1 + 4 * 200);
    printf("\n");
}

// Run
void main()
{
    printf("Running %s\n", __FILE__);
    test_suite_1();
}