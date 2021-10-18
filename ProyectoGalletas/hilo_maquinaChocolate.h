#ifndef HILO_MAQUINACHOCOLATE_H
#define HILO_MAQUINACHOCOLATE_H
#include "Estructuras.h"
#include <QLabel>

class hilo_maquinaChocolate: public QThread{
    public:
        MaquinaMezclaMasaChocolate * maquinaMasaC;
        QLabel * lbl_totalProduccion;
        QLabel * lbl_cantidadActual;
        bool corriendo;
        bool pausa;

        hilo_maquinaChocolate();
        void __init__(MaquinaMezclaMasaChocolate *,QLabel *,QLabel *);
        void run();
        void stop();
        void pause();
        void resume();
};
#endif // HILO_MAQUINACHOCOLATE_H
