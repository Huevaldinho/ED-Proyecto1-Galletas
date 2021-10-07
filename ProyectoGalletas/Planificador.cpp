#include "Estructuras.h"

#include <QDebug>
Planificador::Planificador(){
    this->listaPaquetes=NULL;
    this->receta = new Receta();
    this->cantidadSolicitadaGalletas=0;
}

void Planificador::setPunteros(ListaPaquetes * _listaPaquetes,Almacen * _almacen,MaquinaMezclaMasaChocolate *_maquinaMasa1,
                               MaquinaMezclaMasaChocolate *_maquinaMasa2, MaquinaMezclaMasaChocolate *_maquinaChocolate){
    this->almacen=_almacen;
    this->maquinaMasa1=_maquinaMasa1;
    this->maquinaMasa2=_maquinaMasa2;
    this->maquinaChocolate=_maquinaChocolate;
    this->listaPaquetes=_listaPaquetes;

}
double Planificador::calcularCantidadGalletasSolicitadas(){
    /*
        Toma la lista si no es vacia y llama al metodo que le da la cantidad de galletas que hay en la lista.
        (ese metodo revisa todos los nodos multiplica los paquetes por la cantidad de galletas y retorna el total de galletas)
        Luego calcula la cantidad necesaria de masa y chocolate para crear ese total de galletas
        retorna la cantidad de galletas por si  alguien mas necesita saber o algo asi jaja xd

        Cada vez que se ingrese un pedido nuevo a la lista debe recalcular la cantidad necesaria de materiales

    */
    //Pide la cantidad de galletas a la lista
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

