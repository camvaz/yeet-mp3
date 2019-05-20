#ifndef PISTA_H
#define PISTA_H
#include <qstring.h>

class Pista
{
    QString nombre;
    QString duracion;
    QString autor;
    QString imagen;
    QString ruta;
public:
    Pista();
    Pista(QString, QString, QString, QString, QString);
    Pista(const Pista&);
    void setObject(QString, QString, QString, QString, QString);
    QString getNombre();
    QString getDuracion();
    QString getAutor();
    QString getImagen();
    QString getRuta();
    QString toString();
};

#endif // PISTA_H
