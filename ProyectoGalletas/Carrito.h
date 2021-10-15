#ifndef CARRITO_H
#define CARRITO_H
#include "Estructuras.h"

struct Carrito{
    public:
        MaquinaMezclaMasaChocolate * maquinaMasa1;
        MaquinaMezclaMasaChocolate * maquinaMasa2;
        MaquinaMezclaMasaChocolate * maquinaChocolate;
        ColaAlmacen * cola;
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
        void setPunteros(ColaAlmacen *, MaquinaMezclaMasaChocolate *, MaquinaMezclaMasaChocolate *, MaquinaMezclaMasaChocolate *);
};
#endif // CARRITO_H
