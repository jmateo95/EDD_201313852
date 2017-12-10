#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int valor;
    struct nodo *siguiente;
    struct nodo *anterior;
}nodo;

typedef struct lista
{
    nodo *primero;
    nodo *ultimo;
    struct lista *listaDoble;
}lista;

void insertar(lista*ListaDoble, int valor)
{
    nodo *nuevo= malloc(sizeof(nodo));
    nuevo->valor=valor;
    nuevo->siguiente=NULL;
    if(ListaDoble->primero==NULL)
    {
        ListaDoble->primero=nuevo;
        ListaDoble->ultimo=nuevo;
    }else
    {
        ListaDoble->ultimo->siguiente=nuevo;
        nuevo->anterior=ListaDoble->ultimo;
        ListaDoble->ultimo=nuevo;
    }
};
void mostrar(lista *listadoble)
{
    if(listadoble->primero==NULL){
        printf("lista vacia \n");
    }else
    {
        nodo*aux=listadoble->primero;
        while(aux!=NULL)
        {
        printf("Valor: %d\n", aux->valor);
        aux=aux->siguiente;
        }
    }
}
void eliminar(lista *listadoble, int valor)
{
    if(listadoble->primero==NULL)
    {
        printf("La lista esta vacia \n");
    }else
    {
        nodo*ant=NULL;
        nodo*aux=listadoble->primero;
        nodo*sig=NULL;
        int verificador=0;
        while(aux!=NULL)
        {
            if(aux->valor==valor)
            {
                if(aux==listadoble->primero)
                {
                   listadoble->primero=aux->siguiente;
                   verificador=1;
                   break;

                }else if(aux==listadoble->ultimo)
                {
                   ant=aux->anterior;
                   aux->anterior=NULL;
                   ant->siguiente=NULL;
                   listadoble->ultimo=ant;
                   verificador=1;
                   break;
                }else
                {
                    ant=aux->anterior;
                    aux->anterior=NULL;
                    sig=aux->siguiente;
                    aux->siguiente=NULL;
                    ant->siguiente=sig;
                    sig->anterior=ant;
                    verificador=1;
                    break;
                }

            }
            aux=aux->siguiente;
        }
        free(aux);
        free(ant);
        free(sig);
        if(verificador==0)
        {
            printf("No se encontro el Valor: %d\n", valor);
        }else
        {
            printf("Se elimino el valor: %d\n", valor);
        }
    }

}
lista *ListaDoblemente;

int opcion=0;
int valor=0;

int main()
{
    ListaDoblemente= malloc(sizeof(lista));
    ListaDoblemente->primero=NULL;
    ListaDoblemente->ultimo=NULL;
    while(opcion<4)
    {
        printf("\n Ingrese la Opcion: 1 Agregar, 2 Mostrar, 3 Eliminar \n");
        scanf("%d", &opcion);
    if(opcion==1)
    {
    printf("ingrese el dato\n");
    scanf("%d",&valor);
    insertar(ListaDoblemente, valor);
    }
    else if(opcion==2)
    {
    mostrar(ListaDoblemente);
    }
    else if(opcion==3)
    {
    printf("ingrese el dato\n");
    scanf("%d",&valor);
    eliminar(ListaDoblemente, valor);
    }else
    {
    opcion=0;
    printf("Caracter ingresado no reconocido \n");
    }
    }
    return 0;
}
