#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define CANT 3
#define VACIO 0
#define OCUPADO 1

int main()
{
    char seguir='s';
    int opcion=0, i;
    EMovie inicio[CANT], movie;

    for(i = 0; i<CANT; i++)
    {
        inicio[i].estado=VACIO;
    }

    open(inicio);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        lectura(inicio);

        switch(opcion)
        {
        case 1:
            cargarPelicula(inicio);
            break;
        case 2:
            eliminarPelicula(inicio);
            break;
        case 3:
            crearPagina(inicio);
            break;
        case 4:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
