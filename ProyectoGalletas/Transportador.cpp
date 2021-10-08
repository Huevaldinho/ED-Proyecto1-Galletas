#include "Estructuras.h"

Transportador::Transportador(){}

Transportador::Transportador(int _maximo,int _tiempoTransporte,int _actuales,string _tipoPaquete){
    this->maximo=_maximo;
    this->tiempoTransporte=_tiempoTransporte;
    this->tipoPaquete=_tipoPaquete;
    this->actuales=_actuales;
};
void Transportador::setActual(int actual){

    this->actuales=actual;
}

