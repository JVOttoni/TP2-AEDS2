#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

unsigned long int compSH = 0, trocaSH = 0, media_compSH = 0, media_trocaSH = 0;
long double media_tempoSH = 0;

int shell_sort(item vetor[], int max, int fim) {
  struct rusage start, end;
  getrusage(RUSAGE_SELF, &start);

  int i, j, item;
  int indice = 1;

  do {
    indice = 3 * indice + 1;
  } while (indice < max);

  do {
    indice = indice / 3;
    for (i = indice; i < max; i++) {
      item = vetor[i].chave;
      j = i;

      compSH++;
      while (j >= indice && item < vetor[j - indice].chave) {
        compSH++;
        vetor[j].chave = vetor[j - indice].chave;
        trocaSH++;
        j -= indice;
      }
      vetor[j].chave = item;
    }
  } while (indice > 1);

  getrusage(RUSAGE_SELF, &end);
  long double startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
  long double endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;

  long double diferenca = endTime - startTime;
  printf("\n\nShell Sort:\n");
  printf("Tempo decorrido = %Lf\n", diferenca);
  printf("Numero de comparacoes: %ld\n", compSH);
  printf("Numero de trocas: %ld\n", trocaSH);
  printf("----------------------------\n");

  //Ordenado!

  media_tempoSH += diferenca;
  media_compSH += compSH;
  media_trocaSH += trocaSH;
  compSH = 0;
  trocaSH = 0;
  
  if(fim == 10) {
    media_tempoSH /= 10;
    media_compSH /= 10;
    media_trocaSH /= 10;
    printf("**************************\n");
    printf("Media de tempo de execucao:%Lf\n", media_tempoSH);
    printf("Media de comparacoes feitas:%ld\n", media_compSH);
    printf("Media de trocas feitas:%ld\n", media_trocaSH);
    printf("**************************\n");
  }
  
return 0;
}


/*int main() {
  int max;
  printf("tamanho do vetor:\n");
  scanf("%d", &max);
  item *vetor = (item *)malloc(sizeof(item) * max);
  for (int i = 0; i < max; i++) {
    printf("item:\n");
    scanf("%d", &(vetor[i].chave));
  }
  shell_sort(vetor, max);
}*/