#include "nodopasajero.h"
#include "maletas.h"
listama *listamaletas;

void crearlistamaletas(){
    listamaletas= (listama*)malloc(sizeof(listama));
    listamaletas->primero=NULL;
    listamaletas->ultimo=NULL;
}
void insertarper(listaper* listapersona, int n, int maletas, int turnos, int documentos)
{

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
    for(int i=0; i<maletas;i++){
    insertarmaletas(listamaletas);
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
