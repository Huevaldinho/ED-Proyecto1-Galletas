#include "ventanaprincipal.h"
#include "ventanaconfigurar.h"

#include <QApplication>
#include "Estructuras.h"
#include "Punteros.h"
#include "controlador.h"



int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    //VentanaConfigurar b;
    //b.show();
    //VentanaPrincipal w;
    //w.show();

    Punteros * punteros = new Punteros();
    Controlador * control = new Controlador(punteros);

    control->iniciarHiloPlanificador();

    qDebug()<<"maquinaMasa1 en main: "<<punteros->maquinaMasa1->cantidadAProcesar;
    qDebug()<<"maquinaMasa2 en main: "<<punteros->maquinaMasa2->cantidadAProcesar;
    qDebug()<<"maquinaChocolate en main: "<<punteros->maquinaChocolate->cantidadAProcesar;

    qDebug()<<"Direccion de memoria de masa1 en main: "<<&(punteros->maquinaMasa1);
    qDebug()<<"Direccion de memoria de masa2 en main: "<<&(punteros->maquinaMasa2);
    qDebug()<<"Direccion de memoria de masaChocolate en main: "<<&(punteros->maquinaChocolate);



    return a.exec();
}

