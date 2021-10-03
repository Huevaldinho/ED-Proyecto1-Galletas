#include "ventanaprincipal.h"
#include "ventanaconfigurar.h"

#include <QApplication>
#include "Estructuras.h"

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    //VentanaConfigurar config;//primero se tiene que ejecutar la configuracion
    //config.show();
    VentanaPrincipal w;
    w.show();
    ListaPaquetes * l = new ListaPaquetes();
    l->insertar(4,"Paquetitos",100);
    l->insertar(16,"Tubos",250);
    qDebug()<<"Lista retorna: galleta"<<l->getCantidadGalletas();
    Planificador * plani = new Planificador();
    qDebug()<<"Plani retorna: por defecto tiene "<<plani->calcularCantidadGalletasSolicitadas();
    plani->leerListaPaquetes(l);
    qDebug()<<"Plani ahora con la lista retorna:  "<<plani->calcularCantidadGalletasSolicitadas();
    qDebug()<<"Plani necesita masa:  "<<plani->cantidadNecesariaMasa;
    qDebug()<<"Plani necesita chocolate:  "<<plani->cantidadNecesariaChocolate;

    return a.exec();
}
