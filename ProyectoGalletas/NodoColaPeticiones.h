#ifndef NODOCOLAPETICIONES_H
#define NODOCOLAPETICIONES_H
#include "Estructuras.h"

struct NodoColaPeticiones{//Peticiones de material por parte de las maquinas
    public:
        double cantidadSolicitada;
        int idMaquina;//Para saber de quien es la orden
        NodoColaPeticiones * siguiente;
        NodoColaPeticiones * anterior;

        NodoColaPeticiones(){
            cantidadSolicitada=0;
            siguiente = anterior = NULL;
        }
        NodoColaPeticiones(double pedido,int _idMaquina){
            cantidadSolicitada= pedido;
            idMaquina=_idMaquina;
            siguiente = anterior = NULL;
        }
        void imprimir (){
            cout << "<-|" << cantidadSolicitada <<" - maquina"<<idMaquina<< "|-> ";
        }
};
#endif // NODOCOLAPETICIONES_H
