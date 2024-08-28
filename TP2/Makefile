CC=gcc
CFLAGS=-I.
DEPS = ordenacao.h
OBJ = main.o HeapSort.o Insertion_Sort.o MergeSort.o QuickSort.o Selection_Sort.o ShellSort.o
EXEC = tp2

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(EXEC) *.o *~ core