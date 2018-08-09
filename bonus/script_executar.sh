#!/bin/bash



gcc 1.c -o saida1 -lm
gcc -pthread -o saida2 2.c -lm
gcc -o saida3 -fopenmp 3.c -lm


vetor_N=(512 2024 1536 2048 3072 4096)
#Vetor contendo o número de Threads
vetor_k=(1 2 4 8 16 32)

#Vetor com a quantidade de exercicios
vetor_execucao=(1 2 3)
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
			./saida$x $i $j
			#i e j sao os argumentos
			echo -e "**************************************************"
			echo -e "FINALIZANDO...  PARA N = $i E K = $j..."
			echo -e "**************************************************"
			echo -e ""
			sleep 2			   
		done
	done
done