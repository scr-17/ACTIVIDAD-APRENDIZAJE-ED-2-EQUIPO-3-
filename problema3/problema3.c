#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/*Funcion para leer un entero validado entre dos limites, si ambos son iguales solo valida que sea entero*/
int leerOpciones(int, int);

/*Funcion para leer una cadena que sea un numero valido*/
void leerNumero(char cadena[]);

/*Funcion para obtener el inverso de un número previamente validado*/
void obtenerInverso(char[], int);

int main()
{
    int op = 2; //Declaramos una variable para controlar el menu
    char n[' ']; //Declaramos una variable para almacenar el numero a invertir
    do
    {
        system("cls"); //Limpiamos consola
        printf("\t\tINVERTIR NUMERO\n\n");
        printf("Ingrese un numero a invertir: ");
        /*Leemos el numero a invertir considerando como limites el 0 y el tamaño mayor de un entero sin signo de 32 bits*/
        leerNumero(n);
        /*Imprimimos el numero invertido*/
        printf("\nEl numero invertido es: ");
        obtenerInverso(n, strcspn(n, "\0"));
        /*Preguntamos al usuario si desea realizar otra operacion y leemos ese valor*/
        printf("\n\nDesea invertir otro numero?\n1 - Si\n2 - No\n> ");
        op = leerOpciones(1, 2);
    } while (op != 2); //En caso que el usuario elija que no
    printf("\nTerminando programa\n\n");
    system("pause");
    return 0;
}

/*Funcion para imprimir de derecha a izquierda*/
void obtenerInverso(char n[], int i)
{
    /*Imprimimos el caracter i de la cadena, se inicia con el ultimo*/
    printf("%c", n[i]);
    if (i == 0)
    {
        return;
    }
    else
    {
        /*Volvemos a llamar a la funcion con un índice menor*/
        obtenerInverso(n, i - 1);
    }
}

/*Funcion para validar que una cadena sea un numero por medio de banderas*/
void leerNumero(char cadena[])
{
    char aux[' '];
    int bandera, longitud, i; 

    do
    {
        fflush(stdin);
        fgets(aux, ' ', stdin); //Leemos la cadena
        longitud = strlen(aux);
        fflush(stdin);
        /*En base a la longitud, checamos que sea digito o salto de linea*/
        for (i = 0; i < longitud; i++)
        {
            if (aux[i] == '\n')
                break;

            if (isdigit(aux[i])) //Si es un digito
            {
                bandera = 1;
            }
            else //Si no es un digito
                bandera = 0;

            /*En caso de que la condición principal se incumpla*/
            if (bandera == 0)
            {
                bandera = 0;
                printf("\nError validando el dato, favor de ingresarlo de nuevo: ");
                break;
            }
        }

        /*En caso de que la  longitud sea uno, osea, el unico caracter sea \n*/
        if (longitud == 1)
        {
            printf("\nError, cadena vacia, favor de ingresar una cadena valida: ");
            bandera = 0;
        }

    } while (bandera == 0);

    /*Eliminamos el salto de linea y lo reemplazamos por un caracter nulo y lo asignamos a la cadena*/
    aux[strcspn(aux, "\n")] = '\0';
    strcpy(cadena, aux);
}

/*Funcion para leer y devolver un entero ya validado, similar a la funcion de leerNumero*/
int leerOpciones(int limiteInferior, int limiteSuperior)
{
    char aux[' '];
    int bandera, longitud, i; 
    int temp;

    do
    {
        fflush(stdin);
        fgets(aux, ' ', stdin);
        longitud = strlen(aux);
        fflush(stdin);
        for (i = 0; i < longitud; i++)
        {
            if (aux[i] == '\n')
                break;

            /*Valida en caso de que sea negativo el numero, como en este programa no se utiliza, no es necesario*/
            if (isdigit(aux[i]) || aux[i] == '-')
            {
                bandera = 1;

                if (aux[i] == '-' && (i != 0 || longitud < 3))
                    bandera = 0;
            }
            else
                bandera = 0;

            if (bandera == 0)
            {
                bandera = 0;
                printf("\nError validando el dato, favor de ingresarlo de nuevo: ");
                break;
            }

            /*Convertimos la cadena a un entero*/
            temp = atoi(aux);
            /*Validamos si este entero esta dentro de los limites, previamente checando que estos no sean iguales*/
            if (limiteInferior != limiteSuperior)
            {
                if (temp < limiteInferior || temp > limiteSuperior)
                {
                    bandera = 0;
                    printf("\nError, valor fuera de rango, favor de ingresarlo de nuevo: ");
                    break;
                }
            }
        }

        if (longitud == 1)
        {
            printf("\nError, cadena vacia, favor de ingresar una cadena valida: ");
            bandera = 0;
        }

    } while (bandera == 0);

    return temp; //Regresa el entero
}