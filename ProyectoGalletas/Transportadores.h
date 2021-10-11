#ifndef TRANSPORTADORES_H
#define TRANSPORTADORES_H
#include "Estructuras.h"

struct Transportadores{
    Transportador * pn;
    Transportador * un;
    int largo;
    Transportadores();
    void insertarTransportador(string,int, int,int);
};
#endif // TRANSPORTADORES_H
