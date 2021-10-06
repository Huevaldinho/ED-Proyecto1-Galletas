#ifndef CREARPUNTEROS_H
#define CREARPUNTEROS_H

#include "Estructuras.h"

struct CrearPunteros{
    CrearPunteros(){
        //planificador
        Planificador * planificador = new Planificador();
        //paquetes
        ListaPaquetes * paquetes = new ListaPaquetes();
        //cola almacen
        ColaAlmacen * colaAlmacen = new ColaAlmacen();
        //almacen
        Almacen * almacen = new Almacen();
        //carrito
        Carrito * carrito = new Carrito();
        //mezcladora masa 1
        MaquinaMezclaMasaChocolate * maquinaMasa1 = new MaquinaMezclaMasaChocolate();
        //mezcladora masa 2
        MaquinaMezclaMasaChocolate * maquinaMasa2 = new MaquinaMezclaMasaChocolate();
        //mezcladora chocolate
        MaquinaMezclaMasaChocolate * maquinaChocolate = new MaquinaMezclaMasaChocolate();
        //banda de masa - ensambladora
        ColaBandas * colaMasaEnsambladora = new ColaBandas();
        //banda de chocolate - ensambladora
        ColaBandas * colaChocolateEnsambladora = new ColaBandas();
        //ensambladora
        MaquinaEnsambladora * maquinaEnsambladora = new MaquinaEnsambladora();
        //banda ensambladora - horno
        ColaBandas * colaEnsambladoraHorno = new ColaBandas();
        //horno
        Horno * horno = new Horno();
        //supervisores (banda nueva)

        //empacadora
        MaquinaEmpacadora * maquinaEmpacadora = new MaquinaEmpacadora();
        //transporte

        //almacen final

    }
};






















#endif // CREARPUNTEROS_H
