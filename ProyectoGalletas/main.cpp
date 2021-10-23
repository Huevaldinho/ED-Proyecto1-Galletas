#include "ventanaprincipal.h"
#include "ventanaconfigurar.h"

#include <QApplication>
#include "Estructuras.h"
#include "Punteros.h"
#include "controlador.h"



int main(int argc, char *argv[]){

    srand(time(NULL));
    Punteros*punteros=new Punteros();
    punteros->setPunteros();

    QApplication a(argc, argv);

    VentanaConfigurar b;
    //b.punteros=punteros;
    b.show();

    VentanaPrincipal w=new VentanaPrincipal();
    w.punteros=punteros;
    w.show();

    return a.exec();
}

