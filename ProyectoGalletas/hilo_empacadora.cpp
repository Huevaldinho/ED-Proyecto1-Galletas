#include "hilo_empacadora.h"

hilo_Empacadora::hilo_Empacadora(){
    this->corriendo=false;
}

void hilo_Empacadora::__init__(MaquinaEmpacadora * _empacadora){
    this->pausa=false;
    this->empacadora=_empacadora;
}
void hilo_Empacadora::run(){
    double galletas=0;
    double enviarGalletas=0;
    this->corriendo=true;
    qDebug()<<"Corre hilo empacadora";
    this->empacadora->paquetes->setProbabilidades();
    while (this->corriendo){
        while(this->pausa || this->empacadora->cola->frente==NULL){
            qDebug()<<"Pausa hilo empacadora por frente null o this->pausa==true";
            sleep(2);
        }
        qDebug()<<"Cantidad de galletas en empacadora: "<<galletas;
        Nodo * tmp = this->empacadora->paquetes->primerNodo;//Tipos de paquetes
        int proba=100;
        do{
            galletas=this->empacadora->cola->contarGalletas();//Cuenta galletas que tiene la empacadora
            srand(time(0));
            int probaGenerada=1 + rand() % 100;
            qDebug()<<"Probabilidad generada: "<<probaGenerada;
            if(probaGenerada<tmp->probabilidad){
                enviarGalletas=tmp->procesoPaquetesEnsambladora*tmp->cantidadGalletas;//Cantidad de paquetes procesados
                while (enviarGalletas>galletas){
                    qDebug()<<"Dormido porque no tiene suficientes galletas";
                    qDebug()<<"Galletas actuales: "<<galletas;
                    qDebug()<<"Solicitadas: "<<enviarGalletas;
                    sleep(2);
                }
                this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales+=enviarGalletas;
                galletas-=tmp->procesoPaquetesEnsambladora*tmp->cantidadGalletas;
                //Tiene la posibilidad de cual mandar
                qDebug()<<"tmp->probabilidad: "<<tmp->probabilidad;
                qDebug()<<"Transporte actual: "<<this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales;
                sleep(this->empacadora->tiempoEmpaque);

            }else{
                qDebug()<<"ELSE DE PROBABILIDAD HILO EMPACADORA";
                proba-=tmp->probabilidad;
                sleep(2);
            }
            tmp=tmp->siguiente;
        }while(tmp!=NULL);

    }
}
void hilo_Empacadora::stop(){
    this->corriendo=false;
}
void hilo_Empacadora::pause(){
    this->pausa=true;
}
void hilo_Empacadora::resume(){
    this->pausa=false;
}
