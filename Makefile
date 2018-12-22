CC     = gcc
CFLAGS = -I include -g

LIB_NAMES = merge_sort insertion_sort bubble_sort square_matrix_multiply
LIBS = $(foreach lib, $(LIB_NAMES), build/$(lib).o)
TEST = $(foreach test, $(LIB_NAMES), bin/$(test)_test.exe) bin/eval_test.exe

.PHONY: all
all: $(LIBS) $(TEST) bin/compare_sorting_algorithms.exe

.PHONY: clean
clean:
	rm $(wildcard bin/*.exe) $(wildcard build/*.o)

build/%.o : src/%.c
	$(CC) $< $(CFLAGS) -c -o $@

bin/%_test.exe : test/%_test.c build/%.o include/eval.h
	$(CC) $< $(CFLAGS) -o $@ build/$*.o
	
bin/compare_sorting_algorithms.exe : test/compare_sorting_algorithms.c build/bubble_sort.o build/insertion_sort.o build/merge_sort.o include/eval.h
	$(CC) $< $(CFLAGS) -o $@ build/bubble_sort.o build/insertion_sort.o build/merge_sort.o
	
bin/eval_test.exe : test/eval_test.c
	$(CC) $< $(CFLAGS) -o $@