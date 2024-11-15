#include "verempleados.h"
#include "ui_verempleados.h"

VerEmpleados::VerEmpleados(std::vector<Empleados *> &vectorEmpleadosRef, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VerEmpleados)
    , vectorEmpleados(vectorEmpleadosRef)
{
    ui->setupUi(this);

    //Establecemos el titulo de la ventana
    this->setWindowTitle("Tabla de empleados");

    //Llamamos al slot para cargar el stylesheet
    initstylesheet();

    // CONFIGURAMOS LA TABLA VERCLIENTES PARA 6 COLUMNAS
      ui->tableWidget->setColumnCount(6);

    // DECLARAMOS QSTRINGLIST PARA LAS COLUMNAS

    QStringList encabezados;

    encabezados << "IDempleado" << "Nombre" << "Apellido" << "Dni" << "Edad" << "Telefono";

    ui->tableWidget->setHorizontalHeaderLabels(encabezados);


}

VerEmpleados::~VerEmpleados()
{
    delete ui;
}

void VerEmpleados::actualizarTablaEmpleados(std::vector<Empleados *> &vectorEmpleados){
    ui->tableWidget->setRowCount(vectorEmpleados.size());

    for(int i = 0; i < vectorEmpleados.size(); i++){
        Empleados *empleado = vectorEmpleados[i];

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(empleado->getIDempleado())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(empleado->getNombre()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(empleado->getApellido()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(empleado->getDni())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(empleado->getEdad())));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(empleado->getTelefono())));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(empleado->getPuesto()));

    }
}

void VerEmpleados::initstylesheet()
{
    QFile style(":/src/stylesheet/stylesheet-ventanas.css");
    bool styleOK = style.open(QFile::ReadOnly);
    qDebug() << "Apertura de archivos: " <<styleOK;
    QString stringEstilo = QString::fromLatin1(style.readAll());
    this->setStyleSheet(stringEstilo);
}



void VerEmpleados::on_Boton_cerrar_clicked()
{
    accept(); // METODO CREADO POR SI EL USUARIO PRESIONA CERRAR, SE CIERRA
}

