#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moto.h"
#include "validaciones.h"
#include "menus.h"



/** \brief da de alta una moto y habilita las otras opciones mediante un flag
 *
 * \param [] Moto lista
 * \param tam int
 * \param idMoto int* recibe un puntero del id y lo incrementa en 1
 * \param flagAltaMoto int*
 * \return int devuelve 1 si pudo hacer el alta, sino 0
 *
 */
int altaMoto(Moto lista [], int tam, int* idMoto, int* flagAltaMoto, Cliente clientes[], int tamClientes)
{

    int retorno = 0;
    Moto auxMoto;
    char marca[20];

    if(lista != NULL && tam > 0)
    {
        if(buscarLibre(lista, tam) != -1)
        {
            system("cls");
            printf("\t\t\t Alta moto\n");

            validarMarca(marca);

            validarTipoMoto(&auxMoto.idTipo);

            validarColor(&auxMoto.idColor);

            validarCilindrada(&auxMoto.cilindrada);

            validarIdCliente(clientes,tamClientes,&auxMoto.idCliente);

            strcpy(auxMoto.marca, marca);
            auxMoto.id = *idMoto;
            (*idMoto)++;
            auxMoto.isEmpty = 0;
            lista[buscarLibre(lista, tam)] = auxMoto;
            printf("Alta exitosa.\n");
            *flagAltaMoto = 1;

            retorno = 1;
        }
        else
        {
            printf("No hay lugar disponible.");
        }
    }
    return retorno;

}

/** \brief modifica una moto
 *
 * \param lista[] Moto
 * \param tam int
 * \param colores[] Color
 * \param tamColores int
 * \param [] Tipo tiposMoto
 * \param tamTipos int
 * \return int devuelve 1 si pudo hacer la modificacion, sino 0
 *
 */
int modificarMoto(Moto lista[], int tam, Color colores[], int tamColores,Tipo tiposMoto [], int tamTipos, Cliente clientes[], int tamClientes)
{


    int retorno = 0;
    int idMoto;
    int indiceMoto;
    char respuesta;
    char color[25];
    Moto moto;


    if(lista != NULL && tam > 0)
    {

        system("cls");

        mostrarMotos(lista, tam, tiposMoto, tamTipos, colores, tamColores, clientes, tamClientes);
        validarIdMoto(&idMoto, &indiceMoto,lista,tam);

        system("cls");
        printf("La moto que quieres modicar es: ");
        mostrarMoto(lista[indiceMoto], tiposMoto, tamTipos, colores, tamColores, clientes, tamClientes);
        moto = lista[indiceMoto];


        do
        {
            printf("\nSeguro que deseas modificarla? Presiona s para Si o n para No  ");
            fflush(stdin);
            scanf("%c", &respuesta);
            if(respuesta == 's')
            {
                system("cls");
                cargarColor(moto.idColor, colores,tamColores, color);
                do
                {
                    switch (menuModificacion())
                    {
                    case 'a':
                        system("cls");
                        printf("Color actual: %s\n", color);
                        system("pause");
                        validarColor(&moto.idColor);
                        lista[indiceMoto].idColor =  moto.idColor;
                        break;
                    case 'b':
                        system("cls");
                        printf("Cilindrada actual: %d\n", moto.cilindrada);
                        system("pause");
                        validarCilindrada(&moto.cilindrada);
                        lista[indiceMoto].cilindrada =  moto.cilindrada;
                        break;
                    case 'c':
                    {

                        printf("\nSeguro que deseas salir? s/n \n");
                        fflush(stdin);
                        respuesta = getchar();
                        while (respuesta != 's' && respuesta != 'n' )
                        {
                            printf("Ingresa s o n \n");
                            fflush(stdin);
                            respuesta = getchar();
                        }
                    }
                    break;
                    }
                    system("pause");
                    system("cls");
                }
                while (respuesta != 's');
            }
            else if(respuesta == 'n')
            {
                printf("Se ha cancelado la modficacion.  ");
            }else{
                printf("Ingresa s o n");

            }
        }
        while (respuesta != 's' && respuesta != 'n');

        retorno = 1;
    }
    return retorno;

}

/** \brief busca un lugar libre en el array
 *
 * \param lista[] Moto
 * \param tam int
 * \return int devuelve el la posicion del lugar libre sino -1
 *
 */
int buscarLibre(Moto lista[], int tam)
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

/** \brief muestra la informacion de una moto
 *
 * \param moto Moto
 * \param [] Tipo tiposMoto
 * \param tam int
 * \param colores[] Color
 * \param tamColores int
 * \return void
 *
 */
void mostrarMoto(Moto moto, Tipo tiposMoto [], int tam, Color colores[], int tamColores, Cliente clientes[], int tamClientes)
{

    char descripcion [20];
    char color[20];
    char nombre[50];

    if(cargarTipoMoto(moto.idTipo,tiposMoto,tam, descripcion) && cargarColor(moto.idColor, colores,tamColores,color)
       && cargarNombreCliente(moto.idCliente, clientes,tamClientes, nombre))
    {

        printf("\n %-10s   %-10s  %-10s   %d           %d      %-10s",
               moto.marca, descripcion,color, moto.cilindrada, moto.id, nombre);

    }
}

/** \brief muestra la informacion de todas las motos
 *
 * \param lista[] Moto
 * \param tam int
 * \param [] Tipo tiposMoto
 * \param tamTipos int
 * \param colores[] Color
 * \param tamColores int
 * \return int devuelve 1 si pudo recorrer todos los arrays y 0 sino pudo hacerlo
 *
 */
int mostrarMotos(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores[], int tamColores, Cliente clientes[], int tamClientes)
{

    int retorno = 0;
    if(lista != NULL && tam > 0 && tiposMoto != NULL && tamTipos > 0 && colores != NULL && tamColores > 0 && clientes != NULL && tamClientes > 0 )
    {
        printf("*******************LISTADO DE MOTOS***************************");
        printf("\n\n MARCA         TIPO       COLOR      CILINDRADA      ID        CLIENTE");

        ordenarMotosPorTipoYId(lista, tam);

        for (int i=0; i<tam ; i++ )
        {
            if(!lista[i].isEmpty)
            {
                mostrarMoto(lista[i], tiposMoto, tamTipos, colores, tamColores, clientes, tamClientes);
                retorno = 1;

            }

        }
        printf("\n");

    }
    return retorno;
}


/** \brief da de baja una moto
 *
 * \param [] Moto lista
 * \param tam int
 * \param [] Tipo listaMotos
 * \param tamMotos int
 * \param [] Color colores
 * \param tamColores int
 * \return int devuelve 1 si pudo hacer la baja, sino 0
 *
 */
int bajaMoto(Moto lista [], int tam, Tipo listaMotos [], int tamMotos, Color colores [], int tamColores, Cliente clientes[], int tamClientes)
{

    int retorno = 0;
    int idMoto;
    int indiceMoto;
    char respuesta;

    if(lista != NULL && tam > 0)
    {

        system("cls");
        mostrarMotos(lista, tam, listaMotos, tamMotos, colores, tamColores, clientes, tamClientes);


        validarIdMoto(&idMoto, &indiceMoto, lista, tam);

        system("cls");
        printf("La moto que que quieres eliminar es: ");
        printf("\n\n MARCA         TIPO       COLOR      CILINDRADA      ID");


        mostrarMoto(lista[indiceMoto], listaMotos, tamMotos, colores, tamColores, clientes, tamClientes);

        do
        {

            printf("\nSeguro que deseas eliminarla? Presiona s para Si o n para No  ");
            fflush(stdin);
            scanf("%c", &respuesta);

            if(respuesta == 's')
            {
                lista[indiceMoto].isEmpty = 1;
                printf("Baja exitosa.\n");

            }
        }
        while (respuesta != 's' && respuesta != 'n');


        retorno = 1;
    }
    return retorno;
}
/** \brief ordena las motos por tipo y luego por id
 *
 * \param lista[] Moto
 * \param tam int
 * \return void
 *
 */
void ordenarMotosPorTipoYId(Moto lista[], int tam)
{
    Moto auxMoto;

    for (int i=0; i<tam-1 ; i++ )
    {
        if(!lista[i].isEmpty)
        {

            for (int j=i+1; j<tam ; j++ )
            {
                if( lista[i].idTipo > lista[j].idTipo || (lista[i].idTipo == lista[j].idTipo
                        && lista[i].id > lista[j].id))
                {
                    auxMoto= lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxMoto;
                }
            }

        }
    }
}

/** \brief busca una moto determinada en el array
 *
 * \param [] Moto lista
 * \param tam int
 * \param idMoto
 * \return int devuelve la posicion de la moto, sino -1
 *
 */
int buscarMoto(Moto lista [], int tam, int idMoto)
{

    int retorno = -1;

    for (int i=0; i<tam ; i++ )
    {
        if(lista[i].id == idMoto && !lista[i].isEmpty)
        {
            retorno = i;
        }

    }

    return retorno;

}
/** \brief libera todos los lugares del array
 *
 * \param lista[] Moto
 * \param tam int
 * \return void
 *
 */
void inicializarMotos(Moto lista[], int tam)
{

    for (int i=0; i<tam ; i++ )
    {
        lista[i].isEmpty = 1;
    }

}


