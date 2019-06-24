#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){

    char nombreArchivo[100000];
    int n;
    printf("Ingrese el nombre del archivo (con .txt): ");
    gets(nombreArchivo);
    system("cls");
    n = TamanoArchivo(nombreArchivo);
    int matrizValuada[n][n];
    leerGrafo(nombreArchivo,n,matrizValuada);
    //imprimirMatriz(n,matrizValuada);
    aristasValidas(n,matrizValuada);
    //printf("estas son las aristas validas %i", nAristas);
    int matrizAristas[4][nAristas];
    int matrizAristasOrdenada[4][nAristas];
    int matrizAdyacenciaGenerada[n][n];
    int visitados[n];
    //printf("\n");
    int tCiclo=1;
    int matrizConjunto[n][n];
    for(int j = 0 ; j < n ; j++){
        for(int k = 0 ; k < n ; k++){
            matrizConjunto[j][k]=-2;
        }
    }
    for(int i = 0 ; i < n ; i++){
        matrizConjunto[0][i] = i;
    }
    crearMatrizAristas(n,matrizValuada,matrizAristas);
    ordenasAristas(matrizAristas,matrizAristasOrdenada);
    int matrizAristasPrimOrdenada[4][nAristas];//es catolica
    copiadorDeMatrices(matrizAristasOrdenada,matrizAristasPrimOrdenada);
    kruskal(n,matrizConjunto,matrizAristasOrdenada);
    int costo=0;
    for(int j = 0 ; j < nAristas ; j++){
        if(matrizAristasOrdenada[3][j]==1){
            costo+=matrizAristasOrdenada[0][j];
        }
    }
    printf("ACM Kruskal: (costo %i)\n",costo);
    for(int i = 0; i < n ; i++){
        if(matrizAristasOrdenada[3][i]==1){
            printf("(%i,%i) costo: %i\n",matrizAristasOrdenada[1][i]+1,matrizAristasOrdenada[2][i]+1,matrizAristasOrdenada[0][i]);
        }
    }
    printf("Iteraciones: %i",repKruskal);
    int acmPrim[3][n-1];
    for(int j = 0 ; j < n-1 ; j++){
        acmPrim[0][j]=-2;
        acmPrim[1][j]=-2;
        acmPrim[2][j]=-2;
    }
    prim(n,matrizValuada,acmPrim,matrizAristasPrimOrdenada);
    printf("\n\n");
    int costoprim=0;
    for(int o = 0; o < n-1 ; o++){
        costoprim += acmPrim[0][o];
    }
    printf("ACM Prim: (costo %i)\n",costoprim);
    for(int i = 0; i < n-1 ; i++){
        printf("(%i,%i) costo: %i",acmPrim[1][i]+1,acmPrim[2][i]+1,acmPrim[0][i]);
        printf("\n");
    }
    printf("Iteraciones: %i",repPrim);
    printf("\n\n");
    return 0;
}
