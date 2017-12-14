#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<nodoavion.h>
#include<nodopasajero.h>
#include<maletas.h>
#include <iostream>
#include <string>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
