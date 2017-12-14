#ifndef MALETAS_H
#define MALETAS_H
#include<mainwindow.h>
#include <iostream>
#include <string>
#include <nodopasajero.h>
#include <maletas.h>
typedef struct maletapa
{
    int numero;
    struct maletapa *siguiente;
    struct maletapa *anterior;
}maletapa;
typedef struct listama
{
    maletapa *primero;
    maletapa *ultimo;
    struct listama *listaDoble;
}listama;
void insertarmaletas(listama*ListaDoble);
QString mostrarmaletas();
class maletas
{
public:
    maletas();
};

#endif // MALETAS_H
