#include "ventanaprincipal.h"
#include "ventanaconfigurar.h"

#include <QApplication>

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    VentanaConfigurar config;//primero se tiene que ejecutar la configuracion
    config.show();
    VentanaPrincipal w;
    w.show();
    return a.exec();

}
