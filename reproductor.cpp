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

    //Agregamos canciones predeterminadas a la playlist
    player = new QMediaPlayer;
    //connect(player, &QMediaPlayer::positionChanged, this, &);
    player->setMedia(QUrl::fromLocalFile("/home/vic/Documents/QT/mediaplayer/musica/ElectricRelaxation.mp3"));
    player->setVolume(50);
    player->play();


    //Esconder GroupBoxes
    //ui->groupBoxInsert->hide();
    //ui->groupBoxDelete->hide();
    //ui->groupBoxSearch->hide();
}

Reproductor::~Reproductor()
{
    delete ui;
}
