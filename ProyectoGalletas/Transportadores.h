#ifndef TRANSPORTADORES_H
#define TRANSPORTADORES_H
#include "Estructuras.h"

struct Transportadores{
    Transportador * pn;
    Transportador * un;
    int largo;
    Transportadores();
    void insertarTransportador(QString,int, int,int);
    Transportador * transporteParaEnviar(QString);
};
#endif // TRANSPORTADORES_H
