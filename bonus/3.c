#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include <math.h>


//THiAGO MORAES 
//MATRÍCULA 21452625
//2ºTP BÔNUS - LPA
//PROFESSOR RAIMUNDO BARRETO
//MONITOR Jonathas Borges Cavalcante


//gcc -o terceira -fopenmp 3.c -lm
// ./terceira N K, onde N é a serie e k numero de threads


int N =0 ; ///numero de series
int K 	=0;//numero de threads
int parcela = 1; // // para termos o controle de cada parcela da serie
double soma =0.0;
double resultado=0.0;



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



void *Taylor_Swuift(Controle_Threads *vet){ //funcao para calcular a série de Taylor
	int i;
	
	printf("Thread %d : parcela : %d  \n",vet->thread, parcela); //identificador da thread e fim e inicio da k parte

	parcela++; // para termos o controle de cada parcela da serie
	for(i=0;i<=N;i++){
		soma = soma + ((pow((-1),(double)i))/(2*i+1));
	}
	resultado = 4*soma;

	return NULL;
}

int main(int argc, char *argv[]){
	N = atoi(argv[1]);//primeiro argumento é o numero de series
 	K = atoi(argv[2]);//segundo argumento é o numero de threads

	int i,inicio_anterior=0,fim_anterior; //variaveis para termos o controle do inicio e fim das k partes
	
 	Controle_Threads *vet; 
	int id; //id para termos controle de cada thread
 	double comecoTempo,fimTempo; //variaveis para marcarmos os tempos, inicio e final

 	comecoTempo=chronos();//inicio do tempo

 	#pragma omp parallel num_threads(K)//iniciando as threads 
 	{
 		
 		#pragma omp for ordered //para que as threads estejam ordenadas
 		
		for(i=0; i<K; i++){ 
		vet = (Controle_Threads*) malloc(sizeof(struct Controle_Threads*));///alacando o vetor para as k partes
		id = omp_get_thread_num();//pegando o id de cada thread

		vet->thread = id; 
		
		Taylor_Swuift(vet); //chamada funcao soma	
		}

	}
	fimTempo=chronos(); //fim do tempo
	printf("O valor da serie é:: %lf\n", resultado); //exibindo resultado final
	printf("TEMPO %lf\n: ",fimTempo-comecoTempo); // imprimindo tempo
}