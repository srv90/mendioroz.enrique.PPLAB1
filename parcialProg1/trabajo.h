#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "servicio.h"
#include "moto.h"
#include "cliente.h"


typedef struct{
 int id;
 int idMoto;
 int idServicio;
 Fecha fechaAlta;
 int isEmpty;
}Trabajo;
#endif // TRABAJO_H_INCLUDED


int altaTrabajo(Trabajo listaTrabajos[], int tamTrabajos, Servicio listaServicios[],
                int tamServicios, Moto listaMotos[], int tamMotos, Tipo tiposMoto [],
                int tamTipos, Color colores [], int tamColores, int*idTrabajo, Cliente clientes[], int tamClientes);

int buscarLibreTrabajo(Trabajo lista[], int tam);
int listarTrabajos(Trabajo listaTrabajos[], int tamTrabajos, Servicio listaServicios[],
                int tamServicios, Moto listaMotos[], int tamMotos, Tipo tiposMoto [],
                int tamTipos, Color colores [], int tamColores);


void mostrarTrabajo(Trabajo trabajo, Servicio listaServicios[],
                int tamServicios, Moto listaMotos[], int tamMotos, Tipo tiposMoto [],
                int tamTipos, Color colores [], int tamColores
                );

void inicializarTrabajos(Trabajo lista[], int tam);

