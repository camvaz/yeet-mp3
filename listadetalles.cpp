#include "listadetalles.h"
#include "ui_listadetalles.h"

ListaDetalles::ListaDetalles(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ListaDetalles)
{
    ui->setupUi(this);
}

ListaDetalles::~ListaDetalles()
{
    delete ui;
}
