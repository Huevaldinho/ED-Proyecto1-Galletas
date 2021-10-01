#ifndef VENTANAMODIFICAR_H
#define VENTANAMODIFICAR_H

#include <QDialog>

namespace Ui {
class Ventana_AgregarPaquete;
}

class Ventana_AgregarPaquete : public QDialog
{
    Q_OBJECT

public:
    explicit Ventana_AgregarPaquete(QWidget *parent = nullptr);
    ~Ventana_AgregarPaquete();

private:
    Ui::Ventana_AgregarPaquete *ui;
};

#endif // VENTANAMODIFICAR_H
