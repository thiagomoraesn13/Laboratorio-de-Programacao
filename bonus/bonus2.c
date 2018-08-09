#include <stdio.h>
#define N 1
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

int multiplica(int x, int y){
    int result=0;
    int i;

    for(i=0;i<y;i++){
        result = soma(result,x);
    }
    return result;
}

int simetrico(int x, int y, int z){
    while(x>0){
        return simetrico(decrementa(x), incrimenta(y), z);
    }
    while(y>0){
        return simetrico(decrementa(x),decrementa(y), z);
    }
    return x+z;
}
int main(){
    int n1, n2=0, n3=0;
    scanf("%d", &n1);
    n2=n1;
    n3=n2;
       while((n1)) {
           printf("%d\n", simetrico(n1, n2, n3));
           scanf("%d", &n1);
       }
    printf("\n");
}