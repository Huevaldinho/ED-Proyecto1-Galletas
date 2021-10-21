#ifndef HILO_SUPERVISORES_H
#define HILO_SUPERVISORES_H

#include "Estructuras.h"
#include <QLabel>
class hilo_Supervisores: public QThread{
    public:
        QLabel*lbl_aprobo;
        QLabel*lbl_rechazo;
        Supervisor * supervisor1;
        Supervisor * supervisor2;
        bool corriendo;
        bool pausa;

        hilo_Supervisores();
        void __init__(Supervisor *,Supervisor *,QLabel*,QLabel*);
        void run();
        void stop();
        void pause();
        void resume();



};

#endif // HILO_SUPERVISORES_H
