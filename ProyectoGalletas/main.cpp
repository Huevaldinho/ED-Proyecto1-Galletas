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

    punteros->paquetes->insertar(4,"Paquetito",4,5,1,0);//(cantidaGalletas,nombre,cantidadPaquetes,procesoPaquetes,tiempoProceso)
    punteros->paquetes->insertar(16,"Tubos",1,1,1,0);//(cantidaGalletas,nombre,cantidadPaquetes,procesoPaquetes,tiempoProceso)
    //this->punteros->paquetes->insertar(16,"Paquetes",2,2,1,0);//(cantidaGalletas,nombre,cantidadPaquetes,procesoPaquetes,tiempoProceso)
    //this->punteros->paquetes->insertar(16,"Tubos",3);
    //this->punteros->paquetes->insertar(10,"Paquetes",5);

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

