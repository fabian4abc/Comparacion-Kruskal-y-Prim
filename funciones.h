#define infinito 99999999
int nvisitas = 0;
int nAristas1 = 0;
int nAristas = 0;
int repKruskal;
int repPrim;

void leerGrafo (char nombreArchivo[100000], int n, int matrizValuada[n][n]){
    FILE *archivo;
    int i = 0, dato, j = 0;

    if (fopen(nombreArchivo, "r") != NULL){
        archivo = fopen(nombreArchivo, "r");
    }else{
        printf("El archivo no existe!... el programa se va a cerrar");
        exit(1);
    }
    fscanf(archivo,"%i", &dato);
    while(i<n){
        j=0;
        while(j<n){
            fscanf(archivo,"%i", &dato);
            matrizValuada[i][j] = dato;
            j++;
        }
        i++;
    }
}

void aristasValidas(int n, int matrizValuada[n][n]){
    int i = 0,j = 0;
    while (i < n){
        j = 0;
        while (j < n){
            if (matrizValuada[i][j] != 0){
                nAristas++;
            }
            j++;
        }
        i++;
    }
    nAristas = nAristas/2;
}
void aristasValidas1(int n, int matrizGenerada[n][n]){
    nAristas1 = 0;
    int i = 0,j = 0;
    while (i < n){
        j = 0;
        while (j < n){
            if (matrizGenerada[i][j] != 0){
                nAristas1++;repPrim++;
            }
            j++;
        }
        i++;
    }
    nAristas1 = nAristas1/2;
}
void crearMatrizAristas (int n, int matrizValuada[n][n], int matrizAristas[4][nAristas]){
    int i = 0, j = 0, k = 0;
    while (i < n - 1){
        j = i + 1;
        while (j < n){
            if(matrizValuada[i][j] != 0){
                matrizAristas[0][k] = matrizValuada [i][j];
                matrizAristas[1][k] = i;
                matrizAristas[2][k] = j;
                matrizAristas[3][k] = 0;//se asigna 0 ya que no ha sido visitado :c (como quisiera que me vistara ella)
                k++;
            }
            j++;
        }
        i++;
    }


}
void imprimirMatriz (int n, int matrizValuada[n][n]){
    int i = 0, j = 0;
    while(i<n){
        j=0;
        while(j<n){
            printf(" %i ",matrizValuada[i][j]);
            j++;
        }
            printf("\n");
            i++;
    }

}

void imprimirMatrizAristas(int matrizAristas[4][nAristas]){
    int i = 0, j = 0;
    while(i < 4){
        j = 0;
        while(j < nAristas){
            printf(" %3i ",matrizAristas[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

}
void ordenasAristas(int matrizAristas[4][nAristas], int matrizAristasOrdenadas[4][nAristas]){
    int i = 0;
    int pos = -1;
    int valor;
    int j = 0;
    while(i < nAristas){
        j = 0;
        pos = -1;
        valor = infinito;

        while(j < nAristas){
            if(valor > matrizAristas[0][j] && matrizAristas[3][j] == 0){
                valor = matrizAristas[0][j];
                pos = j;//aqui agarro el menor valor
            }
            j++;
        }
        if(pos != -1){
            matrizAristasOrdenadas[0][i] = matrizAristas[0][pos];
            matrizAristasOrdenadas[1][i] = matrizAristas[1][pos];
            matrizAristasOrdenadas[2][i] = matrizAristas[2][pos];
            matrizAristasOrdenadas[3][i] = 0;
            matrizAristas[3][pos] = 1;
        }
        i++;
        matrizAristas[3][pos] = 1;
    }

}
void copiadorDeMatrices(int matrizAristas[4][nAristas], int matrizAristasOrdenadas[4][nAristas]){
    for(int i = 0 ; i < nAristas ; i++){
        matrizAristasOrdenadas[0][i] = matrizAristas[0][i];
        matrizAristasOrdenadas[1][i] = matrizAristas[1][i];
        matrizAristasOrdenadas[2][i] = matrizAristas[2][i];
        matrizAristasOrdenadas[3][i] = matrizAristas[3][i];
    }
}


int TamanoArchivo(char nombreArchivo[100000]){
    int dato;
    FILE *arch;
    if (fopen(nombreArchivo, "r") != NULL){
        arch = fopen(nombreArchivo, "r");
    }else{
        return 0;
    }
    fscanf(arch,"%d", &dato);
    fclose(arch);
    return dato;
}

void kruskal(int n, int matrizConjunto[n][n], int matrizAristasOrdenadas[4][nAristas]){
    repKruskal = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int p = 0;
    int numRep = 0;
    int posFila, posColum, posFilaOr, posColumOr;
    while(j < nAristas){//recorre la matriz de aristas por columnas
        posColum=-1;
        i = 0;
        while(i < n){//recorre la matriz de conjunto por sus filas
            l = 0;
            while(l < n){//recorre la matriz de conjunto por columnas
                if(matrizConjunto[i][l]==matrizAristasOrdenadas[1][j]){//se encuentra el numero de la columna donde esta el vertice 1
                    posColum = l;//posColum esta en la columna donde esta el vertice 1
                }
                repKruskal++;
                l++;
            }
            i++;
        }
        i = 0;
        while(i < n){//recorre la matriz de conjunto por sus filas
            l = 0;
            while(l < n){//recorre la matriz de conjunto por columnas
                if(matrizConjunto[i][l]==matrizAristasOrdenadas[2][j]){//se encuentra el numero de la columna donde esta el vertice 2
                    posColumOr = l;//posColumOr esta en la columna donde esta el vertice 2
                }
                repKruskal++;
                l++;
            }
            i++;
        }
        if(posColum != posColumOr){//si estaban el la misma columna, por ende si agrego esta arista formo un ciclo
            i = 0;
            while(i < n && matrizConjunto[i][posColum] != -2){
                posFila = i + 1;//queda justo en la posicion donde debo insertar
                i++;
                repKruskal++;
            }
            i = 0;
            while(i < n){
                if(matrizConjunto[i][posColumOr] != -2){
                    matrizConjunto[posFila][posColum] = matrizConjunto[i][posColumOr];
                    posFila++;
                }
                repKruskal++;
                i++;
            }
            i = 0;
            while(i < n){
                matrizConjunto[i][posColumOr]=-2;
                i++;
                repKruskal++;
            }
            matrizAristasOrdenadas[3][j] = 1;
        }
        j++;
    }
}


void prim(int n, int matrizAdyacencia[n][n], int acmPrim[3][n-1], int matrizAristasOrdenadasPrim[4][nAristas]){
    repPrim = 0;
    int matrizVertices[2][n];
    int ArregloN[n];
    int estaU = 0, estaV = 0;
    int i = 0, j = 0;
    for (int i = 0 ; i < n ; i++){//este es el conjunto V y la matrizdearistas es es A
        matrizVertices[0][i] = i;
        matrizVertices[1][i] = 0;
        ArregloN[i] = -2;
        repPrim++;
    }
    ArregloN[0] = 0;

    while(i < n-1){//recorre la matriz de acm
        j = 0;
        while(j < nAristas){//recorre la matriz de aristas
            estaU = estaEnN(n,ArregloN,matrizAristasOrdenadasPrim[1][j]);
            estaV = estaEnN(n,ArregloN,matrizAristasOrdenadasPrim[2][j]);
            repPrim++;
            if(estaU ^ estaV && matrizAristasOrdenadasPrim[3][j] == 0){
                for(int k = 0 ; k < n ; k++){//se agrega el vertice nuevo a N
                    repPrim++;
                    if(ArregloN[k] == -2){//encontre la posicion de insercion
                        if(estaU == 1){
                            ArregloN[k] = matrizAristasOrdenadasPrim[2][j];
                        }else if(estaV == 1){
                            ArregloN[k] = matrizAristasOrdenadasPrim[1][j];
                        }
                        break;
                    }
                }
                for(int k = 0 ; k < n-1 ; k++){//agrego la arista al acm
                    repPrim++;
                    if(acmPrim[0][k]== - 2){
                        acmPrim[0][k] = matrizAristasOrdenadasPrim[0][j];
                        acmPrim[1][k] = matrizAristasOrdenadasPrim[1][j];
                        acmPrim[2][k] = matrizAristasOrdenadasPrim[2][j];
                        break;
                    }
                }
                matrizAristasOrdenadasPrim[3][j] = 1;//la use, la marco
                break;
            }
            j++;
        }
        i++;
    }
}

int estaEnN(int n, int arregloN[n], int vertice){
    for(int i = 0 ; i < n ; i++){
        if(arregloN[i]==vertice){
            return 1;//el vertice esta en N
        }
        repPrim++;
    }
    return 0;//el vertice no estaba en N
}

















