#ifndef ALMACEN_H
#define ALMACEN_H
#include "Estructuras.h"

struct Almacen{//Falta
    //Cantidad iliminada de mezcla y chocolate.
    //Cola de peticiones debe poder verse y tambien las peticiones procesadas
    public:
        Carrito * carrito;
        ColaAlmacen * colaPeticiones;
        int peticionesProcesadas;
        int peticionesActuales;
        Almacen();
        Almacen(ColaAlmacen *);
        void setColaPeticiones(ColaAlmacen * _colaPeticiones);
        void setCarrito(Carrito *);
        double darCantidades(double);
        double verPeticiones();//ver peticiones en cola pendientes y las que ha procesado

};
#endif // ALMACEN_H
