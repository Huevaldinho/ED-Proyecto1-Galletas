#ifndef SUPERVISOR_H
#define SUPERVISOR_H
#include "Estructuras.h"

struct Supervisor{
    //esta es como cualquier otra cola de banda, solo que los "supervisores" quitan galletas que llegan y manda otras
    // se crea la banda por aparte y los supervisores pueden mandar a desencolar a la banda con su probabilidad
    public:
        ColaBandas * colaSupervisores;
        double probabilidadDesecho;
        int galletasAceptadas;
        int galletasRechazadas;
        ListaPaquetes*listaPaquetes; //esto es solo para actualizar la lista cuando termine de evaluar //como en el planificador

        Supervisor();
        void setPunteros(ColaBandas*,ListaPaquetes*);
        void setProbabilidad(double);
        void quitarGalletas(); //realmente es solo desencolar desde la cola.
        ListaPaquetes*actualizarListaPaquetes();

};
#endif // SUPERVISOR_H
