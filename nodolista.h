#ifndef NODOLISTA_H
#define NODOLISTA_H
#include <pista.h>

class NodoLista
{
    Pista song;
    NodoLista *next;
public:
    NodoLista();
    NodoLista(const Pista&);
    QString regresaNombre();
    friend class Lista;
};

#endif // NODOLISTA_H
