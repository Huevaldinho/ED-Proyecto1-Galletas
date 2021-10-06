#include "Estructuras.h"

ListaBandejas::ListaBandejas(){
    this->primeraBandeja = NULL;
    this->cantidadActual=2;
    this->maximoBandejas=6;
}

bool ListaBandejas::estaVacia(){
    return this->primeraBandeja==NULL;
}
void ListaBandejas::insertarAlFinal(int _galletas){

}
NodoBandeja * ListaBandejas::borrarAlFinal(){
    return NULL;
}
void ListaBandejas::imprimir(){
    NodoBandeja * tmp = this->primeraBandeja;
        while (tmp != NULL){
            tmp->imprimir();
            tmp = tmp->siguienteBandeja;
        }
        cout <<endl;
}
