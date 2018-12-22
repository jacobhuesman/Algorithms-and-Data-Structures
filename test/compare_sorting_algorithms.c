#include <merge_sort.h>
#include <insertion_sort.h>
#include <eval.h>

int main(int argc, char *argv[])
{
    int size = 1e3;
    if (argc > 1)
    {
        size = atoi(argv[1]);
    }
    printf("Trial size = %i\n", size);
    return 0;
}