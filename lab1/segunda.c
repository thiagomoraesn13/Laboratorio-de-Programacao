#include <stdio.h>

//THIAGO MORAES -> 21452625
int main(){
	int jogador1,jogador2, jogadas;
	scanf("%d", &jogadas);
	int i,soma1=0, soma2=0;
	for(i=0;i<jogadas;i++){
		scanf("%d%d", &jogador1,&jogador2);
	
	if(jogador1 - jogador2 == -2 || jogador1 - jogador2 == 1){
		soma1=soma1+1;
	}

	if(jogador1 - jogador2 == -1 || jogador1 - jogador2 == 2){
		soma2=soma2+1;
	}

	}

	if(soma1 > soma2){
	printf("1");
	}
	if(soma2 > soma1){
	printf("2");
	}
	if(soma1==soma2){
	printf("0");
	}
return 0;
}