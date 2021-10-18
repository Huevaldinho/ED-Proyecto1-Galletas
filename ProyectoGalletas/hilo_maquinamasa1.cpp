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
    qDebug()<<"Entra hilo "<<this->maquinaMasa1->id;
    qDebug()<<"Procesada "<<this->maquinaMasa1->id<<": "<<this->maquinaMasa1->cantidadProcesada;
    qDebug()<<"A procesar por "<<this->maquinaMasa1->id<<": "<<this->maquinaMasa1->cantidadAProcesar;
    sleep(2);
    bool yaEncole=false;
    qDebug()<<"A PEDIR MAQUINA "<<this->maquinaMasa1->id<<": "<<this->maquinaMasa1->maximaCapacidad-this->maquinaMasa1->capacidadActual;
    while(true){
      while(this->maquinaMasa1->cantidadProcesada<this->maquinaMasa1->cantidadAProcesar){
          qDebug()<<"Corre el hilo: "<<this->maquinaMasa1->id;
          //Se pone en pausa
          while ((this->maquinaMasa1->cola->actual >= this->maquinaMasa1->cola->maximaCapacidad) || (this->maquinaMasa1->capacidadActual<this->maquinaMasa1->minimaCapacidad)){
              qDebug()<<"Dormido :"<<this->maquinaMasa1->id;
              double pedir= this->maquinaMasa1->pedirMaterial();//max capacidad - capacidad actual -> llego al maximo
              if(yaEncole==false){//Encola si pedir es diferente de !=0
                  if (pedir!=0){
                      this->maquinaMasa1->colaPeticiones->encolar(pedir,this->maquinaMasa1->id);//cantidad soli, id maquina
                      yaEncole=true;
                      qDebug()<<"Maquina "<<this->maquinaMasa1->id<<" encolo";
                  }
              }
              this->lbl_cantidadActual->setText(QString::number(this->maquinaMasa1->capacidadActual));//GUI 1
              this->lbl_totalProduccion->setText(QString::number(this->maquinaMasa1->cantidadProcesada));//GUI 2
              qDebug()<<"DORMIDO Actual "<<this->maquinaMasa1->id<<": "<<this->maquinaMasa1->capacidadActual;
              qDebug()<<"DORMIDO Procesada "<<this->maquinaMasa1->id<<": "<<this->maquinaMasa1->cantidadProcesada;
              qDebug()<<"DORMIDO A Procesar "<<this->maquinaMasa1->id<<": "<<this->maquinaMasa1->cantidadAProcesar;
              qDebug()<<"DORMIDO CantidadEnviadaBanda por:  "<<this->maquinaMasa1->id<<this->maquinaMasa1->cantidadEnviadaABanda;
              if (this->maquinaMasa1->cantidadProcesada>this->maquinaMasa1->cantidadAProcesar){//para que no se pase de la cantida maxima
                  //como la maquina siempre envia 10, se pasa en algunas ocaciones

                  this->maquinaMasa1->capacidadActual+=this->maquinaMasa1->cantidadProcesada-this->maquinaMasa1->cantidadAProcesar;
                  this->maquinaMasa1->cantidadProcesada-=this->maquinaMasa1->cantidadProcesada-this->maquinaMasa1->cantidadAProcesar;
              }
              sleep(3);
          }
          //Parte de cola banda
          yaEncole=false;
          this->maquinaMasa1->cola->encolar(this->maquinaMasa1->cantidadEnviadaABanda);//enviar a la banda
          this->maquinaMasa1->cantidadProcesada+=this->maquinaMasa1->cantidadEnviadaABanda;//Suma al total de procesamiento
          this->lbl_cantidadActual->setText(QString::number(this->maquinaMasa1->capacidadActual));//GUI 1
          this->maquinaMasa1->capacidadActual-=this->maquinaMasa1->cantidadEnviadaABanda;//Resta lo que proceso al actual
          this->lbl_totalProduccion->setText(QString::number(this->maquinaMasa1->cantidadProcesada));//GUI
          //Condicion cochina para la ultima iteracion, como mete de 10 en 10, puede que la cantidad se pase y el total producida sea mayor,
          //en ese caso, lo que se hace es quitar el exceso y ponerlo en actual.
          if (this->maquinaMasa1->cantidadProcesada>this->maquinaMasa1->cantidadAProcesar){//para que no se pase de la cantida maxima
              //como la maquina siempre envia 10, se pasa en algunas ocaciones

              this->maquinaMasa1->capacidadActual+=this->maquinaMasa1->cantidadProcesada-this->maquinaMasa1->cantidadAProcesar;
              this->maquinaMasa1->cantidadProcesada-=this->maquinaMasa1->cantidadProcesada-this->maquinaMasa1->cantidadAProcesar;
              this->lbl_cantidadActual->setText(QString::number(this->maquinaMasa1->capacidadActual));//GUI 1
              this->lbl_totalProduccion->setText(QString::number(this->maquinaMasa1->cantidadProcesada));//GUI
          }
          sleep(this->maquinaMasa1->tiempoProceso);//lo que dura procesando xd
          qDebug()<<"Actual "<<this->maquinaMasa1->id<<": "<<this->maquinaMasa1->capacidadActual;
          qDebug()<<"Procesada "<<this->maquinaMasa1->id<<": "<<this->maquinaMasa1->cantidadProcesada;
      }
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



