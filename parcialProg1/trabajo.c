#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "validaciones.h"


/** \brief da de alta un trabajo
 *
 * \param
 * \param
 * \return devuelve 1 si pudo hacerlo, sino 0
 *
 */
int altaTrabajo(Trabajo listaTrabajos[], int tamTrabajos, Servicio listaServicios[],
                int tamServicios, Moto listaMotos[], int tamMotos, Tipo tiposMoto [],
                int tamTipos, Color colores [], int tamColores, int*idTrabajo,Cliente clientes[], int tamClientes )
{

    Trabajo trabajoAux;
    int indiceTrabajo;
    int indiceMoto;


    int retorno = 0;
    if(listaTrabajos != NULL && listaServicios != NULL && listaMotos != NULL && tamMotos > 0
            && tamServicios > 0 && tamTrabajos > 0)
    {

        indiceTrabajo = buscarLibreTrabajo(listaTrabajos, tamTrabajos);
        if(indiceTrabajo != -1)
        {

            mostrarMotos(listaMotos, tamMotos, tiposMoto, tamTipos, colores, tamColores,clientes, tamClientes);
            validarIdMoto(&trabajoAux.idMoto, &indiceMoto,listaMotos,tamMotos);

            system("cls");
            listarServicios(listaServicios, tamServicios);

            validarServicio(listaServicios, tamServicios, &trabajoAux.idServicio);

            validarFecha(&trabajoAux.fechaAlta);

            trabajoAux.isEmpty = 0;
            trabajoAux.id = *idTrabajo;
            (*idTrabajo)++;
            listaTrabajos[indiceTrabajo] = trabajoAux;
            printf("Alta exitosa.\n");

            retorno = 1;

        }
        else
        {
            printf("No hay lugar disponible.\n");
        }
    }

    return retorno;

}

/** \brief busca la primer posicion libre del array de trabajos
 *
 * \param lista[] Trabajo
 * \param tam int
 * \return int devuelve la posicion libre sino -1
 *
 */
int buscarLibreTrabajo(Trabajo lista[], int tam)
{
    int retorno = -1;
    for (int i=0; i<tam ; i++ )
    {
        if(lista[i].isEmpty)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


/** \brief muestra la informacion de todos los trabajos
 *
 * \param
 * \param
 * \return devuelve 1 si pudo recorrer todos los arrays, sino 0
 *
 */
int listarTrabajos(Trabajo listaTrabajos[], int tamTrabajos, Servicio listaServicios[],
                   int tamServicios, Moto listaMotos[], int tamMotos, Tipo tiposMoto [],
                   int tamTipos, Color colores [], int tamColores)
{

    int retorno = 0;
    int flag = 0;

    if(listaTrabajos != NULL && listaServicios != NULL && listaMotos != NULL && tiposMoto != NULL && colores != NULL
            && tamMotos > 0 && tamTipos > 0 && tamServicios > 0 && tamTrabajos > 0 && tamColores >0)
    {
        printf("***********************LISTA DE TRABAJOS*****************************\n\n");
        printf("ID      ID MOTO     SERVICIO     FECHA         PRECIO");
        for (int i=0; i<tamTrabajos ; i++ )
        {

            if(!listaTrabajos[i].isEmpty)
            {
                mostrarTrabajo(listaTrabajos[i], listaServicios, tamServicios, listaMotos, tamMotos, tiposMoto,
                                tamTipos, colores,tamColores);
                                flag = 1;
                                retorno =1;
            }
        }
        if(!flag){
            printf("\nNo hay trabajos cargados.");
            retorno =1;

        }
        printf("\n");
    }
    return retorno;

}


/** \brief muestra la informacion de un trabajo
 *
 * \param
 * \param
 * \return void
 *
 */
void mostrarTrabajo(Trabajo trabajo, Servicio listaServicios[],
                    int tamServicios, Moto listaMotos[], int tamMotos, Tipo tiposMoto [],
                    int tamTipos, Color colores [], int tamColores)
{

    char servicio[25];
    float precio;


    if(cargarServicio(trabajo.idServicio, listaServicios, tamServicios, servicio, &precio))
    {

        printf("\n %d      %d        %-10s   %02d/%02d/%02d      %.2f", trabajo.id, trabajo.idMoto,
               servicio, trabajo.fechaAlta.dia, trabajo.fechaAlta.mes, trabajo.fechaAlta.anio, precio);

    }

}

/** \brief libera todos los lugares del array
 *
 * \param lista[] Trabajo
 * \param tam int
 * \return void
 *
 */
void inicializarTrabajos(Trabajo lista[], int tam)
    {

        for (int i=0; i<tam ; i++ )
        {
            lista[i].isEmpty = 1;
        }

    }


