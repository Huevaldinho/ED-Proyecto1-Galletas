#include "Estructuras.h"


Almacen::Almacen(){
    this->carrito = NULL;
    this->colaPeticiones=NULL;
    this->peticionesProcesadas=0;
    this->peticionesActuales=0;
}
Almacen::Almacen(double capacidadTransporteCarritoMasa,
                 double capacidadTransporteCarritoChocolate,
                 int duracionCarrito,ColaAlmacen * _colaPeticiones){
    this->colaPeticiones=_colaPeticiones;
    this->carrito = new Carrito(capacidadTransporteCarritoMasa,capacidadTransporteCarritoChocolate,duracionCarrito,true);
}
double Almacen::darCantidades(double _solicitud){
    return _solicitud;

}
void Almacen::setColaPeticiones(ColaAlmacen * _colaPeticiones){
    this->colaPeticiones=_colaPeticiones;
}
double Almacen::verPeticiones(){
   //Masa


   //Chocolate

}//ver peticiones en cola pendientes y las que ha procesado
