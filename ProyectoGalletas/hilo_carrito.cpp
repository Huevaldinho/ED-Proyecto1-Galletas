#include "hilo_carrito.h"
#include <QDebug>
hilo_carrito::hilo_carrito(){
    this->corriendo=false;
}
void hilo_carrito::__init__(Carrito * _carrito){
    this->corriendo = false;
    this->pausa = false;
    this->carrito=_carrito;
}
void hilo_carrito::run(){
    this->corriendo=true;
    sleep(6);//this->carrito->cola->frente!=NULL
    //estaba como while true
    bool primera=true;
    while (this->corriendo){//se sale porque borramos el frente y por eso la maquina no avanza

        if(this->carrito->cola->frente==NULL){
            sleep(2);
            continue;

        }
        else if (this->carrito->cola->frente->idMaquina==1){//Peticion de maquina 1
            if (this->carrito->cola->frente->cantidadSolicitada>=this->carrito->capacidadTransporteMezcla){
                this->carrito->maquinaMasa1->capacidadActual+=this->carrito->capacidadTransporteMezcla;
                this->carrito->cola->frente->cantidadSolicitada-=this->carrito->capacidadTransporteMezcla;
                this->tabla->insertRow(this->tabla->rowCount());
                //cantidad, id, estado -> son las columnas de la tabla
                this->tabla->setItem(this->tabla->rowCount()-1,0,new QTableWidgetItem(QString::number(this->carrito->capacidadTransporteMezcla)));
                this->tabla->setItem(this->tabla->rowCount()-1,1,new QTableWidgetItem(QString::number(this->carrito->cola->frente->idMaquina)));
                this->tabla->setItem(this->tabla->rowCount()-1,2,new QTableWidgetItem("Procesada"));
                bool ok=true;
                if ((this->carrito->maquinaMasa1->capacidadActual>this->tabla->itemAt(0,0)->text().toInt(&ok) )&& (primera==false))
                    this->tabla->removeRow(0);
            }
            else
                this->pausa=true;
        }else if (this->carrito->cola->frente->idMaquina==2){//Peticion de maquina 2
            if (this->carrito->cola->frente->cantidadSolicitada>=this->carrito->capacidadTransporteMezcla){
                this->carrito->maquinaMasa2->capacidadActual+=this->carrito->capacidadTransporteMezcla;
                this->carrito->cola->frente->cantidadSolicitada-=this->carrito->capacidadTransporteMezcla;
                this->tabla->insertRow(this->tabla->rowCount());
                //cantidad, id, estado -> son las columnas de la tabla
                this->tabla->setItem(this->tabla->rowCount()-1,0,new QTableWidgetItem(QString::number(this->carrito->capacidadTransporteMezcla)));
                this->tabla->setItem(this->tabla->rowCount()-1,1,new QTableWidgetItem(QString::number(this->carrito->cola->frente->idMaquina)));
                this->tabla->setItem(this->tabla->rowCount()-1,2,new QTableWidgetItem("Procesada"));
                bool ok=true;

                if (primera==false)
                    if ((this->carrito->maquinaMasa1->capacidadActual>this->tabla->itemAt(0,0)->text().toInt(&ok)))
                        this->tabla->removeRow(0);
            }
            else
                this->pausa=true;
        }else{       //Peticion de maquina choco                       //capacidadTransporteMezcla
            if (this->carrito->cola->frente->cantidadSolicitada>=this->carrito->capacidadTransporteChocolate){
                this->carrito->maquinaChocolate->capacidadActual+=this->carrito->capacidadTransporteChocolate;
                this->carrito->cola->frente->cantidadSolicitada-=this->carrito->capacidadTransporteChocolate;
                this->tabla->insertRow(this->tabla->rowCount());
                //cantidad, id, estado -> son las columnas de la tabla
                this->tabla->setItem(this->tabla->rowCount()-1,0,new QTableWidgetItem(QString::number(this->carrito->capacidadTransporteMezcla)));
                this->tabla->setItem(this->tabla->rowCount()-1,1,new QTableWidgetItem(QString::number(this->carrito->cola->frente->idMaquina)));
                this->tabla->setItem(this->tabla->rowCount()-1,2,new QTableWidgetItem("Procesada"));
                bool ok=true;

                if ((this->carrito->maquinaMasa1->capacidadActual>this->tabla->itemAt(0,0)->text().toInt(&ok) )&& (primera==false))
                    this->tabla->removeRow(0);
            }
            else
                this->pausa=true;
        }
        if (this->carrito->cola->frente->cantidadSolicitada==0)//Ya le dio todo el pedido a la maquina
            this->carrito->cola->desencolar();
        while (pausa){
            sleep(1);
        }
        sleep(this->carrito->duracion);
        primera=false;
    }
    qDebug()<<"DETENER HILO CARRITO";
}
void hilo_carrito::stop(){
    this->corriendo=false;
}
void hilo_carrito::pause(){
    this->pausa=true;
}
void hilo_carrito::resume(){
    this->pausa=false;
}
