#include "nodopasajero.h"
void insertarper(listaper* listapersona, int n)
{
    srand (time(NULL));
    int maletas=1+rand()%4;
    int turnos=1+rand()%3;
    int documentos=1+rand()%10;
    nodoper *nuevoper=(nodoper*)malloc(sizeof(nodoper));
    if(listapersona->primero==NULL)
    {
        listapersona->primero=nuevoper;
        listapersona->ultimo=nuevoper;
        nuevoper->pasajero=n;
        nuevoper->maletas=maletas;
        nuevoper->turnos=turnos;
        nuevoper->documentos=documentos;
        nuevoper->proximo=NULL;

    }else
    {
        listapersona->ultimo->proximo=nuevoper;
        listapersona->ultimo=nuevoper;
        nuevoper->pasajero=n;
        nuevoper->maletas=maletas;
        nuevoper->turnos=turnos;
        nuevoper->documentos=documentos;
        nuevoper->proximo=NULL;
    }
}

QString mostrarper(listaper*listadoble){
    QString texto="";
    if(listadoble->primero==NULL){
        texto=("lista vacia \n");
    }else
    {
        nodoper*aux=listadoble->primero;
        while(aux!=NULL)
        {
        texto=texto+("ID: "+QString::number(aux->pasajero)+("\n"));
        texto=texto+("maletas: "+QString::number(aux->maletas)+("\n"));
        texto=texto+("documentos: "+QString::number(aux->documentos)+("\n"));
        texto=texto+("turnos: "+QString::number(aux->turnos)+("\n"));
        aux=aux->proximo;
        }
    return texto;
    }
}
nodopasajero::nodopasajero()
{

}
