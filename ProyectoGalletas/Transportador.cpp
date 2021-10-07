#include "Estructuras.h"

Transportador::Transportador(){};

Transportador::Transportador(int _maximo,int _tiempoTransporte,string _tipoPaquete){
    this->maximo=_maximo;
    this->tiempoTransporte=_tiempoTransporte;
    this->tipoPaquete=_tipoPaquete;
};

void Transportador::setEmpacadora(MaquinaEmpacadora *_maquina){
    this->maquinaEmpacadora = _maquina;
}
