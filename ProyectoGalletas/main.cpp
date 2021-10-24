#include "ventanaprincipal.h"
#include "ventanaconfigurar.h"

#include <QApplication>
#include "Punteros.h"
#include "controlador.h"



int main(int argc, char *argv[]){

    srand(time(NULL));
    Punteros*punteros=new Punteros();
    punteros->setPunteros();

    punteros->paquetes->setProbabilidades();
    //punteros->paquetes->insertar(16,"tubos",5,1,1,0);

    punteros->maquinaChocolate->cantidadEnviadaABanda=5;
    punteros->supervisor1->probabilidadDesecho=80;
    punteros->supervisor2->probabilidadDesecho=95;

    QApplication a(argc, argv);

    VentanaConfigurar b=new VentanaConfigurar();
    b.punteros=punteros;
    b.show();
    VentanaPrincipal w=new VentanaPrincipal();
    w.punteros=punteros;
    w.show();


    return a.exec();
}

