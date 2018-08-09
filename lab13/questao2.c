//THiAGO MORAES
//MATRÍCULA 21452625
//LABORATÓRIO DE PROGRAMAÇÃO AVANÇADA - TP13
// gcc -pthread -o questao2 questao2.c
// ./questao1 128 1 
//onde 128 é N e 1 é K
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
int N;
int K;
int **matrizA;
int **matrizB;
int **matriz_resultado;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
double *Controle_Threads; 

double chronos();
void criando_matriz();
void* multiplicacao(void* num);

int main(int argc, char const *argv[]) {
  double comeco=0.0,fim =0.0;
	N = atoi(argv[1]);
 	K = atoi(argv[2]);
	pthread_t threads[K];
  int i;
  int results;
  srand(time(NULL));
  criando_matriz();
  comeco=chronos();
	for (i = 0; i < K; i++){
		results= pthread_create(&threads[i], NULL, multiplicacao, (void*) &i);
    pthread_join(threads[i], NULL);
	}
  fim=chronos();
  printf("Tempo Total: %lf\n", fim-comeco);///exibindo tempo de execucao

	return 0;
}

double chronos(){ //para controle do tempo de execução
    struct timeval tv;
    gettimeofday(&tv,0);
    return tv.tv_sec+tv.tv_usec/1e6;
}
void criando_matriz(){ //criando(alocando) matrizes
  int i = 0;
  int j = 0;
  matrizA = (int **) malloc(N * sizeof(int*));
  matrizB = (int **) malloc(N * sizeof(int*));
  matriz_resultado = (int **) malloc(N * sizeof(int*));
  Controle_Threads = (double *) malloc(K * sizeof(double*));
    for(i = 0; i < N; i++) {
        matrizA[i] = (int *) malloc(N * sizeof(int));
        matrizB[i] = (int *) malloc(N * sizeof(int));
        matriz_resultado[i] = (int *) malloc(N * sizeof(int));
        for (j = 0; j < N; j++){
          matrizA[i][j] = rand() % (2*N); //alocando valores aletórios para a matriz A
          matrizB[i][j] = rand() % (2*N); //alocando valores aletórios para a matriz B
          matriz_resultado[i][j] = 0; 
        }
    }
    
}
void* multiplicacao(void* num){ //multiplicando as matrizes
  pthread_mutex_lock( &mutex1 );
  int id_bloco = *((int *) num);
  int size_bloco = N/K;
  int offset = id_bloco*size_bloco;
  int i, j, k;
  int soma = 0;
  for (i = offset; i < offset + size_bloco; i++) {
      for (j = 0; j  < N; j++) {
        for (k = offset; k < offset + size_bloco; k++) {
          soma = soma + matrizA[i][k]*matrizB[k][j]; //multiplciando as matrizes
        }
        matriz_resultado[i][j] = soma;
        soma = 0;
      }
  }
  pthread_mutex_unlock( &mutex1 );
  pthread_exit(NULL);
}