#include "Estructuras.h"


MaquinaMezclaMasaChocolate::MaquinaMezclaMasaChocolate(){
    this->minimaCapacidad=10;
    this->maximaCapacidad=2000;
    this->tiempoProceso=5;
    this->cantidadProcesada=0;
    this->cantidadEnProceso=0;
    this->capacidadActual=0;
    this->cola = NULL;
    this->estado=true;
}
MaquinaMezclaMasaChocolate::MaquinaMezclaMasaChocolate(int _id,double _minimaCapacidad,double _maximaCapacidad,
                                                       int _tiempoProceso,bool _estado, ColaBandas * _cola,
                                                       Carrito * _carrito, ColaAlmacen * _colaPeticiones){
    this->id=_id;
    this->estado=_estado;
    this->minimaCapacidad=_minimaCapacidad;
    this->maximaCapacidad=_maximaCapacidad;
    this->tiempoProceso=_tiempoProceso;
    this->cantidadProcesada=0;
    this->cantidadEnProceso=0;
    this->capacidadActual=0;
    this->cola=_cola;
    this->carrito=_carrito;
    this->colaPeticiones=_colaPeticiones;
}

void MaquinaMezclaMasaChocolate::setCapacidades(double _minimaCapacidad,double _maximaCapacidad){
    this->minimaCapacidad=_minimaCapacidad;
    this->maximaCapacidad=_maximaCapacidad;
}
double MaquinaMezclaMasaChocolate::pedirMaterial(){//Se pide al almacen directamente
    double pedir=0;
    if (this->capacidadActual<this->minimaCapacidad)
        pedir = this->maximaCapacidad-this->capacidadActual;
    return pedir;
}
void MaquinaMezclaMasaChocolate::setPunteros(ColaBandas * _cola, ColaAlmacen * _colaPeticiones, Carrito * _carrito){
    this->cola=_cola;
    this->colaPeticiones=_colaPeticiones;
    this->carrito=_carrito;
}
//Procesos
void MaquinaMezclaMasaChocolate::procesar(){//El proceso es meter datos a la cola de la banda y disminuir los contadores


}


//Ver cantidades realizadas.
