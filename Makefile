CC=clang
CFLAGS=-Wall -pedantic -O0 -g

merge-sort: merge-sort.o
	$(CC) $(CFLAGS) -o $@ $<
