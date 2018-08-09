#include <stdio.h>
//THIAGO MORAES
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
int igual(int x, int y){
    if(menor(x,y)){
        if (!(menor(y,x))){
            return 0;
        }
    }
    if(!(menor(x,y))){
        if(menor(y,x)){
            return 0;
        }

    }
    return 1;
}

void solucao(){
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    /*free*/while((n1)||(n2)){
        if (igual(n1,n2)==1){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
        scanf("%d %d", &n1, &n2);
    }
    printf("\n");

}

int soma(int x, int y){
    if(zero(x)){
        return y;
    }
    else{
        return soma(decrementa(x), incrimenta(y));
    }
}

int main(){

    int n1, n2;
    scanf("%d %d", &n1,&n2);
        while((n1)||(n2)){
            printf("%d\n",  soma(n1,n2));
            scanf("%d %d", &n1,&n2);
        }
    printf("\n");

}