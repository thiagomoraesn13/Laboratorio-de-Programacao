#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h> 
#include <time.h> 
#include <math.h>


//THiAGO MORAES 
//MATRÍCULA 21452625
//2ºTP BÔNUS - LPA
//PROFESSOR RAIMUNDO BARRETO
//MONITOR Jonathas Borges Cavalcante

// gcc -pthread -o saida 2.c -lm
// ./saida N K 
//onde N é a serie e K as threads


int n =0 ; ///numero de series
int K 	=0;//numero de threads
int parcela = 1;
double soma =0.0;
double resultado=0.0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 



double chronos(){ //para controle do tempo de execução
    struct timeval tv;
    gettimeofday(&tv,0);
    return tv.tv_sec+tv.tv_usec/1e6;
}


typedef struct threads{ //registro para guardar o inicio,fim e o numero da thread, por exemplo: inicio 0(inicio)-511(fim), thread 0(thread=0);  
	int inicio;
	int fim;
	int thread; 
	
}Controle_Threads;



void *Taylor_Swuift(void *arg){ //funcao para calcular a série de Taylor
	int i;
	pthread_mutex_lock(&mutex);
	Controle_Threads *vet = (Controle_Threads*)(arg);
	printf("Thread %d : parcela : %d  \n",vet->thread, parcela); //identificador da thread e fim e inicio da k parte
	parcela++;
	for(i=0;i<=n;i++){
		soma = soma + ((pow((-1),(double)i))/(2*i+1));
	}
	resultado = 4*soma;
	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main(int argc, char const *argv[]) {
	n = atoi(argv[1]); //tamanho da serie
	K = atoi(argv[2]); //numero de threads


	pthread_t thread[K];
	Controle_Threads *vet;

	double comeco,fim; 
	int i;
	for(i=0; i<K; i++){ 
		vet = (Controle_Threads*) malloc(sizeof(struct Controle_Threads*));
		vet->thread = i; 
		pthread_create(&thread[i],NULL,Taylor_Swuift,(void*)(vet));
	}
	comeco = chronos(); //tempo de inicio
	for(i=0; i<K; i++){
		pthread_join(thread[i],NULL);
	}
	fim = chronos(); //fim

	printf("O resultado da serie é: %lf\n", resultado); // exibindo resultado final
	printf("\nTempo: %lf \n", fim-comeco); //exibir tempo de execucao 

	return 0;

}