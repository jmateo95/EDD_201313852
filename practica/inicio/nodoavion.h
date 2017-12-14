#ifndef NODOAVION_H
#define NODOAVION_H
#include<mainwindow.h>
#include <iostream>
#include <string>
#include <nodopasajero.h>
typedef struct nodo
{
    int numero;
    int pasajeros;
    int tipo;
    int turnos;
    int mantenimiento;
    struct nodo *siguiente;
    struct nodo *anterior;
}nodo;

typedef struct lista
{
    nodo *primero;
    nodo *ultimo;
    struct lista *listaDoble;
}lista;
void crearlista();
void insertar(lista*ListaDoble);
void eliminar(lista*ListaDoble);
QString mostrar(lista*ListaDoble);
void restar(lista*listadoble);

class nodoavion
{
public:
    nodoavion();
};

#endif // NODOAVION_H
