#include "Estructuras.h"

Carrito::Carrito(){
     this->capacidadTransporteMezcla=10;
     this->capacidadTransporteChocolate=5;
     this->duracion=1;
     this->estado=false;
}
Carrito::Carrito(double _capacidadTransporteMezcla,double _capacidadTransporteChocolate,int _duracion, bool _estado){
     this->capacidadTransporteMezcla=_capacidadTransporteMezcla;
     this->capacidadTransporteChocolate=_capacidadTransporteChocolate;
     this->duracion=_duracion;
     this->estado=_estado;
}
void Carrito::setEstado(bool _estado){
     this->estado=_estado;
}
void Carrito::setCapacidades(double _capacidadTransporteMezcla,double _capacidadTransporteChocolate){
     this->capacidadTransporteMezcla=_capacidadTransporteMezcla;
        this->capacidadTransporteChocolate=_capacidadTransporteChocolate;
}
void Carrito::setCapacidadTransporteMezcla(double _capacidadTransporteMezcla){
     this->capacidadTransporteMezcla=_capacidadTransporteMezcla;
}
void Carrito::setCapacidadTransporteChocolate(double _capacidadTransporteChocolate){
     this->capacidadTransporteChocolate=_capacidadTransporteChocolate;
}
void Carrito::setPunteros(ColaAlmacen * _colaAlmacen, MaquinaMezclaMasaChocolate * _maquinaMasa1,
                          MaquinaMezclaMasaChocolate * _maquinaMasa2, MaquinaMezclaMasaChocolate * _maquinaChocolate){
    this->cola=_colaAlmacen;
    this->maquinaMasa1=_maquinaMasa1;
    this->maquinaMasa2=_maquinaMasa2;
}
