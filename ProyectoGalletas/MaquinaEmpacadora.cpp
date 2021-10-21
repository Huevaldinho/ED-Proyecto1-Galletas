#include "Estructuras.h"

MaquinaEmpacadora::MaquinaEmpacadora(){
    this->cantidadActual=0;
    this->cantidadDePaquetes=0;
    this->galletasAceptadas=0;
    this->tiempoEmpaque=2;
    this->estado=false;
    this->cola= NULL;//cola que recibe nodos de supervisores

}
void MaquinaEmpacadora::setPunteros(ColaBandas * colaBanda, ListaPaquetes * listaPaquetes){
    this->cola = colaBanda;
    this->paquetes=listaPaquetes;

}
