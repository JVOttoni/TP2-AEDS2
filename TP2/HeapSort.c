#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

unsigned long int compH = 0, trocaH = 0, media_compH = 0, media_trocaH = 0;
long double media_tempoH = 0;

void troca(item *a, item *b) {
  item temp = *a;

  *a = *b;

  *b = temp;
  trocaH += 3;
}

void heap(item vetor[], int N, int i) {
  struct rusage start, end;
  getrusage(RUSAGE_SELF, &start);
  
  int maior = i;
  int esquerda = 2 * i + 1;
  int direita = 2 * i + 2;

  compH++;
  if (esquerda < N && vetor[esquerda].chave > vetor[maior].chave){
    maior = esquerda;
  }

  compH++;
  if (direita < N && vetor[direita].chave > vetor[maior].chave){
    maior = direita;
  }

  if (maior != i) {
    troca(&vetor[i], &vetor[maior]);
    heap(vetor, N, maior);
  }
}

int heapsort(item vetor[], int N, int fim) {
  struct rusage start, end;
  getrusage(RUSAGE_SELF, &start);

  for (int i = N / 2 - 1; i >= 0; i--)

    heap(vetor, N, i);
  for (int i = N - 1; i >= 0; i--) {

    troca(&vetor[0], &vetor[i]);

    heap(vetor, i, 0);
  }
  getrusage(RUSAGE_SELF, &end);
  long double startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
  long double endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;

  long double diferenca = endTime - startTime;
  printf("\n\nHeap Sort:\n");
  printf("Tempo decorrido = %Lf\n", diferenca);
  printf("Numero de comparacoes: %ld\n", compH);
  printf("Numero de trocas: %ld\n", trocaH);
  printf("----------------------------\n");

  //Ordenado!

  media_tempoH += diferenca;
  media_compH += compH;
  media_trocaH += trocaH;
  compH = 0;
  trocaH = 0;
  if(fim == 10) {
    media_tempoH /= 10;
    media_compH /= 10;
    media_trocaH /= 10;
    printf("**************************\n");
    printf("Media de tempo de execucao:%Lf\n", media_tempoH);
    printf("Media de comparacoes feitas:%ld\n", media_compH);
    printf("Media de trocas feitas:%ld\n", media_trocaH);
    printf("**************************\n");
  }
  
  return 0;
}

/*int main() {

  int max, i;
  printf("tamanho do vetor:\n");
  scanf("%d", &max);
  item *vetor = (item *)malloc(sizeof(item)*max);

  for (i = 0; i < max; i++) {
    printf("item:\n");
    scanf("%d", &(vetor[i].chave));
  }

  heapsort(vetor, max);
  printf("\n");
    for (int i = 0; i < max; i++) {
      printf(" %d", vetor[i].chave);
    }
    printf ("\n");
}
 */
