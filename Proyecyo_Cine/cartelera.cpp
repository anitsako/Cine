#include "cartelera.h"
#include "ui_cartelera.h"

Cartelera::Cartelera(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cartelera)
{
    ui->setupUi(this);
}

Cartelera::~Cartelera()
{
    delete ui;
}
