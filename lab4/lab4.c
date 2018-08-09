#include <stdio.h>
#include <stdlib.h>
int** matriz ;
int** visitado;  
int m,n;
//Thiago Moraes //
int labirinto_maldito(int i, int j){
    if((matriz[i][j] == 1) || (i>m-1 || i<0) || (j>n-1 || j<0) || (visitado[i][j] == 1)){
        return 0;
    }
    if((i==m-1) && (j==n-1)){
        printf("%d %d\n",i+1,j+1);
        return 1;
    }
    visitado[i][j] = 1;
    if(labirinto_maldito(i,j+1)||
       labirinto_maldito(i+1,j)||
       labirinto_maldito(i+1,j+1)||
       labirinto_maldito(i,j-1)||
       labirinto_maldito(i-1,j)||
       labirinto_maldito(i-1,j-1)||
       labirinto_maldito(i-1,j+1)||
       labirinto_maldito(i+1,j-1)){
       printf("%d %d\n",i+1,j+1);
       return 1;
    }

}
void ler(){
int i,j;
      for (i = 0; i < m; i++) {
          for (j = 0; j < n; j++) {
             scanf("%d", &matriz[i][j]);
          }
    }
}
int main() {
      //int m, n;
      int i,j;
      scanf("%d %d", &m,&n);
      matriz = (int**)(malloc (m*(sizeof(int*)))); 
      for(i=0;i<m;i++){
          matriz[i] = (int*)(malloc(n*(sizeof(int)))); 

      }
      visitado = (int**)(malloc (m*(sizeof(int*))));
    for(j=0;j<m;j++){
          visitado[j] = (int*)(malloc(n*(sizeof(int)))); 

      }
      ler();
      labirinto_maldito(0,0);
      return 0;
}
