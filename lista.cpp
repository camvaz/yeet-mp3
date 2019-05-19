#include "lista.h"

Lista::Lista()
{
    head = nullptr;
}

NodoLista *Lista::getHead()
{
    return head;
}

void Lista::InsertaInicio(Pista song)
{
    NodoLista *p;
    p = new NodoLista(song);
    p->next = head;
    head = p;
}

void Lista::InsertaFinal(Pista song)
{
    NodoLista *p, *cola;
    p = new NodoLista(song);
    if (head)
    {
       cola = p;
       while (cola->next)
           cola = cola->next;

       cola->next = p;
    }
    else
        head = p;
}

bool Lista::eliminaPrimero()
{
    NodoLista *p;
    bool Resp = 1;
    if (head)
    {
       p = head;
       head = p->next;
       delete (p);
    }
    else
       // La lista está vacía
       Resp = 0;

    return Resp;
}

bool Lista::eliminaUltimo()
{
    NodoLista *Ant, *P;
    bool Resp = 1;
    if (head)
    {
       if (!head->next)
       {
           delete (head);
           head = nullptr;
       }
       else
       {
          P = head;
          while (P->next)
          {
             Ant = P;
             P = P->next;
          }
          Ant->next = nullptr;
          delete (P);
       }
    }
    else
       Resp = 0;

    return Resp;
}

NodoLista *Lista::busqueda(QString nombre, NodoLista *Q)
{
    if (Q)
        if (Q->regresaNombre() == nombre)
            return Q;
        else
            return busqueda(nombre, Q->next);
    else
        return nullptr;
}
