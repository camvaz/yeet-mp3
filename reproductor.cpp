#include "reproductor.h"
#include "ui_reproductor.h"

Reproductor::Reproductor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reproductor)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

Reproductor::~Reproductor()
{
    delete ui;
}
