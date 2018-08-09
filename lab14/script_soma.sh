#!/bin/bash
#Compilando os exercícios do 1 ao 3
gcc 1.c -o exercicio1 -lpthread
#gcc exercicio2.c -o exercicio2 -lpthread
#gcc exercicio3.c -o exercicio3 -lpthread
#Vetor contendo o tamanho dos dados
vetor_N=(1024 2048 4096 8192 16384 32768 65536)
#Vetor contendo o número de Threads
vetor_k=(1 2 4 8 16 32 64)
#Vetor com a quantidade de exercicios
vetor_execucao=(1 2 3)
#Execução dos 3 exercícios
#Número do exercício
#for x in "${vetor_execucao[@]}"
#do
	echo -e "-----------Execução do Exercicio $x-------------"
	#Tamanho do Vetor de dados
	for i in "${vetor_N[@]}"
	do
		echo "LOOP COM N = $i"
		sleep 2
		#Quantidade de Threads
		for j in "${vetor_k[@]}"
		do
			echo -e "**************************************************"
			echo -e "INICIANDO EXPERIMENTO PARA N = $i E K = $j..."
			echo -e "**************************************************"	
			#./exercicio$x $i $j
			./exercicio1 $i $j
			#i e j sao os argumentos
			echo -e "**************************************************"
			echo -e "FINALIZANDO EXPERIMENTO PARA N = $i E K = $j..."
			echo -e "**************************************************"
			echo -e ""
			sleep 2			   
		done
	done
#done