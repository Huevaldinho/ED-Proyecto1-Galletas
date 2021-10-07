#include "Estructuras.h"

MaquinaEmpacadora::MaquinaEmpacadora(){}

void MaquinaEmpacadora::setGalletasAceptadas(Supervisor*supervisorA,Supervisor*supervisorB){
    this->galletasAceptadas=supervisorA->galletasAceptadas+supervisorB->galletasAceptadas;
}
