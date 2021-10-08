#include "Estructuras.h"

Supervisor::Supervisor(){
    this->colaSupervisores=NULL;
    this->galletasAceptadas=0;
    this->galletasRechazadas=0;
    this->listaPaquetes=NULL;
    this->probabilidadDesecho=0;
}

void Supervisor::setPunteros(ColaBandas *_cola,ListaPaquetes*_listaPaquetes){
    this->colaSupervisores=_cola;
    this->listaPaquetes=_listaPaquetes;
}

void Supervisor::setProbabilidad(double _probabilidad){
    this->probabilidadDesecho=_probabilidad;
}
