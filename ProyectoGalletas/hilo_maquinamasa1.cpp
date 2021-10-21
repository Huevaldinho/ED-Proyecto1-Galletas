#include "hilo_maquinamasa1.h"

hilo_maquinaMasa1::hilo_maquinaMasa1(){
    this->corriendo=false;
}
void hilo_maquinaMasa1::__init__(MaquinaMezclaMasaChocolate * maquina,QLabel * lbl_producido,QLabel * lbl_enProceso, QLabel * lbl_ColaEnProce,QLabel * lbl_ColaMax){
    this->corriendo = false;
    this->pausa = false;
    this->maquinaMasa1=maquina;
    this->lbl_totalProduccion=lbl_producido;
    this->lbl_cantidadActual=lbl_enProceso;
    this->lbl_BandaTActual= lbl_ColaEnProce;
    this->lbl_BandaTProcesada=lbl_ColaMax;
}
void hilo_maquinaMasa1::run(){
    this->corriendo=true;
    qDebug()<<"Entra hilo "<<this->maquinaMasa1->id;
    qDebug()<<"Procesada "<<this->maquinaMasa1->id<<": "<<this->maquinaMasa1->cantidadProcesada;
    qDebug()<<"A procesar por "<<this->maquinaMasa1->id<<": "<<this->maquinaMasa1->cantidadAProcesar;
    sleep(2);
    bool yaEncole=false;
    qDebug()<<"A PEDIR MAQUINA "<<this->maquinaMasa1->id<<": "<<this->maquinaMasa1->maximaCapacidad-this->maquinaMasa1->capacidadActual;
    while(this->corriendo){
        while(this->maquinaMasa1->cantidadProcesada<this->maquinaMasa1->cantidadAProcesar){
            while (this->pausa){
                qDebug()<<"Pausa manual de maquina: "<<this->maquinaMasa1->id;
                if (this->corriendo==false)
                    break;
                sleep(3);
            }
            //Se pone en pausa
            this->lbl_BandaTProcesada->setText(QString::number(this->maquinaMasa1->cola->maximaCapacidad));//Set cantidad actual de banda GUI
            while ((this->maquinaMasa1->cola->actual >= this->maquinaMasa1->cola->maximaCapacidad) || (this->maquinaMasa1->capacidadActual<this->maquinaMasa1->minimaCapacidad)){
                double pedir= this->maquinaMasa1->pedirMaterial();//max capacidad - capacidad actual -> llego al maximo
                if(yaEncole==false){//Encola si pedir es diferente de !=0
                    if (pedir!=0){
                        this->maquinaMasa1->colaPeticiones->encolar(pedir,this->maquinaMasa1->id);//cantidad soli, id maquina
                        yaEncole=true;
                    }
                }
                this->lbl_cantidadActual->setText(QString::number(this->maquinaMasa1->capacidadActual));//GUI 1
                this->lbl_totalProduccion->setText(QString::number(this->maquinaMasa1->cantidadProcesada));//GUI 2
                if (this->maquinaMasa1->cantidadProcesada>this->maquinaMasa1->cantidadAProcesar){//para que no se pase de la cantida maxima
                    this->maquinaMasa1->capacidadActual+=this->maquinaMasa1->cantidadProcesada-this->maquinaMasa1->cantidadAProcesar;
                    this->maquinaMasa1->cantidadProcesada-=this->maquinaMasa1->cantidadProcesada-this->maquinaMasa1->cantidadAProcesar;
                }
                sleep(2);
            }
            //Parte de cola banda
            yaEncole=false;//Cambia bandera para encolar en cola almacen
            this->maquinaMasa1->cola->encolar(this->maquinaMasa1->cantidadEnviadaABanda);//enviar a la banda 10
            this->maquinaMasa1->cantidadProcesada+=this->maquinaMasa1->cantidadEnviadaABanda;//Suma al total de procesamiento
            this->maquinaMasa1->capacidadActual-=this->maquinaMasa1->cantidadEnviadaABanda;//Resta 10 a la capacidad actual (los que envia a la cola)
            this->lbl_cantidadActual->setText(QString::number(this->maquinaMasa1->capacidadActual));//Set cantidad actual en GUI
            this->lbl_totalProduccion->setText(QString::number(this->maquinaMasa1->cantidadProcesada));//Set cantidad procesada GUI
            this->lbl_BandaTActual->setText(QString::number(this->maquinaMasa1->cola->actual));//Set cantidad actual de banda GUI
            sleep(this->maquinaMasa1->tiempoProceso);//lo que dura procesando xd
            if (this->maquinaMasa1->cantidadProcesada>this->maquinaMasa1->cantidadAProcesar){//para que no se pase de la cantida maxima
                //como la maquina siempre envia 10, se pasa en algunas ocaciones

                this->maquinaMasa1->capacidadActual+=this->maquinaMasa1->cantidadProcesada-this->maquinaMasa1->cantidadAProcesar;
                this->maquinaMasa1->cantidadProcesada-=this->maquinaMasa1->cantidadProcesada-this->maquinaMasa1->cantidadAProcesar;
                this->lbl_cantidadActual->setText(QString::number(this->maquinaMasa1->capacidadActual));//Actual GUI
                this->lbl_totalProduccion->setText(QString::number(this->maquinaMasa1->cantidadProcesada));//Procesada GUI
                //el error de las colas se arregla con una cola que solo tenga un contador en vez de la cola.
                //nodos con mas o menos cantidad que hace que la proxima maquina reciba menos o mas
                //si se usa solo un contador como acumulador es mas facil porque solo se resta
                if (this->maquinaMasa1->cola->actual>(this->maquinaMasa1->cantidadAProcesar*2)&(this->maquinaMasa1->id==1 ||this->maquinaMasa1->id==2)){
                    this->maquinaMasa1->cola->actual=this->maquinaMasa1->cantidadAProcesar*2;
                }else if (this->maquinaMasa1->id==3){
                    this->maquinaMasa1->cola->actual=this->maquinaMasa1->cantidadAProcesar;
                }
                //this->maquinaMasa1->cola->desencolar();//no funciona, hace que falte 1 galleta
            }
            this->lbl_BandaTActual->setText(QString::number(this->maquinaMasa1->cola->actual));//Set cantidad actual de banda GUI
            this->lbl_totalProduccion->setText(QString::number(this->maquinaMasa1->cantidadProcesada));//Set cantidad procesada GUI
            if (this->corriendo==false){
                break;
            }
      }
        this->lbl_BandaTActual->setText(QString::number(this->maquinaMasa1->cola->actual));//Set cantidad actual de banda GUI
        sleep(5);
    }
    qDebug()<<"DETENER HILO MAQUINAL: "<<this->maquinaMasa1->id;
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



