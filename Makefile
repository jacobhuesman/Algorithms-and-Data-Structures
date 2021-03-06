CC     = gcc
#CFLAGS = -Wl,--stack,16777216 -I include -g
CFLAGS = -I include -g

LIB_NAMES = merge_sort insertion_sort bubble_sort \
			square_matrix_multiply_direct square_matrix_multiply_recursive \
			square_matrix_multiply_strassen heap quick_sort \
			randomized_quick_sort counting_sort radix_sort \
            stack queue doubly_linked_list binary_search_tree
LIBS = $(foreach lib, $(LIB_NAMES), build/$(lib).o)
TEST = $(foreach test, $(LIB_NAMES), bin/$(test)_test.exe)

.PHONY: all
all: $(LIBS) $(TEST) bin/compare_sorting_algorithms.exe bin/compare_matrix_multiplication_algorithms.exe bin/eval_test.exe

.PHONY: clean
clean:
	rm $(wildcard bin/*.exe) $(wildcard build/*.o)

build/%.o : src/%.c include/%.h
	$(CC) $< $(CFLAGS) -c -o $@

bin/%_test.exe : test/%_test.c build/%.o include/eval.h
	$(CC) $< $(CFLAGS) -o $@ build/$*.o
	
bin/eval_test.exe : test/eval_test.c include/eval.h
	$(CC) $< $(CFLAGS) -o $@
	
#bin/compare_sorting_algorithms.exe : test/compare_sorting_algorithms.c build/bubble_sort.o build/insertion_sort.o build/merge_sort.o build/heap.o build/quick_sort.o build/randomized_quick_sort.o include/eval.h
#	$(CC) $< -Wl,--stack,1000000000 $(CFLAGS) -o $@ build/bubble_sort.o build/insertion_sort.o build/merge_sort.o build/heap.o build/quick_sort.o build/randomized_quick_sort.o
bin/compare_sorting_algorithms.exe : test/compare_sorting_algorithms.c build/bubble_sort.o build/insertion_sort.o build/merge_sort.o build/heap.o build/quick_sort.o build/randomized_quick_sort.o build/counting_sort.o build/radix_sort.o include/eval.h
	$(CC) $< $(CFLAGS) -o $@ build/bubble_sort.o build/insertion_sort.o build/merge_sort.o build/heap.o build/quick_sort.o build/randomized_quick_sort.o build/counting_sort.o build/radix_sort.o
	
#bin/compare_matrix_multiplication_algorithms.exe : test/compare_matrix_multiplication_algorithms.c build/square_matrix_multiply_direct.o build/square_matrix_multiply_recursive.o build/square_matrix_multiply_strassen.o include/eval.h
#	$(CC) $< -Wl,--stack,1000000000 $(CFLAGS) -o $@ build/square_matrix_multiply_direct.o build/square_matrix_multiply_recursive.o build/square_matrix_multiply_strassen.o
bin/compare_matrix_multiplication_algorithms.exe : test/compare_matrix_multiplication_algorithms.c build/square_matrix_multiply_direct.o build/square_matrix_multiply_recursive.o build/square_matrix_multiply_strassen.o include/eval.h
	$(CC) $< $(CFLAGS) -o $@ build/square_matrix_multiply_direct.o build/square_matrix_multiply_recursive.o build/square_matrix_multiply_strassen.o