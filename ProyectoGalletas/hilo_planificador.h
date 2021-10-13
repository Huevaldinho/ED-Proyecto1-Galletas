#ifndef HILO_PLANIFICADOR_H
#define HILO_PLANIFICADOR_H
#include "Estructuras.h"


class hilo_planificador: public QThread{
    public:
        QLabel*etiqueta;
        hilo_planificador();
        Planificador * planificador;
        bool corriendo;
        bool pausa;

        void __init__(Planificador *, QLabel*);
        void run();
        void stop();
        void pause();
        void resume();

};

#endif // HILO_PLANIFICADOR_H
