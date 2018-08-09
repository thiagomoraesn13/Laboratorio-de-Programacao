//THiAGO MORAES - 21452625
/
//PROFESSOR : Raimundo Barreto
//CIÊNCIA DA COMPUTAÇÃO 

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>


double chronos(){ //para controle do tempo de execução
    struct timeval tv;
    gettimeofday(&tv,0);
    return tv.tv_sec+tv.tv_usec/1e6;
}

void imprime(int vetor[], int n){ //metodo para imprimir os valores do vetor
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\n", vetor[i]);
       
    }
}

void aleatorio(int vetor[], int n){ //gerando valores aleatórios
    int i;
    for(i=0;i<n;i++){
        vetor[i] = rand() % n;
    }
}

int soma_vetor(int *vet, int n){ //funcao para somar os valores do vetor
	int i,soma =0;
	for(i=0; i<n;i++){
		soma = soma+vet[i];
	}
	return soma;
}
int main(int argc, char *argv[]){
	int* vetor; 
	int n = atoi(argv[1]); //tamanho vetor passando via argumento
	double inicio=0.0, fim =0.0;
	
	vetor = (int*)malloc(sizeof(int)*n); //alocando vetor

	aleatorio(vetor,n); //preenchendo o vetor com valores aleatórios
	inicio = chronos(); //inicio do tempo
	soma_vetor(vetor,n);  //somando os valores
	fim=chronos(); //fim do tempo

	printf("O tempo para soma do vetor é %lf:\n", fim-inicio);
	

}


