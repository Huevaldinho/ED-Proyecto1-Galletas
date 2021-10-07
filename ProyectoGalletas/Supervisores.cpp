#include "Estructuras.h"

Supervisor::Supervisor(){}

void Supervisor::setPunteros(ColaBandas *_cola,ListaPaquetes*_listaPaquetes){
    this->colaSupervisores=_cola;
    this->listaPaquetes=_listaPaquetes;
}

void Supervisor::setProbabilidad(double _probabilidad){
    this->probabilidadDesecho=_probabilidad;
}
