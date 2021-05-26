#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moto.h"
#include "servicio.h"
#include "trabajo.h"

#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED


int validarNumeroEntero(char*);
void validarServicio(Servicio tiposServicios[], int tam,int* idServicio);
void validarFecha(Fecha* fecha);
void validarMarca(char marca[]);
void validarTipoMoto(int* idTipo);
void validarColor(int* idColor);
void validarCilindrada(int* cilindrada);
void validarIdMoto(int* idMoto,int* indiceMoto,Moto lista [], int tam);
void validarIdCliente(Cliente clientes[], int tam, int* idCliente);

