#include "reproductor.h"
#include "ui_reproductor.h"

Reproductor::Reproductor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reproductor)
{
    ui->setupUi(this);

    fuenteBoton.setBold(1);
    fuenteBoton.setFamily("Loma");
    fuenteBoton.setPointSize(11);

    //Definimos el nombre de la aplic  acion
    this->setWindowTitle("Yeet");
    duracion = 0;
    //Como no va a ser responsivo, esta linea no permite al usuario modificar el tamanio de la ventana
    this->setFixedSize(QSize(1113, 665));

    //Escondemos el GroupBox de Agregar Pista
    ui->groupBoxAdd->hide();


    //Prueba de sonido e imagen
    player = new QMediaPlayer;
    connect(player, &QMediaPlayer::positionChanged, this, &Reproductor::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &Reproductor::on_durationChanged);
    player->setMedia(QUrl::fromLocalFile("/home/vic/Documents/QT/mediaplayer/musica/fsmh.mp3"));
    rutaAux = "/home/vic/Documents/QT/mediaplayer/musica/covers/tlop.png";
    pixmap.load(rutaAux);
    //definimos el tamanio del pixmap para el label
    pixmap = pixmap.scaled(251,251, Qt::KeepAspectRatio);
    ui->labelImagen->setPixmap(pixmap);

    //Agregamos canciones predeterminadas a la playlist

    player->setMedia(QUrl::fromLocalFile("/home/vic/Documents/QT/mediaplayer/musica/Dang.mp3"));
    pistaBase.setObject("Dang! (feat. Anderson Paak)", "5:05", "Mac Miller", "/home/vic/Documents/QT/mediaplayer/musica/covers/divinefeminine.png","/home/vic/Documents/QT/mediaplayer/musica/Dang.mp3");
    lista.InsertaFinal(pistaBase);
    ui->listaReproduccion->addItem(pistaBase.getNombre());


    player->setMedia(QUrl::fromLocalFile("/home/vic/Documents/QT/mediaplayer/musica/ladders.mp3"));
    pistaBase.setObject("Ladders", "4:47", "Mac Miller", "/home/vic/Documents/QT/mediaplayer/musica/covers/swimming.png","/home/vic/Documents/QT/mediaplayer/musica/ladders.mp3");
    lista.InsertaFinal(pistaBase);
    ui->listaReproduccion->addItem(pistaBase.getNombre());

    player->setMedia(QUrl::fromLocalFile("/home/vic/Documents/QT/mediaplayer/musica/cantgetoveryou.mp3"));
    pistaBase.setObject("CAN'T GET OVER YOU", "2:38", "Joji", "/home/vic/Documents/QT/mediaplayer/musica/covers/joji.png","/home/vic/Documents/QT/mediaplayer/musica/cantgetoveryou.mp3");
    lista.InsertaFinal(pistaBase);
    ui->listaReproduccion->addItem(pistaBase.getNombre());

    player->setMedia(QUrl::fromLocalFile("/home/vic/Documents/QT/mediaplayer/musica/fsmh.mp3"));
    pistaBase.setObject("Father Stretch My Hands Pt. 1", "2:15", "Kanye West", "/home/vic/Documents/QT/mediaplayer/musica/covers/tlop.png","/home/vic/Documents/QT/mediaplayer/musica/fsmh.mp3");
    lista.InsertaFinal(pistaBase);
    ui->listaReproduccion->addItem(pistaBase.getNombre());



    qDebug() << lista.getHead()->regresaNombre();

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


void Reproductor::on_botonInsInicio_clicked()
{
    //Esconder GroupBoxes
    ui->groupBoxInsert->hide();
    ui->groupBoxDelete->hide();
    ui->groupBoxSearch->hide();

    //Escondemos el GroupBox de Agregar Pista
    ui->groupBoxAdd->show();
}

void Reproductor::on_botonInsFin_clicked()
{
    //Esconder GroupBoxes
    ui->groupBoxInsert->hide();
    ui->groupBoxDelete->hide();
    ui->groupBoxSearch->hide();

    //Escondemos el GroupBox de Agregar Pista
    ui->groupBoxAdd->show();
}


void Reproductor::on_botonDelInicio_clicked()
{

}

void Reproductor::on_BotonDelFin_clicked()
{

}

void Reproductor::on_botonReproducir_clicked()
{

}

void Reproductor::on_botonBuscar_clicked()
{

}

void Reproductor::on_cargaImagen_clicked()
{

}

void Reproductor::on_cargaArchivo_clicked()
{

}

void Reproductor::on_addSong_clicked()
{

}

void Reproductor::on_addCancel_clicked()
{
    //Esconder GroupBoxes
    ui->groupBoxInsert->show();
    ui->groupBoxDelete->show();
    ui->groupBoxSearch->show();

    //Escondemos el GroupBox de Agregar Pista
    ui->groupBoxAdd->hide();
    ui->addNombre->clear();
    ui->addArtista->clear();
    ui->addDuracion->clear();
}

void Reproductor::on_listaReproduccion_itemDoubleClicked(QListWidgetItem *item)
{
        ui->pausaBoton->setText("⏸");
        busqueda = lista.getHead();
        aux = lista.busqueda(ui->listaReproduccion->currentItem()->text(), busqueda);
        lista.setIterator(aux);
        if(aux){
            pistaBase = aux->regresaPista();

            player->setMedia(QUrl::fromLocalFile(pistaBase.getRuta()));
            player->play();
            pixmap.load(pistaBase.getImagen());
            pixmap = pixmap.scaled(251,251, Qt::KeepAspectRatio);
            ui->labelImagen->setPixmap(pixmap);
            ui->labelNombre->setText(pistaBase.getNombre());
            ui->labelArtista->setText(pistaBase.getAutor()+" - "+pistaBase.getDuracion());
        } else {
            QMessageBox::warning(this,"Error de reproduccion.","No se encontro un archivo para la cancion indicada.");
        }
}

void Reproductor::on_listaReproduccion_itemEntered(QListWidgetItem *item)
{
    ui->pausaBoton->setText("⏸");
    busqueda = lista.getHead();
    aux = lista.busqueda(ui->listaReproduccion->currentItem()->text(), busqueda);
    if(aux){
        pistaBase = aux->regresaPista();

        player->setMedia(QUrl::fromLocalFile(pistaBase.getRuta()));
        player->play();
        pixmap.load(pistaBase.getImagen());
        pixmap = pixmap.scaled(251,251, Qt::KeepAspectRatio);
        ui->labelImagen->setPixmap(pixmap);
        ui->labelNombre->setText(pistaBase.getNombre());
        ui->labelArtista->setText(pistaBase.getAutor()+" - "+pistaBase.getDuracion());
    } else {
        QMessageBox::warning(this,"Error de reproduccion.","No se encontro un archivo para la cancion indicada.");
    }
}

void Reproductor::on_listaReproduccion_itemPressed(QListWidgetItem *item)
{
    ui->pausaBoton->setText("⏸");
    busqueda = lista.getHead();
    aux = lista.busqueda(ui->listaReproduccion->currentItem()->text(), busqueda);
    lista.setIterator(aux);
    if(aux){
        pistaBase = aux->regresaPista();

        player->setMedia(QUrl::fromLocalFile(pistaBase.getRuta()));
        player->play();
        pixmap.load(pistaBase.getImagen());
        pixmap = pixmap.scaled(251,251, Qt::KeepAspectRatio);
        ui->labelImagen->setPixmap(pixmap);
        ui->labelNombre->setText(pistaBase.getNombre());
        ui->labelArtista->setText(pistaBase.getAutor()+" - "+pistaBase.getDuracion());
    } else {
        QMessageBox::warning(this,"Error de reproduccion.","No se encontro un archivo para la cancion indicada.");
    }
}

void Reproductor::on_botonAdelante_clicked()
{
    aux = lista.iteratorRight();
    if(aux){
        pistaBase = aux->regresaPista();
        player->setMedia(QUrl::fromLocalFile(pistaBase.getRuta()));
        player->play();
        pixmap.load(pistaBase.getImagen());
        pixmap = pixmap.scaled(251,251, Qt::KeepAspectRatio);
        ui->labelImagen->setPixmap(pixmap);
        ui->labelNombre->setText(pistaBase.getNombre());
        ui->labelArtista->setText(pistaBase.getAutor()+" - "+pistaBase.getDuracion());
    } else {

    }
}

void Reproductor::on_botonAtras_clicked()
{
    aux = lista.iteratorLeft();
    if(aux){
        pistaBase = aux->regresaPista();
        player->setMedia(QUrl::fromLocalFile(pistaBase.getRuta()));
        player->play();
        pixmap.load(pistaBase.getImagen());
        pixmap = pixmap.scaled(251,251, Qt::KeepAspectRatio);
        ui->labelImagen->setPixmap(pixmap);
        ui->labelNombre->setText(pistaBase.getNombre());
        ui->labelArtista->setText(pistaBase.getAutor()+" - "+pistaBase.getDuracion());
    } else {

    }
}

void Reproductor::on_botonEnorden_clicked()
{
    lista.reproducirOrden(player);
}

void Reproductor::on_botonReproducir_2_clicked()
{
    this->close();
}
