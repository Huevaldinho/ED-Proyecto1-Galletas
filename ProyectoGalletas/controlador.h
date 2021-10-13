#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "Estructuras.h"
#include "Punteros.h"

//Esto se utiliza de intermediario entre la ui y la programacion pura.
class Controlador{
    public:
        Punteros * punteros;
        QLabel*etiqueta;
        Controlador(Punteros * punte,QLabel*);
        void iniciarHiloPlanificador();
};

#endif // CONTROLADOR_H
