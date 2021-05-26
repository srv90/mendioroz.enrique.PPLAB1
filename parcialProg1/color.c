#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"





/** \brief carga el color del id de la moto
 *
 * \param idMoto int
 * \param colores[] Color
 * \param tam int
 * \param color[] char
 * \return int devuelve 1 si encontro el color, sino 0
 *
 */
int cargarColor(int idMoto, Color colores[], int tam, char color[])

{
    int retorno = 0;

    if(colores != NULL && tam >=0)
    {
        for (int i=0; i<tam ; i++ )
        {
            if(colores[i].id == idMoto)
            {
                strcpy(color, colores[i].nombreColor);
                break;
            }
        }
        retorno = 1;
    }
    return retorno;

}

/** \brief muestra el color
 *
 * \param color Color
 * \return void
 *
 */
void mostrarColor(Color color)
{


    printf("\n  %d     %-10s ", color.id, color.nombreColor);

}


/** \brief muestra el listado de colores
 *
 * \param colores[] Color
 * \param tam int
 * \return int  devuelve 1 si pudo recorrer el array y 0 sino pudo hacerlo
 *
 */
int listarColores(Color colores[], int tam)
{

    int retorno = 0;
    if(colores != NULL && tam > 0)
    {
        printf("*******************LISTADO DE COLORES***************************");
        printf("\n\n   ID     COLOR");

        for (int i=0; i<tam ; i++ )
        {

            mostrarColor(colores[i]);
            retorno = 1;

        }

    }
    printf("\n");

return retorno;
}





