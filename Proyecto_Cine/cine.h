#ifndef CINE_H
#define CINE_H

#include <QMainWindow>
#include "array"
#include "QDebug"

#include <QMenuBar>
#include <QAction>
#include <QMessageBox>

namespace Ui {
class Cine;
}

class Cine : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cine(QWidget *parent = nullptr);
    ~Cine();

    // METODOS
    QString getNombre();
    void setNombre(QString nombre);
    QString getUbicacion();
    void setUbicacion(QString ubicacion);

private slots:
    //Slots para los elementos de QMenuBar
    void agregarPelicula();
    void agregarClientes();
    void agregarEmpleados();

    //Slots para los botones
/*
    void mostrarPrecios();
    void mostrarHorarios();

    void venderBoletos();
*/

private:
    Ui::Cine *ui;
    // ATRIBUTOS
    QString Nombre;
    QString Ubicacion;
    std::array<int, 4> salas;
};

#endif // CINE_H