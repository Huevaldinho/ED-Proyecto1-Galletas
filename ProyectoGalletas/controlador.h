#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "Estructuras.h"
#include "Punteros.h"

//Esto se utiliza de intermediario entre la ui y la programacion pura.
class Controlador{
    public:
        Punteros * punteros;
        Controlador(Punteros * punte);
        void iniciarHiloPlanificador();
};

#endif // CONTROLADOR_H
