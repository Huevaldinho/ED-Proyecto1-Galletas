#include "ventanaprincipal.h"
#include "ventanaconfigurar.h"

#include <QApplication>
#include "Estructuras.h"
#include "Punteros.h"
#include "controlador.h"
#include "peticionesalmacen.h"



int main(int argc, char *argv[]){

    srand(time(NULL));
    Punteros*punteros=new Punteros();
    punteros->setPunteros();

    punteros->paquetes->setProbabilidades();

    punteros->maquinaChocolate->cantidadEnviadaABanda=5;
    punteros->supervisor1->probabilidadDesecho=80;
    punteros->supervisor2->probabilidadDesecho=95;

    QApplication a(argc, argv);

    VentanaConfigurar b;
    b.punteros=punteros;
    b.show();
    VentanaPrincipal w=new VentanaPrincipal();
    w.punteros=punteros;
    w.show();

    return a.exec();
}

