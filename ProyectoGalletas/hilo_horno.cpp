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
    this->corriendo=true;
    while (this->corriendo){//estaba como while true
        this->horno->capacidadTotalGalletas();
        //qDebug()<<"\n\n\nLA CANTIDAD DE BANDEJAS ES DE: "<<this->horno->bandejasFuncionando;
        while (this->horno->bandejas->totalCapacidadGalletas>this->horno->bandejas->galletasActuales){
            NodoBandeja*tmp=this->horno->bandejas->primeraBandeja;
            while (tmp!=NULL){
                while (tmp->actual<tmp->capacidadGalletas){
                    double datoFuera =this->horno->colaEntrada->desencolar()->dato;
                    tmp->actual+=datoFuera;
                    tmp->horneadas+=datoFuera;
                    this->lbl_BandaTActual->setText(QString::number(tmp->actual));
                }
                if (tmp->actual>tmp->capacidadGalletas){
                    double excedente = tmp->capacidadGalletas-tmp->actual;
                    this->horno->colaEntrada->frente->dato+=excedente;
                    tmp->actual-=excedente;
                    tmp->horneadas-=excedente;
                }
                tmp=tmp->siguienteBandeja;
            }
            sleep(this->horno->duracionHorneado);//se hornean
            NodoBandeja*moment=this->horno->bandejas->primeraBandeja;
            double totalGalletas=0;
            while (moment!=NULL){
                totalGalletas+=moment->horneadas;
                this->lbl_BandaTMax->setText(QString::number(totalGalletas));
                this->horno->colaSalida->encolar(moment->actual);
                moment->actual=0;
                this->lbl_BandejasActivas->setText(QString::number(totalGalletas));
                moment=moment->siguienteBandeja;
            }//Este if no estaba es para probar
            if (this->corriendo==false){
                break;
            }
        }
    }
    qDebug()<<"DETENER HILO HORNO";

}
void hilo_Horno::pause(){
    this->pausa=true;
}
void hilo_Horno::stop(){
    this->corriendo=false;
}
