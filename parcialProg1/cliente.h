#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int id;
    char nombre[50];
    char sexo;


}Cliente;

#endif // CLIENTE_H_INCLUDED

int cargarNombreCliente(int idCliente, Cliente clientes[], int tam, char nombre[]);
int mostrarClientes(Cliente clientes [], int tam);
void mostrarCliente(Cliente cliente);
