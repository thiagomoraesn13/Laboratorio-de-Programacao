#include <stdio.h>
///THIAGO MORAES -> 21452625
int primo(int numero){
	int i;
	if(numero == 1){
		return 0;
	}
	for(i=2;i<numero;i++){
		if(numero % i == 0 && i != numero){
			return 0;
		}
	}
	return 1;
}
int main(){
	int valor1, valor2;
	scanf("%d %d", &valor1, &valor2);
	int primo1=0;
	for(primo1=valor1;primo1<=valor2;primo1++){
		if(primo(primo1)==1){
				if(primo(primo1+2)==1 && primo1+2<=valor2){
					printf("(%d,%d)", primo1,primo1+2);

				}
		}
	}
	return 0;
}