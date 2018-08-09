//THiAGO MORAES - 21452625

//PROFESSOR : Raimundo Barreto
//CIÊNCIA DA COMPUTAÇÃO 


//gcc -o bankai -fopenmp 5.c -lm
//onde bankai é a saída, pode ser qualquer outro nome

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>

long int soma = 0;


int K=0,N=0;
int* vetor;

typedef struct threads{ //registro para guardar o inicio,fim e o numero da thread, por exemplo: inicio 0(inicio)-511(fim), thread 0(thread=0);  
	int inicio;
	int fim;
	int thread; 
	
}Controle_Threads;


double chronos(){ //para controle do tempo de execução 
    struct timeval tv;
    gettimeofday(&tv,0);
    return tv.tv_sec+tv.tv_usec/1e6;
}

void aleatorio(int vetor[], int n){ // metodo para gerar valores aleatórios para vetor
    int i;
    for(i=0;i<n;i++){
        vetor[i] = rand() % n;
    }
}

void *somavet(Controle_Threads *vet){ // metodo para somar os valores das k partes usando threads
	int i;
	printf("Thread %d : [%d , %d]\n",vet->thread,vet->inicio,vet->fim); //identificador da thread e fim e inicio da k parte
	#pragma omp for reduction (+:soma) //usando a funcao reduction na variavel soma

	for(i = vet->inicio; i<= vet->fim; i++){
		
		soma = soma + vetor[i];//a variavel soma estar protegida lá na funcao main quando a funcao somavet é chamada
	}
	return NULL;
}
void imprime(){//imprimir os valores do vetor
    int i;
    for (i = 0; i < N; i++) {
        printf("%d\n", vetor[i]);
    }
}
int main(int argc, char *argv[]){
	N = atoi(argv[1]);//primeiro argumento é o tamanho do vetor
 	K = atoi(argv[2]);//segundo argumento é o numero de threads

 	vetor = (int*)malloc(sizeof(int)*N); //alocando o vetor
 	aleatorio(vetor,N); //gerando valores aleatórios para o vetor

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

		vet->inicio = inicio_anterior;
		vet->fim = vet->inicio + ((N/K)-1);

		vet->thread = id; 
		inicio_anterior = vet->fim+1;

		//#pragma omp critical //protegeando a regiao critica, para que cada chamada seja acessada uma unica vez por cada thread
		somavet(vet); //chamada funcao soma	
		}

	}
	fimTempo=chronos(); //fim do tempo
	printf("O valor total da soma: %ld\n", soma);
	printf("TEMPO %lf\n: ",fimTempo-comecoTempo);
}