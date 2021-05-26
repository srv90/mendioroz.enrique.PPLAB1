#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED

#include "Tipo.h"
#include "color.h"
#include "cliente.h"

typedef struct{
 int id;
 char marca[20];
 int idTipo;
 int idColor;
 int cilindrada;
 int isEmpty;
 int idCliente;
}Moto;

#endif // MOTO_H_INCLUDED


int altaMoto(Moto lista [], int tam, int* idMoto, int* flagAltaMoto, Cliente clientes[], int tamClientes);
int modificarMoto(Moto lista[], int tam, Color colores [], int tamColores, Tipo tiposMoto [], int tamTipos, Cliente clientes[], int tamClientes);
int bajaMoto(Moto lista [], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes);
void inicializarMotos(Moto lista[], int tam);

int buscarMoto(Moto lista [], int tam, int idMoto);



void mostrarMoto(Moto moto, Tipo tiposMoto [], int tam,  Color colores [], int tamColores, Cliente clientes[], int tamClientes);
int mostrarMotos(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes);
void ordenarMotosPorTipoYId(Moto lista[], int tam);

int buscarLibre(Moto lista[], int tam);


