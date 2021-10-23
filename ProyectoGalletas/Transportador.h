#ifndef TRANSPORTADOR_H
#define TRANSPORTADOR_H
#include "Estructuras.h"

struct Transportador{
    int maximo;
    int actuales;
    int tiempoTransporte;
    int totalEnviados;
    QString tipoPaquete;
    Transportador * siguiente;
    Transportador * anterior;

    Transportador();
    Transportador(int,int,int,QString);
    void setEmpacadora(MaquinaEmpacadora*);
    void setActual(int actual);
};
#endif // TRANSPORTADOR_H
