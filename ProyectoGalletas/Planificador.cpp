#include "Estructuras.h"

#include <QDebug>
Planificador::Planificador(){
    this->listaPaquetes=NULL;
    this->receta = new Receta();
    this->cantidadSolicitadaGalletas=0;
}
void Planificador::leerListaPaquetes(ListaPaquetes * lista){
    /*
        Recibe de controlador un puntero a una lista de paquetes creados (cada paquete tiene una cantidad de galletas,
        nombre del paquete y cantidad de paquetes de ese tipo). (4,"Paquetitos",100)

    */
    this->listaPaquetes=lista;//Supongamos que se crea la lista en el controlador
}
double Planificador::calcularCantidadGalletasSolicitadas(){
    /*
        Toma la lista si no es vacia y llama al metodo que le da la cantidad de galletas que hay en la lista.
        (ese metodo revisa todos los nodos multiplica los paquetes por la cantidad de galletas y retorna el total de galletas)
        Luego calcula la cantidad necesaria de masa y chocolate para crear ese total de galletas
        retorna la cantidad de galletas por si  alguien mas necesita saber o algo asi jaja xd

        Cada vez que se ingrese un pedido nuevo a la lista debe recalcular la cantidad necesaria de materiales

    */
    //Pide la cantidad de galletas a la lista
    if (this->listaPaquetes!=NULL){
        this->cantidadSolicitadaGalletas=this->listaPaquetes->getCantidadGalletas();
        this->cantidadNecesariaMasa=cantidadSolicitadaGalletas*this->receta->cantidadMasa;
        this->cantidadNecesariaChocolate=cantidadSolicitadaGalletas*this->receta->cantidadChocolate;
    }
    return cantidadSolicitadaGalletas;
};

void Planificador::modificarReceta(double masa, double chocolate){
    //Cambia la cantidad de masa y chocolate
    receta->setCantidadMasa(masa);
    receta->setCantidadChocolate(chocolate);
    //Se tiene que modificar toda la produccion
};

