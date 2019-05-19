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
    connect(player, &QMediaPlayer::positionChanged, this, &Reproductor::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &Reproductor::on_durationChanged);
    player->setMedia(QUrl::fromLocalFile("/home/vic/Documents/QT/mediaplayer/musica/ElectricRelaxation.mp3"));



    //Esconder GroupBoxes
    //ui->groupBoxInsert->hide();
    //ui->groupBoxDelete->hide();
    //ui->groupBoxSearch->hide();
}

Reproductor::~Reproductor()
{
    delete ui;
}

void Reproductor::on_pausaBoton_clicked()
{
    if( ui->pausaBoton->text() == "▶" ){
        ui->pausaBoton->setText("⏸");
        player->play();
    } else {
        ui->pausaBoton->setText("▶");
        player->pause();
    }
}

void Reproductor::on_positionChanged(qint64 posicion)
{
    ui->sliderRola->setValue(posicion);
}

void Reproductor::on_durationChanged(qint64 posicion)
{
    ui->sliderRola->setMaximum(posicion);
}

void Reproductor::on_sliderRola_sliderMoved(int position)
{
    player->setPosition(position);
}

void Reproductor::on_sliderVolumen_sliderMoved(int position)
{
    player->setVolume(position);
}
