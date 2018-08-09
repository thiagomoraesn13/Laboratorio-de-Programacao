#include <stdio.h>
#define N 9

int Verifica_quadrante(int matriz[][N], int linha, int coluna, int num)
{
    int iauxiliar_linha = (linha/3) * 3;
    int auxiliar_coluna= (coluna/3) * 3;
    int i, j;

    for(i=0; i<N; i++){
        if (matriz[linha][i] == num){

         return 0;
        }
        if (matriz[i][coluna] == num) {
            return 0;
        }
        if (matriz[iauxiliar_linha + (i%3)][auxiliar_coluna + (i/3)] == num){ 
            return 0;
        }
    }
    return 1;
}

int resolve(int matriz[][N], int linha, int coluna)
{
    int i;
    if(linha<N && coluna<N){
        if(matriz[linha][coluna] != 0){
            if((coluna+1)<N) {
                return resolve(matriz, linha, coluna+1);
            }
            else if((linha+1)<N){ 
                return resolve(matriz, linha+1, 0);
            }
            else{ 
                return 1;
            }
        }
        else
        {
            for(i=0; i<N; ++i){
                if(Verifica_quadrante(matriz, linha, coluna, i+1))
                {
                    matriz[linha][coluna] = i+1;
                    if((coluna+1)<N){
                        if(resolve(matriz, linha, coluna +1)){
                            return 1;
                        }
                        else{ 
                            matriz[linha][coluna] = 0;
                        }
                    }
                    else if((linha+1)<N){
                        if(resolve(matriz, linha+1, 0)) {
                            return 1;
                        }
                        else{
                         matriz[linha][coluna] = 0;
                        }
                    }
                    else {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    else{
     return 1;
 }
}

void leitura(int matriz[N][N]){
     for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                scanf("%d", &matriz[i][j]);
            }
    }     
}
void imprime(int matriz[N][N]){
     for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++){
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
    }

int main(){
    int i, j;
    int matriz[N][N]={0};
    leitura(matriz);
    resolve(matriz,0,0);
    imprime(matriz);
    return 0;
}