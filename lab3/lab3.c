#include <stdio.h>

int veri_padroes(int matriz[6][6],int x,int y,int valor){
    int i, l= 1, c = 1;

    if(y < 4 && matriz[x][y+1] == valor){
        if(matriz[x][y+2] == valor){
                return 0;
        }
    }
    
    if(x < 4 && matriz[x+1][y] == valor){
         if(matriz[x+2][y] == valor){
            return 0;
         }
    }

    if(y > 0 && y < 5 && matriz[x][y-1] == valor){
            if(matriz[x][y+1] == valor){
                 return 0;
            }
    }
    if(x > 0 && x < 5 && matriz[x-1][y] == valor){
            if(matriz[x+1][y] == valor){
                return 0;
            }
    }

    if(y > 1 && matriz[x][y-2] == valor){
             if(matriz[x][y-1] == valor){
                    return 0;
             }
    }
    if(x > 1 && matriz[x-2][y] == valor) { 
            if(matriz[x-1][y] == valor) {
                return 0;
            }

    }
    for (i=0; i<6; i++){
        if (matriz[i][y] == valor){
            c++;
        }
        if(matriz[x][i] == valor){
            l++;
        }
    }

    if(l > 3 || c > 3){
        return 0;
    }
    else{
        return 1;
    }
}

int verifica_um(int matriz[6][6],int x,int y,int verifica){
    int i, contador = 0;
    if (verifica){
        for (i=0; i<6; i++){
            if (matriz[i][y] == 1){
                contador++;
            }
        }
    } else {
        for (i=0; i<6; i++){
            if (matriz[x][i] == 1){
                contador++;
            }
        }
    }
    return contador;
}
int verifica(int matriz[6][6],int *x,int *y){
    int i, j;
    for (i=0; i<6; i++){
        for (j=0; j<6; j++){
            if (matriz[i][j] == 2){
                *x = i;
                *y = j;
                return 1;
            }
        }
    }
    return 0;
}
int verifica_linha(int matriz[6][6]){
    int i, j, k;
    for (k=0; k<5; k++){
        for (i=k+1; i<6; i++){
            for (j=0; j<6; j++){
                if (matriz[k][j] != matriz[i][j]){
                    break;
                }
                if (j == 5) {
                    return 1;
                }
            }
        }
    }
    return 0;   
}
int verifica_coluna(int matriz[6][6]){
    int i, j, k;
    for (k=0; k<5; k++){
        for (i=k+1; i<6; i++){
            for (j=0; j<6; j++){
                if (matriz[j][k] != matriz[j][i]){
                    break;
                }
                if (j == 5){ 
                    return 1;
                }
            }
        }
    }

    return 0;
}

int resolve(int matriz[6][6]){

    int i, j, fim, passo;
    if(!verifica(matriz,&i,&j)){
        if((verifica_linha(matriz) || verifica_coluna(matriz))){
            return 0;
        }
        else{
            return 1;
        }
    }
    for(passo = 0; passo <= 1; passo++){
        if(veri_padroes(matriz,i,j,passo)){
            matriz[i][j] = passo;
            if(resolve(matriz)){
                return 1;
            }
        }
        matriz[i][j] = 2;
    }

    return 0;
}
void imprime(int matriz[6][6]) {
    int i, j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int matriz[6][6], m, n;
    for (m = 0; m < 6; m++) {
        for (n = 0; n < 6; n++) {
            scanf("%d", &matriz[m][n]);
        }
    }
    resolve(matriz);
    imprime(matriz);
    printf("\n");

    return 0;
}
/*

2  2  2  0  2  2
2  2  0  0  2  1
2  0  0  2  2  1
2  2  2  2  2  2
0  0  2  1  2  2
2  1  2  2  0  0
*/