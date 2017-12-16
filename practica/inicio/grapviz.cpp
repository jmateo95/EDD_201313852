#include "grapviz.h"
#include "mainwindow.h"
#include "nodoavion.h"
#include "maletas.h"
#include "nodopasajero.h"
#include "escritorios.h"

void graficar(lista*listadoble, estacionlista*listaestacion, estacioncola *colaestacion)
{

       FILE *dot;
       dot = fopen("dot.dot", "w+");
       fprintf(dot, "digraph{\n");
       fprintf(dot,"rankdir = RL; \n");
       fprintf(dot, "subgraph clusterPRACTICA{\n");
       fprintf(dot,"rankdir = BT; \n");
       fprintf(dot,"node[shape = record];\n");
       fprintf(dot, "label = \"PRACTICA\";\n");
       fprintf(dot, "subgraph clusterAVIONES{\n");
       fprintf(dot, "label = \" AVIONES \"\n");
       if(listadoble->primero != NULL){
           nodo *aux = listadoble->primero;
           int cont = 0;
           while(aux != NULL){
               QString tamano;
               if(aux->tipo == 1){
                   tamano = "PEQUEÑO";
               }else if(aux->tipo == 2){
                   tamano = "MEDIANO";
               }else{
                   tamano = "GRANDE";
               }
               fprintf(dot, "avion%d[label = \"AVION %d\\n TAMAÑO %s\\n TURNOSR %d\\n PASAJEROS %d\"];\n", cont, aux->numero, tamano.toStdString().c_str(),aux->turnos, aux->pasajeros);
               cont++;
               aux = aux->siguiente;
           }
           cont = 0;
           aux = listadoble->primero;
           while(aux != NULL && listadoble->primero != listadoble->ultimo){
               if(aux == listadoble->primero && aux->siguiente != NULL){
                   fprintf(dot, "avion%d->avion%d", cont, cont+1);
               }else if(aux == listadoble->ultimo && aux->anterior != NULL){
                   fprintf(dot, "avion%d->avion%d", cont, cont-1);
               }else{
                   fprintf(dot, "avion%d->avion%d\n", cont, cont+1);
                   fprintf(dot, "avion%d->avion%d", cont, cont-1);
               }
               fprintf(dot, "\n");
               aux = aux->siguiente;
               cont++;
           }
       }

       fprintf(dot, "}\n");
       QString escribir= graficarmaletas1()+graficarescritorios()+graficarpasjeros()+graficarestaciones(listaestacion)+graficarcolaestaciones(colaestacion);
       QByteArray ba = escribir.toLatin1();
        const char *c_str2 = ba.data();
       fprintf(dot, c_str2);
       fprintf(dot, "}\n");
       fprintf(dot, "}\n");
       fclose(dot);
       system("dot -Tjpg C:\\Users\\joubm\\Documents\\QT\\practica\\build-inicio-Desktop_Qt_5_9_3_MinGW_32bit-Debug\\dot.dot -o C:\\Users\\joubm\\Documents\\QT\\practica\\build-inicio-Desktop_Qt_5_9_3_MinGW_32bit-Debug\\imagen.jpg");
}



grapviz::grapviz()
{

}
