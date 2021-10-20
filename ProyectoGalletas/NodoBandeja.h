#ifndef NODOBANDEJA_H
#define NODOBANDEJA_H
#include "Estructuras.h"
#include <QDebug>
struct NodoBandeja{
    double horneadas;//cuantas galletas ha horneado
    double actual;//son las galletas en espera, o sea, las que se estan horneando en ese momento
    int capacidadGalletas;
    bool estado;
    NodoBandeja * siguienteBandeja;
    NodoBandeja * anteriorBandeja;


    NodoBandeja(){
        horneadas = 0;
        actual = 0;
        capacidadGalletas=8;
        estado=true;
        siguienteBandeja = NULL;
        anteriorBandeja=NULL;
    }

    NodoBandeja(double galletas){
        estado=true;
        actual += galletas;
        horneadas += galletas;

    }
    void setEstado(bool _estado){
        estado=_estado;
    }
    void imprimir(){
        qDebug() << " | " << actual << " | -> ";
    }

};
#endif // NODOBANDEJA_H
