#ifndef MAQUINAENSAMBLADORA_H
#define MAQUINAENSAMBLADORA_H
#include "Estructuras.h"

struct MaquinaEnsambladora{
    public:
        int galletasHechas;
        int galletasEnProceso;
        int duracion;
        bool estado;
        ColaBandas * colaEntradaMasa;
        ColaBandas * colaEntradaChocolate;
        ColaBandas * colaSalida;


        //Recibe materia prima y retorna deliciosas galletas
        MaquinaEnsambladora();

        void setPunteros(ColaBandas *,ColaBandas *,ColaBandas *);
        void setEstado(bool);
};
#endif // MAQUINAENSAMBLADORA_H
