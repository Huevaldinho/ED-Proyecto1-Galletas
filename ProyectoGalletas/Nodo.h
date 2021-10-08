#ifndef NODO_H
#define NODO_H
#include "Estructuras.h"


struct Nodo{//Nodo de la lista doblemente enlazada //Nodo equivale a paquete
    public:
        int cantidadPaquetes;
        int cantidadGalletas;
        string nombre;
        Nodo * siguiente;
        Nodo * anterior;

        Nodo(int d,string _nombre,int _cantidadPaquetes){
            cantidadPaquetes= _cantidadPaquetes;
            cantidadGalletas = d;
            nombre=_nombre;
            siguiente = anterior = NULL;
        }
        Nodo(){
            cantidadPaquetes=0;
            cantidadGalletas = 0;
            nombre="N/A";
            siguiente = anterior = NULL;
        }
        void imprimir (){
            cout << "<-|" << cantidadGalletas << "|-> ";
        }
};
#endif // NODO_H
