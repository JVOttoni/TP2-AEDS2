#include "ordenacao.h"
#include <math.h>
#include <stdio.h>
#include <sys/resource.h>

unsigned long int compI = 0, trocaI = 0, media_compI = 0, media_trocaI = 0;
long double media_tempoI = 0;

int insertionSort(item vetor[], int max, int fim) {
  struct rusage start, end;
  getrusage(RUSAGE_SELF, &start);

  int i, chaveaux, j;
  for (i = 1; i < max; i++) {
    chaveaux = vetor[i].chave;
    j = i - 1;

    compI++;
    while (j >= 0 && vetor[j].chave > chaveaux) {
      compI++;
      vetor[j + 1] = vetor[j];
      trocaI ++;
      j = j - 1;
    }
    vetor[j + 1].chave = chaveaux;
  }
  getrusage(RUSAGE_SELF, &end);
  long double startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
  long double endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;

  long double diferenca = endTime - startTime;
  printf("\n\nInsertion Sort:\n");
  printf("Tempo decorrido = %Lf\n", diferenca);
  printf("Numero de comparacoes: %ld\n", compI);
  printf("Numero de trocas: %ld\n", trocaI);
  printf("----------------------------\n");
  
  //Ordenado!

  media_tempoI += diferenca;
  media_compI += compI;
  media_trocaI += trocaI;
  compI = 0;
  trocaI = 0;

  if(fim == 10) {
    media_tempoI /= 10;
    media_compI /= 10;
    media_trocaI /= 10;
    printf("**************************\n");
    printf("Media de tempo de execucao:%Lf\n", media_tempoI);
  printf("Media de comparacoes feitas:%ld\n", media_compI);
    printf("Media de trocas feitas:%ld\n", media_trocaI);
    printf("**************************\n");
  }

  return 0;
}


/*int main() {

  int max, i;

  printf("tamanho do vetor:\n");
  scanf("%d", &max);

  item vetor[max];
  for (i = 0; i < max; i++) {
    printf("item:\n");
    scanf("%d", &(vetor[i].chave));
  }
  printf("\n");
  insertionSort(vetor, max);
}*/
