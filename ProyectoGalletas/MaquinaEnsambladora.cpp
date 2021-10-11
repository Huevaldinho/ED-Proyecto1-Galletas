#include "Estructuras.h"

MaquinaEnsambladora::MaquinaEnsambladora(){
    this->galletasEnProceso=0;
    this->galletasHechas=0;
    this->estado=false;
    this->colaEntradaChocolate=NULL;
    this->colaEntradaMasa=NULL;
    this->colaSalida=NULL;
}

void MaquinaEnsambladora::setEstado(bool _estado){
    this->estado=_estado;
}
void MaquinaEnsambladora::setPunteros(ColaBandas *_colaEntradaChocolate,ColaBandas *_colaEntradaMasa,ColaBandas *_colaSalida){
    this->galletasEnProceso=0;
    this->galletasHechas=0;
    this->colaEntradaChocolate=_colaEntradaChocolate;
    this->colaEntradaMasa=_colaEntradaMasa;
    this->colaSalida=_colaSalida;
}

//Proceso
