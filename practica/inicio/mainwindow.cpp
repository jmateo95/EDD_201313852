#include "mainwindow.h"
#include "nodoavion.h"
#include "ui_mainwindow.h"
#include "grapviz.h"
#include "nodopasajero.h"
#include "maletas.h"
#include "escritorios.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
int tu=0;
int av=0;
int *tu1=0;
int *av1=0;

int es=0;
int man=0;
lista *ListaDoblemente;
estacionlista *listaestacion=(estacionlista*)malloc(sizeof(estacionlista));
estacioncola *colaestacion=(estacioncola*)malloc(sizeof(estacioncola));
QString h;
void MainWindow::on_pushButton_clicked()
{
    ListaDoblemente= (lista*)malloc(sizeof(lista));
    ListaDoblemente->primero=NULL;
    ListaDoblemente->ultimo=NULL;
    listaestacion->primero=NULL;
    listaestacion->ultimo=NULL;
    colaestacion->primero=NULL;
    colaestacion->ultimo=NULL;
    tu=ui->lineEdit->text().toInt();
    av=ui->lineEdit_2->text().toInt();
    es=ui->lineEdit_3->text().toInt();
    man=ui->lineEdit_4->text().toInt();
    av1=&av;
    tu1=&tu;
    ui->pushButton->setEnabled(false);
    crearlista();
    crearlistamaletas();
    crearlistaescri(es);
    for(int i=0;i<man;i++){
        insertarestacion(listaestacion, i);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
   if(tu>0){
    if(ListaDoblemente->primero!=NULL &&tu!=0)
    {

        restar(ListaDoblemente, colaestacion);
        restarestaciones(listaestacion, colaestacion);
    }
    if(av!=0){
    insertar(ListaDoblemente);
    }
    for(int i=0;i<es;i++){

    }
    QString hola=mostrar(ListaDoblemente);
    ui->textEdit->setText(hola);
    graficar(ListaDoblemente, listaestacion,colaestacion);
    QString imagefilename = ("C:\\Users\\joubm\\Documents\\QT\\practica\\build-inicio-Desktop_Qt_5_9_3_MinGW_32bit-Debug\\imagen.jpg");
    QImage QImagen;
    QImagen.load ( imagefilename);
    ui->label_3->setPixmap(QPixmap::fromImage(QImagen));
    ui->textEdit_2->setText(graficarcolaestaciones(colaestacion));

}
   (*av1)=(*av1)-1;
   (*tu1)=(*tu1)-1;
}
/*ui->label_3->setText(QString::number(tipo2));*/
