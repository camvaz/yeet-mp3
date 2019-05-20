#include "lista.h"

Lista::Lista()
{
    head = nullptr;
    iteradorPlaylist = head;
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
    p->next = nullptr;
    if (head)
    {
       cola = head;
       while (cola->next){
           cola = cola->next;
        }
       cola->next = p;
    }
    else{
        head = p;
    }
}

void Lista::escribe()
{
    QFile archivo("lista.txt");

    if(!archivo.open(QFile::ReadWrite | QFile::Text))
        return;
    else{
        uint32_t i =1;
        QTextStream toSave(&archivo);
        NodoLista *aux = head;
        while(aux){
            toSave << "============= Pista " << QString::number(i) << " =============\n" << aux->regresaPista().toString();
            aux = aux->next;
            ++i;
        }
        toSave.flush();
        archivo.close();
    }
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

void Lista::setIterator(NodoLista *aux)
{
    iteradorPlaylist = aux;
}

void Lista::reproducirOrden(QMediaPlayer *player)
{
    if(head){

        NodoLista *aux = head;
        player->setMedia(QUrl::fromLocalFile(aux->regresaPista().getRuta()));
        player->play();
        while(aux->next && player->state() == QMediaPlayer::StoppedState){
            aux = aux->next;
            player->setMedia(QUrl::fromLocalFile(aux->regresaPista().getRuta()));
            player->play();
        }

    } else {

    }
}

NodoLista *Lista::iteratorRight()
{
    if(head){
        if(iteradorPlaylist){
            if(iteradorPlaylist->next){
                iteradorPlaylist = iteradorPlaylist->next;
                return iteradorPlaylist;
            }else {
                iteradorPlaylist = head;
                return head;
            }
        } else {
            return nullptr;
        }
    } else{
        return nullptr;
    }
}

NodoLista *Lista::iteratorLeft()
{
    if(head){
        NodoLista *aux;
        aux = head;
        while(aux->next && aux->next->regresaNombre()!=iteradorPlaylist->regresaNombre()){
            aux = aux->next;
        }
        iteradorPlaylist = aux;
        return aux;
    } else {
        return nullptr;
    }
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

NodoLista *Lista::returnIterador()
{
    if(head){
        if(iteradorPlaylist->next)
        {
            iteradorPlaylist = iteradorPlaylist->next;
            return iteradorPlaylist->next;

        } else {
            iteradorPlaylist = head;
            return iteradorPlaylist;
        }
    } else {
        return nullptr;
    }
}
