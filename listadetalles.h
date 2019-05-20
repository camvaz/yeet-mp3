#ifndef LISTADETALLES_H
#define LISTADETALLES_H

#include <QMainWindow>
#include <QFile>
#include <qtextstream.h>
namespace Ui {
class ListaDetalles;
}

class ListaDetalles : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListaDetalles(QWidget *parent = nullptr);
    ~ListaDetalles();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ListaDetalles *ui;
};

#endif // LISTADETALLES_H
