#include "listadetalles.h"
#include "ui_listadetalles.h"

ListaDetalles::ListaDetalles(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ListaDetalles)
{
    ui->setupUi(this);
    this->setWindowTitle("Lista de Reproduccion");
    QFile archivo("lista.txt");
    QString cadena;
    if(archivo.open(QFile::ReadOnly)){
        QTextStream mensaje(&archivo);
        cadena = mensaje.readAll();
    }

    ui->textBrowser->setText(cadena);
}

ListaDetalles::~ListaDetalles()
{
    delete ui;
}

void ListaDetalles::on_pushButton_clicked()
{
    this->close();
}
