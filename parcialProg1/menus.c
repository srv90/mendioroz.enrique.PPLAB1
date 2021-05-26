#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"


/** \brief recibe la opcion que eligio el usuario
 *
 * \return char devuelve esta opcion en minuscula
 *
 */
char menu()
{
    char opcion;

    printf("*******************MENU DE OPCIONES*******************************\n");
    printf(" A) ALTA MOTO\n B) MODIFICAR MOTO\n C) BAJA MOTO\n D) LISTAR MOTOS\n");
    printf(" E) LISTAR TIPOS\n F) LISTAR COLORES\n G) LISTAR SERVICIOS\n");
    printf(" H) ALTA TRABAJO\n I) LISTAR TRABAJOS\n J) INFORMES\n");
    printf(" K) SALIR");

    printf("\nIngresa opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return tolower(opcion);
}

/** \brief recibe la opcion que eligio el usuario
 *
 * \return char devuelve esta opcion en minuscula
 *
 */
char menuModificacion()
{
    char opcion;

    printf("*******************MENU DE OPCIONES*******************************\n");
    printf(" A) MODIFICAR COLOR\n B) MODIFICAR CILINDRADA\n");
    printf(" C) SALIR");

    printf("\nIngresa opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = tolower(opcion);

    while(opcion != 'a' && opcion != 'b' && opcion !='c')
    {
        printf("Ingresa una opcion de las que figura en pantalla.");
        fflush(stdin);
        scanf("%c", &opcion);
    }

    return opcion;

}

/** \brief muestra el menu de informes
 *
 * \return int devuelve la opcion elegida por el usuario
 *
 */
int menuInformes()
{

    int opcion;
    char auxOpcion[50];

    printf("*******************MENU DE INFORMES*******************************\n");
    printf(" 1) MOTOS DEL MISMO COLOR \n 2) MOTOS DE UN MISMO TIPO\n 3) MOTOS DE MAYOR CILINDRADA\n 4) MOTOS LISTADAS POR TIPO\n");
    printf(" 5) CANTIDAD DE MOTOS POR COLOR Y TIPO\n 6) LISTAR COLORES MAS ELEGIDOS\n 7) LISTAR TRABAJOS POR MOTO\n");
    printf(" 8) LISTAR REPARACIONES TOTAL DE UNA MOTO\n 9) LISTAR SERVICIOS POR MOTO\n 10) LISTAR SERVICIOS POR FECHA\n");
    printf(" 11) SALIR");


    do
    {
        printf("\nIngresa opcion: ");
        fflush(stdin);
        fgets(auxOpcion, sizeof(auxOpcion), stdin);
        auxOpcion[strcspn(auxOpcion, "\n")] = '\0';
        if(!validarNumeroEntero(auxOpcion))
        {
            printf("Solo puedes ingresar numeros.");
        }
        else
        {
            opcion = atoi(auxOpcion);
            if(opcion < 1 || opcion > 11){
                printf("Ingresa una de las opciones disponibles.");

            }
        }

    }
    while (!validarNumeroEntero(auxOpcion) || opcion < 1 || opcion > 11);

    return opcion;
}

