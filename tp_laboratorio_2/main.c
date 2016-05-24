#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define MAX_INTENTOS 4
int main()
{
    char seguir='s';
    int contador_intentos = 0;
    int opcion=0;
    EPersona personas[MAX_PERSONAS];
    inicializarArray(&personas);

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                 system("cls");
                 agregarPersona(&personas);
                break;
            case 2:
                system("cls");
                eliminarPersona(&personas);
                break;
            case 3:
                system("cls");
                imprimirListaOrdenada(&personas);
                break;
            case 4:
                system("cls");
                imprimirGraficoEdades(&personas);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                if(contador_intentos == MAX_INTENTOS ){
                    seguir = 'n';
                }
                system("cls");
                printf("Ingrese una opcion valida.");
                contador_intentos++;
        }
    }

    return 0;
}
