#include "ordenacao.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
  int opcoes[] = {20, 500, 5000, 10000, 200000};
  int escolha, opcao;
  int organiza(item vetor[], int opcoes[], int escolha, int opcao);
  srand( (time(NULL) ));

  printf("\nEscolha o tamanho do vetor:\n");
  for (int i = 0; i < sizeof(opcoes) / sizeof(opcoes[0]); i++) {
    printf("%d - %d\n", i, opcoes[i]);
  }
  scanf("%d", &escolha);
  int max = opcoes[escolha];
  item *vetor = (item *)malloc(sizeof(item) * max);

  printf("Escolha a forma ordenada:\n");
  printf("1 - Ordem aleatoria:\n");
  printf("2 - Ordem crescente:\n");
  printf("3 - Ordem decrescente:\n");
  scanf("%d", &opcao);

  for (int j = 1; j <= 10; j++) {
    printf("\n ************");
    printf("\n * Teste: %d *", j);
    printf("\n ************\n");

    organiza(vetor, opcoes, escolha, opcao);

    insertionSort(vetor, max, j);

    organiza(vetor, opcoes, escolha, opcao);
    
    selection_externo(vetor, max, j);

    organiza(vetor, opcoes, escolha, opcao);

    merge_externo(vetor, max, j);

    organiza(vetor, opcoes, escolha, opcao);

    quick_externo(vetor, 0, max, j);

    organiza(vetor, opcoes, escolha, opcao);

    heapsort(vetor, max, j);

    organiza(vetor, opcoes, escolha, opcao);

    shell_sort(vetor, max, j);
  }
}

int organiza(item vetor[], int opcoes[], int escolha, int opcao) {

  int max = opcoes[escolha];
  switch (opcao) {

  case 1:

    for (int i = 0; i < max; i++) {

      vetor[i].chave = rand() % max;
    }
    
    break;

  case 2:

    for (int i = 0; i < max; i++) {
      vetor[i].chave = i;
    }

    break;

  default:
    for (int i = 0; i < max; i++) {
      vetor[i].chave = max - i;
    }

    break;
  }
}