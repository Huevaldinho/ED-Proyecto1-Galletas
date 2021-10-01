#ifndef VENTANACONFIGURAR_H
#define VENTANACONFIGURAR_H

#include <QMainWindow>

namespace Ui {
class VentanaConfigurar;
}

class VentanaConfigurar : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaConfigurar(QWidget *parent = nullptr);
    ~VentanaConfigurar();

private:
    Ui::VentanaConfigurar *ui;
};

#endif // VENTANACONFIGURAR_H
