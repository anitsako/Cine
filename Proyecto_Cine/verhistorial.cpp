#include "verhistorial.h"
#include "ui_verhistorial.h"

verHistorial::verHistorial(std::vector<Pago* > &vectorPagoRef, std::vector<Venta *> &vectorHistorialRef, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::verHistorial)
    , vectorHistorial(vectorHistorialRef)
    , vectorPago(vectorPagoRef)
{
    ui->setupUi(this);

    //ESTABLECEMOS EL TITULO DE LA VENTANA
    this->setWindowTitle("Historial de ventas");
    // LLAMAMOS AL METODO PARA CARGAR LA HOJA DE ESTILOS
    initstylesheet();

    // CONFIGURAMOS LA TABLA VERCLIENTES PARA 2 COLUMNAS
    ui->tableWidget->setColumnCount(2);

    // DECLARAMOS QSTRINGLIST PARA LAS COLUMNAS

    QStringList encabezados;

    encabezados << "Fecha" << "Monto";

    ui->tableWidget->setHorizontalHeaderLabels(encabezados);
}

verHistorial::~verHistorial()
{
    delete ui;
}

void verHistorial::initstylesheet(){
    QFile style(":/src/stylesheet/stylesheet-ventanas.css");
    bool styleOK = style.open(QFile::ReadOnly);
    qDebug() << "Apertura de archivos: " <<styleOK;
    QString stringEstilo = QString::fromLatin1(style.readAll());
    this->setStyleSheet(stringEstilo);
}





