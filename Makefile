CC     = gcc
#CFLAGS = -Wl,--stack,16777216 -I include -g
CFLAGS = -I include -g


LIB_NAMES = eval merge_sort insertion_sort bubble_sort square_matrix_multiply_direct \
			square_matrix_multiply_recursive square_matrix_multiply_strassen \
			heap
LIBS = $(foreach lib, $(LIB_NAMES), build/$(lib).o)
TEST = $(foreach test, $(LIB_NAMES), bin/$(test)_test.exe)

.PHONY: all
all: $(LIBS) $(TEST) bin/compare_sorting_algorithms.exe bin/compare_matrix_multiplication_algorithms.exe

.PHONY: clean
clean:
	rm $(wildcard bin/*.exe) $(wildcard build/*.o)

build/%.o : src/%.c
	$(CC) $< $(CFLAGS) -c -o $@

bin/%_test.exe : test/%_test.c build/%.o build/eval.o include/eval.h
	$(CC) $< $(CFLAGS) -o $@ build/$*.o build/eval.o
	
bin/compare_sorting_algorithms.exe : test/compare_sorting_algorithms.c build/bubble_sort.o build/insertion_sort.o build/merge_sort.o include/eval.h
	$(CC) $< $(CFLAGS) -o $@ build/bubble_sort.o build/insertion_sort.o build/merge_sort.o build/eval.o
	
bin/compare_matrix_multiplication_algorithms.exe : test/compare_matrix_multiplication_algorithms.c build/square_matrix_multiply_direct.o build/square_matrix_multiply_recursive.o build/square_matrix_multiply_strassen.o include/eval.h
	$(CC) $< -Wl,--stack,1000000000 $(CFLAGS) -o $@ build/square_matrix_multiply_direct.o build/square_matrix_multiply_recursive.o build/square_matrix_multiply_strassen.o build/eval.o
	
bin/eval_test.exe : test/eval_test.c
	$(CC) $< $(CFLAGS) -o $@ build/eval.o