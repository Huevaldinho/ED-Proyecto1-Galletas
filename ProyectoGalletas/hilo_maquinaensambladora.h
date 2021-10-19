#ifndef HILO_MAQUINAENSAMBLADORA_H
#define HILO_MAQUINAENSAMBLADORA_H

#include "Estructuras.h"
#include <QLabel>

class hilo_MaquinaEnsambladora: public QThread{
    public:


    MaquinaEnsambladora * maquinaEnsambladora;
    QLabel * lbl_totalProduccion;
    QLabel * lbl_cantidadActual;
    QLabel * lbl_BandaTActual;
    QLabel * lbl_BandaTProcesada;
    bool corriendo;
    bool pausa;

    hilo_MaquinaEnsambladora();
    void __init__(MaquinaEnsambladora *,QLabel *,QLabel *,QLabel *);
    void run();
    void stop();
    void pause();
    void resume();
};

#endif // HILO_MAQUINAENSAMBLADORA_H
