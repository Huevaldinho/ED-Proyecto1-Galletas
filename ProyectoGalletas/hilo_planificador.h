#ifndef HILO_PLANIFICADOR_H
#define HILO_PLANIFICADOR_H
#include "Estructuras.h"


class hilo_planificador: public QThread{
    public:
        hilo_planificador();
        Planificador * planificador;
        bool corriendo;
        bool pausa;

        void __init__(Planificador *);
        void run();
        void stop();
        void pause();
        void resume();

};


#endif // HILO_PLANIFICADOR_H
