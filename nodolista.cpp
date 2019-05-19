#include "nodolista.h"

NodoLista::NodoLista()
{
    next = nullptr;
}

NodoLista::NodoLista(const Pista &_song):song(_song)
{

}

QString NodoLista::regresaNombre()
{
    return song.getNombre();
}
