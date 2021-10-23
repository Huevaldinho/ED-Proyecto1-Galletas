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
    double paquetesEnviados=0;
    double excedente = 0;
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
            int probaGenerada=0 +rand()%((proba+1)-0);
            qDebug()<<"Probabilidad generada: "<<probaGenerada;
            paquetesEnviados=tmp->procesoPaquetesEnsambladora;//Cantidad de paquetes procesados
            if(probaGenerada<tmp->probabilidad){
                while (paquetesEnviados>galletas){
                    qDebug()<<"Dormido porque no tiene suficientes galletas";
                    qDebug()<<"Galletas actuales: "<<galletas;
                    qDebug()<<"Solicitadas: "<<paquetesEnviados;
                    galletas=this->empacadora->cola->contarGalletas();//Cuenta galletas que tiene la empacadora
                    sleep(2);
                }
                qDebug()<<"actuales: "<<this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales;
                qDebug()<<"Tmp cantidad: "<<tmp->cantidadPaquetes;
                if (this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales>=tmp->cantidadPaquetes){
                    paquetesEnviados=0;
                    QString qstr = this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->tipoPaquete;
                    qDebug()<<qstr<<" ya tiene todos los paquetes: "<<(this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales);
                    sleep(2);
                    tmp=tmp->siguiente;
                    continue;
                }
                this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales+=paquetesEnviados;
                this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->totalEnviados+=paquetesEnviados;
                //Si se paso de paquetes quita el exceso
                if (this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->totalEnviados>tmp->cantidadPaquetes){
                    excedente=this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->totalEnviados-tmp->cantidadPaquetes;
                    this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales-=(excedente);
                    galletas+=(excedente*tmp->cantidadGalletas);
                    galletas=this->empacadora->cola->contarGalletas();//Cuenta galletas que tiene la empacadora
                }else{
                    galletas-=tmp->procesoPaquetesEnsambladora*tmp->cantidadGalletas;
                    //Tiene la posibilidad de cual mandar
                    qDebug()<<"tmp->probabilidad: "<<tmp->probabilidad;
                    qDebug()<<"Transporte:"<<this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales;
                    qDebug()<<"Total enviados : "<<this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->totalEnviados;
                    sleep(this->empacadora->tiempoEmpaque);

                }




            }else{
                qDebug()<<"ELSE DE PROBABILIDAD HILO EMPACADORA";
                proba-=tmp->probabilidad;
                sleep(2);
            }
            paquetesEnviados=0;
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
