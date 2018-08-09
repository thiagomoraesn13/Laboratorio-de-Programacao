#include <stdio.h>

int zero(int x){
    return (x==0);
}
int incrimenta(int x){
    return (x+1);
}
int decrementa(int x){
    return (x-1);
}

int menor(int x, int y){
    if(zero(y)){
        return 0;
    }
    else{
        if(zero(x)){
            return 1;
        }
        else{
            return  menor(decrementa(x),decrementa(y));
        }
    }
}
int main(){
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    while ((n1 && n2) != 0){
    if (menor(n1,n2)){
        printf("SIM\n");
    }
    else{
    printf("NAO\n");
    }
        scanf("%d %d", &n1, &n2);
    }
    printf("\n");
}