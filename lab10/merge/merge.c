#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

long int comparacoes=0, trocas =0;
int contador=0;

void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;

    if(posicaoInicio == posicaoFim) return;

    // ordenacao recursiva das duas metades
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);

    // intercalacao no vetor temporario t
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { // i passou do final da primeira metade, pegar v[j]
            comparacoes++;
            trocas;
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            comparacoes++;
            trocas++;
            if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
                trocas++;
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                comparacoes++;
                trocas++;
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    // copia vetor intercalado para o vetor original
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        trocas++;
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
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
    mergeSort(vetor,0,n);

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
        mergeSort(vetor,0,n);
        fim=chronos();
    }
    printf("\n");
    printf("Tempo Medio : %lf\n", somaTempo/10);
    printf("Média de comparacoes: %ld\n", somaComparacoes/10);
    printf("Média das trocas: %ld\n", somaTroca/10);
  
}
  