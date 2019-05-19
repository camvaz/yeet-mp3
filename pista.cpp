#include "pista.h"

Pista::Pista()
{

}

Pista::Pista(QString _nombre, qint64 _duracion, QString _autor, QString _imagen, QString _ruta)
            :nombre(_nombre),duracion(_duracion), autor(_autor),imagen(_imagen),ruta(_ruta)
{

}

Pista::Pista(const Pista &copia)
{
    this->nombre = copia.nombre;
    this->duracion = copia.duracion;
    this->autor = copia.autor;
    this->imagen = copia.imagen;
    this->ruta = copia.ruta;
}

void Pista::setObject(QString _nombre, qint64 _duracion, QString _autor, QString _imagen, QString _ruta)
{
    this->nombre = _nombre;
    this->duracion = _duracion;
    this->autor = _autor;
    this->imagen = _imagen;
    this->ruta = _ruta;
}

QString Pista::getNombre()
{
    return this->nombre;
}
