#include "ventanaprincipal.h"
#include "ventanaconfigurar.h"

#include <QApplication>
#include "Estructuras.h"
#include "Punteros.h"

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    //VentanaConfigurar config;//primero se tiene que ejecutar la configuracion
    //config.show();
    //VentanaPrincipal w;
    //w.show();

    Punteros * p = new Punteros();
    p->setPunteros();
    //qDebug()<<"Cantidad masa por defecto: "<<p->_receta->cantidadMasa;
    //qDebug()<<"Cantidad chocolate por defecto: "<<p->_receta->cantidadChocolate;
    //qDebug()<<"Cola almacen:";//primero se ejecutan los qDebug
    //p->colaAlmacen->imprimir();
    //qDebug()<<"Lista peticiones:";
    //p->paquetes->imprimir();
    //qDebug()<<"Cantidad de galleta solicitadas: "<<p->planificador->cantidadSolicitadaGalletas;
    //qDebug()<<"Cantidad de masa necesaria: "<<p->planificador->cantidadNecesariaMasa;
    //qDebug()<<"Cantidad de chocolate necesaria: "<<p->planificador->cantidadNecesariaChocolate;
    //qDebug()<<"Cantidad producida de maquina masa 1: "<<p->planificador->maquinaMasa1->cantidadProcesada;
    //qDebug()<<"Cantidad producida de maquina masa 2: "<<p->planificador->maquinaMasa2->cantidadProcesada;
    //qDebug()<<"Cantidad producida de maquina chocolate: "<<p->planificador->maquinaChocolate->cantidadProcesada;
    //qDebug()<<"Total peticiones cola almacen: "<<p->colaAlmacen->totalPeticiones;
    //qDebug()<<"Pendientes cola almacen: "<<p->colaAlmacen->pendientes;
//    p->paquetes->imprimir();

//    p->paquetes->insertar(4,"Paquetitos",100);
//    p->paquetes->insertar(16,"Tubo",250);
//    p->paquetes->insertar(10,"Paquetes",500);

//    p->paquetes->insertar(4,"Paquetitos",100);
//    p->paquetes->imprimir();


//    p->colaMasaEnsambladora->encolar(40);
//    p->colaMasaEnsambladora->encolar(30);
//    p->colaMasaEnsambladora->encolar(20);
//    p->colaMasaEnsambladora->encolar(10);
//    p->colaMasaEnsambladora->imprimir();

    //p->colaMasaEnsambladora->desencolar();
    //p->colaMasaEnsambladora->desencolar();
    //p->colaMasaEnsambladora->desencolar();
    //p->colaMasaEnsambladora->imprimir();

    //p->listaBandejas->imprimir();
//    p->almacen->carrito->duracion=15;
//    qDebug()<<(p->carrito->duracion);

//    qDebug()<<(p->almacen->carrito->duracion);

//    qDebug()<<p->maquinaChocolate->carrito->duracion;

    return a.exec();
}

