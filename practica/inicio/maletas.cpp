
#include "maletas.h"
int numm;

QString mostrarmaletas(){
    return (QString::number(numm));
}
void insertarmaletas(listama*ListaDoble)
{
    int *numm1=&numm;
    maletapa *nuevo=(maletapa*)malloc(sizeof(maletapa));
    nuevo->siguiente=NULL;
    maletapa *pprim1=(maletapa*)malloc(sizeof(maletapa));
    maletapa *uulti2=(maletapa*)malloc(sizeof(maletapa));
    if(ListaDoble->primero==NULL)
    {
        ListaDoble->primero=nuevo;
        ListaDoble->ultimo=nuevo;
        nuevo->siguiente=nuevo;
        nuevo->anterior=nuevo;
        nuevo->numero=*numm1;
    }else
    {
        pprim1=ListaDoble->primero;
        uulti2=ListaDoble->ultimo;
        nuevo->siguiente=pprim1;
        uulti2->siguiente=nuevo;
        pprim1->anterior=nuevo;
        nuevo->anterior=uulti2;
        ListaDoble->ultimo=nuevo;
        nuevo->numero=*numm1;

    }
(*numm1)++;
}


maletas::maletas()
{

}
