#ifndef ESCRITORIOS_H
#define ESCRITORIOS_H
#include<mainwindow.h>
#include <iostream>
#include <string>
#include <nodopasajero.h>
#include <maletas.h>
#include <windows.h>

typedef struct colaescri
{
public:
    int pasajero;
    int maletas;
    int turnos;
    int documentos;
    struct colaescri *siguiente;
}colaescri;

typedef struct colaescritorios
{
public:
    int tama;
    colaescri *primero;
    colaescri *ultimo;
    struct  colaescritorios *cola;
} colaescritorios;


typedef struct escri
{
public:
    char letra;
    int estado;
    int pasajero;
    int docs;
    int turnos;
    int maletas;
    struct escri *siguiente;
    struct escri *anterior;
    colaescritorios *micola;
}escri;

typedef struct listaescritorios
{
public:
    int tama;
    escri *primero;
    escri *ultimo;
    struct  listaescritorios *listaescri;
} listaescritorios;

void meterescritorios(char let, listaescritorios*lisadeescritorios);
void crearlistaescri(int numerox);
QString graficarescritorios();
class escritorios
{
public:
    escritorios();
};

#endif // ESCRITORIOS_H
