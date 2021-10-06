#include "Estructuras.h"

MaquinaEnsambladora::MaquinaEnsambladora(){
    this->galletasEnProceso=0;
    this->galletasHechas=0;
    this->estado=true;
    this->colaEntradaChocolate=NULL;
    this->colaEntradaMasa=NULL;
    this->colaSalida=NULL;
}
MaquinaEnsambladora::MaquinaEnsambladora(ColaBandas * _colaEntradaMasa,ColaBandas * _colaEntradaChocolate, ColaBandas * _colaSalida){
    this->galletasEnProceso=0;
    this->galletasHechas=0;
    this->colaEntradaChocolate=_colaEntradaChocolate;
    this->colaEntradaMasa=_colaEntradaMasa;
    this->colaSalida=_colaSalida;
}
void MaquinaEnsambladora::setEstado(bool _estado){
    this->estado=_estado;
}

//Proceso
