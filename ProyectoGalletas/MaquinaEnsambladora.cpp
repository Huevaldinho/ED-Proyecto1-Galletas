#include "Estructuras.h"

MaquinaEnsambladora::MaquinaEnsambladora(){
    this->galletasEnProceso=0;
    this->galletasHechas=0;
    this->galletasAProcesar=0;
    this->estado=false;
    this->colaEntradaChocolate=NULL;
    this->colaEntradaMasa=NULL;
    this->colaSalida=NULL;
    this->receta=NULL;
    this->duracion=2;
    this->produceNGalletas=5;
}

void MaquinaEnsambladora::setEstado(bool _estado){
    this->estado=_estado;
}
void MaquinaEnsambladora::setPunteros(ColaBandas *_colaEntradaChocolate,ColaBandas *_colaEntradaMasa,ColaBandas *_colaSalida,Receta * _receta){
    this->galletasEnProceso=0;
    this->galletasHechas=0;
    this->colaEntradaChocolate=_colaEntradaChocolate;
    this->colaEntradaMasa=_colaEntradaMasa;
    this->colaSalida=_colaSalida;
    this->receta=_receta;
}

//Proceso
