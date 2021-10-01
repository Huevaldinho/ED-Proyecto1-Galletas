#ifndef VENTANCONFIGURAR_H
#define VENTANCONFIGURAR_H

#include <QMainWindow>

namespace Ui {
class VentanConfigurar;
}

class VentanConfigurar : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanConfigurar(QWidget *parent = nullptr);
    ~VentanConfigurar();

private:
    Ui::VentanConfigurar *ui;
};

#endif // VENTANCONFIGURAR_H
