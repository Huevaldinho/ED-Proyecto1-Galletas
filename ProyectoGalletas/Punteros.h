#ifndef PUNTEROS_H
#define PUNTEROS_H

#include "Estructuras.h"


struct Punteros{
    //planificador
    Planificador * planificador = new Planificador();

    //receta
    Receta * _receta = new Receta();

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
        //listaBandejas
        ListaBandejas * listaBandejas = new ListaBandejas();//falta agregarle nodosbandeja
            //Bandejas
            NodoBandeja * nodoBandeja1 = new NodoBandeja();
            NodoBandeja * nodoBandeja2 = new NodoBandeja();

    //supervisores (banda nueva)
    ColaBandas * colaSupervisores = new ColaBandas();
    Supervisor * supervisor1 = new Supervisor();
    Supervisor * supervisor2 = new Supervisor();

    //empacadora
    MaquinaEmpacadora * maquinaEmpacadora = new MaquinaEmpacadora();

    //transporte


    //almacen final
    Punteros(){}
    void setPunteros(){
        //------------------------SET PUNTEROS------------------------//
        planificador->setPunteros(paquetes,almacen,maquinaMasa1,maquinaMasa2,maquinaChocolate, _receta);//pts planificador

        almacen->setCarrito(carrito);//pt carrito almacen
        almacen->setColaPeticiones(colaAlmacen);//pt colaAlmacen

        maquinaMasa1->setPunteros(colaMasaEnsambladora,colaAlmacen,carrito);//pts maquinaMasa1
        maquinaMasa2->setPunteros(colaMasaEnsambladora,colaAlmacen,carrito);//pts maquinaMasa2
        maquinaChocolate->setPunteros(colaChocolateEnsambladora,colaAlmacen,carrito);//pts maquinaChocolate

        maquinaEnsambladora->setPunteros(colaChocolateEnsambladora,colaMasaEnsambladora,colaEnsambladoraHorno); //pts maquina ensambladora

        horno->setPunteros(listaBandejas,colaEnsambladoraHorno,colaSupervisores);//pts horno

        supervisor1->setPunteros(colaSupervisores,paquetes);//pts supervisores
        supervisor2->setPunteros(colaSupervisores,paquetes);//pts supervisores

        maquinaEmpacadora->setGalletasAceptadas(supervisor1,supervisor2);

        listaBandejas->insertarAlFinal(nodoBandeja1);
        listaBandejas->insertarAlFinal(nodoBandeja2);


        Transportadores * trans = paquetes->getTransportadores();
        /*

         se crean n transportadores según la n cantidad de paquetes que hay, pero si lo hago aquí no va a servir porque obvio
        la lista de paquetes está vacia entonces no sé como hacer eso, me dejo bateadisimo

        */
    }

};






















#endif // PUNTEROS_H
