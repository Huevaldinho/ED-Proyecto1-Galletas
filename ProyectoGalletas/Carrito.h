#ifndef CARRITO_H
#define CARRITO_H
#include "Estructuras.h"

struct Carrito{
    public:
        double capacidadTransporteMezcla;
        double capacidadTransporteChocolate;
        int duracion;
        bool estado;
        Carrito();
        Carrito(double,double,int,bool);
        void setEstado(bool );
        void setCapacidades(double,double);
        void setCapacidadTransporteMezcla(double);
        void setCapacidadTransporteChocolate(double);
};
#endif // CARRITO_H
