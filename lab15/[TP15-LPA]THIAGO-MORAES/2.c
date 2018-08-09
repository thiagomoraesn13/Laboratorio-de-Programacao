//THIAGO MORAES - 21452625
//LPA
//PROFESSOR : Raimundo Barreto
//CIÊNCIA DA COMPUTAÇÃO 
//QUESTAO 2

//gcc -o bankai -fopenmp 2.c -lm
//onde bankai é a saída, pode ser qualquer outro nome

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>

//para controle do tempo de execução
double chronos(){ 
    struct timeval tv;
    gettimeofday(&tv,0);
    return tv.tv_sec+tv.tv_usec/1e6;
}

double* polinomio(int grau){ //para lermos os coeficientes da funcao
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


void trapezio_descendente(double a, double b, int n, double* global_result_p, double *vet){ //funcao para calcular a integral
	double h,x,my_result; //variveis para obtermos os valores parciais	
	double local_a, local_b; //limite inferior e superior
	int i, local_n, posi=0;;
	int my_rank = omp_get_thread_num(); //indice da thread
	int thread_count = omp_get_num_threads(); // para termos os controle das threads

	int vetor_parcial[16]; // vetor parcial
	h = (b-a)/n; //obtendo as areas parciais
	local_n = n / thread_count;
	local_a = a + my_rank*local_n*h;
	local_b = local_a+local_n*h;
	my_result = (f(vet,2,local_a) + f(vet,2,local_b))/2.0; //aplicando a funcao no polinomio
	for(i=1; i<=local_n-1;i++){
		x = local_a+i*h;
		my_result+=f(vet,2,x); //resultado parcial
	}

	my_result = my_result*h; 
	vetor_parcial[posi] = my_result;
	# pragma omp critical //protegendo a area critica do resultado final
	  *global_result_p += my_result;
}



int main(int argc, char *argv[]){
	int grau = 2;
	
	double global_result = 0.0; //para termos o valor final da integral
	double a,b; //onde é o A limite inferior e B o limite superior
	int thread_count, n; //onde N é a quantidade de trapezios E thread_count é quantidade de threads

	thread_count = strtol(argv[2], NULL, 10);
	//printf("n: \n");	
	//scanf("%d", &n);
	n = atoi(argv[1]);
	///printf("polinomio\n");

	double inicio, fim;
	double * vetor = polinomio(grau);
	a=0;  //limite inf
	b=1;  //limite superior
	inicio=chronos();
	#pragma omp parallel num_threads(thread_count) //iniciando as threadS
	trapezio_descendente(a,b,n, &global_result, vetor); //executando o calculo da integral 
	fim = chronos();
	//printf("com N = %d trapezio\n", n);
	printf("o valor de integral para de %f até %f = %.14e \n", a,b,global_result);
	printf("Tempo: %lf\n", fim-inicio);
	return 0;
}
