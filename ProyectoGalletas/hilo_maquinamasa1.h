#ifndef HILO_MAQUINAMASA1_H
#define HILO_MAQUINAMASA1_H
#include "Estructuras.h"
#include <QLabel>

class hilo_maquinaMasa1: public QThread{
    public:
        MaquinaMezclaMasaChocolate * maquinaMasa1;
        QLabel * lbl_totalProduccion;
        QLabel * lbl_cantidadActual;
        QLabel * lbl_BandaTActual;
        QLabel * lbl_BandaTProcesada;
        bool corriendo;
        bool pausa;

        hilo_maquinaMasa1();
        void __init__(MaquinaMezclaMasaChocolate *,QLabel *,QLabel *,QLabel *,QLabel *);
        void run();
        void stop();
        void pause();
        void resume();
};
#endif // HILO_MAQUINAMASA1_H
