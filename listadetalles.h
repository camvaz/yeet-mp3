#ifndef LISTADETALLES_H
#define LISTADETALLES_H

#include <QMainWindow>

namespace Ui {
class ListaDetalles;
}

class ListaDetalles : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListaDetalles(QWidget *parent = nullptr);
    ~ListaDetalles();

private:
    Ui::ListaDetalles *ui;
};

#endif // LISTADETALLES_H
