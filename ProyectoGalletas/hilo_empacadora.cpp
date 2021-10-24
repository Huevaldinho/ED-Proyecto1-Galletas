#include "hilo_empacadora.h"

hilo_Empacadora::hilo_Empacadora(){
    this->corriendo=false;
}

void hilo_Empacadora::__init__(MaquinaEmpacadora * _empacadora){
    this->pausa=false;
    this->empacadora=_empacadora;
}
void hilo_Empacadora::run(){
    this->corriendo=true;
    double galletas=0;
    double galletasEnviadas=0;
    double paquetesEnviados=0;
    double excedente = 0;
    bool flag=true;
    qDebug()<<"Corre hilo empacadora";
    this->empacadora->paquetes->setProbabilidades();
    Nodo * tmp = this->empacadora->paquetes->primerNodo;//Tipos de paquetes
    while (this->corriendo){
        while(this->pausa || this->empacadora->cola->frente==NULL){
            qDebug()<<"Pausa hilo empacadora por frente null o this->pausa==true";
            sleep(2);
        }
        qDebug()<<"Cantidad de galletas en empacadora: "<<galletas;
        while(tmp!=NULL){
            flag=true;
            galletas=this->empacadora->cola->contarGalletas()-galletasEnviadas+excedente;//Cuenta galletas que tiene la empacadora
            qDebug()<<"Galletas: "<<galletas;
            paquetesEnviados=tmp->procesoPaquetesEnsambladora;//Cantidad de paquetes procesados
            qDebug()<<"Paquetes Enviados: "<<paquetesEnviados;
            sleep(1);
            int proba=100;
            while (galletas<this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->maximo*tmp->cantidadGalletas){
                qDebug()<<"Dormido porque no tiene suficientes galletas";
                qDebug()<<"Galletas actuales: "<<galletas;
                qDebug()<<"Solicitadas: "<<paquetesEnviados;
                galletas=this->empacadora->cola->contarGalletas()-galletasEnviadas+excedente;//Cuenta galletas que tiene la empacadora
                sleep(2);
            }
            while (flag==true){
                galletas=this->empacadora->cola->contarGalletas()-galletasEnviadas+excedente;//Cuenta galletas que tiene la empacadora
                qDebug()<<"Galletas: "<<galletas;
                while (galletas<this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->maximo*tmp->cantidadGalletas){
                    qDebug()<<"Dormido porque no tiene suficientes galletas";
                    qDebug()<<"Galletas actuales: "<<galletas;
                    qDebug()<<"Solicitadas: "<<paquetesEnviados;
                    galletas=this->empacadora->cola->contarGalletas()-galletasEnviadas+excedente;//Cuenta galletas que tiene la empacadora
                    sleep(2);
                }
                qDebug()<<"UN ciclo del flag";
                srand(time(0));
                int probaGenerada=0 +rand()%((proba+1)-0);
                qDebug()<<"Probabilidad generada: "<<probaGenerada;
                sleep(1);
                if(probaGenerada<tmp->probabilidad){
                    if (this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales>=this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->maximo){
                        QString qstr = tmp->nombre;
                        qDebug()<<qstr<<" ya tiene todos los paquetes: "<<(this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales);
                        sleep(2);
                        //mandar a llamar al almacen y modificar actual de ese tipo de transporte
                        //tipo, actual,max
                        this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->totalEnviados+=this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales;
                        this->tabla->insertRow(this->tabla->rowCount());
                        this->tabla->setItem(this->tabla->rowCount()-1,0,new QTableWidgetItem(QString(tmp->nombre)));
                        this->tabla->setItem(this->tabla->rowCount()-1,1,new QTableWidgetItem(QString::number(this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales)));
                        this->tabla->setItem(this->tabla->rowCount()-1,2,new QTableWidgetItem(QString::number(this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->maximo)));
                        this->tabla->setItem(this->tabla->rowCount()-1,3,new QTableWidgetItem(QString::number(this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->totalEnviados)));

                        lbl_galletasTotales->setText(QString::number(this->empacadora->cola->contarGalletas()));
                        galletasEnviadas+=this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales;
                        this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales=0;
                        sleep(this->empacadora->tiempoEmpaque);
                        excedente=0;
                        if (this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->totalEnviados==tmp->cantidadPaquetes){
                            qDebug()<<"CAMBIO EL TMP NOOOO AMAZING";
                            tmp=tmp->siguiente;
                        }
                        else continue;
                    }else{
                        qDebug()<<"Entrada del else";
                        this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales+=paquetesEnviados;
                        if (this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales>tmp->cantidadPaquetes){
                            excedente=this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales-tmp->cantidadPaquetes;
                            this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales-=excedente;
                            excedente*=tmp->cantidadGalletas;
                        }
                    }
                }else{
                    proba-=tmp->probabilidad;
                    sleep(2);
                }
            }

        }
        lbl_galletasTotales->setText(QString::number(this->empacadora->cola->contarGalletas()));

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
