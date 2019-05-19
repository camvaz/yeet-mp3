#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <lista.h>
#include <QMediaPlaylist>

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

private:
    Ui::Reproductor *ui;
    Lista lista;
    NodoLista *busqueda, *aux;
    Pista pistaBase;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QString nombreAux, autorAux, rutaAux, imagenAux;
};

#endif // REPRODUCTOR_H
