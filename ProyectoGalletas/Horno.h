#ifndef HORNO_H
#define HORNO_H
#include "Estructuras.h"

struct Horno{
    //El horneado se empiza cuando se llenen las bandejas activas
    public:
        double bandejasFuncionando;
        double maximoBandejas;
        int duracionHorneado;
        bool estado;
        ListaBandejas * bandejas;
        ColaBandas * colaEntrada;
        ColaBandas * colaSalida;
        Horno();
        void setPunteros(ListaBandejas *, ColaBandas *, ColaBandas *);
        void capacidadTotalGalletas();
};
#endif // HORNO_H
