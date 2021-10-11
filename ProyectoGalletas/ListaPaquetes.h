#ifndef LISTAPAQUETES_H
#define LISTAPAQUETES_H
#include "Estructuras.h"

struct ListaPaquetes{//Doblemente enlazada circular, son los paquetes
    public:
        Nodo * primerNodo;
        Transportadores * listaTransportadores;

        ListaPaquetes();
        bool estaVacia();
        void insertar(int,string,int);
        void imprimir();
        Nodo * buscar(int,string);
        Nodo * eliminar(int,string);
        double getCantidadGalletas();
        Transportadores * getTransportadores();
        void setTransportadores(Transportadores *);

};
#endif // LISTAPAQUETES_H
