#include "Estructuras.h"

#include <QDebug>
Planificador::Planificador(){
    this->listaPaquetes=NULL;
    this->receta = NULL;
    this->almacen=NULL;
    this->cantidadSolicitadaGalletas=0;
    this->cantidadNecesariaChocolate=0;
    this->cantidadNecesariaMasa=0;
    this->maquinaMasa1=NULL;
    this->maquinaChocolate=NULL;
    this->maquinaMasa2=NULL;
    this->maquinaEnsambladora = NULL;
}

void Planificador::setPunteros(ListaPaquetes * _listaPaquetes,Almacen * _almacen,MaquinaMezclaMasaChocolate *_maquinaMasa1,
                               MaquinaMezclaMasaChocolate *_maquinaMasa2, MaquinaMezclaMasaChocolate *_maquinaChocolate,Receta * _receta,
                               MaquinaEnsambladora * ensambladora){
    this->almacen=_almacen;
    this->maquinaMasa1=_maquinaMasa1;
    this->maquinaMasa2=_maquinaMasa2;
    this->maquinaChocolate=_maquinaChocolate;
    this->maquinaEnsambladora = ensambladora;
    this->listaPaquetes=_listaPaquetes;
    this->receta=_receta;

}
double Planificador::calcularCantidadGalletasSolicitadas(){
    if (this->listaPaquetes!=NULL){
        this->cantidadSolicitadaGalletas=this->listaPaquetes->getCantidadGalletas();
        this->cantidadNecesariaMasa=cantidadSolicitadaGalletas*this->receta->cantidadMasa;
        this->cantidadNecesariaChocolate=cantidadSolicitadaGalletas*this->receta->cantidadChocolate;
    }
    return cantidadSolicitadaGalletas;
};
void Planificador::modificarReceta(double masa, double chocolate){
    //Cambia la cantidad de masa y chocolate
    receta->setCantidadMasa(masa);
    receta->setCantidadChocolate(chocolate);
    //Se tiene que modificar toda la produccion
};

