#include "Estructuras.h"

Supervisor::Supervisor(){
    this->colaSupervisores=NULL;
    this->galletasAceptadas=0;
    this->galletasRechazadas=0;
    this->listaPaquetes=NULL;
    this->probabilidadDesecho=0;
}

void Supervisor::setPunteros(ColaBandas *_cola,ListaPaquetes*_listaPaquetes,ColaBandas * _colaEmpacadora){
    this->colaSupervisores=_cola;
    this->listaPaquetes=_listaPaquetes;
    this->colaEmpacadora=_colaEmpacadora;
}

void Supervisor::setProbabilidad(double _probabilidad){
    this->probabilidadDesecho=_probabilidad;
}
void Supervisor::quitarGalletas(NodoBandas * nodo){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> probabilidad(1,99); // distribution in range [1, 99]
    if (probabilidad(rng)<this->probabilidadDesecho){//Si random esta entre 1 y 99
        //Tiene que desechar
        nodo->dato--;
        this->colaSupervisores->actual--;
        this->galletasRechazadas++;
    }
    this->galletasAceptadas+=nodo->dato;//suma la cantidad modificada (o no) del nodo
}
