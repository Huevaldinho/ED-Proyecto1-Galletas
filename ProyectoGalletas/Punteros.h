#ifndef PUNTEROS_H
#define PUNTEROS_H

#include "Estructuras.h"


struct Punteros{
    //planificador
    Planificador * planificador;

    //receta
    Receta * receta;

    //paquetes
    ListaPaquetes * paquetes;

    //cola almacen
    ColaAlmacen * colaAlmacen;

    //almacen
    Almacen * almacen;

    //carrito
    Carrito * carrito;

    //mezcladora masa 1
    MaquinaMezclaMasaChocolate * maquinaMasa1;

    //mezcladora masa 2
    MaquinaMezclaMasaChocolate * maquinaMasa2;

    //mezcladora chocolate
    MaquinaMezclaMasaChocolate * maquinaChocolate;

    //banda de masa - ensambladora
    ColaBandas * colaMasaEnsambladora;

    //banda de chocolate - ensambladora
    ColaBandas * colaChocolateEnsambladora;

    //ensambladora
    MaquinaEnsambladora * maquinaEnsambladora;

    //banda ensambladora - horno
    ColaBandas * colaEnsambladoraHorno;

    //horno
    Horno * horno;
        //listaBandejas
        ListaBandejas * listaBandejas;
            //Bandejas
            NodoBandeja * nodoBandeja1;
            NodoBandeja * nodoBandeja2;

    //supervisores (banda nueva)
    ColaBandas * colaSupervisores;
    ColaBandas * colaEmpacadora;
    Supervisor * supervisor1;
    Supervisor * supervisor2;

    //empacadora
    MaquinaEmpacadora * maquinaEmpacadora;


    //transporte
    Transportadores * trans;

    //almacen final
    Punteros(){
        //planificador
        planificador = new Planificador();

        //receta
        receta = new Receta();

        //paquetes
        paquetes = new ListaPaquetes();

        //cola almacen
        colaAlmacen = new ColaAlmacen();

        //almacen
        almacen = new Almacen();

        //carrito
        carrito = new Carrito();

        //mezcladora masa 1
        maquinaMasa1 = new MaquinaMezclaMasaChocolate();

        //mezcladora masa 2
        maquinaMasa2 = new MaquinaMezclaMasaChocolate();

        //mezcladora chocolate
        maquinaChocolate = new MaquinaMezclaMasaChocolate();

        //banda de masa - ensambladora
        colaMasaEnsambladora = new ColaBandas();

        //banda de chocolate - ensambladora
        colaChocolateEnsambladora = new ColaBandas();

        //ensambladora
        maquinaEnsambladora = new MaquinaEnsambladora();

        //banda ensambladora - horno
        colaEnsambladoraHorno = new ColaBandas();

        //horno
        horno = new Horno();
            //listaBandejas
            listaBandejas = new ListaBandejas();//falta agregarle nodosbandeja
                //Bandejas
                nodoBandeja1 = new NodoBandeja();
                nodoBandeja2 = new NodoBandeja();

        //supervisores (banda nueva)
        colaSupervisores = new ColaBandas();
        supervisor1 = new Supervisor();
        supervisor2 = new Supervisor();

        //empacadora
        maquinaEmpacadora = new MaquinaEmpacadora();


        //transporte
        trans=new Transportadores();
        colaEmpacadora=new ColaBandas();
    }
    void setPunteros(){
        //------------------------SET PUNTEROS------------------------//
        paquetes->setTransportadores(trans);
        planificador->setPunteros(paquetes,almacen,maquinaMasa1,maquinaMasa2,maquinaChocolate, receta,maquinaEnsambladora);//pts planificador
        //qDebug()<<"DIRECCION De MASA 1"<<this->maquinaMasa1;
        //qDebug()<<"DIRECCION De MASA 1 desde el planificador"<<this->planificador->maquinaMasa1;

        almacen->setCarrito(carrito);//pt carrito almacen
        almacen->setColaPeticiones(colaAlmacen);//pt colaAlmacen

        maquinaMasa1->setPunteros(colaMasaEnsambladora,colaAlmacen,carrito);//pts maquinaMasa1
        maquinaMasa1->id=1;
        maquinaMasa2->setPunteros(colaMasaEnsambladora,colaAlmacen,carrito);//pts maquinaMasa2
        maquinaMasa2->id=2;
        maquinaChocolate->setPunteros(colaChocolateEnsambladora,colaAlmacen,carrito);//pts maquinaChocolate
        maquinaChocolate->id=3;
        maquinaEnsambladora->setPunteros(colaChocolateEnsambladora,colaMasaEnsambladora,colaEnsambladoraHorno,receta); //pts maquina ensambladora

        horno->setPunteros(listaBandejas,colaEnsambladoraHorno,colaSupervisores);//pts horno

        supervisor1->setPunteros(colaSupervisores,paquetes,colaEmpacadora);//pts supervisores
        supervisor2->setPunteros(colaSupervisores,paquetes,colaEmpacadora);//pts supervisores

        maquinaEmpacadora->setPunteros(colaEmpacadora,paquetes);

        listaBandejas->insertarAlFinal(nodoBandeja1);
        listaBandejas->insertarAlFinal(nodoBandeja2);

        carrito->setPunteros(colaAlmacen,maquinaMasa1,maquinaMasa2,maquinaChocolate);



        /*

         se crean n transportadores según la n cantidad de paquetes que hay, pero si lo hago aquí no va a servir porque obvio
        la lista de paquetes está vacia entonces no sé como hacer eso, me dejo bateadisimo

        */
    }

};






















#endif // PUNTEROS_H
