#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
 int id;
 char descripcion[20];
}Tipo;



#endif // TIPO_H_INCLUDED
int cargarTipoMoto(int idTipoMoto, Tipo tiposMoto[], int tam, char descripcion[]);
int listarTipos(Tipo tiposMoto[], int tam);
void mostrarTipo(Tipo tipoMoto);


