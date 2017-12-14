#include "mainwindow.h"
#include "nodoavion.h"
#include "ui_mainwindow.h"
#include "grapviz.h"
#include "nodopasajero.h"
#include "maletas.h"

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
lista *ListaDoblemente;

QString h;
void MainWindow::on_pushButton_clicked()
{
    ListaDoblemente= (lista*)malloc(sizeof(lista));
    ListaDoblemente->primero=NULL;
    ListaDoblemente->ultimo=NULL;
    tu=ui->lineEdit->text().toInt();
    av=ui->lineEdit->text().toInt();
    crearlista();
    crearlistamaletas();

}

void MainWindow::on_pushButton_2_clicked()
{
    if(ListaDoblemente->primero!=NULL)
    {
        restar(ListaDoblemente);
    }

    insertar(ListaDoblemente);
    QString hola=mostrar(ListaDoblemente);

    ui->textEdit->setText(hola);
    graficar(ListaDoblemente);
    QString imagefilename = ("C:\\Users\\joubm\\Documents\\QT\\practica\\build-inicio-Desktop_Qt_5_9_3_MinGW_32bit-Debug\\imagen.jpg");
    QImage QImagen;
    QImagen.load ( imagefilename);
    ui->label_3->setPixmap(QPixmap::fromImage(QImagen));
    ui->label_6->setText(mostrarmaletas());

}
/*ui->label_3->setText(QString::number(tipo2));*/
