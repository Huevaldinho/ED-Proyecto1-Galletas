#include "ventanaprincipal.h"
#include "ventanaconfigurar.h"

#include <QApplication>
#include "Estructuras.h"
#include "Punteros.h"
#include "controlador.h"



int main(int argc, char *argv[]){
    srand(time(NULL));
    QApplication a(argc, argv);
    VentanaConfigurar b;
    b.show();
    VentanaPrincipal w=new VentanaPrincipal();
    w.show();




    return a.exec();
}

