#include "nodoavion.h"
#include "nodopasajero.h"
#include "maletas.h"
#include "escritorios.h"
int t;
int t1;
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
void eliminar(lista*listadoble,estacioncola*colaestacion){

          nodo*aux=listadoble->primero;
          insertarestacioncola(colaestacion,aux);
          listadoble->primero=aux->siguiente;
          free(aux);
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
void restar(lista*listadoble, estacioncola*colaestacion){

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
        eliminar(listadoble, colaestacion);
    }else{
        aux->turnos=turnos-1;
    }
}
QString graficarpasjeros(){
    QString viendo="";
    viendo=viendo+"subgraph clusterPASAJEROS{\n";
    viendo=viendo+"rankdir = LR; \n";
    viendo=viendo+"node[shape = record];\n";
    viendo=viendo+"label = \" PASAJEROS \"\n";
    if(listapersona->primero!=NULL){
        nodoper* esc=listapersona->primero;
        int i=0;
        while(esc!=NULL){
        viendo=viendo+"pasajero"+QString::number(i)+"[label = \"PASAJERO "+QString::number(esc->pasajero)+ "\\n TURNOS: "+QString::number(esc->turnos)+"\\n DOCUMENTOS "+QString::number(esc->documentos)+"\\n MALETAS: "+QString::number(esc->maletas)+"\"];";
        viendo=viendo+"\n";
        esc = esc->proximo;
        i++;
        }
        i=0;
        esc=listapersona->primero;
        while(esc->proximo!=NULL)
        {
        viendo=viendo+"pasajero"+QString::number(i)+"->"+"pasajero"+QString::number(i+1);
        viendo=viendo+"\n";
        viendo=viendo+"\n";
        esc = esc->proximo;
        i++;
        }

    }
    viendo=viendo+"}\n";
    return viendo;
}
QString graficarestaciones(estacionlista*listaestaciones){
        QString viendo="";
        viendo=viendo+"subgraph clusterESTACIONES{\n";
        viendo=viendo+"rankdir = LR; \n";
        viendo=viendo+"node[shape = record];\n";
        viendo=viendo+"label = \" ESTACIONES \"\n";
        if(listaestaciones->primero!=NULL){
            mantenimiento1* esc=listaestaciones->primero;
            int i=0;
            while(esc!=NULL){
                QString estado1="";
                if(esc->estado==0){
                    estado1="vacio";
                }else{
                    estado1="ocupado";
                }
            viendo=viendo+"estacion"+QString::number(i)+"[label = \"AVION "+QString::number(esc->numero)+ "\\n TURNOS: "+QString::number(esc->mantenimiento)+"\\n ESTADO "+estado1+"\"];";
            viendo=viendo+"\n";
            esc = esc->siguiente;
            i++;
            }
            i=0;
            esc=listaestaciones->primero;
            while(esc->siguiente!=NULL)
            {
            viendo=viendo+"estacion"+QString::number(i)+"->"+"estacion"+QString::number(i+1);
            viendo=viendo+"\n";
            viendo=viendo+"\n";
            esc = esc->siguiente;
            i++;
            }

        }
        viendo=viendo+"}\n";
        return viendo;
}
QString graficarcolaestaciones(estacioncola*colaestacion){
        QString viendo="";
        viendo=viendo+"subgraph clusterCOLA{\n";
        viendo=viendo+"rankdir = LR; \n";
        viendo=viendo+"node[shape = record];\n";
        viendo=viendo+"label = \" COLA \"\n";
        if(colaestacion->primero!=NULL){
            cola* esc=colaestacion->primero;
            int i=0;
            while(esc!=NULL){
                QString estado1="";
            viendo=viendo+"COLA"+QString::number(i)+"[label = \"AVION "+QString::number(esc->numero)+ "\\n TURNOS: "+QString::number(esc->mantenimiento)+"\"];";
            viendo=viendo+"\n";
            esc = esc->siguiente;
            i++;
            }
            i=0;
            esc=colaestacion->primero;
            while(esc->siguiente!=NULL)
            {
            viendo=viendo+"COLA"+QString::number(i)+"->"+"COLA"+QString::number(i+1);
            viendo=viendo+"\n";
            viendo=viendo+"\n";
            esc = esc->siguiente;
            i++;
            }

        }
        viendo=viendo+"}\n";
        return viendo;
}
void insertarestacioncola(estacioncola*colaestacion, nodo *av){
    cola *nuevo=(cola*)malloc(sizeof(cola));
    nuevo->siguiente=NULL;

    if(colaestacion->primero==NULL)
    {
        colaestacion->primero=nuevo;
        colaestacion->ultimo=nuevo;
        nuevo->numero=av->numero;
        nuevo->mantenimiento=av->mantenimiento;
        nuevo->tipo=av->tipo;
    }else
    {
        colaestacion->ultimo->siguiente=nuevo;
        colaestacion->ultimo=nuevo;
        nuevo->numero=av->numero;
        nuevo->mantenimiento=av->mantenimiento;
        nuevo->tipo=av->tipo;
    }
}
void insertarestacion(estacionlista*listaestacion, int num2){
    mantenimiento1 *nuevo=(mantenimiento1*)malloc(sizeof(mantenimiento1));
    nuevo->siguiente=NULL;
    if(listaestacion->primero==NULL)
    {
        listaestacion->primero=nuevo;
        listaestacion->ultimo=nuevo;
        nuevo->numero=num2;
        nuevo->mantenimiento=0;
        nuevo->tipo=0;
        nuevo->estado=0;
    }else
    {

        listaestacion->ultimo->siguiente=nuevo;
        listaestacion->ultimo=nuevo;
        nuevo->numero=num2;
        nuevo->mantenimiento=0;
        nuevo->tipo=0;
        nuevo->estado=0;
    }
}
void comprobarestaciones(estacionlista*listaestacion, estacioncola*colaestacion)
{
 if(colaestacion->primero!=NULL){
 mantenimiento1 *aux=(mantenimiento1*)malloc(sizeof(mantenimiento1));
 cola *aux1=(cola*)malloc(sizeof(cola));
 aux=listaestacion->primero;
    while(aux!=NULL){
        if (aux->estado==0){

            aux->estado=1;
            aux->mantenimiento=colaestacion->primero->mantenimiento;
            aux->numero=colaestacion->primero->numero;
            aux->tipo=colaestacion->primero->tipo;

            eliminarestacioncola(colaestacion);
            break;
        }
        aux=aux->siguiente;
    }
}
}
void restarestaciones(estacionlista*listaestacion, estacioncola*colaestacion)
{
    mantenimiento1 *aux=listaestacion->primero;

    while(aux!=NULL)
    {
    if(aux->estado==1){
        int turnos=aux->mantenimiento;
        if(turnos==1){
            aux->estado=0;
            aux->mantenimiento=0;
            aux->numero=0;
            aux->tipo=0;
        }else if(turnos>1){
            aux->mantenimiento=(turnos-1);
        }

    }
    aux=aux->siguiente;
    }

   if(colaestacion->primero!=NULL){
    comprobarestaciones(listaestacion, colaestacion);
   }
}
void eliminarestacioncola(estacioncola*colaestacion){
    if(colaestacion->primero==NULL)
      {
          std::printf("La lista esta vacia \n");
      }else
      {
          cola*aux=colaestacion->primero;

          colaestacion->primero=aux->siguiente;
          free(aux);
      }

  }
nodoavion::nodoavion()
{

}
