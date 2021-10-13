#include "ventanaprincipal.h"
#include "ventanaconfigurar.h"

#include <QApplication>
#include "Estructuras.h"
#include "Punteros.h"
#include "controlador.h"



int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    //VentanaConfigurar b;
    //b.show();
    VentanaPrincipal w;
    w.show();

    Punteros * punteros = new Punteros();
    Controlador * control = new Controlador(punteros);

    control->iniciarHiloPlanificador();



    return a.exec();
}

