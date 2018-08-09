import java.util.*;

///THiAGO MORAES //

public class main {
    private int dimensao;
    private int dimensao2;
    char matriz[][];
    int visitados[][];
    int bombas[][];

    public main(int dimensao, int dimensao2, char[][] matriz, int[][] visitados, int[][] bombas) {
        this.dimensao = dimensao;
        this.dimensao2 = dimensao2;
        this.matriz = matriz;
        this.visitados = visitados;
        this.bombas = bombas;
    }

    public int getDimensao() {
        return dimensao;
    }
    public int getDimensao2() {
        return dimensao2;
    }

    public void setDimensao(int dimensao) {
        this.dimensao = dimensao;
    }

    public void setDimensao2(int dimensao2) {
        this.dimensao2 = dimensao2;
    }

    boolean naval(int i, int j, int acumulador) {
        if (i >= getDimensao() || j >= getDimensao2() || i < 0 || j < 0 ||  visitados[i][j] == 1) {
            return false;
        }
        else if (matriz[i][j] == '#' && bombas[i][j] != acumulador && bombas[i][j] != 0) {
            visitados[i][j] = 1;
            return (naval(i + 1, j, acumulador) ||
                    naval(i, j + 1, acumulador) ||
                    naval(i - 1, j, acumulador) ||
                    naval(i, j - 1, acumulador));


        }
        else if (matriz[i][j] == '#') {
            this.bombas[i][j] = acumulador;
            this.visitados[i][j] = 1;
            return (naval(i + 1, j, acumulador) ||
                    naval(i, j + 1, acumulador)||
                    naval(i - 1, j, acumulador) ||
                    naval(i, j - 1, acumulador));

        }
      else{
        this.visitados[i][j] = 1;
        return false;
    }
    }
     int navios(){
         int i,j;
        int contador = 1;
        for( i=0;i<getDimensao();i++){
            for ( j=0;j<getDimensao2(); j++){
                if(this.bombas[i][j]==0 && this.matriz[i][j]=='#'){
                    contador++;
                }
                this.naval(i,j,contador);
            }
        }
        return contador-1;
    }
     int tiros(int embarcacoes){
        int acumulador=0, contador =0, navi;
        for(navi=2;navi<=embarcacoes+1;navi++){
            for(int i =0; i<getDimensao();i++){
                for(int j=0;j<getDimensao2();j++){
                    if(bombas[i][j]==navi){
                        acumulador++;
                    }
                }
            }
            if(acumulador==0){
                contador++;
                acumulador=0;
            }
            else{
            acumulador=0;
            }
        }
        return contador;
    }
    void balasAOMar(int vertices, int adj){
        bombas[vertices][adj] = 0;
    }
    public static void main(String args[]) {
        Scanner leitura = new Scanner(System.in);
        int dim, dim2;
        dim = leitura.nextInt();
        dim2 = leitura.nextInt();
        char matriz[][] = new char [dim][dim2];
        int visitada [][]  = new int [dim][dim2];
        int bombas [][] = new int [dim][dim2];
        int balas;
        main barco  = new main(dim,dim2,matriz,visitada,bombas);

            for (int i=0; i<dim; i++){
                String char_aux = leitura.next();
                for (int j=0; j<dim2; j++){
                    barco.matriz[i][j] = char_aux.charAt(j);
                }
            }
        int linha=0, coluna=0;
        int quantidade = barco.navios();
        int tiros = leitura.nextInt();

        for(int k=0;k<tiros;k++){
            linha = leitura.nextInt();
            coluna = leitura.nextInt();
            barco.balasAOMar(linha-1,coluna-1);
        }
        balas = barco.tiros(quantidade);
        System.out.println(balas);
    }
}

