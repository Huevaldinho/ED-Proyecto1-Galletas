#include "Estructuras.h"


Almacen::Almacen(){
    this->carrito = NULL;
    this->colaPeticiones=NULL;
    this->peticionesProcesadas=0;
    this->peticionesActuales=0;
}
Almacen::Almacen(ColaAlmacen * _colaPeticiones){
    this->colaPeticiones=_colaPeticiones;


}
double Almacen::darCantidades(double _solicitud){
    return _solicitud;

}
void Almacen::setCarrito(Carrito * carro){
    this->carrito=carro;
}
void Almacen::setColaPeticiones(ColaAlmacen * _colaPeticiones){
    this->colaPeticiones=_colaPeticiones;
}
double Almacen::verPeticiones(){
   //Masa


   //Chocolate

}//ver peticiones en cola pendientes y las que ha procesado
