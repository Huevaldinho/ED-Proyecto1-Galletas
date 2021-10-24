#include "hilo_planificador.h"

hilo_planificador::hilo_planificador(){
    this->corriendo=false;
}


void hilo_planificador::__init__(Planificador * plani,QLabel*eti,QLabel*lbl_cantidadMasa,QLabel*lbl_cantidadChoco){

    this->corriendo = false;
    this->pausa = false;
    this->planificador=plani;
    this->etiqueta=eti;
    this->lbl_masa=lbl_cantidadMasa;
    this->lbl_choco=lbl_cantidadChoco;

}
void hilo_planificador::run(){
    //Aqui se programa toda la mica
    qDebug()<<"Entra al run hilo planificador";
    this->corriendo=true;
    while (this->corriendo){
         while(planificador->listaPaquetes->primerNodo==NULL){
             sleep(1);
             if (this->corriendo==false)
                 break;
         }

         this->planificador->calcularCantidadGalletasSolicitadas();//Calcula cuantas galletas y masa/chocolate tiene que hacer
         this->planificador->maquinaMasa1->cantidadAProcesar=this->planificador->cantidadNecesariaMasa/2;//Lo reparte a las maquinas
         this->planificador->maquinaMasa2->cantidadAProcesar=this->planificador->cantidadNecesariaMasa/2;
         this->planificador->maquinaChocolate->cantidadAProcesar=this->planificador->cantidadNecesariaChocolate;
         this->planificador->maquinaEnsambladora->galletasAProcesar=this->planificador->cantidadSolicitadaGalletas;

         this->etiqueta->setText(QString::number(this->planificador->cantidadSolicitadaGalletas));
         this->lbl_masa->setText(QString::number(this->planificador->cantidadNecesariaMasa));
         this->lbl_choco->setText(QString::number(this->planificador->cantidadNecesariaChocolate));

         sleep(3);//1
         if (this->corriendo==false){
             break;
         }
         while (pausa){
             qDebug()<<"Pausa manual de planificador";
             if (this->corriendo==false)
                 break;
             sleep(3);
         }
    }
    qDebug()<<"DETENER HILO PLANIFICADOR";
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
