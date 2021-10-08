#include "Estructuras.h"

MaquinaEmpacadora::MaquinaEmpacadora(){
    this->cantidadActual=0;
    this->cantidadDePaquetes=0;
    this->galletasAceptadas=0;
    this->paqueteActual=NULL;
    this->tiempoEmpaque=2;
}

void MaquinaEmpacadora::setGalletasAceptadas(Supervisor*supervisorA,Supervisor*supervisorB){
    this->galletasAceptadas=supervisorA->galletasAceptadas+supervisorB->galletasAceptadas;
}
