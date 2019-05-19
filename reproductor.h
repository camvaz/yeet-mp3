#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

#include <QMainWindow>

namespace Ui {
class Reproductor;
}

class Reproductor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Reproductor(QWidget *parent = nullptr);
    ~Reproductor();

private:
    Ui::Reproductor *ui;
};

#endif // REPRODUCTOR_H
