#ifndef HILO_EMPACADORA_H
#define HILO_EMPACADORA_H
#include "Estructuras.h"
#include <QLabel>
#include <QTableWidget>

class hilo_Empacadora: public QThread{
    public:
        MaquinaEmpacadora * empacadora;
        QTableWidget * tabla;
        QTableWidget * tablaAF;
        QLabel * lbl_galletasTotales;
        bool corriendo;
        bool pausa;
        hilo_Empacadora();
        void __init__(MaquinaEmpacadora *);
        void run();
        void stop();
        void pause();
        void resume();
};

#endif // HILO_EMPACADORA_H
