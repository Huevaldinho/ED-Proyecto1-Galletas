#ifndef COLAALMACEN_H
#define COLAALMACEN_H
#include "Estructuras.h"

struct ColaAlmacen{//No podemos usar la misma cola para bandas porque la del almacen no tiene limite
    public:
        NodoColaPeticiones * frente;
        int totalPeticiones;
        int pendientes;

        ColaAlmacen();
        bool estaVacia();
        void encolar(double _cantidadSolicitada, int _idMaquina);
        NodoColaPeticiones * desencolar(void);
        void imprimir();
};
#endif // COLAALMACEN_H
