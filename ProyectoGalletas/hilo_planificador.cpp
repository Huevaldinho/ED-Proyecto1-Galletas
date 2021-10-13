#include "hilo_planificador.h"

hilo_planificador::hilo_planificador(){
    this->corriendo=false;
}


void hilo_planificador::__init__(Planificador * plani){

    this->corriendo = false;
    this->pausa = false;
    this->planificador=plani;

}
void hilo_planificador::run(){
    //Aqui se programa toda la mica
    qDebug()<<"entra";

    this->corriendo=true;
    while (corriendo){
        qDebug()<<"corriendo";
         while(planificador->listaPaquetes->primerNodo==NULL){
             qDebug()<<"dormido";
             sleep(1);
         }
         this->planificador->calcularCantidadGalletasSolicitadas();//Calcula cuantas galletas y masa/chocolate tiene que hacer
         this->planificador->maquinaMasa1->cantidadAProcesar=this->planificador->cantidadNecesariaMasa/2;//Lo reparte a las maquinas
         this->planificador->maquinaMasa2->cantidadAProcesar=this->planificador->cantidadNecesariaMasa/2;
         this->planificador->maquinaChocolate->cantidadAProcesar=this->planificador->cantidadNecesariaChocolate;
         //qDebug()<<"Cantidad a procesar"<<planificador->maquinaMasa1->cantidadAProcesar;
         qDebug()<<"hilo masa: "<<(planificador->maquinaMasa1->cantidadAProcesar);
         sleep(1);
    }
}
void hilo_planificador::stop(){
    this->corriendo = false;
}
void hilo_planificador::pause(){
    this->pausa = true;

}
void hilo_planificador::resume(){
    this->pausa=false;
}
