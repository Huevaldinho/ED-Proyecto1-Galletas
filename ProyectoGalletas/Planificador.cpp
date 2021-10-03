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
    this->listaPaquetes=lista;
}
double Planificador::calcularCantidadGalletasSolicitadas(){
    /*
        Toma la lista si no es vacia y llama al metodo que le da la cantidad de galletas que hay en la lista.
        (ese metodo revisa todos los nodos multiplica los paquetes por la cantidad de galletas y retorna el total de galletas)
        Luego calcula la cantidad necesaria de masa y chocolate para crear ese total de galletas
        retorna la cantidad de galletas por si  alguien mas necesita saber o algo asi jaja xd

    */
    //Primero calcula la cantidad de galletas que hay que hacer usando la lista de pedidos en la doblemente enlazada
    if (this->listaPaquetes!=NULL){
        this->cantidadSolicitadaGalletas=this->listaPaquetes->getCantidadGalletas();
        this->cantidadNecesariaMasa=cantidadSolicitadaGalletas*this->receta->cantidadMasa;
        this->cantidadNecesariaChocolate=cantidadSolicitadaGalletas*this->receta->cantidadChocolate;
        //qDebug()<<"Cantidad galletas solicitidas: "<<this->calcularCantidadGalletasSolicitadas()<<", cantidad masa necesaria: "<<this->cantidadNecesariaMasa<<", cantidad chocolate necesario: "<<this->cantidadNecesariaChocolate;
    }
    return cantidadSolicitadaGalletas;
};

void Planificador::modificarReceta(double masa, double chocolate){
    //Cambia la cantidad de masa y chocolate
    receta->setCantidadMasa(masa);
    receta->setCantidadChocolate(chocolate);
    //Se tiene que modificar toda la produccion
};

