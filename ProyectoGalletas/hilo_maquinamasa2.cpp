#include "hilo_maquinamasa2.h"

hilo_maquinaMasa2::hilo_maquinaMasa2(){
    this->corriendo=false;
}
void hilo_maquinaMasa2::__init__(MaquinaMezclaMasaChocolate * maquina,QLabel * lbl_producido,QLabel * lbl_enProceso){
    this->corriendo = false;
    this->pausa = false;
    this->maquinaMasa2=maquina;
    this->lbl_totalProduccion=lbl_producido;
    this->lbl_cantidadActual=lbl_enProceso;
}
void hilo_maquinaMasa2::run(){
    qDebug()<<"Entra hilo "<<this->maquinaMasa2->id;
    qDebug()<<"Procesada "<<this->maquinaMasa2->id<<": "<<this->maquinaMasa2->cantidadProcesada;
    qDebug()<<"A procesar por "<<this->maquinaMasa2->id<<": "<<this->maquinaMasa2->cantidadAProcesar;
    sleep(2);
    bool yaEncole=false;
    qDebug()<<"A PEDIR MAQUINA "<<this->maquinaMasa2->id<<": "<<this->maquinaMasa2->maximaCapacidad-this->maquinaMasa2->capacidadActual;
    while(true){
      while(this->maquinaMasa2->cantidadProcesada<this->maquinaMasa2->cantidadAProcesar){
          qDebug()<<"Corre el hilo: "<<this->maquinaMasa2->id;
          //Se pone en pausa
          while ((this->maquinaMasa2->cola->actual >= this->maquinaMasa2->cola->maximaCapacidad) || (this->maquinaMasa2->capacidadActual<this->maquinaMasa2->minimaCapacidad)){
              qDebug()<<"Dormido :"<<this->maquinaMasa2->id;
              double pedir= this->maquinaMasa2->pedirMaterial();//max capacidad - capacidad actual -> llego al maximo
              if(yaEncole==false){//Encola si pedir es diferente de !=0
                  if (pedir!=0){
                      this->maquinaMasa2->colaPeticiones->encolar(pedir,this->maquinaMasa2->id);//cantidad soli, id maquina
                      yaEncole=true;
                      qDebug()<<"Maquina "<<this->maquinaMasa2->id<<" encolo";
                  }
              }
              this->lbl_cantidadActual->setText(QString::number(this->maquinaMasa2->capacidadActual));//GUI 1
              this->lbl_totalProduccion->setText(QString::number(this->maquinaMasa2->cantidadProcesada));//GUI 2
              qDebug()<<"DORMIDO Actual "<<this->maquinaMasa2->id<<": "<<this->maquinaMasa2->capacidadActual;
              qDebug()<<"DORMIDO Procesada "<<this->maquinaMasa2->id<<": "<<this->maquinaMasa2->cantidadProcesada;
              qDebug()<<"DORMIDO A Procesar "<<this->maquinaMasa2->id<<": "<<this->maquinaMasa2->cantidadAProcesar;
              qDebug()<<"DORMIDO CantidadEnviadaBanda por:  "<<this->maquinaMasa2->id<<this->maquinaMasa2->cantidadEnviadaABanda;
              if (this->maquinaMasa2->cantidadProcesada>this->maquinaMasa2->cantidadAProcesar){//para que no se pase de la cantida maxima
                  //como la maquina siempre envia 10, se pasa en algunas ocaciones

                  this->maquinaMasa2->capacidadActual+=this->maquinaMasa2->cantidadProcesada-this->maquinaMasa2->cantidadAProcesar;
                  this->maquinaMasa2->cantidadProcesada-=this->maquinaMasa2->cantidadProcesada-this->maquinaMasa2->cantidadAProcesar;
              }
              sleep(3);
          }
          //Parte de cola banda
          yaEncole=false;
          this->maquinaMasa2->cola->encolar(this->maquinaMasa2->cantidadEnviadaABanda);//enviar a la banda
          this->maquinaMasa2->cantidadProcesada+=this->maquinaMasa2->cantidadEnviadaABanda;//Suma al total de procesamiento
          this->lbl_cantidadActual->setText(QString::number(this->maquinaMasa2->capacidadActual));//GUI 1
          this->maquinaMasa2->capacidadActual-=this->maquinaMasa2->cantidadEnviadaABanda;//Resta lo que proceso al actual
          this->lbl_totalProduccion->setText(QString::number(this->maquinaMasa2->cantidadProcesada));//GUI
          //Condicion cochina para la ultima iteracion, como mete de 10 en 10, puede que la cantidad se pase y el total producida sea mayor,
          //en ese caso, lo que se hace es quitar el exceso y ponerlo en actual.
          if (this->maquinaMasa2->cantidadProcesada>this->maquinaMasa2->cantidadAProcesar){//para que no se pase de la cantida maxima
              //como la maquina siempre envia 10, se pasa en algunas ocaciones

              this->maquinaMasa2->capacidadActual+=this->maquinaMasa2->cantidadProcesada-this->maquinaMasa2->cantidadAProcesar;
              this->maquinaMasa2->cantidadProcesada-=this->maquinaMasa2->cantidadProcesada-this->maquinaMasa2->cantidadAProcesar;
              this->lbl_cantidadActual->setText(QString::number(this->maquinaMasa2->capacidadActual));//GUI 1
              this->lbl_totalProduccion->setText(QString::number(this->maquinaMasa2->cantidadProcesada));//GUI
          }
          sleep(this->maquinaMasa2->tiempoProceso);//lo que dura procesando xd
          qDebug()<<"Actual "<<this->maquinaMasa2->id<<": "<<this->maquinaMasa2->capacidadActual;
          qDebug()<<"Procesada "<<this->maquinaMasa2->id<<": "<<this->maquinaMasa2->cantidadProcesada;
      }
    }
}
void hilo_maquinaMasa2::pause(){
    this->pausa=true;
}
void hilo_maquinaMasa2::stop(){
    this->corriendo=false;
}
void hilo_maquinaMasa2::resume(){
    this->pausa=false;
}
