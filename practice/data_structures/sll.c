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