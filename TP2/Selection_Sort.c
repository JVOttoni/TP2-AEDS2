#include "ordenacao.h"
#include <stdio.h>
#include <sys/resource.h>

unsigned long int compS = 0, trocaS = 0, media_compS = 0, media_trocaS = 0;
long double media_tempoS = 0;

void trocaselect(int *esq, int *dir) {
  int temp = *esq;
  *esq = *dir;
  *dir = temp;
  trocaS += 3;
}

void selectionSort(item vetor[], int max) {
  int i, j, esq;

  for (i = 0; i < max - 1; i++) {
    esq = i;

    for (j = i + 1; j < max; j++) {
      compS++;
      if (vetor[j].chave < vetor[esq].chave)

        esq = j;

    }
      trocaselect(&vetor[esq].chave, &vetor[i].chave);
  }
}

  int selection_externo(item vetor[], int max, int fim) {
    struct rusage start, end;
    getrusage(RUSAGE_SELF, &start);

    selectionSort(vetor, max);

    getrusage(RUSAGE_SELF, &end);
    long double startTime =
        start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
    long double endTime =
        end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;

    long double diferenca = endTime - startTime;
  printf("\n\nSelection Sort:\n");
  printf("Tempo decorrido = %Lf\n", diferenca);
    printf("Numero de comparacoes: %ld\n", compS);
    printf("Numero de trocas: %ld\n", trocaS);
    printf("----------------------------\n");

    media_tempoS += diferenca;
    media_compS += compS;
    media_trocaS += trocaS;
    compS = 0;
    trocaS = 0;
    
    if(fim == 10) {
    media_tempoS /= 10;
    media_compS /= 10;
    media_trocaS /= 10;
    printf("**************************\n");
    printf("Media de tempo de execucao:%Lf\n", media_tempoS);
    printf("Media de comparacoes feitas:%ld\n", media_compS);
    printf("Media de trocas feitas:%ld\n", media_trocaS);
    printf("**************************\n");
  }

    return 0;
  }

  // Imprime o vetor ordenado
  /*for (i = 0; i < max; i++) {
    printf ("%d ", vetor[i].chave);
  }
  printf ("\n");
  }
  int main () {
  int max, i;
  printf("tamanho do vetor:\n");
  scanf ("%d",&max);
  item  vetor[max];
  for (i = 0; i < max; i++) {
    printf("item:\n");
    scanf ("%d",&(vetor[i].chave));
  }
  selection_sort (vetor, max);

  }*/