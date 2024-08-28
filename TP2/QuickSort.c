#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include "ordenacao.h"

unsigned long int compQ = 0, trocaQ = 0, media_compQ = 0, media_trocaQ = 0;
long double media_tempoQ = 0;

void trocaquick(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
  trocaQ += 3;
}

int particionar(item vetor[], int esq, int dir)
{
	int pivo = vetor[dir].chave;
	int i = (esq - 1);

	for (int j = esq; j <= dir - 1; j++)
	{
    compQ ++;
		if (vetor[j].chave < pivo)
		{
			i++;
			trocaquick(&vetor[i].chave, &vetor[j].chave);
		}
	}
	trocaquick(&vetor[i + 1].chave, &vetor[dir].chave);
	return (i + 1);
}

void quickSort(item vetor[], int esq, int dir)
{
	if (esq < dir)
	{
		int indice = particionar(vetor, esq, dir);
		quickSort(vetor, esq, indice - 1);
		quickSort(vetor, indice + 1, dir);
	}
}

int quick_externo(item vetor[], int esq, int dir, int fim)
{
  struct rusage start, end;
  getrusage(RUSAGE_SELF, &start);

  quickSort(vetor, esq, dir);

  getrusage(RUSAGE_SELF, &end);
  long double startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
  long double endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;

  long double diferenca = endTime - startTime;
  printf("\n\nQuick Sort:\n");
  printf("Tempo decorrido = %Lf\n", diferenca);
  printf("Numero de comparacoes: %ld\n", compQ);
  printf("Numero de trocas: %ld\n", trocaQ);
  printf("----------------------------\n");

  media_tempoQ += diferenca;
  media_compQ += compQ;
  media_trocaQ += trocaQ;
  compQ = 0;
  trocaQ = 0;
  
  if(fim == 10) {
    media_tempoQ /= 10;
    media_compQ /= 10;
    media_trocaQ /= 10;
    printf("**************************\n");
    printf("Media de tempo de execucao: %Lf\n", media_tempoQ);
  printf("Media de comparacoes feitas: %ld\n", media_compQ);
    printf("Media de trocas feitas: %ld\n", media_trocaQ);
    printf("**************************\n");
  }
  return 0;    
}


/*int main() {

  int max, i, n;
  printf("tamanho do vetor:\n");
  scanf("%d", &max);
  item *vetor = (item *)malloc(sizeof(item)*max);

  for (i = 0; i < max; i++) {
    printf("item:\n");
    scanf("%d", &(vetor[i].chave));
  }
  
  quick_sort(vetor, 0, max);
  printf("\n");
    for (int i = 0; i < max; i++) {
      printf("%d ", vetor[i].chave);
    }
    printf ("\n");
  }*/


