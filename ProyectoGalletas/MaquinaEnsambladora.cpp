#include "Estructuras.h"


MaquinaEnsambladora::MaquinaEnsambladora(){
    this->entradaChocolate=NULL;
    this->entradaMasa=NULL;
    this->galletasEnProceso=0;
    this->galletasHechas=0;
}
MaquinaEnsambladora::MaquinaEnsambladora(TransportadoraMezcladoraEnsambladora * _entradaMasa,
                                         TransportadoraMezcladoraEnsambladora * _entradaChocolate){//falta la salida

    this->entradaMasa=_entradaMasa;
    this->entradaChocolate=_entradaChocolate;
}
