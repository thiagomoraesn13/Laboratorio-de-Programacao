#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include <math.h>
 

 //gcc 1.c -o saida -lm
// ./saida N
// onde N corresponde o tamanho da série


double chronos(){ //para controle do tempo de execução
    struct timeval tv;
    gettimeofday(&tv,0);
    return tv.tv_sec+tv.tv_usec/1e6;
}

double Taylor_Swuift(int n){ //funcao para calcular a série de Taylor
	int i;
	double soma =0.0;
	double resultado=0.0;

	for(i=0;i<=n;i++){
		soma = soma + ((pow((-1),(double)i))/(2*i+1));
	}
	resultado = 4*soma;
	return resultado;
}
int main(int argc, char *argv[]){
	int n =0; 
	n = atoi(argv[1]); //recebendo primeiro argumento, tamanho da série
	double inicio=0.0, fim=0.0; //variaveis para inicio e fim do tempo
	inicio = chronos(); 
	printf("O resultado da série: %lf\n",Taylor_Swuift(n)); //imprimindo resultado da série
	fim = chronos();
	printf("Tempo: %lf\n", fim-inicio); //exibindo tempo
}