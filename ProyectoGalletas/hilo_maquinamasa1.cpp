#include "hilo_maquinamasa1.h"

hilo_maquinaMasa1::hilo_maquinaMasa1(){
    this->corriendo=false;
}
void hilo_maquinaMasa1::__init__(MaquinaMezclaMasaChocolate * maquina,QLabel * lbl_producido,QLabel * lbl_enProceso){
    this->corriendo = false;
    this->pausa = false;
    this->maquinaMasa1=maquina;
    this->lbl_totalProduccion=lbl_producido;
    this->lbl_cantidadActual=lbl_enProceso;
}
void hilo_maquinaMasa1::run(){
    qDebug()<<"Entra hilo maquina1";
    qDebug()<<"Procesada: "<<this->maquinaMasa1->cantidadProcesada;
    qDebug()<<"A procesar: "<<this->maquinaMasa1->cantidadAProcesar;
    sleep(2);
    bool yaEncole=false;
    while(this->maquinaMasa1->cantidadProcesada<this->maquinaMasa1->cantidadAProcesar){
        qDebug()<<"Corre el hilo masa ";
        while ((this->maquinaMasa1->cola->actual >= this->maquinaMasa1->cola->maximaCapacidad) || (this->maquinaMasa1->capacidadActual<this->maquinaMasa1->minimaCapacidad)){
            qDebug()<<"Dormido hilo masa";
            double pedir= this->maquinaMasa1->pedirMaterial();//max capacidad - capacidad actual -> llego al maximo
            if(yaEncole==false){//Encola si pedir es diferente de !=0
                if (pedir!=0){
                    this->maquinaMasa1->colaPeticiones->encolar(pedir,this->maquinaMasa1->id);//cantidad soli, id maquina
                    yaEncole=true;
                    qDebug()<<"Maquina 1 encolo";
                }
            }
            this->lbl_cantidadActual->setText(QString::number(this->maquinaMasa1->capacidadActual));//GUI
            this->lbl_totalProduccion->setText(QString::number(this->maquinaMasa1->cantidadProcesada));//GUI
            sleep(1);
        }
        yaEncole=false;
        this->maquinaMasa1->cola->encolar(this->maquinaMasa1->cantidadEnviadaABanda);//enviar a la banda
        this->maquinaMasa1->cantidadProcesada+=this->maquinaMasa1->cantidadEnviadaABanda;//Suma al total de procesamiento
        this->maquinaMasa1->capacidadActual-=this->maquinaMasa1->cantidadEnviadaABanda;//Resta lo que proceso al actual
        sleep(this->maquinaMasa1->tiempoProceso);//lo que dura procesando xd
    }
}
void hilo_maquinaMasa1::pause(){
    this->pausa=true;
}
void hilo_maquinaMasa1::stop(){
    this->corriendo=false;
}
void hilo_maquinaMasa1::resume(){
    this->pausa=false;
}



