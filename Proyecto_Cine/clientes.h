#ifndef CLIENTES_H
#define CLIENTES_H

#include "iostream"
#include <QDialog>
#include "vector"


using namespace std;

namespace Ui {
class Clientes;
}

class Clientes : public QDialog
{
    Q_OBJECT

public:
    explicit Clientes(QWidget *parent = nullptr);
    ~Clientes();


    Clientes (string nombre, string apellido, int dni, int edad, int teléfono, int idCliente);
    int getIDcliente();
    void setIDcliente(int idcliente);
    std::vector<QString> getHistorial();
 //   void agregarHistorial(reserva *Reserva);
    void mostrarHistorial();


private:
    Ui::Clientes *ui;

    int idCliente;
    std::vector<QString> Historial;
//    reserva *Reserva;

};

#endif // CLIENTES_H