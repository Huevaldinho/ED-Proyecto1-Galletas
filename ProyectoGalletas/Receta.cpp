#include "Estructuras.h"

Receta::Receta(){
    //Valores por defecto
    this->cantidadMasa=10;
    this->cantidadChocolate=5;
    this->unidad="gramos";
}

Receta::Receta(double _cantidadMasa, double _cantidadChocolate){
    this->cantidadMasa=_cantidadMasa;
    this->cantidadChocolate=_cantidadChocolate;
    this->unidad="gramos";
}
void Receta::setCantidadMasa(double _cantidadMasa){
     this->cantidadMasa=_cantidadMasa;
}
void Receta::setCantidadChocolate(double _cantidadChocolate){
     this->cantidadChocolate=_cantidadChocolate;
}

