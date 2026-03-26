#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


void secuencia(int a, int b);
int leerEntero();
int leerOpcion();

int main(){
 	int a,b,opc = 1;
 	while(opc == 1){
 		system("cls");
 		printf("\ningrese el primer numero: ");
	 	a = leerEntero();
	 	printf("\ningrese el segundo numero: ");
	 	b = leerEntero();
	 	if(a > b){
	 		printf("\nNo es posible mostrar esta lista ya que el primer numero es mayor al segundo");
		 }
		 else{
		 	printf("\nla secuencia es:\n");
	 		secuencia(a,b);
		 }
	 	printf("\n\ningrese una opcion:\n1. obtener otra lista\n2. salir\n");
	 	opc = leerOpcion();
	 }
 	system("pause");
 	return 0;
 }
 
void secuencia(int a, int b){
 	if(a == b)
 		printf("%d ",a);
 	else{
 		printf("%d ",a);
 		secuencia(a+1,b);
	 }		
 }

int leerOpcion() 
{
    char Aux[' '];
    int i, p, y, num;
    do
    {
        fflush(stdin);
        scanf(" %s", Aux); // se lee los datos introducidos
        fflush(stdin);
        y = strlen(Aux);

        for (i = 0; i < y; i++){
            if (isdigit(Aux[i])) /*Con una bandera valida que el caracter leido de una cadena sea un digito*/
                p = 1;
            else
                p = 0;
            if (p == 0){
                printf("\nError de lectura\nFavor de introducir un numero correcto: ");
                break;
            }
        }
        if (y == 0)
            p = 0;
    } while (p == 0);
    num = atoi(Aux); /*Regresa la conversion de la cadena introducida a un digito */
    if(num == 1 || num == 2) return num;
    else{
    	printf("\nINGRESA UNA OPCION VALIDA\n"); return leerOpcion();		//uso de recursion para validar que el numero este entre 1 y 2
	} 
}

int leerEntero(){
    char aux[50];
    int  p, y, num, i;

    do {
        fflush(stdin);
        scanf(" %s", aux);
        fflush(stdin);

        y = strlen(aux);
        p = 1;

        int inicio = 0;
        if (aux[0] == '-' && y > 1)
            inicio = 1;

        for (i = inicio; i < y; i++) {
            if (!isdigit(aux[i])) {
                p = 0;
                printf("\nEntrada invalida. Ingrese un numero entero: ");
                break;
            }
        }
        if (y == 0) p = 0;

    } while (p == 0);

    num = atoi(aux);
    return num;
}
