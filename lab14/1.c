//THiAGO MORAES
//MATRÍCULA 21452625
//LABORATÓRIO DE PROGRAMAÇÃO AVANÇADA - TP13
// gcc -pthread -o questao1 questao1.c
// ./questao1 512 1 
//onde 512 é N e 1 é K
#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h> 
#include <time.h> 

int N =0 ; ///tamanho do vetor
int K 	=0;//numero de threads
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 

int vetor[65536]; //
int soma_parcial[64]; // para salvar os valores das somas

typedef struct threads{ //registro para guardar o inicio,fim e o numero da thread, por exemplo: inicio 0(inicio)-511(fim), thread 0(thread=0);  
	int inicio;
	int fim;
	int thread; 
	
}Controle_Threads;

void *somavet(void *arg){ // metodo para somar os valores das k partes usando threads
	pthread_mutex_lock(&mutex);
	Controle_Threads *vet = (Controle_Threads*)(arg);
	long int soma = 0;
	int i;
	printf("Thread %d : [%d , %d]\n",vet->thread,vet->inicio,vet->fim); //identificador da thread e fim e inicio da k parte
	for(i = vet->inicio; i<= vet->fim; i++){
		soma = soma + vetor[i];
	}
	soma_parcial[vet->thread] = soma;
	pthread_mutex_unlock(&mutex);
	return NULL;
}
double chronos(){ //para controle do tempo de execução
    struct timeval tv;
    gettimeofday(&tv,0);
    return tv.tv_sec+tv.tv_usec/1e6;
}

void aleatorio(int vetor[]){ //gera valores aleatórios
    int i;
    for(i=0;i<N;i++){
        vetor[i] = rand() % (2*N);
    }
}


int main(int argc, char const *argv[]) {
	N = atoi(argv[1]);
 	K = atoi(argv[2]);


	//vetor[200000];
	///soma_parcial[22222];

	long int soma=0;
	pthread_t thread[K];
	Controle_Threads *vet;
	double comeco,fim; 
	int i,inicio_anterior,fim_anterior;
	aleatorio(vetor); //gerando valores aleatórios pro vetor
	inicio_anterior = 0; 
	for(i=0; i<K; i++){ 
		vet = (Controle_Threads*) malloc(sizeof(struct Controle_Threads*));
		vet->inicio = inicio_anterior;
		vet->fim = vet->inicio + ((N/K)-1);
		vet->thread = i; 
		inicio_anterior = vet->fim+1;
		fim_anterior = vet->fim + ((N/K));
		pthread_create(&thread[i],NULL,somavet,(void*)(vet));
	}
	comeco = chronos(); //tempo de inicio
	for(i=0; i<K; i++){
		pthread_join(thread[i],NULL);
	}
	fim = chronos(); //fim
	for(i=0; i<K; i++){
		soma = soma + soma_parcial[i];
	}
	printf("\nTempo: %lf \n", fim-comeco); //exibir tempo de execucao 
	return 0;
}

