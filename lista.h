#ifndef LISTA_H
#define LISTA_H
#include <nodolista.h>

class Lista
{
    NodoLista *head;
public:
    Lista();
    NodoLista *getHead();
    void InsertaInicio(Pista);
    void InsertaFinal(Pista);
    bool eliminaPrimero();
    bool eliminaUltimo();
    NodoLista *busqueda(QString);
};

#endif // LISTA_H
