#ifndef NODOLISTA_H
#define NODOLISTA_H
#include <pista.h>

class NodoLista
{
    Pista song;
    NodoLista *next;
public:
    NodoLista();
    Pista regresaInfo();
    friend class Lista;
};

#endif // NODOLISTA_H
