#ifndef NODOBANDEJA_H
#define NODOBANDEJA_H
#include "Estructuras.h"

struct NodoBandeja{
    int horneadas;//cuantas galletas ha horneado
    int actual;//son las galletas en espera, o sea, las que se estan horneando en ese momento
    bool estado;
    NodoBandeja * siguienteBandeja;
    NodoBandeja * anteriorBandeja;


    NodoBandeja(){
        horneadas = 0;
        actual = 0;
        estado=true;
        siguienteBandeja = NULL;
        anteriorBandeja=NULL;
    }

    NodoBandeja(int galletas){
        estado=true;
        actual += galletas;
        horneadas += galletas;

    }
    void setEstado(bool _estado){
        estado=_estado;
    }
    void imprimir(){
        cout << " | " << actual << " | -> ";
    }

};
#endif // NODOBANDEJA_H
