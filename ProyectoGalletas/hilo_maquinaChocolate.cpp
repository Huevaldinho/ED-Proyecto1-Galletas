#include "hilo_maquinaChocolate.h"

hilo_maquinaChocolate::hilo_maquinaChocolate(){
    this->corriendo=false;
}
void hilo_maquinaChocolate::__init__(MaquinaMezclaMasaChocolate * maquina,QLabel * lbl_producido,QLabel * lbl_enProceso){
    this->corriendo = false;
    this->pausa = false;
    this->maquinaMasaC=maquina;
    this->lbl_totalProduccion=lbl_producido;
    this->lbl_cantidadActual=lbl_enProceso;
}
void hilo_maquinaChocolate::run(){
    qDebug()<<"Entra hilo "<<this->maquinaMasaC->id;
    qDebug()<<"Procesada "<<this->maquinaMasaC->id<<": "<<this->maquinaMasaC->cantidadProcesada;
    qDebug()<<"A procesar por "<<this->maquinaMasaC->id<<": "<<this->maquinaMasaC->cantidadAProcesar;
    sleep(2);
    bool yaEncole=false;
    qDebug()<<"A PEDIR MAQUINA "<<this->maquinaMasaC->id<<": "<<this->maquinaMasaC->maximaCapacidad-this->maquinaMasaC->capacidadActual;
    while(true){
      while(this->maquinaMasaC->cantidadProcesada<this->maquinaMasaC->cantidadAProcesar){
          qDebug()<<"Corre el hilo: "<<this->maquinaMasaC->id;
          //Se pone en pausa
          while ((this->maquinaMasaC->cola->actual >= this->maquinaMasaC->cola->maximaCapacidad) || (this->maquinaMasaC->capacidadActual<this->maquinaMasaC->minimaCapacidad)){
              qDebug()<<"Dormido :"<<this->maquinaMasaC->id;
              double pedir= this->maquinaMasaC->pedirMaterial();//max capacidad - capacidad actual -> llego al maximo
              if(yaEncole==false){//Encola si pedir es diferente de !=0
                  if (pedir!=0){
                      this->maquinaMasaC->colaPeticiones->encolar(pedir,this->maquinaMasaC->id);//cantidad soli, id maquina
                      yaEncole=true;
                      qDebug()<<"Maquina "<<this->maquinaMasaC->id<<" encolo";
                  }
              }
              this->lbl_cantidadActual->setText(QString::number(this->maquinaMasaC->capacidadActual));//GUI 1
              this->lbl_totalProduccion->setText(QString::number(this->maquinaMasaC->cantidadProcesada));//GUI 2
              qDebug()<<"DORMIDO Actual "<<this->maquinaMasaC->id<<": "<<this->maquinaMasaC->capacidadActual;
              qDebug()<<"DORMIDO Procesada "<<this->maquinaMasaC->id<<": "<<this->maquinaMasaC->cantidadProcesada;
              qDebug()<<"DORMIDO A Procesar "<<this->maquinaMasaC->id<<": "<<this->maquinaMasaC->cantidadAProcesar;
              qDebug()<<"DORMIDO CantidadEnviadaBanda por:  "<<this->maquinaMasaC->id<<this->maquinaMasaC->cantidadEnviadaABanda;
              if (this->maquinaMasaC->cantidadProcesada>this->maquinaMasaC->cantidadAProcesar){//para que no se pase de la cantida maxima
                  //como la maquina siempre envia 10, se pasa en algunas ocaciones

                  this->maquinaMasaC->capacidadActual+=this->maquinaMasaC->cantidadProcesada-this->maquinaMasaC->cantidadAProcesar;
                  this->maquinaMasaC->cantidadProcesada-=this->maquinaMasaC->cantidadProcesada-this->maquinaMasaC->cantidadAProcesar;
              }
              sleep(3);
          }
          //Parte de cola banda
          yaEncole=false;
          this->maquinaMasaC->cola->encolar(this->maquinaMasaC->cantidadEnviadaABanda);//enviar a la banda
          this->maquinaMasaC->cantidadProcesada+=this->maquinaMasaC->cantidadEnviadaABanda;//Suma al total de procesamiento
          this->lbl_cantidadActual->setText(QString::number(this->maquinaMasaC->capacidadActual));//GUI 1
          this->maquinaMasaC->capacidadActual-=this->maquinaMasaC->cantidadEnviadaABanda;//Resta lo que proceso al actual
          this->lbl_totalProduccion->setText(QString::number(this->maquinaMasaC->cantidadProcesada));//GUI
          //Condicion cochina para la ultima iteracion, como mete de 10 en 10, puede que la cantidad se pase y el total producida sea mayor,
          //en ese caso, lo que se hace es quitar el exceso y ponerlo en actual.
          if (this->maquinaMasaC->cantidadProcesada>this->maquinaMasaC->cantidadAProcesar){//para que no se pase de la cantida maxima
              //como la maquina siempre envia 10, se pasa en algunas ocaciones

              this->maquinaMasaC->capacidadActual+=this->maquinaMasaC->cantidadProcesada-this->maquinaMasaC->cantidadAProcesar;
              this->maquinaMasaC->cantidadProcesada-=this->maquinaMasaC->cantidadProcesada-this->maquinaMasaC->cantidadAProcesar;
              this->lbl_cantidadActual->setText(QString::number(this->maquinaMasaC->capacidadActual));//GUI 1
              this->lbl_totalProduccion->setText(QString::number(this->maquinaMasaC->cantidadProcesada));//GUI
          }
          sleep(this->maquinaMasaC->tiempoProceso);//lo que dura procesando xd
          qDebug()<<"Actual "<<this->maquinaMasaC->id<<": "<<this->maquinaMasaC->capacidadActual;
          qDebug()<<"Procesada "<<this->maquinaMasaC->id<<": "<<this->maquinaMasaC->cantidadProcesada;
      }
    }
}
void hilo_maquinaChocolate::pause(){
    this->pausa=true;
}
void hilo_maquinaChocolate::stop(){
    this->corriendo=false;
}
void hilo_maquinaChocolate::resume(){
    this->pausa=false;
}
