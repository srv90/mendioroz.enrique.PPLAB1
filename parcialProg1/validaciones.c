#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"


/** \brief valida que la cadena ingresada sean solos numeros
 *
 * \param numero char*
 * \return int devuelve 1 si solo habia numeros sino 0
 *
 */
int validarNumeroEntero(char* numero)
{

    int retorno = 1;

    for (int i=0; numero[i]!= '\0' ; i++ )
    {
        if(numero[i] < '0' || numero[i] > '9')
        {
            retorno = 0;
            break;
        }
    }

    return retorno;

}
/** \brief valida si un servicio existe o no de acuerdo a su id
 *
 * \param tiposServicios[] Servicio
 * \param tam int
 * \param idServicio int*
 * \return void
 *
 */
void validarServicio(Servicio tiposServicios[], int tam,int* idServicio)
{

    char cadAux[20];
    int idAux;

    do
    {
        printf("Ingresa el id del servicio:  ");

        fflush(stdin);
        fgets(cadAux, sizeof(cadAux), stdin);
        cadAux[strcspn(cadAux, "\n")] = '\0';

        if(!validarNumeroEntero(cadAux))
        {
            printf("Solo puedes ingresar numeros.\n");
        }
        else
        {
            idAux =  atoi(cadAux);
            if(buscarServicio(tiposServicios, tam, idAux) == -1)
            {
                printf("Id inexistente.\n");
            }
            else
            {
                *idServicio = idAux;
            }
        }
    }
    while (!validarNumeroEntero(cadAux) || buscarServicio(tiposServicios, tam, idAux) == -1);

}

/** \brief valida que la fecha ingresada sea correcta
 *
 * \param fecha Fecha*
 * \return void
 *
 */
void validarFecha(Fecha* fecha)
{

    int diaAux;
    int mesAux;
    int anioAux;
    int cantidad;


    do
    {
        printf("Ingresa la fecha de ingreso en formato dd/MM/aaaa:   ");
        cantidad = scanf("%d/%d/%d",&diaAux,&mesAux,&anioAux);
        if(cantidad != 3)
        {
            printf("Solo puedes ingresar numeros.\n");
            fflush(stdin);
        }
        else
        {
            if(diaAux < 1 || diaAux > 31 )
            {
                printf("El dia es incorrecto. \n");
            }
            else if(mesAux < 1 || mesAux > 12)
            {
                printf("El mes es incorrecto. \n");
            }
            else if(anioAux > 2021)
            {
                printf("El año no puede ser posterior al actual. \n");
            }
        }
    }
    while (cantidad != 3 || diaAux < 1 || diaAux > 31 || mesAux < 1 || mesAux > 12 || anioAux > 2021);

    (*fecha).anio = anioAux;
    (*fecha).mes = mesAux;
    (*fecha).dia = diaAux;
}

/** \brief valida el tipo de moto de acuerdo a su id
 *
 * \param idTipo int*
 * \return void
 *
 */
void validarTipoMoto(int* idTipo)
{

    char cadAux[20];
    int idAux;
    system("cls");
    printf(" 1000 -Enduro\n 1001 -Chopera\n 1002 -Scooter\n 1003 -Ciclomotor\n");

    do
    {
        printf("Ingresa el numero del tipo de moto:  ");
        fflush(stdin);
        fgets(cadAux, sizeof(cadAux), stdin);
        cadAux[strcspn(cadAux, "\n")] = '\0';

        if(!validarNumeroEntero(cadAux))
        {
            printf("Solo puedes ingresar numeros.\n");

        }
        else
        {
            idAux =  atoi(cadAux);
            if(idAux < 1000 || idAux > 1003)
            {
                printf("Ingresa un id valido.\n");
            }
            else
            {
                *idTipo = idAux;
            }
        }
    }
    while (!validarNumeroEntero(cadAux) || idAux < 1000 || idAux > 1003);
}

/** \brief valida un color de acuerdo a su id
 *
 * \param idColor int*
 * \return void
 *
 */
void validarColor(int* idColor)
{

    char cadAux[20];
    int idAux;
    system("cls");
    printf(" 10000-  Gris\n 10001-  Negro\n 10002-  Blanco\n 10003-  Azul\n 10004-  Rojo\n");

    do
    {
        printf("Ingresa el numero del color que deseas:  ");

        fflush(stdin);
        fgets(cadAux, sizeof(cadAux), stdin);
        cadAux[strcspn(cadAux, "\n")] = '\0';

        if(!validarNumeroEntero(cadAux))
        {
            printf("Solo puedes ingresar numeros.\n");

        }
        else
        {
            idAux =  atoi(cadAux);
            if(idAux < 10000 || idAux > 10004)
            {
                printf("Ingresa un id valido.\n");
            }
            else
            {
                *idColor = idAux;
            }
        }
    }
    while (!validarNumeroEntero(cadAux) || idAux < 10000 || idAux > 10004);

}


/** \brief valida una cilindrada de acuerdo a su id
 *
 * \param cilindrada int*
 * \return void
 *
 */
void validarCilindrada(int* cilindrada)
{

    char cadAux[20];
    int idAux;

    system("cls");
    printf(" 50cc \n 125cc \n 500cc \n 600cc \n 700cc \n");
    do
    {
        printf("Ingresa la cilindrada que deseas:  ");

        fflush(stdin);
        fgets(cadAux, sizeof(cadAux), stdin);
        cadAux[strcspn(cadAux, "\n")] = '\0';

        if(!validarNumeroEntero(cadAux))
        {
            printf("Solo puedes ingresar numeros.\n");

        }
        else
        {
            idAux =  atoi(cadAux);
            if(idAux != 50 && idAux != 125 && idAux != 500 && idAux != 600 && idAux != 700)
            {
                printf("Ingresa una cilindrada valida.\n");
            }
            else
            {
                *cilindrada = idAux;
            }
        }
    }
    while (!validarNumeroEntero(cadAux) || (idAux != 50 && idAux != 125 && idAux != 500 && idAux != 600 && idAux != 700));
}


/** \brief valida el largo de la marca o que la misma no este vacia
 *
 * \param marca[] char
 * \return void
 *
 */
void validarMarca(char marca[])
{
    char auxCad[200];

    do
    {
        printf("Ingresa marca: ");
        fflush(stdin);
        gets(auxCad);
        if(strlen(auxCad) > strlen(marca))
        {
            printf("La marca excede el largo permitido. \n ");
        }
        else if(strlen(auxCad) == 0)
        {
            printf("No has ingresado nada. \n");
        }
    }
    while (strlen(auxCad) > strlen(marca) || strlen(auxCad) == 0);

    strcpy(marca, auxCad);

}
/** \brief valida el id de una moto y copia este y el indice de la moto en sus respectivos punteros
 *
 * \param idMoto int*
 * \param indiceMoto int*
 * \param [] Moto lista
 * \param tam int
 * \return void
 *
 */
void validarIdMoto(int* idMoto,int* indiceMoto, Moto lista [], int tam){

    char cadAux[20];
    int idAux;

    do
    {
        printf("Ingresa el id de la moto:  ");

        fflush(stdin);
        fgets(cadAux, sizeof(cadAux), stdin);
        cadAux[strcspn(cadAux, "\n")] = '\0';

        if(!validarNumeroEntero(cadAux))
        {
            printf("Solo puedes ingresar numeros.\n");
        }
        else
        {
            idAux =  atoi(cadAux);
            if(buscarMoto(lista, tam, idAux) == -1)
            {
                printf("Id inexistente.\n");
            }
            else
            {
                *indiceMoto = buscarMoto(lista, tam, idAux);
                *idMoto = idAux;
            }
        }
    }
    while (!validarNumeroEntero(cadAux) || buscarMoto(lista, tam, idAux) == -1);

}

/** \brief valida el id del cliente ingresado por el usuario
 *
 * \param clientes[] Cliente
 * \param tam int
 * \param idCliente int*
 * \return void
 *
 */
void validarIdCliente(Cliente clientes[], int tam, int* idCliente){

    char cadAux[20];
    int idAux;

    do
    {
        system("cls");
        mostrarClientes(clientes, tam);
        printf("Ingresa el id del cliente:  ");

        fflush(stdin);
        fgets(cadAux, sizeof(cadAux), stdin);
        cadAux[strcspn(cadAux, "\n")] = '\0';

        if(!validarNumeroEntero(cadAux))
        {
            printf("Solo puedes ingresar numeros.\n");
        }
        else
        {
            idAux =  atoi(cadAux);
            if(idAux < 0 || idAux > 5 )
            {
                printf("Id inexistente.\n");
            }
            else
            {
                *idCliente = idAux;
            }
        }
    }
    while (!validarNumeroEntero(cadAux) || idAux < 0 || idAux > 5  );



}
