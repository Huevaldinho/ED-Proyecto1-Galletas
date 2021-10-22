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
    srand(time(0));
    int probabilidad = 1 + rand() % 100; 	// Genera un valor entre 1 y 100
    if (probabilidad<this->probabilidadDesecho){//Si random esta entre 1 y 99
        //Tiene que desechar
        nodo->dato--;
        this->colaSupervisores->actual--;
        this->galletasRechazadas++;
    }
    this->galletasAceptadas+=nodo->dato;//suma la cantidad modificada (o no) del nodo
}
