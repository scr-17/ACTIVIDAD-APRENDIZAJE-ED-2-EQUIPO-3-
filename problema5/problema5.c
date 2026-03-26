#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef int **matriz;   						//declara una matriz como un puntero a puntero

matriz nuevaMatriz(int n);						//funcion que crea una nueva matriz 
void liberarMatriz(matriz matriz, int n);		//funcion que libera la memoria de una matriz
matriz matrizMenor(matriz mat, int n, int col); //funcion que llena los valores de la matriz menor
int determinante(matriz mat, int n);			//funcion recursiva que calcula el determinante de una matriz
int leerEntero();

int main() {
    int n;
    printf("Ingrese la dimension de la matriz (NxN) de la matriz (ingrese el valor de N): "); 
    n = leerEntero();							//se pide el tamaño de la matriz nxn
    matriz mat = nuevaMatriz(n);				//se crea una nueva matriz 
	int i, j;
    printf("Ingrese los elementos:\n");
    for (i = 0; i < n; i++){					//se llena la matriz con valores enteros
        for (j = 0; j < n; j++){
        	mat[i][j] = leerEntero();
		}
	}
    printf("\nLA MATRIZ ES:\n");						//muestra la matriz
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++){
        	printf(" %d  ", mat[i][j]);
		}
        printf("\n");
    }
    int det = determinante(mat, n);				//calcula e imprime el determinante
    printf("\nDeterminante = %d\n", det);
    liberarMatriz(mat, n);
    return 0;
}

matriz nuevaMatriz(int n){
	int i;
    matriz nueva = malloc(n * sizeof(int *));	//crea una matriz, es decir un puntero que apunta a otros punteros
    for (i = 0; i < n; i++) {
        nueva[i] = malloc(n * sizeof(int));
    }
    return nueva;
}

void liberarMatriz(matriz matriz, int n) {
	int i;
    for ( i = 0; i < n; i++) {					//libera la memoria de cada apuntador y de la matriz
        free(matriz[i]);
    }
    free(matriz);
}

matriz matrizMenor(matriz mat, int n, int col) {
    matriz menor = nuevaMatriz(n - 1);
    int menorFila , menorColumna, i;						
	int j;
    for (i = 1, menorFila = 0; i < n; i++, menorFila++) { 	//se llena la matriz menor con los valores de la matriz original excluyendo los de la fila y columna
        menorColumna = 0;
        for (j = 0; j < n; j++) {			
            if (!(j == col)){					
            	menor[menorFila][menorColumna] = mat[i][j];
            	menorColumna++;
			}
        }
    }
    return menor;
}

int determinante(matriz mat, int n) {
    if (n == 1)
        return mat[0][0];
    int det = 0;
	int i = 0, j = 0, signo;
    for (j = 0; j < n; j++) {
		if((j + i) % 2 == 0) signo = 1;
		else signo = -1;											//se recorre cada elemento de la primera fila de la matriz
        matriz menor = matrizMenor(mat, n, j);							
        det = det + signo * mat[0][j] * determinante(menor, n - 1);		//se calcula el determinante usando recursividad					
        liberarMatriz(menor, n - 1);									//se libera cada matriz luego de haber hecho el calculo recursivo												//se calcula el siguiente valor del signo
    }
    return det;
}

int leerEntero(){
    char aux[50];
    int p, y, num, i;
    do{
        fflush(stdin);
        scanf(" %s", aux);
        fflush(stdin);
        y = strlen(aux);
        p = 1;
        int inicio = 0;
        if (aux[0] == '-' && y > 1)
            inicio = 1;
        for (i = inicio; i < y; i++){
            if (!isdigit(aux[i])){
                p = 0;
                printf("\nEntrada invalida. Ingrese un numero entero: ");
                break;
            }
        }
        if (y == 0)
            p = 0;
    }while (p == 0);
    num = atoi(aux);
    return num;
}
