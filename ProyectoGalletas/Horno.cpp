#include "Estructuras.h"

Horno::Horno(){
    this->bandejasFuncionando=this->bandejas->contarBandejas();
    this->maximoBandejas=6;
    this->colaEntrada=NULL;
    this->colaSalida=NULL;
    this->estado=false;
}
void Horno::setPunteros(ListaBandejas * _bandejas, ColaBandas * colaIN, ColaBandas *ColaOUT){
    this->bandejas=_bandejas;
    this->colaEntrada=colaIN;
    this->colaSalida=ColaOUT;

}
void Horno::capacidadTotalGalletas(){
    this->bandejas->totalCapacidad();
}
