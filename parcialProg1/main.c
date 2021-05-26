#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moto.h"
#include "servicio.h"
#include "trabajo.h"
#include "menus.h"
#include "cliente.h"
#include "informes.h"



#define TAMCOLORES 5
#define TAMTIPOS 4
#define TAMSERVICIOS 4
#define TAMMOTOS 10
#define TAMTRABAJOS 10
#define TAMCLIENTES 5


int main()
{

    Color colores [TAMCOLORES] = {{10000,"Gris"}, {10001,"Negro"}, {10002,"Blanco"}, {10003,"Azul"}, {10004,"Rojo"}};
    Tipo tipos [TAMTIPOS] = {{1000,"Enduro"}, {1001,"Chopera"}, {1002,"Scooter"}, {1003,"Ciclomotor"}};
    Servicio servicios [TAMSERVICIOS] = {{20000,"Limpieza", 250}, {20001,"Ajuste", 300},
        {20002,"Balanceo", 17}, {20003,"Cadena", 190}
    };

    Trabajo trabajos[TAMTRABAJOS] = {{1, 1000, 20000, {10,12,2021},0}, {2, 2000, 20000, {10,10,2021},0},
        {3, 3000, 20002, {11,11,2021},0}, {4, 3000, 20003, {11,11,2021},0}, {5, 4000, 20002, {13,11,2021},0},
        {6, 9000, 20001, {18,9,2021},1}, {7, 7000, 20000, {10,10,2021},1},
        {8, 8000, 20003, {16,11,2021},1}, {9, 7000, 20003, {11,11,2021},1}, {10, 4000, 20002, {13,11,2021},1}
    } ;

    Moto motos[TAMMOTOS] = {{1000,"aaa",1000,10001,150,0,1}, {2000,"bbbb",1000,10001,50,0,1},  {3000,"ccc",1001,10004,300,0,3},
        {4000,"dddd",1000,10004,400,0,3}, {5000,"eeee",1003,10001,50,0,3}, {6000,"ffff",1003,10001,50,0,2},{7000,"eeee",1002,10003,500,0,4},
        {8000,"ffff",1001,10000,500,0,4}, {9000,"eeee",1002,10002,500,1,1}, {10000,"ffff",1003,10002,500,1,5}
    };

    Cliente clientes[TAMCLIENTES] = {{1, "juan",'m'}, {2, "jorge",'m'}, {3, "tomas",'m'}, {4, "ana",'f'},
        {5, "sofia",'f'}
    };

    char respuesta;
    int idMoto = 1000;
    int idTrabajo = 1;
    int flagAltaMoto = 0;

    inicializarMotos(motos, TAMMOTOS);
    inicializarTrabajos(trabajos, TAMTRABAJOS);


    do
    {

        switch (menu())
        {
        case 'a' :
            if(!altaMoto(motos,TAMMOTOS, &idMoto, &flagAltaMoto, clientes, TAMCLIENTES))
            {
                printf("Ocurrio un error\n");
            }
            break;
        case 'b' :
            if(flagAltaMoto)
            {
                if(!modificarMoto(motos, TAMMOTOS, colores, TAMCOLORES, tipos, TAMTIPOS, clientes, TAMCLIENTES))
                {
                    printf("Ocurrio un error.");

                }
            }
            else
            {
                printf("Primero debes ingresar una moto.\n");
            }
            break;
        case 'c' :
            if(flagAltaMoto)
            {
                if(!bajaMoto(motos, TAMMOTOS, tipos, TAMMOTOS, colores, TAMCOLORES, clientes, TAMCLIENTES))
                {
                    printf("Ocurrio un error.");

                }
            }
            else
            {
                printf("Primero debes ingresar una moto.\n");
            }
            break;
        case 'd' :
            if(flagAltaMoto)
            {
                system("cls");
                if(!mostrarMotos(motos, TAMMOTOS, tipos, TAMTIPOS, colores, TAMCOLORES, clientes, TAMCLIENTES))
                {
                    printf("Ocurrio un error.");
                }
            }
            else
            {
                printf("Primero debes ingresar una moto.\n");
            }
            break;
        case 'e' :
            system("cls");
            if(!listarTipos(tipos, TAMTIPOS))
            {
                printf("Ocurrio un error.\n");
            }
            break;
        case 'f' :
            system("cls");
            if(!listarColores(colores,TAMCOLORES))
            {
                printf("Ocurrio un error.\n");
            }
            break;
        case 'g' :
            system("cls");
            if(!listarServicios(servicios,TAMSERVICIOS))
            {
                printf("Ocurrio un error.\n");
            }
            break;
        case 'h' :
            if(flagAltaMoto)
            {
                system("cls");
                if(!altaTrabajo(trabajos, TAMTRABAJOS, servicios, TAMSERVICIOS, motos, TAMMOTOS, tipos, TAMTIPOS, colores, TAMCOLORES, &idTrabajo, clientes, TAMCLIENTES))
                {
                    printf("Ocurrio un error.");
                }
            }
            else
            {
                printf("Primero debes ingresar una moto.\n");
            }
            break;
        case 'i' :
            if(flagAltaMoto)
            {
                system("cls");
                if(!listarTrabajos(trabajos, TAMTRABAJOS, servicios, TAMSERVICIOS, motos, TAMMOTOS, tipos, TAMTIPOS, colores, TAMCOLORES))
                {
                    printf("Ocurrio un error.");
                }
            }
            else
            {
                printf("Primero debes ingresar una moto.\n");
            }
            break;
        case 'j' :
        {
            if(flagAltaMoto)
            {
                system("cls");
                mostarMenuDeInformes(motos,TAMMOTOS,tipos, TAMTIPOS,colores,TAMCOLORES,clientes,TAMCLIENTES, servicios, TAMSERVICIOS, trabajos,TAMTRABAJOS);
            }
            else
            {
                printf("Primero debes ingresar una moto.\n");
            }
        }
        break;
        case 'k':
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
        default:
        {
            printf("Ingresa una de las opciones disponibles. \n");

        }
        break;
        }
        system("pause");
        system("cls");
    }
    while (respuesta != 's');


    return 0;
}
