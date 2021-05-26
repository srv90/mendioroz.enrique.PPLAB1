#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/** \brief carga el nombre del cliente de acuerdo a su id
 *
 * \param idCliente int
 * \param clientes[] Cliente
 * \param tam int
 * \param nombre[] char
 * \return devuelve 1 si pudo y 0 sino pudo
 *
 */
int cargarNombreCliente(int idCliente, Cliente clientes[], int tam, char nombre[]){


 int retorno = 0;

    if(clientes != NULL && tam >=0)
    {
        for (int i=0; i<tam ; i++ )
        {
            if(clientes[i].id == idCliente)
            {
                strcpy(nombre, clientes[i].nombre);
                break;
            }
        }
        retorno = 1;
    }
    return retorno;


}
/** \brief muestra el listado de clientes
 *
 * \param [] Cliente clientes
 * \param tam int
 * \return int devuelve 1 si pudo recorrer el array y 0 sino
 *
 */
int mostrarClientes(Cliente clientes [], int tam){

    int retorno = 0;

    if(clientes != NULL && tam > 0)
    {
        printf("***********************LISTA DE CLIENTES*****************************\n\n");
        printf("ID      NOMBRE     SEXO");
        for (int i=0; i<tam ; i++ )
        {


            mostrarCliente(clientes[i]);
            retorno =1;
            }
        }

        printf("\n");

    return retorno;
}

/** \brief muestra la informacion de un solo cliente
 *
 * \param cliente Cliente
 * \return void
 *
 */
void mostrarCliente(Cliente cliente)
{



        printf("\n %d      %-10s   %c", cliente.id, cliente.nombre, cliente.sexo);


}
