#ifndef MAQUINAENSAMBLADORA_H
#define MAQUINAENSAMBLADORA_H
#include "Estructuras.h"

struct MaquinaEnsambladora{
    public:
        double galletasAProcesar;
        double galletasHechas;
        double galletasEnProceso;
        double produceNGalletas;
        int duracion;
        bool estado;
        ColaBandas * colaEntradaMasa;
        ColaBandas * colaEntradaChocolate;
        ColaBandas * colaSalida;
        Receta * receta;


        //Recibe materia prima y retorna deliciosas galletas
        MaquinaEnsambladora();

        void setPunteros(ColaBandas *,ColaBandas *,ColaBandas *,Receta *);
        void setEstado(bool);
};
#endif // MAQUINAENSAMBLADORA_H
