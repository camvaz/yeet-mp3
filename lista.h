#ifndef LISTA_H
#define LISTA_H
#include <nodolista.h>
#include <qdebug.h>
#include <qmediaplayer.h>
#include <qfile.h>
class Lista
{
    NodoLista *head;
    NodoLista *iteradorPlaylist;
public:
    Lista();
    NodoLista *getHead();
    void InsertaInicio(Pista);
    void InsertaFinal(Pista);
    void escribe();
    bool eliminaPrimero();
    bool eliminaUltimo();
    void setIterator(NodoLista*);
    void reproducirOrden(QMediaPlayer*);
    NodoLista *iteratorRight();
    NodoLista *iteratorLeft();
    NodoLista *busqueda(QString,NodoLista*);
    NodoLista *returnIterador();
};

#endif // LISTA_H
