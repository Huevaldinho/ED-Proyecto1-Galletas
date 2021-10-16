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
    qDebug()<<"Entra hilo carrito";
    sleep(6);//this->carrito->cola->frente!=NULL
    while (true){//se sale porque borramos el frente y por eso la maquina no avanza
        qDebug()<<"Ciclo hilo carrito";
        if(this->carrito->cola->frente==NULL){
            sleep(2);
            continue;

        }

        else if (this->carrito->cola->frente->idMaquina==1){
            qDebug()<<"---Entra if maquina 1----";
            if (this->carrito->cola->frente->cantidadSolicitada>=this->carrito->capacidadTransporteMezcla){
                this->carrito->maquinaMasa1->capacidadActual+=this->carrito->capacidadTransporteMezcla;
                this->carrito->cola->frente->cantidadSolicitada-=this->carrito->capacidadTransporteMezcla;

            }
            else
                this->pausa=true;
        }else if (this->carrito->cola->frente->idMaquina==2){
            qDebug()<<"---Entra if maquina 2----";
            if (this->carrito->cola->frente->cantidadSolicitada>=this->carrito->capacidadTransporteMezcla){
                this->carrito->maquinaMasa2->capacidadActual+=this->carrito->capacidadTransporteMezcla;
                this->carrito->cola->frente->cantidadSolicitada-=this->carrito->capacidadTransporteMezcla;
            }
            else
                this->pausa=true;
        }else{
            qDebug()<<"---Entra if maquina 3----";
            if (this->carrito->cola->frente->cantidadSolicitada>=this->carrito->capacidadTransporteMezcla){
                this->carrito->maquinaChocolate->capacidadActual+=this->carrito->capacidadTransporteMezcla;
                this->carrito->cola->frente->cantidadSolicitada-=this->carrito->capacidadTransporteMezcla;
            }
            else
                this->pausa=true;
        }
        if (this->carrito->cola->frente->cantidadSolicitada==0)//Ya le dio todo el pedido a la maquina
            this->carrito->cola->desencolar();
        while (pausa){
            qDebug()<<"Dormido hilo carrito";
            sleep(1);
        }
        sleep(this->carrito->duracion);
    }
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
