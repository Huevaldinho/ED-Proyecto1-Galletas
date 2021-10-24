#ifndef HILO_HORNO_H
#define HILO_HORNO_H

#include "Estructuras.h"
#include <QLabel>
#include <QTableWidget>
class hilo_Horno: public QThread{
    public:
        Horno * horno;
        QLabel * lbl_BandaTActual;
        QLabel * lbl_BandaTMax;
        QLabel * lbl_BandejasActivas;
        QTableWidget * tabla;
        bool corriendo;
        bool pausa;

        hilo_Horno();
        void __init__(Horno*,QLabel *,QLabel *,QLabel *);
        void run();
        void stop();
        void pause();
        void resume();
};

#endif // HILO_HORNO_H
