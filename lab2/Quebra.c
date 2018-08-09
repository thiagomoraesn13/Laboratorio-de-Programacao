#include <stdio.h>

#define N 6

//Thiago Moraes
//REGRA 00 -> 1001 / 100/ 001   | REGRA 010 -> 010
//REGRA 11 -> 0110 / 011 / 110  | REGRA 1*1 -> 101
void regra12coluna(int matriz[6][6]) {
    int i, j;
    int som1 = 0, som2 = 0;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (matriz[j][i] == 1 && matriz[j + 1][i] == 1) {
                if (matriz[j + 2][i] == 2) {
                    matriz[j + 2][i] = 0;


                }
            }
            if (matriz[j][i] == 2 && matriz[j + 1][i] == 1 && matriz[j + 2][i] == 1) {
                matriz[j][i] = 0;
            }
            if (matriz[j][i] == 0 && matriz[j + 1][i] == 0) {
                if (matriz[j + 2][i] == 2) {
                    matriz[j + 2][i] = 1;

                }
            }
            if (matriz[j][i] == 2 && matriz[j + 1][i] == 0 && matriz[j + 2][i] == 0) {
                matriz[j][i] = 1;

            }
        }
    }
}

void regra34coluna(int matriz[6][6]) {
    int i, j = 0;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (matriz[j][i] == 1 && matriz[j + 2][i] == 1 && (j + 2 < 6)) {
                //   printf("aaaaaa");
                if (matriz[j + 1][i] == 2) {
                    matriz[j + 1][i] = 0;
                }
            }
            if (matriz[j][i] == 0 && matriz[j + 2][i] == 0 && (j + 2 < 6)) {
                if (matriz[j + 1][i] == 2) {
                    matriz[j + 1][i] = 1;
                }
            }
        }
    }
}

void regra12liinha(int matriz[6][6]) {
    int i, j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (matriz[i][j] == 2 && matriz[i][j + 1] == 0 && matriz[i][j + 2] == 0 && (j + 2 < 6)) {
                matriz[i][j] = 1;
            }
            if (matriz[i][j] == 1 && matriz[i][j + 1] == 1 && (j + 2 < 6)) {
                if (matriz[i][j + 2] == 2) {
                    matriz[i][j + 2] = 0;
                }
            }
            if (matriz[i][j] == 2 && matriz[i][j + 1] == 1 && matriz[i][j + 2] == 1) {
                matriz[i][j] = 0;
            }
            if (matriz[i][j] == 0 && matriz[i][j + 1] == 0 && (j + 2 < 6)) {
                if (matriz[i][j + 2] == 2) {
                    matriz[i][j + 2] = 1;
                }
            }
        }
    }
}

void regra34liinha(int matriz[6][6]) {
    int i, j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (matriz[i][j] == 1 && matriz[i][j + 2] == 1 && (j + 2 < 6)) {
                if (matriz[i][j + 1] == 2) {
                    matriz[i][j + 1] = 0;
                }
            }
            if (matriz[i][j] == 0 && matriz[i][j + 2] == 0 && (j + 2 < 6)) {
                if (matriz[i][j + 1] == 2) {
                    matriz[i][j + 1] = 1;
                }
            }
        }
    }
}

int imprime(int matriz[6][6]) {
    int i, j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void completa(int matriz[6][6]) {
    int i, j, somaUm = 0, somaZ = 0;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (matriz[j][i] == 1) {
                somaUm++;
            }
            if (matriz[j][i] == 0) {
                somaZ++;
            }
        }
        if (somaZ == 3) {
            int k;
            for (k = 0; k < 6; k++) {
                if (matriz[k][i] == 2) {
                    matriz[k][i] = 1;
                }
            }

        }
        if (somaUm == 3) {
            int k;
            for (k = 0; k < 6; k++) {
                if (matriz[k][i] == 2) {
                    matriz[k][i] = 0;
                }
            }

        }
        somaUm = 0;
        somaZ = 0;
    }
}

void completaLinha(int matriz[6][6]) {
    int i, j, somaUm = 0, somaZ = 0;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (matriz[i][j] == 1) {
                somaUm++;
            }
            if (matriz[i][j] == 0) {
                somaZ++;
            }
        }
        if (somaZ == 3) {
            int k;
            for (k = 0; k < 6; k++) {
                if (matriz[i][k] == 2) {
                    matriz[i][k] = 1;
                }
            }

        }
        if (somaUm == 3) {
            int k;
            for (k = 0; k < 6; k++) {
                if (matriz[i][k] == 2) {
                    matriz[i][k] = 0;
                }
            }

        }
        somaUm = 0;
        somaZ = 0;
    }
}
int main() {
    int matriz[6][6], m, n;
    for (m = 0; m < 6; m++) {
        for (n = 0; n < 6; n++) {
            scanf("%d", &matriz[m][n]);
        }
    }
    int i, j;
    for (i = 0; i < 6; i++) {
            regra12liinha(matriz);
            regra34liinha(matriz);
            regra12coluna(matriz);
            regra34coluna(matriz);
            completa(matriz);
            completaLinha(matriz);

    }
    imprime(matriz);
    return 0;
}