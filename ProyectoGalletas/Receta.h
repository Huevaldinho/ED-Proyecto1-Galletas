#ifndef RECETA_H
#define RECETA_H
#include "Estructuras.h"

struct Receta{
    public:
        double cantidadMasa;
        double cantidadChocolate;
        string unidad;
        Receta();
        Receta(double,double);
        void setCantidadMasa(double);
        void setCantidadChocolate(double);

};
#endif // RECETA_H
