#include "Estructuras.h"

Horno::Horno(){
    this->bandejasFuncionando=2;
    this->maximoBandejas=6;
    this->capacidadBandeja=20;
    this->colaEntrada=NULL;
    this->colaSalida=NULL;
    this->estado=true;
}
void Horno::HornearGalletas(){}
