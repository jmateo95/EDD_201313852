#ifndef NODOPASAJERO_H
#define NODOPASAJERO_H
#include<mainwindow.h>
#include <iostream>
#include <string>
#include <maletas.h>
#include <stdlib.h>
#include <time.h>


typedef struct nodoper
{
public:
    int pasajero;
    int maletas;
    int turnos;
    int documentos;
    struct nodoper *proximo;
}nodoper;

typedef struct listaper
{
public:
    nodoper *primero;
    nodoper *ultimo;
    struct listaper *perlist;
}listaper;

QString graficarmaletas1();
void crearlistamaletas();
void insertarper(listaper*Listapersonas, int n, int maletas, int turnos, int documentos);
void eliminarper(listaper*Listapersonas);
QString mostrarper(listaper*Listapersonas);
void restarper(listaper*Listapersonas);


class nodopasajero
{
public:
    nodopasajero();
};

#endif // NODOPASAJERO_H
