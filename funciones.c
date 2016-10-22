#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#define CANT 3
#define VACIO 0
#define OCUPADO 1

/** \brief agrega una pelicula.
 *
 * \param int i
 * \return retorna la posicion como ocupada.
 *
 */

void cargarPelicula(EMovie inicio[])
{

    int i, aux;

    for(i=0; i<CANT; i++)
    {
        if(inicio[i].estado==VACIO)
        {
            printf("Ingrese titulo\n");
            fflush(stdin);
            gets(inicio[i].titulo);

            printf("Ingrese genero\n");
            fflush(stdin);
            gets(inicio[i].genero);

            printf("Ingrese duracion\n");
            fflush(stdin);
            scanf("%d",&inicio[i].duracion);

            printf("Ingrese descripcion\n");
            fflush(stdin);
            gets(inicio[i].descripcion);

            printf("Ingrese puntaje del 0 al 10\n");
            fflush(stdin);
            aux=scanf("%d",&inicio[i].puntaje);

            while(aux<0 || aux>10)
            {
                printf("Ingrese puntaje valido, del 0 al 10 ");
                fflush(stdin);
                aux=scanf("%d",&inicio[i].puntaje);
            }

            printf("Ingrese link imagen\n");
            fflush(stdin);
            gets(inicio[i].linkImagen);

            inicio[i].estado=OCUPADO;
        }
    }
}


/** \brief elimina de manera logica una pelicula
 *
 * \param int i, flag.
 * \param char tit.
 * \return VACIO.
 *
 */
void eliminarPelicula(EMovie inicio[])
{

    char tit;
    int i, flag=0;

    printf("Ingrese el titulo de la pelicula a borrar:\n");
    fflush(stdin);
    gets(tit);

    for(i=0; i<CANT; i++)
    {
         if((stricmp(inicio[i].titulo,tit)) == 0)
        {
            inicio[i].estado=VACIO;
        }
        else
        {
            printf("NO EXISTE LA PELICULA\n");
        }
        break;

    }
}

/** \brief lectura archivo
 *
 * \param cant, i
 * \param FILE *f
 * \return lectura
 *
 */


void lectura(EMovie inicio[])
{

FILE *f;
int cant;
int i=0;
if((f=fopen("d://bin.dat", "rb"))==NULL)
{
    printf("No se pudo abrir el archivo");
    exit(1);
}

while(!feof(f))
{
    cant=fread(&inicio[i], sizeof(inicio), CANT, f);
    i++;
    if(cant!=1)
    {
        if(feof(f))
            break;
        else
        {
            printf("No leyo el ultimo registro");
            break;
        }
    }
    i++;
}
fclose(f);
}


/** \brief crea html
 *
 * \param i
 * \param archivo
 * \return
 *
 */
void crearPagina(EMovie inicio[])
{

    FILE *archivo;
    int i;
    archivo=fopen("d://peliculas.html","wb");
    fprintf(archivo,"<html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head>");

    archivo=fopen("d://bin.dat", "w");

    fprintf(archivo,"</article></body></html>");

    fclose(archivo);

}


void open(EMovie inicio[])
{
    FILE *f;
    f=fopen("d://bin.dat","rb");
    int cant,i=0;
    while(!feof(f))
    {
        cant=fread((inicio),sizeof(EMovie),1,f);
        if(cant!=1)
        {
            if(feof(f))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
        i++;
    }
    fclose(f);
}
