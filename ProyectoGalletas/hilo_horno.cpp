#include "hilo_horno.h"

hilo_Horno::hilo_Horno(){
    this->corriendo=false;
}
void hilo_Horno::__init__(Horno * _horno, QLabel * lblBandaActual, QLabel * lblBandaMax, QLabel * lblCantidadBandejasActivas){
    this->corriendo = false;
    this->pausa = false;
    this->horno=_horno;
    this->lbl_BandaTActual=lblBandaActual;
    this->lbl_BandaTMax=lblBandaMax;
    this->lbl_BandejasActivas=lblCantidadBandejasActivas;

}
void hilo_Horno::run(){


}
void hilo_Horno::pause(){
    this->pausa=true;
}
void hilo_Horno::stop(){
    this->corriendo=false;
}
