#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>


void qSortInterno(int vetor[], int inicio, int fim) {
  int pivot;
  int temp;
  int i,j;

  i = inicio;
  j = fim;
  pivot = vetor[(i+j)/2];
    
  do {
  	
    while(vetor[i] < pivot) {
      
        i++;
    }
    while(vetor[j] > pivot){ 
       
        j--;
    }
    if(i<= j) {
      temp = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = temp;
      i++; j--;
    
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



int main() {
    //N = atoi(argv[1]);
    printf("Tamanho do vetor: \n");
    
    int N=0;  
      

    scanf("%d", &N);

    double inicio=0.0, fim =0.0;
    
    int vetor[N];
  
    aleatorio(vetor,N);

    inicio=chronos();

    quickSort(vetor,N);
    
    fim=chronos();
    
    printf("Tempo : %lf\n", fim-inicio);
  
  }
   