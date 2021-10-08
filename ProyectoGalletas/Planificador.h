#ifndef PLANIFICADOR_H
#define PLANIFICADOR_H
#include "Estructuras.h"

struct Planificador{
    public:
        //Recibe paquetes de x cantidad.
        ListaPaquetes * listaPaquetes;//Guarda las ordenes de paquetes en la lista
        Almacen * almacen;
        MaquinaMezclaMasaChocolate * maquinaMasa1;
        MaquinaMezclaMasaChocolate * maquinaMasa2;
        MaquinaMezclaMasaChocolate * maquinaChocolate;
        double cantidadSolicitadaGalletas;
        double cantidadNecesariaMasa;
        double cantidadNecesariaChocolate;
        Receta * receta;//Cantidad de masa y chocolate por galleta
        Planificador();
        void setPunteros(ListaPaquetes *,Almacen *,MaquinaMezclaMasaChocolate *,MaquinaMezclaMasaChocolate *,
                         MaquinaMezclaMasaChocolate *,Receta *);
        double calcularCantidadGalletasSolicitadas();//(paquete1*cantidadDeGalletas) + (paquete2*cantidadDeGalletas). se guarda en cantidadSolicitada
        void modificarReceta(double, double);//Cambia la cantidad de masa y chocolate
};
#endif // PLANIFICADOR_H
