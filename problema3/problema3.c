#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int contarDigitos(int);

int leerEnteros(int, int);

int obtenerInverso(int);

int main()
{
    int op = 2;
    unsigned int n;
    do
    {
        system("cls");
        printf("\t\tINVERTIR NUMERO\n\n");
        printf("Ingrese un numero a invertir: ");
        /*Leemos el numero a invertir considerando como limites el 0 y el tamaño mayor de un entero sin signo de 32 bits */
        n = leerEnteros(0, 429967295);
        printf("\n\nEl numero invertido es: %d", obtenerInverso(n));
        printf("\n\nDesea invertir otro numero?\n1 - Si\n2 - No\n> ");
        op = leerEnteros(1, 2);
    } while (op != 2);
    printf("\n\nTerminando programa\n\n");
    system("pause");
    return 0;
}

int contarDigitos(int n)
{
    int cuenta = 0;
    if (n == 0) return 1;
    while (n != 0)
    {
        n = n / 10;
        cuenta++;
    }
    return cuenta;
}

int obtenerInverso(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        return (n % 10 * pow(10, contarDigitos(n) - 1)) + (obtenerInverso(n / 10));
    }
}

int leerEnteros(int limite_inferior, int limite_superior)
{
    char aux[' '];
    int bandera, longitud, i, temp;

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
                printf("\n\nError validando el dato, favor de ingresarlo de nuevo: ");
                break;
            }

            temp = atoi(aux);
            if (limite_inferior != limite_superior)
            {
                if (temp < limite_inferior || temp > limite_superior)
                {
                    bandera = 0;
                    printf("\n\nError, valor fuera de rango, favor de ingresarlo de nuevo: ");
                    break;
                }
            }
        }

        if (longitud == 1)
        {
            printf("\n\nError, cadena vacia, favor de ingresar una cadena valida: ");
            bandera = 0;
        }

    } while (bandera == 0);

    return temp;
}