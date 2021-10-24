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
        while (this->pausa||this->horno->colaSalida->actual>=this->horno->colaSalida->maximaCapacidad){
            sleep(2);
        }
        this->horno->capacidadTotalGalletas();
        while (this->horno->bandejas->totalCapacidadGalletas>this->horno->bandejas->galletasActuales){
            NodoBandeja*tmp=this->horno->bandejas->primeraBandeja;
            int i = 1;
            while (tmp!=NULL){
                while (tmp->actual<tmp->capacidadGalletas){//Mientras la bandeja tenga menos de la capacidad max se llena
                    while (this->horno->colaEntrada->frente==NULL){
                        this->lbl_BandaTActual->setText(QString::number(tmpActual));
                        sleep(3);
                    }
                    double datoFuera =this->horno->colaEntrada->desencolar()->dato;
                    tmp->actual+=datoFuera;
                    tmp->horneadas+=datoFuera;
                    this->lbl_BandaTActual->setText(QString::number(tmp->actual));
                }
                if (tmp->actual>tmp->capacidadGalletas){
                    double excedente = tmp->capacidadGalletas-tmp->actual;
                    if (excedente<0)
                        excedente*=-1;
                    //this->horno->colaEntrada->frente->dato+=excedente;
                    this->horno->colaEntrada->encolar(excedente);
                    tmp->actual-=excedente;
                    tmp->horneadas-=excedente;

                }
                //#, actual, procesadas
                this->tabla->setItem(this->tabla->rowCount()-i,0,new QTableWidgetItem(QString::number(tmp->actual)));
                this->tabla->setItem(this->tabla->rowCount()-i,1,new QTableWidgetItem(QString::number(tmp->horneadas)));
                i++;//numeros de bandeja
                tmpActual=tmp->actual;
                this->lbl_BandaTActual->setText(QString::number(tmpActual));
                tmp=tmp->siguienteBandeja;
            }//actualGalletas, horneadasGalletas, colaSiguienteActual
            sleep(this->horno->duracionHorneado);//se hornean//this->horno->duracionHorneado
            NodoBandeja*moment=this->horno->bandejas->primeraBandeja;
            double totalGalletas=0;
            int j =1;
            while (moment!=NULL){//encolar galletas en supervisores
                totalGalletas+=moment->horneadas;
                this->lbl_BandaTMax->setText(QString::number(totalGalletas));//horneadasGalletas
                this->horno->colaSalida->encolar(moment->actual);
                moment->actual=0;
                this->lbl_BandejasActivas->setText(QString::number(this->horno->colaSalida->actual));//supervisores
                tmpActual=moment->actual;
                this->tabla->setItem(this->tabla->rowCount()-j,0,new QTableWidgetItem(QString::number(moment->actual)));
                this->tabla->setItem(this->tabla->rowCount()-j,1,new QTableWidgetItem(QString::number(moment->horneadas)));

                j++;//numeros de bandeja
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
