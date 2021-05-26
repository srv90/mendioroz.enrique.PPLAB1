#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
 int id;
 char descripcion[25];
 float precio;
}Servicio;

#endif // SERVICIO_H_INCLUDED


int listarServicios(Servicio tiposServicios[], int tam);
void mostrarServicio(Servicio servicio);
int cargarServicio(int idServicio, Servicio tiposServicios[], int tam, char servicio[], float* precio);
int buscarServicio(Servicio tiposServicios [], int tam, int idServicio);



