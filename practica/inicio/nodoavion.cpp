#include "nodoavion.h"
#include "nodopasajero.h"
#include "maletas.h"

int t;
int num;
listaper *listapersona;
void crearlista(){
    listapersona= (listaper*)malloc(sizeof(listaper));
    listapersona->primero=NULL;
    listapersona->ultimo=NULL;
}
void insertar(lista*ListaDoble)
{
    int *num1=&num;
    nodo *nuevo=(nodo*)malloc(sizeof(nodo));
    int pasajeros=0;
    int desabordaje=0;
    int mantenimiento=0;
    srand (time(NULL));
    int tipo=1+rand()%3;
    if(tipo==1)
    {
       pasajeros= 5+rand()%6;
       desabordaje=1;
       mantenimiento=1+rand()%3;
    }else if(tipo==2)
    {
        pasajeros= 15+rand()%11;
        desabordaje=2;
        mantenimiento=2+rand()%3;
    }else
    {
        pasajeros= 30+rand()%11;
        desabordaje=3;
        mantenimiento=3+rand()%4;
    }

    nuevo->siguiente=NULL;
    if(ListaDoble->primero==NULL)
    {
        ListaDoble->primero=nuevo;
        ListaDoble->ultimo=nuevo;
        nuevo->numero=*num1;
        nuevo->tipo=tipo;
        nuevo->pasajeros=pasajeros;
        nuevo->turnos=desabordaje;
        nuevo->mantenimiento=mantenimiento;
    }else
    {
        ListaDoble->ultimo->siguiente=nuevo;
        nuevo->anterior=ListaDoble->ultimo;
        ListaDoble->ultimo=nuevo;
        nuevo->numero=*num1;
        nuevo->tipo=tipo;
        nuevo->pasajeros=pasajeros;
        nuevo->turnos=desabordaje;
        nuevo->mantenimiento=mantenimiento;
    }
(*num1)++;
}

void eliminar(lista*listadoble){
    if(listadoble->primero==NULL)
      {
          std::printf("La lista esta vacia \n");
      }else
      {
          nodo*aux=listadoble->primero;
               listadoble->primero=aux->siguiente;
          free(aux);
      }

  }
QString mostrar(lista*listadoble){
    QString texto="";
    QString texto2="";
    QString texto3="";
    if(listadoble->primero==NULL){
        texto=("lista vacia \n");
    }else
    {
        nodo*aux=listadoble->primero;
        while(aux!=NULL)
        {
        texto=texto+("numero: "+QString::number(aux->numero)+("\n"));
        texto=texto+("Tipo: "+QString::number(aux->tipo)+("\n"));
        texto=texto+("Pasajeros: "+QString::number(aux->pasajeros)+("\n"));
        texto=texto+("Desabordaje: "+QString::number(aux->turnos)+("\n"));
        texto=texto+("Mantenimiento: "+QString::number(aux->mantenimiento)+("\n"));
        aux=aux->siguiente;
        }
        texto2=mostrarper(listapersona);
        texto3=texto+texto2;
    return texto3;
    }
}
void restar(lista*listadoble){

    int *n=&t;
    nodo*aux=listadoble->primero;
    int turnos=aux->turnos;
    if(turnos==1){
        srand(time(NULL));
        for(int i=0; i<aux->pasajeros;i++)
        {
            int maletas1=1+rand()%4;
            int turnos1=1+rand()%3;
            int documentos1=1+rand()%10;
         insertarper(listapersona, (*n),maletas1, turnos1, documentos1);
         (*n)++;
      }
        eliminar(listadoble);
    }else{
        aux->turnos=turnos-1;
    }
}

nodoavion::nodoavion()
{

}
