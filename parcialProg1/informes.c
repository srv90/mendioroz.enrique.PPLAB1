#include "informes.h"
#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"


/** \brief valida la opcion elegida por el usuario
 *
 * \param
 * \param
 * \return devuelve la opcion elegida por el usuario
 *
 */
void mostarMenuDeInformes(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [],
                          int tamColores, Cliente clientes[], int tamClientes, Servicio servicios[], int tamServicios, Trabajo trabajos[], int tamTrabajos)
{
    char respuesta;

    do
    {
        switch (menuInformes())
        {
        case 1:
            system("cls");
            if(!mostrarMotosPorColor(lista, tam, tiposMoto,tamTipos,colores,tamColores,clientes,tamClientes))
            {
                printf("Ocurrio un error");
            }
            break;
        case 2:
            system("cls");
            if(!mostrarMotosPorTipo(lista, tam, tiposMoto,tamTipos,colores,tamColores,clientes,tamClientes))
            {
                printf("Ocurrio un error");
            }
            break;
        case 3:
            system("cls");
            if(!mostrarMotosMayorCilindrada(lista, tam, tiposMoto,tamTipos,colores,tamColores,clientes,tamClientes))
            {
                printf("Ocurrio un error");
            }
            break;
        case 4:
            system("cls");
            if(!mostrarMotosSeparadasPorTipo(lista, tam, tiposMoto,tamTipos,colores,tamColores,clientes,tamClientes))
            {
                printf("Ocurrio un error");
            }
            break;
        case 5:
            system("cls");
            if(!mostrarMotosPorColoryTipo(lista, tam, tiposMoto,tamTipos,colores,tamColores,clientes,tamClientes))
            {
                printf("Ocurrio un error");
            }
            break;
        case 6:
            system("cls");
            if(!mostrarColoresMasElegidos(lista, tam, tiposMoto,tamTipos,colores,tamColores,clientes,tamClientes))
            {
                printf("Ocurrio un error");
            }
            break;
        case 7:
            system("cls");
            if(!mostrarTrabajosPorMoto(lista,tam,tiposMoto,tamTipos,colores,tamColores,clientes,tamClientes,servicios,tamServicios, trabajos, tamTrabajos))
            {
                printf("Ocurrio un error");
            }
            break;
        case 8:
            system("cls");
            if(!mostrarSumaImportesPorMoto(lista,tam,tiposMoto,tamTipos,colores,tamColores,clientes,tamClientes,servicios,tamServicios, trabajos, tamTrabajos))
            {
                printf("Ocurrio un error");
            }
            break;
        case 9:
            system("cls");
            if(!mostrarServiciosPorMotoYFecha(lista,tam,tiposMoto,tamTipos,colores,tamColores,clientes,tamClientes,servicios,tamServicios, trabajos, tamTrabajos))
            {
                printf("Ocurrio un error");
            }
            break;
        case 10:
            if(!mostrarServiciosPorFecha(lista,tam,tiposMoto,tamTipos,colores,tamColores,clientes,tamClientes,servicios,tamServicios, trabajos, tamTrabajos))
            {
                printf("Ocurrio un error");
            }
            system("cls");
            break;
        case 11:
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

/** \brief despliega el listado de motos del mismo color
 *
 * \param
 * \param
 * \return devuelve 1 si pudo recorrer los arrays y 0 sino pudo hacerlo
 *
 */
int mostrarMotosPorColor(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [],
                         int tamColores, Cliente clientes[], int tamClientes)
{

    int retorno =0;
    int colorSeleccionado;
    int flag =0;
    if(lista != NULL && tam > 0 && tiposMoto != NULL && tamTipos > 0 && colores != NULL
            && tamColores > 0 && clientes != NULL && tamClientes > 0 )
    {

        listarColores(colores, tamColores);
        validarColor(&colorSeleccionado);
        system("cls");
        printf("*******************LISTADO DE MOTOS DEL MISMO COLOR***************************");
        printf("\n\n MARCA         TIPO       COLOR      CILINDRADA      ID        CLIENTE");
        for (int i=0; i<tam ; i++ )
        {
            if(lista[i].idColor == colorSeleccionado && !lista[i].isEmpty)
            {
                mostrarMoto(lista[i], tiposMoto, tamTipos, colores, tamColores, clientes, tamClientes);
                flag = 1;

            }
        }
        printf("\n");
        if(!flag)
        {
            printf("No hay motos de ese color.\n");
        }

        retorno = 1;


    }


    return retorno;


}

/** \brief despliega las motos de un solo tipo elegido por el usuario
 *
 * \param lista[] Moto
 * \param tam int
 * \param [] Tipo tiposMoto
 * \param tamTipos int
 * \param [] Color colores
 * \param tamColores int
 * \param clientes[] Cliente
 * \param tamClientes int
 * \return devuelve 1 si pudo recorrer los arrays y 0 sino pudo hacerlo
 *
 */
int mostrarMotosPorTipo(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes)
{

    int retorno =0;
    int tipoSeleccionado;
    int flag = 0;

    if(lista != NULL && tam > 0 && tiposMoto != NULL && tamTipos > 0 && colores != NULL
            && tamColores > 0 && clientes != NULL && tamClientes > 0 )
    {

        listarTipos(tiposMoto, tamTipos);
        validarTipoMoto(&tipoSeleccionado);
        system("cls");
        printf("*******************LISTADO DE MOTOS DEL MISMO TIPO***************************");
        printf("\n\n MARCA         TIPO       COLOR      CILINDRADA      ID        CLIENTE");
        for (int i=0; i<tam ; i++ )
        {
            if(lista[i].idTipo == tipoSeleccionado && !lista[i].isEmpty)
            {
                mostrarMoto(lista[i], tiposMoto, tamTipos, colores, tamColores, clientes, tamClientes);
                flag = 1;

            }
        }
        if(!flag)
        {
            printf("\nNo hay motos de ese tipo.");
        }
        printf("\n");
        retorno = 1;
    }
    return retorno;

}

/** \brief muestra la o las motos de mayor cilindrada
 *
 * \param lista[] Moto
 * \param tam int
 * \param [] Tipo tiposMoto
 * \param tamTipos int
 * \param [] Color colores
 * \param tamColores int
 * \param clientes[] Cliente
 * \param tamClientes int
 * \return devuelve 1 si pudo recorrer los arrays y 0 sino pudo hacerlo
 *
 */
int mostrarMotosMayorCilindrada(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes)
{

    int retorno =0;
    int cilindradaMayor;
    if(lista != NULL && tam > 0 && tiposMoto != NULL && tamTipos > 0 && colores != NULL
            && tamColores > 0 && clientes != NULL && tamClientes > 0 )
    {

        printf("*******************LISTADO DE MOTOS DE MAYOR CILINDRADA***************************");
        printf("\n\n MARCA         TIPO       COLOR      CILINDRADA      ID        CLIENTE");

        cilindradaMayor = lista[0].cilindrada;
        for (int i=0; i<tam ; i++ )
        {

            if(lista[i].cilindrada >= cilindradaMayor && !lista[i].isEmpty )
            {
                cilindradaMayor = lista[i].cilindrada;

            }
        }
        for (int i=0; i<tam ; i++ )
        {

            if(lista[i].cilindrada == cilindradaMayor &&!lista[i].isEmpty )
            {
                mostrarMoto(lista[i], tiposMoto, tamTipos, colores, tamColores, clientes, tamClientes);
            }
        }

        printf("\n");
        retorno = 1;
    }
    return retorno;

}
/** \brief muestra las motos separadas por tipo
 *
 * \param lista[] Moto
 * \param tam int
 * \param [] Tipo tiposMoto
 * \param tamTipos int
 * \param [] Color colores
 * \param tamColores int
 * \param clientes[] Cliente
 * \param tamClientes int
 * \return devuelve 1 si pudo recorrer los arrays y 0 sino pudo hacerlo
 *
 */
int mostrarMotosSeparadasPorTipo(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes)
{
    int retorno =0;
    int flag;
    if(lista != NULL && tam > 0 && tiposMoto != NULL && tamTipos > 0 && colores != NULL
            && tamColores > 0 && clientes != NULL && tamClientes > 0 )
    {

        printf("*******************LISTADO DE MOTOS POR TIPO***************************");
        printf("\n\n MARCA         TIPO       COLOR      CILINDRADA      ID        CLIENTE");

        for (int i=0; i<tamTipos ; i++ )
        {
            flag = 0;
            for (int j=0; j<tam ; j++ )
            {
                if(tiposMoto[i].id == lista[j].idTipo && !lista[j].isEmpty)
                {
                    mostrarMoto(lista[j],tiposMoto, tamTipos, colores,tamColores,clientes,tamClientes);
                    flag = 1;
                }
            }
            if(!flag)
            {
                printf("No hay motos de el tipo: %s.\n", tiposMoto[i].descripcion);

            }
            printf("\n ------------------------------\n");

        }

        printf("\n");
        retorno = 1;
    }
    return retorno;
}

/** \brief muestra las motos de un solo color y tipo elegidos por el usuario
 *
 * \param lista[] Moto
 * \param tam int
 * \param [] Tipo tiposMoto
 * \param tamTipos int
 * \param [] Color colores
 * \param tamColores int
 * \param clientes[] Cliente
 * \param tamClientes int
 * \return devuelve 1 si pudo recorrer los arrays y 0 sino pudo hacerlo
 *
 */
int mostrarMotosPorColoryTipo(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes)
{


    int retorno =0;
    int color;
    int tipo;
    Moto motoAux [tam];
    int total =0;
    int flag = 0;
    if(lista != NULL && tam > 0 && tiposMoto != NULL && tamTipos > 0 && colores != NULL
            && tamColores > 0 && clientes != NULL && tamClientes > 0 )
    {

        printf("*******************LISTADO DE MOTOS POR COLOR Y TIPO***************************");
        printf("\n\n MARCA         TIPO       COLOR      CILINDRADA      ID        CLIENTE");

        validarColor(&color);
        validarTipoMoto(&tipo);


        for (int i=0; i<tam ; i++ )
        {
            if(!lista[i].isEmpty)
            {
                if(lista[i].idColor == color && lista[i].idTipo == tipo )
                {
                    motoAux[i] = lista[i];
                    total++;
                    flag = 1;
                }
            }
        }
        system("cls");
        if(flag && total == 1)
        {
            printf(" El total de motos es %d y es:\n", total);
            for (int i=0; i<tam ; i++ )
            {
                mostrarMoto(motoAux[i], tiposMoto, tamTipos, colores, tamColores, clientes, tamClientes);

            }
        }
        else if(flag && total > 1)
        {
            for (int i=0; i<tam ; i++ )
            {
                mostrarMoto(motoAux[i], tiposMoto, tamTipos, colores, tamColores, clientes, tamClientes);

            }
        }
        else
        {
            printf("No hay motos de este tipo.");
        }
        printf("\n");
        retorno = 1;
    }
    return retorno;
}

/** \brief muestra el o los colores mas elegidos
 *
 * \param lista[] Moto
 * \param tam int
 * \param [] Tipo tiposMoto
 * \param tamTipos int
 * \param [] Color colores
 * \param tamColores int
 * \param clientes[] Cliente
 * \param tamClientes int
 * \return devuelve 1 si pudo recorrer los arrays y 0 sino pudo hacerlo
 *
 */
int mostrarColoresMasElegidos(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes)
{

    int retorno =0;
    int totalPorColor;
    int colorMasElegido;
    int auxColores [tamColores];
    if(lista != NULL && tam > 0 && tiposMoto != NULL && tamTipos > 0 && colores != NULL
            && tamColores > 0 && clientes != NULL && tamClientes > 0 )
    {

        for (int i=0; i<tamColores ; i++ )
        {
            totalPorColor = 0;

            for (int j=0; j<tam ; j++ )
            {
                if(colores[i].id == lista[j].idColor && !lista[j].isEmpty)
                {
                    totalPorColor++;
                }
            }
            auxColores[i] = totalPorColor;

        }
        system("cls");
        colorMasElegido = auxColores[0];
        for (int i=0; i<tamColores ; i++ )
        {
            if(auxColores[i] > colorMasElegido)
            {
                colorMasElegido = auxColores[i];
            }
        }

        for (int i=0; i<tamColores ; i++ )
        {

            if(auxColores[i] == colorMasElegido)
            {
                printf("El color  mas elegido es el: %s", colores[i].nombreColor);
                printf(" con %d unidad/es\n", colorMasElegido);
            }
        }
        printf("\n");
        retorno = 1;
    }
    return retorno;
}

/** \brief  muestra el listado de trabajos en una sola moto elegida por el usuario
 *
 * \param lista[] Moto
 * \param tam int
 * \param [] Tipo tiposMoto
 * \param tamTipos int
 * \param [] Color colores
 * \param tamColores int
 * \param clientes[] Cliente
 * \param tamClientes int
 * \param servicios[] Servicio
 * \param tamServicios int
 * \param listaTrabajos[] Trabajo
 * \param tamTrabajos int
 * \return devuelve 1 si pudo recorrer los arrays y 0 sino pudo hacerlo
 *
 */
int mostrarTrabajosPorMoto(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes, Servicio servicios[], int tamServicios, Trabajo listaTrabajos[], int tamTrabajos)
{
    int retorno =0;
    int idMoto;
    int indiceMoto;
    int flag = 0;

    if(lista != NULL && tam > 0 && tiposMoto != NULL && tamTipos > 0 && colores != NULL
            && servicios != NULL && tamServicios > 0 && listaTrabajos != NULL && tamTrabajos > 0
            && tamColores > 0 && clientes != NULL && tamClientes > 0 )
    {

        mostrarMotos(lista, tam,tiposMoto,tamTipos,colores,tamColores,clientes,tamClientes);
        validarIdMoto(&idMoto, &indiceMoto, lista,tam);
        system("cls");

        printf("*******************LISTADO DE TRABAJOS POR MOTO***************************");
        printf("\nID      ID MOTO     SERVICIO     FECHA         PRECIO");

        for (int i=0; i<tamTrabajos ; i++ )
        {
            if(!listaTrabajos[i].isEmpty)
            {
                if(listaTrabajos[i].idMoto == idMoto )
                {
                    mostrarTrabajo(listaTrabajos[i],servicios,tamServicios,lista, tam,tiposMoto,tamTipos,colores,tamColores);
                    flag = 1;
                }
            }
        }
        if(!flag)
        {

            printf("\nEsta moto no tiene trabajos realizados.");
        }
        printf("\n");
        retorno = 1;
    }
    return retorno;
}


/** \brief muestra la suma de los servicios realizados a una moto elegida por el usuario
 *
 * \param lista[] Moto
 * \param tam int
 * \param [] Tipo tiposMoto
 * \param tamTipos int
 * \param [] Color colores
 * \param tamColores int
 * \param clientes[] Cliente
 * \param tamClientes int
 * \param servicios[] Servicio
 * \param tamServicios int
 * \param listaTrabajos[] Trabajo
 * \param tamTrabajos int
 * \return devuelve 1 si pudo recorrer los arrays y 0 sino pudo hacerlo
 *
 */
int mostrarSumaImportesPorMoto(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes, Servicio servicios[], int tamServicios, Trabajo listaTrabajos[], int tamTrabajos)
{

    int retorno =0;
    int idMoto;
    int indiceMoto;
    float total =0;
    int flag = 0;

    if(lista != NULL && tam > 0 && tiposMoto != NULL && tamTipos > 0 && colores != NULL
            && servicios != NULL && tamServicios > 0 && listaTrabajos != NULL && tamTrabajos > 0
            && tamColores > 0 && clientes != NULL && tamClientes > 0 )
    {

        mostrarMotos(lista, tam,tiposMoto,tamTipos,colores,tamColores,clientes,tamClientes);
        validarIdMoto(&idMoto, &indiceMoto, lista,tam);
        system("cls");

        printf("*******************IMPORTE TOTAL POR REPARACIONES***************************");


        for (int i=0; i<tamTrabajos ; i++ )
        {
            if(listaTrabajos[i].idMoto == idMoto && !listaTrabajos[i].isEmpty )
            {
                for (int j=0; j<tamServicios ; j++ )
                {
                    if(listaTrabajos[i].idServicio == servicios[j].id)
                    {
                        total +=  servicios[j].precio;
                        flag = 1;
                    }
                }
            }
        }
        if(!flag)
        {

            printf("\nEsta moto no tiene trabajos realizados.");
        }
        else
        {
            printf("\nLa suma total de los servicios es de $ %.2f", total);

        }
        printf("\n");
        retorno = 1;
    }
    return retorno;



}

/** \brief muestra el listado de servicios realizados a una moto elegida por el usuario
 *
 * \param lista[] Moto
 * \param tam int
 * \param [] Tipo tiposMoto
 * \param tamTipos int
 * \param [] Color colores
 * \param tamColores int
 * \param clientes[] Cliente
 * \param tamClientes int
 * \param servicios[] Servicio
 * \param tamServicios int
 * \param listaTrabajos[] Trabajo
 * \param tamTrabajos int
 * \return devuelve 1 si pudo recorrer los arrays y 0 sino pudo hacerlo
 *
 */
int mostrarServiciosPorMotoYFecha(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes, Servicio servicios[], int tamServicios, Trabajo listaTrabajos[], int tamTrabajos)
{

    int retorno =0;
    int idServicio;
    int flag = 0;

    if(lista != NULL && tam > 0 && tiposMoto != NULL && tamTipos > 0 && colores != NULL
            && servicios != NULL && tamServicios > 0 && listaTrabajos != NULL && tamTrabajos > 0
            && tamColores > 0 && clientes != NULL && tamClientes > 0 )
    {

        listarServicios(servicios, tamServicios);
        validarServicio(servicios, tamServicios, &idServicio);
        system("cls");

        printf("*******************LISTADO DE MOTOS POR SERVICIO ***************************");
        printf("\nID      ID MOTO     SERVICIO     FECHA         PRECIO");


        for (int i=0; i<tamTrabajos ; i++ )
        {
            if(listaTrabajos[i].idServicio == idServicio && !listaTrabajos[i].isEmpty)
            {
                mostrarTrabajo(listaTrabajos[i], servicios,tamServicios,lista,tam,tiposMoto,tamTipos,colores, tamColores);
                flag = 1;
            }
        }
        if(!flag)
        {

            printf("\nEste servicio no cuenta con trabajos realizados.");
        }
        printf("\n");
        retorno = 1;
    }
    return retorno;


}

/** \brief muestra el listado de servicios realizados a una moto en una determinada fecha elegida por el usuario
 *
 * \param lista[] Moto
 * \param tam int
 * \param [] Tipo tiposMoto
 * \param tamTipos int
 * \param [] Color colores
 * \param tamColores int
 * \param clientes[] Cliente
 * \param tamClientes int
 * \param servicios[] Servicio
 * \param tamServicios int
 * \param listaTrabajos[] Trabajo
 * \param tamTrabajos int
 * \return int
 *
 */
int mostrarServiciosPorFecha(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes, Servicio servicios[], int tamServicios, Trabajo listaTrabajos[], int tamTrabajos)
{

    int retorno =0;
    int flag = 0;
    Fecha auxFecha;

    if(lista != NULL && tam > 0 && tiposMoto != NULL && tamTipos > 0 && colores != NULL
            && servicios != NULL && tamServicios > 0 && listaTrabajos != NULL && tamTrabajos > 0
            && tamColores > 0 && clientes != NULL && tamClientes > 0 )
    {
        validarFecha(&auxFecha);

        system("cls");

        printf("*******************LISTADO DE SERVICIOS POR FECHA ***************************");
        printf("\nID      ID MOTO     SERVICIO     FECHA         PRECIO");


        for (int i=0; i<tamTrabajos ; i++ )
        {
            if(listaTrabajos[i].fechaAlta.anio == auxFecha.anio && listaTrabajos[i].fechaAlta.mes== auxFecha.mes
                    && listaTrabajos[i].fechaAlta.dia == auxFecha.dia && !listaTrabajos[i].isEmpty)
            {
                mostrarTrabajo(listaTrabajos[i], servicios,tamServicios,lista,tam,tiposMoto,tamTipos,colores, tamColores);
                flag = 1;
            }
        }
        if(!flag)
        {

            printf("\nNo hay servicios realizados en esta fecha.");
        }
        printf("\n");
        system("pause");

        retorno = 1;
    }
    return retorno;




}
