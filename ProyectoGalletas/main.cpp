#include "ventanaprincipal.h"
#include "ventanaconfigurar.h"

#include <QApplication>
#include "Estructuras.h"
#include "CrearPunteros.h"

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    //VentanaConfigurar config;//primero se tiene que ejecutar la configuracion
    //config.show();
    //VentanaPrincipal w;
    //w.show();

    Punteros * p = new Punteros();
    p->setPunteros();


    p->maquinaMasa1->id=1;
    p->maquinaMasa2->id=2;
    qDebug()<<"Planificador->maquinaMasa1->id: "<<p->planificador->maquinaMasa1->id;
    qDebug()<<"Planificador->maquinaMasa2->id: "<<p->planificador->maquinaMasa2->id;



    return a.exec();
}
