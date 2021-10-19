#include "hilo_maquinaensambladora.h"

hilo_MaquinaEnsambladora::hilo_MaquinaEnsambladora(){
    this->corriendo=false;
}


void hilo_MaquinaEnsambladora::__init__(MaquinaEnsambladora * maquina,QLabel * lbl_totalProducida,QLabel *lblBandaActual,QLabel * lblBandaMax){
    this->corriendo = false;
    this->pausa = false;
    this->maquinaEnsambladora=maquina;
    this->lbl_totalProduccion=lbl_totalProducida;
    this->lbl_BandaTActual=lblBandaActual;
    this->lbl_BandaTProcesada=lblBandaMax;
}
void hilo_MaquinaEnsambladora::run(){
    sleep(10);
    double cantidadGalletas=0;
    while(true){
        while (this->maquinaEnsambladora->galletasHechas<this->maquinaEnsambladora->galletasAProcesar){
            //Desencolar y aumentar galletas
            for (int i=0;i<this->maquinaEnsambladora->produceNGalletas;i++){
                while (this->maquinaEnsambladora->colaEntradaMasa->frente==NULL || this->maquinaEnsambladora->colaEntradaChocolate->frente==NULL){
                    qDebug()<<"Hilo esambladora dormido";
                    this->lbl_totalProduccion->setText(QString::number(this->maquinaEnsambladora->galletasHechas));
                    sleep(2);
                }
                cantidadGalletas++;
                this->maquinaEnsambladora->colaEntradaMasa->desencolar();
                this->maquinaEnsambladora->colaEntradaChocolate->desencolar();
                this->maquinaEnsambladora->galletasHechas++;
                if (this->maquinaEnsambladora->galletasAProcesar==this->maquinaEnsambladora->galletasHechas)
                    break;
            }
            this->maquinaEnsambladora->colaSalida->encolar(cantidadGalletas);
            this->lbl_BandaTProcesada->setText(QString::number(this->maquinaEnsambladora->colaSalida->maximaCapacidad));
            this->lbl_totalProduccion->setText(QString::number(this->maquinaEnsambladora->galletasHechas));
            this->lbl_BandaTActual->setText(QString::number(this->maquinaEnsambladora->colaSalida->actual));

            cantidadGalletas=0;
            sleep(this->maquinaEnsambladora->duracion);
            while (this->maquinaEnsambladora->colaSalida->maximaCapacidad==this->maquinaEnsambladora->colaSalida->actual){
                qDebug()<<"La Cola de ensambladora horno esta llena, ensambladora dormida";
                sleep(5);
            }
        }
        qDebug()<<"Termina ciclo hilo ensambladora";
        this->maquinaEnsambladora->colaSalida->imprimir();//16 galletas ak15+1
        sleep(5);


    }

}
void hilo_MaquinaEnsambladora::pause(){
    this->pausa=true;
}
void hilo_MaquinaEnsambladora::stop(){
    this->corriendo=false;
}
void hilo_MaquinaEnsambladora::resume(){
    this->pausa=false;
}

