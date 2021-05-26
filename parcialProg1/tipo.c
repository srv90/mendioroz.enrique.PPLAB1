#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tipo.h"



/** \brief carga y copia la descripcion de un determinado tipo de moto
 *
 * \param idTipoMoto int
 * \param tiposMoto[] Tipo
 * \param tam int
 * \param descripcion[] char
 * \return int devuekve 1 si pudo hacerlo y 0 sino
 *
 */
int cargarTipoMoto(int idTipoMoto, Tipo tiposMoto[], int tam, char descripcion[])
{

    int retorno = 0;

    if(tiposMoto != NULL && tam > 0)
    {
        for (int i=0; i<tam ; i++ )
        {

            if(tiposMoto[i].id == idTipoMoto)
            {
                strcpy(descripcion, tiposMoto[i].descripcion);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;

}

/** \brief muestra un tipo de moto
 *
 * \param tipoMoto Tipo
 * \return void
 *
 */
void mostrarTipo(Tipo tipoMoto)
{


    printf("\n  %d     %-10s ", tipoMoto.id, tipoMoto.descripcion);

}


/** \brief muestra el listado de tipos de moto que existen
 *
 * \param tiposMoto[] Tipo
 * \param tam int
 * \return int devulve 1 si pudo recorrer el array sino 0
 *
 */
int listarTipos(Tipo tiposMoto[], int tam)
{

    int retorno = 0;
    if(tiposMoto != NULL && tam > 0)
    {
        printf("*******************LISTADO DE TIPOS DE MOTOS***************************");
        printf("\n\n   ID     TIPO");

        for (int i=0; i<tam ; i++ )
        {

            mostrarTipo(tiposMoto[i]);
            retorno = 1;

        }

    }
    printf("\n");

return retorno;
}



