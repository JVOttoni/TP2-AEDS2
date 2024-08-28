Para compilar o programa, usando o linux, basta executar o make onde:

DEPS = ordenacao.h
OBJ = main.o HeapSort.o Insertion_Sort.o MergeSort.o QuickSort.o Selection_Sort.o ShellSort.o
EXEC = tp2 //(nome do executável a ser criado)

Após o programa ser compilado, deve-se executar com um arquivo de texto adicional, informando os comandos a serem usados. Exemplo:

./tp2 arquivo.txt
