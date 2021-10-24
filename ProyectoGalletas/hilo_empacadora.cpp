#include "hilo_empacadora.h"

hilo_Empacadora::hilo_Empacadora(){
    this->corriendo=false;
}

void hilo_Empacadora::__init__(MaquinaEmpacadora * _empacadora){
    this->pausa=false;
    this->empacadora=_empacadora;
}
void hilo_Empacadora::run(){
    double totalGalletas=0;
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
            sleep(1);
            paquetesEnviados=tmp->procesoPaquetesEnsambladora;//Cantidad de paquetes procesados
            qDebug()<<"Paquetes Enviados: "<<paquetesEnviados;
            sleep(1);
            if(probaGenerada<tmp->probabilidad){
                while (paquetesEnviados*tmp->cantidadGalletas>galletas){
                    qDebug()<<"Dormido porque no tiene suficientes galletas";
                    qDebug()<<"Galletas actuales: "<<galletas;
                    qDebug()<<"Solicitadas: "<<paquetesEnviados;
                    galletas=this->empacadora->cola->contarGalletas();//Cuenta galletas que tiene la empacadora
                    sleep(2);
                }
                if (this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales>=this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->maximo){
                    QString qstr = tmp->nombre;
                    qDebug()<<qstr<<" ya tiene todos los paquetes: "<<(this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales);
                    sleep(2);
                    //mandar a llamar al almacen y modificar actual de ese tipo de transporte
                    //tipo, actual,max
                    this->tabla->insertRow(this->tabla->rowCount());
                    this->tabla->setItem(this->tabla->rowCount()-1,0,new QTableWidgetItem(QString(tmp->nombre)));
                    this->tabla->setItem(this->tabla->rowCount()-1,1,new QTableWidgetItem(QString::number(this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales)));
                    this->tabla->setItem(this->tabla->rowCount()-1,2,new QTableWidgetItem(QString::number(this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->maximo)));
                    this->tabla->setItem(this->tabla->rowCount()-1,3,new QTableWidgetItem(QString::number(this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->totalEnviados)));
                    totalGalletas+=this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->totalEnviados*tmp->cantidadGalletas;
                    lbl_galletasTotales->setText(QString::number(totalGalletas));
                    this->empacadora->paquetes->listaTransportadores->transporteParaEnviar(tmp->nombre)->actuales=0;
                    tmp=tmp->siguiente;
                    continue;
                }else{
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

                }
            }else{
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
