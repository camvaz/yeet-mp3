#include "reproductor.h"
#include "ui_reproductor.h"

Reproductor::Reproductor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reproductor)
{
    ui->setupUi(this);

    //Definimos el nombre de la aplicacion
    this->setWindowTitle("Yeet");

    //Como no va a ser responsivo, esta linea no permite al usuario modificar el tamanio de la ventana
    this->setFixedSize(QSize(1113, 621));

    //Escondemos el GroupBox de Agregar Pista
    ui->groupBoxAdd->hide();



    //Esconder GroupBoxes
    //ui->groupBoxInsert->hide();
    //ui->groupBoxDelete->hide();
    //ui->groupBoxSearch->hide();
}

Reproductor::~Reproductor()
{
    delete ui;
}
