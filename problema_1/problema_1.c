#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

int suma_digitos(int n);
int leerEntero();
int leerOpcion();

int main(){
    int numero, opc = 1, resultado, maximo = 0, resultado_maximo = -1;
    while(opc == 1){
        system("cls");
        printf("\nIngrese un numero entero positivo: ");
        numero = leerEntero();
        
        resultado = suma_digitos(numero);

        if (resultado > resultado_maximo){
            maximo = numero;
            resultado_maximo = resultado;
        }

        printf("\nSuma de digitos actual: %d", resultado);
        printf("\nEL NUMERO CON LA MAYOR SUMA HASTA AHORA ES: %d", maximo);
        printf("\nCON UNA SUMA DE: %d", resultado_maximo);

        printf("\n\nIngrese una opcion:\n1. Ingresar otro numero\n2. Salir\n");
        opc = leerOpcion();
    }
    system("pause");
    return 0;
}

int suma_digitos(int n){
    if (n < 10) return n;
    return (n % 10) + suma_digitos(n / 10);
}

int leerEntero(){
    char aux[51]; 
    int p, y, i;

    do {
        if (scanf("%50s", aux) < 1) { 
            while(getchar() != '\n'); 
            continue; 
        }
        while(getchar() != '\n'); 

        y = strlen(aux);
        p = 1;

        // 1. Validar que no sea una cadena vacía
        if (y == 0) { p = 0; continue; }

        // max 10 digitos
        if (y > 10) {
            printf("\nNumero demasiado grande. Intente con uno menor a 10 digitos: ");
            p = 0;
            continue;
        }

        for (i = 0; i < y; i++) {
            if (!isdigit(aux[i])) {
                p = 0;
                printf("\nEntrada invalida. Ingrese solo digitos: ");
                break;
            }
        }
        
        if (p == 1 && y == 10) {
            double prueba = atof(aux);
            if (prueba > 2147483647.0) {
                printf("\nEl numero excede el limite de un entero (2,147,483,647): ");
                p = 0;
            }
        }

    } while (p == 0);

    return atoi(aux);
}

int leerOpcion() {
    char Aux[32];
    int i, p, y, num;
    do {
        if (scanf(" %s", Aux) < 1) { while(getchar() != '\n'); continue; }
        while(getchar() != '\n'); 

        y = strlen(Aux);
        p = 1;

        for (i = 0; i < y; i++){
            if (!isdigit(Aux[i])) {
                p = 0;
                printf("\nError. Ingrese una opcion valida (1 o 2): ");
                break;
            }
        }
    } while (p == 0);

    num = atoi(Aux);
    if(num == 1 || num == 2) return num;
    else {
        printf("\nOPCION NO DISPONIBLE. Intente de nuevo.\n"); 
        return leerOpcion();
    } 
}