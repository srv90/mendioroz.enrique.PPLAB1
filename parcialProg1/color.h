#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
typedef struct{
 int id;
 char nombreColor[20];

}Color;




#endif // COLOR_H_INCLUDED
int cargarColor(int idMoto, Color colores[], int tam, char color[]);
int listarColores(Color colores[], int tam);
void mostrarColor(Color colores);

