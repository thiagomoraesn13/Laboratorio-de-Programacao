#!/bin/bash


gcc 1.c -o questao1 -fopenmp 
gcc 2.c -o questao1 -fopenmp 

vetor_N=(1024 2048 4096 8192 16384 32768 65536)
#Vetor contendo o número de Threads
vetor_k=(1 2 4 8 16 32 64)

#Vetor com a quantidade de exercicios
vetor_execucao=(1 2)
#Número do exercício
for x in "${vetor_execucao[@]}"
do
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
			echo -e "INICIANDO...  PARA N = $i E K = $j..."
			echo -e "**************************************************"	
			#./exercicio$x $i $j
			./questao$x $i $j
			#i e j sao os argumentos
			echo -e "**************************************************"
			echo -e "FINALIZANDO...  PARA N = $i E K = $j..."
			echo -e "**************************************************"
			echo -e ""
			sleep 2			   
		done
	done
done