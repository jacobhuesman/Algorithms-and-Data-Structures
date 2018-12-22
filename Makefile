CC     = gcc
CFLAGS = -I include

PROGRAMS = merge_sort insertion_sort eval_test
EXECUTABLES = $(foreach program, $(PROGRAMS), bin/$(program).exe)

bin/%.exe : src/%.c include/eval.h
	$(CC) $< $(CFLAGS) -g -o $@

.PHONY: all
all: $(EXECUTABLES)

.PHONY: clean
clean:
	rm $(wildcard bin/*.exe)