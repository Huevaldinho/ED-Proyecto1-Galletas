#ifndef HILO_PLANIFICADOR_H
#define HILO_PLANIFICADOR_H
#include "Estructuras.h"


class hilo_planificador: public QThread{//TODOS LOS HILOS HEREDAN DE QThread
    public:
        QLabel*etiqueta;
        QLabel*lbl_masa;
        QLabel*lbl_choco;
        Planificador * planificador;
        bool corriendo;
        bool pausa;

        hilo_planificador();
        void __init__(Planificador *, QLabel*,QLabel*,QLabel*);
        void run();
        void stop();
        void pause();
        void resume();

};

#endif // HILO_PLANIFICADOR_H
