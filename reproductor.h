#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <lista.h>
#include <QMediaPlaylist>
#include <qpixmap.h>
#include <qdebug.h>
#include <qmessagebox.h>
#include <QListWidgetItem>
#include <qlistwidget.h>

namespace Ui {
class Reproductor;
}

class Reproductor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Reproductor(QWidget *parent = nullptr);
    ~Reproductor();

private slots:
    void on_pausaBoton_clicked();
    void on_positionChanged(qint64);
    void on_durationChanged(qint64);
    void on_sliderRola_sliderMoved(int position);
    void on_sliderVolumen_sliderMoved(int position);
    void on_botonInsInicio_clicked();

    void on_botonInsFin_clicked();

    void on_botonDelInicio_clicked();

    void on_BotonDelFin_clicked();

    void on_botonReproducir_clicked();

    void on_botonBuscar_clicked();

    void on_cargaImagen_clicked();

    void on_cargaArchivo_clicked();

    void on_addSong_clicked();

    void on_addCancel_clicked();

    void on_listaReproduccion_itemDoubleClicked(QListWidgetItem *item);

    void on_listaReproduccion_itemEntered(QListWidgetItem *item);

    void on_listaReproduccion_itemPressed(QListWidgetItem *item);

    void on_botonAdelante_clicked();

    void on_botonAtras_clicked();

    void on_botonEnorden_clicked();

    void on_botonReproducir_2_clicked();

private:
    Ui::Reproductor *ui;
    Lista lista;
    NodoLista *busqueda, *aux;
    Pista pistaBase;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QPixmap pixmap;
    QFont fuenteBoton;
    QString nombreAux, autorAux, rutaAux, imagenAux;
    qint64 duracion;
};

#endif // REPRODUCTOR_H
