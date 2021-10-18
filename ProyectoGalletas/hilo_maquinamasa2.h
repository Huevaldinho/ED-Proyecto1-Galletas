#ifndef HILO_MAQUINAMASA2_H
#define HILO_MAQUINAMASA2_H
#include "Estructuras.h"
#include <QLabel>

class hilo_maquinaMasa2: public QThread{
    public:
        MaquinaMezclaMasaChocolate * maquinaMasa2;
        QLabel * lbl_totalProduccion;
        QLabel * lbl_cantidadActual;
        bool corriendo;
        bool pausa;

        hilo_maquinaMasa2();
        void __init__(MaquinaMezclaMasaChocolate *,QLabel *,QLabel *);
        void run();
        void stop();
        void pause();
        void resume();
};


#endif // HILO_MAQUINAMASA2_H
