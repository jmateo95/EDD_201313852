#ifndef NODOAVION_H
#define NODOAVION_H
#include<mainwindow.h>
#include <iostream>
#include <string>
#include <nodopasajero.h>
#include <maletas.h>
#include <windows.h>
#include <escritorios.h>

typedef struct nodo
{
 public:
    int numero;
    int pasajeros;
    int tipo;
    int turnos;
    int mantenimiento;
    struct nodo *siguiente=NULL;
    struct nodo *anterior=NULL;
}nodo;

typedef struct lista
{
public:
    nodo *primero;
    nodo *ultimo;
    struct lista *listaDoble;
}lista;
typedef struct mantenimiento1
{
public:
   int numero;
   int tipo;
   int mantenimiento;
   int estado;
   struct mantenimiento1 *siguiente;
}mantenimiento1;
/*estacionlista*/
typedef struct estacionlista
{
public:
    mantenimiento1 *primero;
    mantenimiento1 *ultimo;
    struct estacionlista *listaestacion;
}estacionlista;
/*cola mantenimiento*/
typedef struct cola
{
 public:
    int numero;
    int tipo;
    int mantenimiento;
    struct cola *siguiente;
}cola;
/*estacioncola*/
typedef struct estacioncola
{
public:
    cola *primero;
    cola *ultimo;
    struct estacioncola *listaestacion;
}estacioncola;

void insertarestacion(estacionlista*listaestacion, int num2);
void insertarestacioncola(estacioncola*colaestacion, nodo *av);
/*void restaravion(avionlista*listaavion, estacioncola*colaestacion);*/
void comprobarestaciones(estacionlista*listaestacion, estacioncola*colaestacion);
void restarestaciones(estacionlista*listaestacion, estacioncola*colaestacion);
void eliminarestacioncola(estacioncola*colaestacion);
void crearlista();
void insertar(lista*ListaDoble);
void eliminar(lista*listadoble,estacioncola*colaestacion);
QString mostrar(lista*ListaDoble);
void restar(lista*listadoble, estacioncola*colaestacion);
QString graficarpasjeros();
QString graficarestaciones(estacionlista*listaestaciones);
QString graficarcolaestaciones(estacioncola*colaestacion);
class nodoavion
{
public:
    nodoavion();
};

#endif // NODOAVION_H
