#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"


/** \brief muestra un servicio
 *
 * \param servicio Servicio
 * \return void
 *
 */
void mostrarServicio(Servicio servicio)
{


    printf("\n  %d     %-10s    %.2f ", servicio.id, servicio.descripcion, servicio.precio);

}


/** \brief muestra la informacion de todos los servicios
 *
 * \param servicios[] Servicio
 * \param tam int
 * \return int devuelve 1 si pudo recorrer todos los arrays y 0 sino pudo hacerlo
 *
 */
int listarServicios(Servicio servicios[], int tam)
{

    int retorno = 0;
    if(servicios != NULL && tam > 0)
    {
        printf("*******************LISTADO DE SERVICIOS***************************");
        printf("\n\n   ID      SERVICIO      PRECIO");

        for (int i=0; i<tam ; i++ )
        {

            mostrarServicio(servicios[i]);
            retorno = 1;

        }

    }
    printf("\n");

    return retorno;
}

/** \brief carga y copia la descripcion y precio de un determinado servicio
 *
 * \param idServicio int
 * \param tiposServicios[] Servicio
 * \param tam int
 * \param servicio[] char
 * \param precio float*
 * \return int devuelve 1 si tuvo exito y 0 sino.
 *
 */
int cargarServicio(int idServicio, Servicio tiposServicios[], int tam, char servicio[], float* precio){

 int retorno = 0;

    if(tiposServicios != NULL && tam >=0)
    {
        for (int i=0; i<tam ; i++ )
        {
            if(tiposServicios[i].id == idServicio)
            {
                strcpy(servicio, tiposServicios[i].descripcion);
                *precio = tiposServicios[i].precio;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}

/** \brief busca un determinado servicio de acuerdo a su id
 *
 * \param [] Servicio tiposServicios
 * \param tam int
 * \param idServicio int
 * \return int devuelve la posicion del servicio o -1 sino pudo encontrarlo
 *
 */
int buscarServicio(Servicio tiposServicios [], int tam, int idServicio){

    int retorno = -1;

    for (int i=0; i<tam ; i++ )
    {
        if(tiposServicios[i].id == idServicio)
        {
            retorno = i;
        }

    }

    return retorno;

}
