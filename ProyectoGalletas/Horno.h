#ifndef HORNO_H
#define HORNO_H
#include "Estructuras.h"

struct Horno{
    //El horneado se empiza cuando se llenen las bandejas activas
    public:
        int bandejasFuncionando;
        int maximoBandejas;
        int duracionHorneado;
        bool estado;
        ListaBandejas * bandejas;
        ColaBandas * colaEntrada;
        ColaBandas * colaSalida;
        Horno();
        void setPunteros(ListaBandejas *, ColaBandas *, ColaBandas *);
        void HornearGalletas();
};
#endif // HORNO_H
