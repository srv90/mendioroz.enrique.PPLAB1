#include "fecha.h"
#include "servicio.h"
#include "moto.h"
#include "cliente.h"
#include "trabajo.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


void mostarMenuDeInformes(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes, Servicio servicios[], int tamServicios, Trabajo trabajos[], int tamTrabajos);
int mostrarMotosPorColor(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes);
int mostrarMotosPorTipo(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes);
int mostrarMotosMayorCilindrada(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes);
int mostrarMotosSeparadasPorTipo(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes);
int mostrarMotosPorColoryTipo(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes);
int mostrarColoresMasElegidos(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes);
int mostrarTrabajosPorMoto(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes, Servicio servicios[], int tamServicios, Trabajo listaTrabajos[], int tamTrabajos);
int mostrarSumaImportesPorMoto(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes, Servicio servicios[], int tamServicios, Trabajo listaTrabajos[], int tamTrabajos);
int mostrarServiciosPorMotoYFecha(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes, Servicio servicios[], int tamServicios, Trabajo listaTrabajos[], int tamTrabajos);
int mostrarServiciosPorFecha(Moto lista[], int tam, Tipo tiposMoto [], int tamTipos, Color colores [], int tamColores, Cliente clientes[], int tamClientes, Servicio servicios[], int tamServicios, Trabajo listaTrabajos[], int tamTrabajos);
