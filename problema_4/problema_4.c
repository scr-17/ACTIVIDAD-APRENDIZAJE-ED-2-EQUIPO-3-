#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
} NODO;

int leerEntero();
void agregarElemento(NODO **);
void eliminarElemento(NODO **);
void imprimirLista(NODO *);
void limpiarLista(NODO *);
int hallarMayor(NODO *, int);

int main()
{
    int op = 0;
    NODO *lista = NULL;

    do
    {
        system("cls");
        printf("1.Agregar elemento\n"
               "2.Eliminar ultimo elemento\n"
               "3.Imprimir lista\n"
               "4.Hallar mayor\n"
               "5.Salir\n\n"
               "Ingrese una opcion: ");
        op = leerEntero();
        switch (op)
        {
        case 1:
            agregarElemento(&lista);
            break;
        case 2:
            eliminarElemento(&lista);
            break;
        case 3:
            imprimirLista(lista);
            break;
        case 4:
            if (lista == NULL)
                printf("\nError, Lista Vacia\n");
            else
                printf("\nDato mayor: %d\n", hallarMayor(lista, lista->dato));
            system("pause");
            break;
        case 5:
            printf("\nSaliendo del programa...\n");
            getchar();
            break;
        default:
            printf("Error, opcion invalida.\n");
            system("pause");
            break;
        }
    } while (op != 5);

    limpiarLista(lista);
    return 0;
}

int leerEntero()
{
    char aux[50];
    int p, y, num, i;

    do
    {
        fflush(stdin);
        scanf(" %s", aux);
        fflush(stdin);

        y = strlen(aux);
        p = 1;

        int inicio = 0;
        if (aux[0] == '-' && y > 1)
            inicio = 1;

        for (i = inicio; i < y; i++)
        {
            if (!isdigit(aux[i]))
            {
                p = 0;
                printf("\nEntrada invalida. Ingrese un numero entero: ");
                break;
            }
        }
        if (y == 0)
            p = 0;

    } while (p == 0);

    num = atoi(aux);
    return num;
}

void agregarElemento(NODO **lista)
{
    NODO *nuevo = malloc(sizeof(NODO));

    if (nuevo == NULL)
    {
        printf("Error de alocacion de memoria\n");
        system("pause");
        return;
    }

    printf("Ingrese un entero: ");
    nuevo->dato = leerEntero();
    nuevo->siguiente = *lista;
    *lista = nuevo;
    printf("\nNueva Lista:\n\n");
    imprimirLista(*lista);
    return;
}

void eliminarElemento(NODO **lista)
{
    if (*lista == NULL)
    {
        printf("\nNueva Lista:\n\n");
        imprimirLista(*lista);
        return;
    }

    NODO *temp = *lista;
    *lista = (*lista)->siguiente;
    free(temp);
    printf("\nNueva Lista:\n\n");
    imprimirLista(*lista);
    return;
}

void imprimirLista(NODO *lista)
{
    if (lista == NULL)
    {
        printf("La lista esta vacia.\n");
        system("pause");
        return;
    }

    NODO *actual = lista;
    while (actual != NULL)
    {
        printf(" %d ->", actual->dato);
        actual = actual->siguiente;
    }
    printf(" NULL\n\n");
    system("pause");
    return;
}

void limpiarLista(NODO *lista)
{
    NODO *temp;
    while (lista != NULL)
    {
        temp = lista;
        lista = lista->siguiente;
        free(temp);
    }
}

int hallarMayor(NODO *nodo, int mayor)
{
    if (nodo == NULL)
        return mayor;

    if (nodo->dato > mayor)
        mayor = nodo->dato;

    return hallarMayor(nodo->siguiente, mayor);
}