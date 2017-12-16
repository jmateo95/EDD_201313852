#include "nodopasajero.h"
#include "maletas.h"
listama *listamaletas1;
void crearlistamaletas(){
    listamaletas1= (listama*)malloc(sizeof(listama));
    listamaletas1->primero=NULL;
    listamaletas1->ultimo=NULL;
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
        for(int i=0; i<maletas;i++){
        insertarmaletas(listamaletas1);
        }

    }else
    {
        listapersona->ultimo->proximo=nuevoper;
        listapersona->ultimo=nuevoper;
        nuevoper->pasajero=n;
        nuevoper->maletas=maletas;
        nuevoper->turnos=turnos;
        nuevoper->documentos=documentos;
        nuevoper->proximo=NULL;
        for(int i=0; i<maletas;i++){
        insertarmaletas(listamaletas1);
        }
    }    


}
/*Sintaxis
subgraph clusterMALETAS{
label = " MALETAS "
avion0[label = "AVION 1\ TAMAÑO GRANDE\ TURNOSR 3\ PASAJEROS 38"];
avion1[label = "AVION 2\ TAMAÑO GRANDE\ TURNOSR 3\ PASAJEROS 31"];
avion2[label = "AVION 2\ TAMAÑO GRANDE\ TURNOSR 3\ PASAJEROS 31"];
avion0->avion1
avion1->avion0
avion2->avion1
avion1->avion2
avion2->avion0
avion0->avion2
}
*/
QString     graficarmaletas1(){
int numero= mostrarmaletas();
QString viendo="";
viendo=viendo+"subgraph clusterMALETAS{\n";
viendo=viendo+"rankdir = LR; \n";
viendo=viendo+"node[shape = record];\n";
viendo=viendo+"label = \" MALETAS \"\n";
if(numero!=0){
    maletapa *mal=listamaletas1->primero;
    for(int i=0;i<numero;i++){
    viendo=viendo+"maleta"+QString::number(i)+"[label = \" MALETA "+QString::number(mal->numero)+ "\"];";
    viendo=viendo+"\n";
    mal = mal->siguiente;
    }
    for(int i=0;i<numero;i++)
    {
    viendo=viendo+"maleta"+QString::number(i)+"->"+"maleta"+QString::number(i+1);
    viendo=viendo+"\n";
    viendo=viendo+"maleta"+QString::number(i+1)+"->"+"maleta"+QString::number(i);
    viendo=viendo+"\n";
    }
    viendo=viendo+"maleta"+QString::number(numero)+"->"+"maleta"+QString::number(0);
    viendo=viendo+"\n";
    viendo=viendo+"maleta"+QString::number(0)+"->"+"maleta"+QString::number(numero);
}
viendo=viendo+"}\n";
return viendo;
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
