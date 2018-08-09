//THiAGO MORAES - 21452625

//PROFESSOR : Raimundo Barreto
//CIÊNCIA DA COMPUTAÇÃO 

//gcc 1.c -o saida -lm
// ./sainda 10
//onde 10 é quantidade de trapezios
// digite seguidamente 
//1 
//0 
//0
// sao os coeficiente do polinomio 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>



double chronos(){ //para controle do tempo de execução
    struct timeval tv;
    gettimeofday(&tv,0);
    return tv.tv_sec+tv.tv_usec/1e6;
}

double* polinomio(int grau){ ////para lermos os coeficientes da funcao
	int i;	
	double* vet = (double*)malloc(sizeof(double)*(grau+1));
	for(i=grau; i >=0; i--){
		///printf("Digite o coeficiente:\n");
		scanf("%lf", &vet[i]);		
	}
	return vet;
}

double f(double* vet, int grau, double x){ //aplicando a funcao no polinomio
	int i;
	double resultado=0;
	for(i=0; i<=grau; i++){
		resultado = 4/(1 + resultado + (vet[i] * pow(x, (double) i)));
	}
	return resultado;
}


double trapezio(double* vet,int n){ //calculando a integral
	double a = 0; //limite inferior
	double b = 1; //limite superior
	int grau = 2; //grau do polinomio


	if( n < 0){
		printf("intervalo invalido");
		return 1;
	}
	else{
		double h = (b - a)/n;
		double x = a + h;
		int i;
		double soma=0;
		for(i=0; i < n-1; i++){
			soma = soma + f(vet,grau,x);
			x = x + h; 
		}
		double bx = f(vet,grau,a); //aplicando a funcao em a
		double cx = f(vet,grau,b); //aplicando a funcao em b
		double resultado = h*(((bx+cx)/2)+ soma); //resultado da integral
		return resultado;
	}
}
int main (int argc, char *argv[]){
	
	int n = 0;;    // subintervalo  
	n = atoi(argv[1]); //
	int grau = 2;
	double* vetor = polinomio(grau);
	double inicio=0,fim=0;
	inicio = chronos();
	printf("o valor da integral: %lf\n", trapezio(vetor,n)); // chamada da funcao trapezio 
	fim = chronos();
	printf("Tempo: %lf\n", fim-inicio);
	//polinomio testado : 1 2 -2 3 -4 -2 1 -5	
}
