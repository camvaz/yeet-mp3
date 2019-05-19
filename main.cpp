#include "reproductor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Reproductor w;
    w.show();

    return a.exec();
}
