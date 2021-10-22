#ifndef TRANSPORTADORES_H
#define TRANSPORTADORES_H
#include "Estructuras.h"

struct Transportadores{
    Transportador * pn;
    Transportador * un;
    int largo;
    Transportadores();
    void insertarTransportador(string,int, int,int);
    Transportador * transporteParaEnviar(string);
};
#endif // TRANSPORTADORES_H
