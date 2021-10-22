#include "hilo_horno.h"

hilo_Horno::hilo_Horno(){
    this->corriendo=false;
}
void hilo_Horno::__init__(Horno * _horno, QLabel * lblBandaActual, QLabel * lblBandaMax, QLabel * lblCantidadBandejasActivas){
    this->corriendo = false;
    this->pausa = false;
    this->horno=_horno;
    this->lbl_BandaTActual=lblBandaActual;//actual galletas horno
    this->lbl_BandaTMax=lblBandaMax;//horneadasGalletas
    this->lbl_BandejasActivas=lblCantidadBandejasActivas;//supervisores

}
void hilo_Horno::run(){
    this->corriendo=true;
    double tmpActual=0;
    while (this->corriendo){//estaba como while true
        this->horno->capacidadTotalGalletas();
        //qDebug()<<"\n\n\nLA CANTIDAD DE BANDEJAS ES DE: "<<this->horno->bandejasFuncionando;
        while (this->horno->bandejas->totalCapacidadGalletas>this->horno->bandejas->galletasActuales){
            NodoBandeja*tmp=this->horno->bandejas->primeraBandeja;
            while (tmp!=NULL){
                while (tmp->actual<tmp->capacidadGalletas){
                    while (this->horno->colaEntrada->frente==NULL){
                        qDebug()<<"Pausa horno porque frente cola es NULL";
                        this->lbl_BandaTActual->setText(QString::number(tmpActual));
                        sleep(3);
                    }
                    double datoFuera =this->horno->colaEntrada->desencolar()->dato;
                    qDebug()<<"DatoFuera:  "<<datoFuera;
                    tmp->actual+=datoFuera;
                    qDebug()<<"tmp->actual: "<<tmp->actual;
                    tmp->horneadas+=datoFuera;
                    qDebug()<<"tmp->horneadas: "<<tmp->horneadas;
                    this->lbl_BandaTActual->setText(QString::number(tmp->actual));
                }
                qDebug()<<"Antes if";
                if (tmp->actual>tmp->capacidadGalletas){
                    double excedente = tmp->capacidadGalletas-tmp->actual;
                    qDebug()<<"Excedente: "<<excedente;
                    if (excedente<0)
                        excedente*=-1;
                    //this->horno->colaEntrada->frente->dato+=excedente;
                    this->horno->colaEntrada->encolar(excedente);
                    tmp->actual-=excedente;
                    tmp->horneadas-=excedente;

                }
                tmpActual=tmp->actual;
                this->lbl_BandaTActual->setText(QString::number(tmpActual));
                tmp=tmp->siguienteBandeja;
            }//actualGalletas, horneadasGalletas, colaSiguienteActual
            sleep(this->horno->duracionHorneado);//se hornean//this->horno->duracionHorneado
            NodoBandeja*moment=this->horno->bandejas->primeraBandeja;
            double totalGalletas=0;
            qDebug()<<"ANTES DE MOMENT";
            while (moment!=NULL){//encolar galletas en supervisores
                totalGalletas+=moment->horneadas;
                this->lbl_BandaTMax->setText(QString::number(totalGalletas));//horneadasGalletas
                this->horno->colaSalida->encolar(moment->actual);
                moment->actual=0;
                this->lbl_BandejasActivas->setText(QString::number(this->horno->colaSalida->actual));//supervisores
                tmpActual=moment->actual;
                moment=moment->siguienteBandeja;
                this->lbl_BandaTActual->setText(QString::number(tmpActual));//nuevo
            }//Este if no estaba es para probar
            this->lbl_BandaTActual->setText(QString::number(tmpActual));
            if (this->corriendo==false){
                break;
            }  
        }
        this->lbl_BandejasActivas->setText(QString::number(this->horno->colaSalida->actual));//supervisores
    }
    qDebug()<<"DETENER HILO HORNO";

}
void hilo_Horno::pause(){
    this->pausa=true;
}
void hilo_Horno::stop(){
    this->corriendo=false;
}
