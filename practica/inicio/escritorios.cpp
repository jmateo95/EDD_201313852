#include "escritorios.h"
#include "grapviz.h"
#include "mainwindow.h"
#include "nodoavion.h"
#include "maletas.h"
#include "nodopasajero.h"
#include "escritorios.h"
listaescritorios *listadeescritorios;
void crearlistaescri(int es){
    listadeescritorios= (listaescritorios*)malloc(sizeof(listaescritorios));
    listadeescritorios->primero=NULL;
    listadeescritorios->ultimo=NULL;
    for(int i=0;i<es;i++){
        int numerox=65+i;
        char let=numerox;
        meterescritorios(let, listadeescritorios);
    }

}

QString graficarescritorios(){
QString viendo="";
viendo=viendo+"subgraph clusterESCRITORIOS{\n";
viendo=viendo+"rankdir = LR; \n";
viendo=viendo+"node[shape = record];\n";
viendo=viendo+"label = \" ESCRITORIOS \"\n";
if(listadeescritorios->primero!=NULL){
    escri* esc=listadeescritorios->primero;
    int i=0;
    while(esc!=NULL){
    viendo=viendo+"escritorio"+QString::number(i)+"[label = \"ESCRITORIO "+(esc->letra)+ "\\n PASAJERO: "+QString::number(esc->pasajero)+"\\n TURNOS: "+QString::number(esc->turnos)+"\\n DOCUMENTOS: "+QString::number(esc->docs)+"\"];";
    viendo=viendo+"\n";
    esc = esc->siguiente;
    i++;
    }
    i=0;
    esc=listadeescritorios->primero;
    while(esc->siguiente!=NULL)
    {
    viendo=viendo+"escritorio"+QString::number(i)+"->"+"escritorio"+QString::number(i+1);
    viendo=viendo+"\n";
    viendo=viendo+"escritorio"+QString::number(i+1)+"->"+"escritorio"+QString::number(i);
    viendo=viendo+"\n";
    esc = esc->siguiente;
    i++;
    }
    viendo=viendo+"}\n";
    return viendo;
}
}
int *tam;

void meterescritorios(char let, listaescritorios*lisadeescritorios)
{

    escri *nuevo=(escri*)malloc(sizeof(escri));
    nuevo->siguiente=NULL;
    if(lisadeescritorios->primero==NULL)
    {
        lisadeescritorios->primero=nuevo;
        lisadeescritorios->ultimo=nuevo;
        nuevo->docs=0;
        nuevo->estado=0;
        nuevo->letra=let;
        nuevo->pasajero=0;
        nuevo->turnos=0;
        nuevo->micola=(colaescritorios*)malloc(sizeof(colaescritorios));
        nuevo->micola->primero=NULL;
        nuevo->micola->ultimo=NULL;

    }else
    {
        lisadeescritorios->ultimo->siguiente=nuevo;
        nuevo->anterior=lisadeescritorios->ultimo;
        lisadeescritorios->ultimo=nuevo;
        nuevo->docs=0;
        nuevo->estado=0;
        nuevo->letra=let;
        nuevo->pasajero=0;
        nuevo->turnos=0;
    }
}
escritorios::escritorios()
{

}
