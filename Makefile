CC     = gcc
CFLAGS = -I include

LIB_NAMES = merge_sort insertion_sort
LIBS = $(foreach lib, $(LIB_NAMES), build/$(lib).o)
TEST = $(foreach test, $(LIB_NAMES), bin/$(test)_test.exe) bin/eval_test.exe

build/%.o : src/%.c
	$(CC) $< $(CFLAGS) -g -c -o $@

bin/%_test.exe : test/%_test.c build/%.o include/eval.h
	$(CC) $< $(CFLAGS) -g -o $@ build/$*.o

.PHONY: all
all: $(LIBS) $(TEST)

.PHONY: clean
clean:
	rm $(wildcard bin/*.exe)