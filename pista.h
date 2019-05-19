#ifndef PISTA_H
#define PISTA_H
#include <qstring.h>

class Pista
{
    QString nombre;
    qint64 duracion;
    QString autor;
    QString imagen;
    QString ruta;
public:
    Pista();
    Pista(QString, qint64, QString, QString, QString);
    Pista(const Pista&);
    void setObject(QString, qint64, QString, QString, QString);
    friend class NodoLista;
};

#endif // PISTA_H
