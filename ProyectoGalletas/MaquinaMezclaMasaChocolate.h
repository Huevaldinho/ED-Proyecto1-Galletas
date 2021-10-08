#ifndef MAQUINAMEZCLAMASACHOCOLATE_H
#define MAQUINAMEZCLAMASACHOCOLATE_H
#include "Estructuras.h"

struct MaquinaMezclaMasaChocolate{//se usan 2 de masa y 1 de chocolate
    public:
        //Como me comunico con el  almacen para encolar?
        int id;
        bool estado;
        int cantidadProcesada;//tipo, cantidad solicitada, cantidad entregada
        int cantidadEnProceso;
        int tiempoProceso;//segundos
        double minimaCapacidad;
        double maximaCapacidad;
        double capacidadActual;//cambia conforme crea la mazcla
        ColaBandas * cola;
        Carrito * carrito;
        ColaAlmacen * colaPeticiones;
        MaquinaMezclaMasaChocolate();
        MaquinaMezclaMasaChocolate(int,double,double, int,bool,ColaBandas *,Carrito *,ColaAlmacen*);
        void setPunteros(ColaBandas *,ColaAlmacen *, Carrito *);
        void setCapacidades(double,double);
        //Cada vez que llega por debajo del minimo pedir al almacen lo que falte para completar el maximo(van a una cola del almacen)
        double pedirMaterial();//le pide al carrito que le traiga maximaCapacidad-capacidadActual
        void procesar();
};
#endif // MAQUINAMEZCLAMASACHOCOLATE_H
