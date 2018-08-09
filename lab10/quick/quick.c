#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

long int comparacoes=0, trocas =0;
int contador=0;


void qSortInterno(int vetor[], int inicio, int fim) {
  int pivot;
  int temp;
  int i,j;

  i = inicio;
  j = fim;
  pivot = vetor[(i+j)/2];
    
  do {
  	
    while(vetor[i] < pivot) {
        comparacoes++;
        i++;
    }
    while(vetor[j] > pivot){ 
        comparacoes++;
        j--;
    }
    if(i<= j) {
      temp = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = temp;
      i++; j--;
      trocas++;
    }
  } while (i<=j);
  
  if(inicio < j){ 
    qSortInterno(vetor,inicio, j);
}
  if(i < fim) {
    qSortInterno(vetor, i,fim);
}
}

int quickSort(int vetor[], int n) {
  qSortInterno(vetor, 0, n-1);
}



double chronos(){
    struct timeval tv;
    gettimeofday(&tv,0);
    return tv.tv_sec+tv.tv_usec/1e6;
}

void aleatorio(int vetor[], int n){
    int i;
    for(i=0;i<n;i++){
        vetor[i] = rand() % n;
    }
}

void imprime(int vetor[], int n){
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\n", vetor[i]);
        contador++;
    }
}

void embaralhar_vetor(int vetor[], int n){
    int i, pivo, resultado;
    for(i=0;i<n;i++){
        resultado = rand() % n;
        pivo = vetor[i];
        vetor[i] = vetor[pivo];
        vetor[resultado] = pivo;
    }
}
int main(){
    int n=0,i=0;
    double inicio=0.0, fim =0.0;
    printf("Digite tamanho do vetor\n");
    scanf("%d", &n);
    int vetor[n];
    
    trocas=0;
    comparacoes=0;
    contador=0;

    aleatorio(vetor,n);
    inicio=chronos();
    quickSort(vetor,n);
    fim=chronos();
    int j; 
    double somaTempo=0;
    long int somaComparacoes=0,somaTroca=0;
    for(j=0;j<9;j++) {
        somaTempo=somaTempo+(fim-inicio);
        somaTroca=somaTroca+trocas;
        somaComparacoes=somaComparacoes+comparacoes;
        //fprintf(pont,"\n");
        aleatorio(vetor,n);
        embaralhar_vetor(vetor,n);
        inicio=0, fim=0;
        comparacoes=0,trocas=0;
        inicio=chronos();
        quickSort(vetor,n);
        fim=chronos();
    }
 	 printf("\n");
    printf("Tempo Medio : %lf\n", somaTempo/10);
    printf("Média de comparacoes: %ld\n", somaComparacoes/10);
    printf("Média das trocas: %ld\n", somaTroca/10);
}
   