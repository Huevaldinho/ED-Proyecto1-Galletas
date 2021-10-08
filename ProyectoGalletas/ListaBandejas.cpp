#include "Estructuras.h"

ListaBandejas::ListaBandejas(){
    this->primeraBandeja = NULL;
    this->cantidadActual=0;
    this->maximoBandejas=6;
}

bool ListaBandejas::estaVacia(){
    return this->primeraBandeja==NULL;
}
void ListaBandejas::insertarAlFinal(NodoBandeja * bandeja){
    if (estaVacia())
        this->primeraBandeja = this->ultimaBandeja =bandeja;
    else{
        this->ultimaBandeja ->siguienteBandeja = bandeja;
        this->ultimaBandeja ->siguienteBandeja->anteriorBandeja = this->ultimaBandeja ;
        this->ultimaBandeja  = this->ultimaBandeja ->siguienteBandeja;
    }
    this->cantidadActual++;
}
NodoBandeja * ListaBandejas::borrarAlFinal(){
    NodoBandeja * borrado = this->ultimaBandeja;
    if (!estaVacia()){
        if (this->primeraBandeja == this->ultimaBandeja)
            this->primeraBandeja = this->ultimaBandeja = NULL;
        else{
            this->ultimaBandeja = this->ultimaBandeja->anteriorBandeja;
            this->ultimaBandeja->siguienteBandeja = NULL;
            borrado->anteriorBandeja = NULL;
        }
        return borrado;
    }
    return borrado;
}
void ListaBandejas::imprimir(){
    NodoBandeja * tmp = this->primeraBandeja;
        while (tmp != NULL){
            tmp->imprimir();
            tmp = tmp->siguienteBandeja;
        }
        cout <<endl;
}
