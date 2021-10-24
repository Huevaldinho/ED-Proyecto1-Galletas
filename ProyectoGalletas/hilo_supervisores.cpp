#include "hilo_supervisores.h"

hilo_Supervisores::hilo_Supervisores(){
    this->corriendo=false;
    this->pausa=false;
}

void hilo_Supervisores::__init__(Supervisor * super1,Supervisor * super2,QLabel* lblAceptadas,QLabel* lblRechazadas,QLabel * lblAceptadasSup2,QLabel * lblRechazadaSuop2){
    this->supervisor1=super1;
    this->supervisor2=super2;
    this->lbl_aprobo=lblAceptadas;
    this->lbl_rechazo=lblRechazadas;
    this->lbl_aproboSup2=lblAceptadasSup2;
    this->lbl_rechazoSup2=lblRechazadaSuop2;
}
void hilo_Supervisores::run(){
    this->corriendo=true;
    while (this->corriendo){
        qDebug()<<"Corre hilo supervisores";
        while (this->pausa){
            qDebug()<<"Pausa manual hilo supervisores";
            this->lbl_aprobo->setText(QString::number(this->supervisor1->galletasAceptadas));//Sup 1 aprobadas
            this->lbl_rechazo->setText(QString::number(this->supervisor1->galletasRechazadas));//rechazadas sup1
            this->lbl_aproboSup2->setText(QString::number(this->supervisor2->galletasAceptadas));
            this->lbl_rechazoSup2->setText(QString::number(this->supervisor2->galletasRechazadas));
            sleep(2);
        }
        if (this->supervisor1->colaSupervisores->frente!=NULL){
            this->supervisor1->quitarGalletas(this->supervisor1->colaSupervisores->frente);//Probabilidad super 1
            this->supervisor2->quitarGalletas(this->supervisor2->colaSupervisores->frente);//Probabilidad super 2
            this->supervisor1->colaEmpacadora->encolar(this->supervisor1->colaSupervisores->desencolar()->dato);//Encola en la empacadora
           //desencola colaSupervisores
           qDebug()<<"Encola en banda empacadora: "<<this->supervisor1->colaEmpacadora->frente->dato;
        }
        this->lbl_Actual->setText(QString::number(this->supervisor1->colaSupervisores->actual));
        this->lbl_Max->setText(QString::number(this->supervisor1->colaSupervisores->maximaCapacidad));
        this->lbl_aprobo->setText(QString::number(this->supervisor1->galletasAceptadas));//Sup 1 aprobadas
        this->lbl_rechazo->setText(QString::number(this->supervisor1->galletasRechazadas));//rechazadas sup1
        this->lbl_aproboSup2->setText(QString::number(this->supervisor2->galletasAceptadas));
        this->lbl_rechazoSup2->setText(QString::number(this->supervisor2->galletasRechazadas));
        sleep(4);
    }
    qDebug()<<"Termina hilo supervisores";
}
void hilo_Supervisores::stop(){
    this->corriendo=false;
}
void hilo_Supervisores::pause(){
    this->pausa=true;
}
void hilo_Supervisores::resume(){
    this->corriendo=true;
}
