#ifndef HILO_CARRITO_H
#define HILO_CARRITO_H
#include "Estructuras.h"
#include <QLabel>
#include <QTableWidget>
class hilo_carrito: public QThread{
    public:
        Carrito * carrito;
        QTableWidget * tabla;
        bool corriendo;
        bool pausa;

        hilo_carrito();
        void __init__(Carrito *);
        void run();
        void stop();
        void pause();
        void resume();

};

#endif // HILO_CARRITO_H
