#ifndef LISTAPAQUETES_H
#define LISTAPAQUETES_H
#include "Estructuras.h"

struct ListaPaquetes{//Doblemente enlazada circular, son los paquetes
    public:
        Nodo * primerNodo;
        Transportadores * listaTransportadores;
        int largo;

        ListaPaquetes();
        bool estaVacia();
        void insertar(int,string,int,int,int,int);
        void imprimir();
        Nodo * buscar(int,string);
        Nodo * eliminar(int,string);
        double getCantidadGalletas();
        Transportadores * getTransportadores();
        void setTransportadores(Transportadores *);
        void setProbabilidades();

};
#endif // LISTAPAQUETES_H
