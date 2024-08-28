#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include "ordenacao.h"
unsigned long int compM = 0, trocaM = 0, media_compM = 0, media_trocaM = 0;
long double media_tempoM = 0;

void merge(item vetor[], int tamanho);

int mergesort(item vetor[], int tamanho){
  int meio;

  if(tamanho > 1){
    meio = (tamanho)/2;
    mergesort(vetor, meio);
    mergesort(vetor + meio, tamanho - meio);
    merge(vetor, tamanho);
    
  }
  return 0;
}

void merge(item vetor[], int tamanho){
  int meio, i, j, k;
  item *aux = (item*)malloc(tamanho * sizeof(item));
  meio = tamanho/2;
  i = 0;
  j = meio;
  k = 0;
  while(i < meio && j < tamanho){
    compM++;
    if(vetor[i].chave < vetor[j].chave){
      aux[k].chave = vetor[i].chave;
      i++; 
    }
    else{
      aux[k].chave = vetor[j].chave;
      j++;
    }
    k++;
    trocaM++;
  }
  if(i == meio){
    while(j < tamanho){
      aux[k].chave = vetor[j].chave;
      trocaM ++;
      j++;
      k++;
    }
  }
  else  
    while(i < meio){
      aux[k].chave = vetor[i].chave;
      trocaM++;
      i++;
      k++;
    }
  for(i = 0; i < tamanho; i++){
    vetor[i].chave = aux[i].chave;
    trocaM++;
  }
  free(aux);
} 

int merge_externo(item vetor[], int tamanho, int fim)
{
  struct rusage start, end;
  getrusage(RUSAGE_SELF, &start);

  mergesort(vetor, tamanho);

  getrusage(RUSAGE_SELF, &end);
  long double startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
  long double endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;

  long double diferenca = endTime - startTime;
  printf("\n\nMerge Sort:\n");
  printf("Tempo decorrido = %Lf\n", diferenca);
  printf("Numero de comparacoes: %ld\n", compM);
  printf("Numero de trocas: %ld\n", trocaM);
  printf("----------------------------\n");
  
  // Ordenado!

  media_tempoM += diferenca;
  media_compM += compM;
  media_trocaM += trocaM;
  compM = 0;
  trocaM = 0;

  if(fim == 10) {
    media_tempoM /= 10;
    media_compM /= 10;
    media_trocaM /= 10;
    printf("**************************\n");
    printf("Media de tempo de execucao:%Lf\n", media_tempoM);
    printf("Media de comparacoes feitas:%ld\n", media_compM);
    printf("Media de trocas feitas:%ld\n", media_trocaM);
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
  
  mergesort(vetor, max);
  printf("\n");
    for (int i = 0; i < max; i++) {
      printf("%d ",vetor[i].chave);
    }
    printf ("\n");
  }*/