#include "Estructuras.h"
TransportadoraMezcladoraEnsambladora::TransportadoraMezcladoraEnsambladora(){
    this->id=0;
    this->estado=true;
    this->actual=0;
    this->capacidadMaxima=100;
    this->cola=NULL;
    this->salida=NULL;
}//TAMPOCO PODEMOS USAR EL MISMO MOLDE PARA LAS BANDAS PORQUE RECIBEN PUNTEROS DE DIFERENTES STRUCTS
TransportadoraMezcladoraEnsambladora::TransportadoraMezcladoraEnsambladora(int _id,bool _estado,int _actual,int _capacidadMaxima,
                                                                           ColaBandaT * _cola,MaquinaEmpacadora * _salida){
    this->id=_id;
    this->estado=_estado;
    this->actual=_actual;
    this->capacidadMaxima=_capacidadMaxima;
    this->cola=_cola;
    this->salida=_salida;

}
bool TransportadoraMezcladoraEnsambladora::estaLlena(){
    return this->actual<this->capacidadMaxima;
}
void TransportadoraMezcladoraEnsambladora::setCapacidadMaxima(int _capacidadMaxima){
    this->capacidadMaxima=_capacidadMaxima;
}
void TransportadoraMezcladoraEnsambladora::setEstado(bool _estado){
    this->estado=_estado;
}
void TransportadoraMezcladoraEnsambladora::setSalida(MaquinaEmpacadora * _salida){
    this->salida=_salida;
}
