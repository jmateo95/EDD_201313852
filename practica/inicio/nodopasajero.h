#ifndef NODOPASAJERO_H
#define NODOPASAJERO_H
#include<mainwindow.h>
#include <iostream>
#include <string>

typedef struct nodoper
{
    int pasajero;
    int maletas;
    int turnos;
    int documentos;
    struct nodoper *proximo;
}nodoper;

typedef struct listaper
{
    nodoper *primero;
    nodoper *ultimo;
    struct listaper *listaper;
}listaper;
void insertarper(listaper*Listapersonas, int n);
void eliminarper(listaper*Listapersonas);
QString mostrarper(listaper*Listapersonas);
void restarper(listaper*Listapersonas);


class nodopasajero
{
public:
    nodopasajero();
};

#endif // NODOPASAJERO_H
