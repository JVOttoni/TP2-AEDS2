#ifndef ORDENACAO_H
#define ORDENACAO_H

typedef struct {
    int chave;
}item_leve;

typedef struct {
    int chave;
    char peso[50][50];
}item_pesado;

typedef item_leve item;

int insertionSort(item*, int, int);
int selection_externo(item*, int, int);
int merge_externo(item*, int, int);
int quick_externo(item*, int, int, int);
int heapsort(item*, int, int);
int shell_sort(item*, int, int);

#endif