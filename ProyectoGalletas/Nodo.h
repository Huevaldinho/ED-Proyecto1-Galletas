#ifndef NODO_H
#define NODO_H
#include "Estructuras.h"

struct Nodo{//Nodo de la lista doblemente enlazada //Nodo equivale a paquete
    public:
        int cantidadPaquetes;
        int cantidadGalletas;
        int duracionProceso;
        int procesoPaquetesEnsambladora;
        int probabilidad;
        string nombre;
        Nodo * siguiente;
        Nodo * anterior;

        Nodo(int d,string _nombre,int _cantidadPaquetes, int _procesoPaquete,int duracionPaquete,int _probabilidad){
            cantidadPaquetes= _cantidadPaquetes;
            cantidadGalletas = d;
            nombre=_nombre;
            duracionProceso=duracionPaquete;
            procesoPaquetesEnsambladora=_procesoPaquete;
            probabilidad=_probabilidad;
            siguiente = anterior = NULL;
        }
        Nodo(){
            duracionProceso=1;
            procesoPaquetesEnsambladora=2;
            cantidadPaquetes=0;
            cantidadGalletas = 0;
            probabilidad=1;
            nombre="N/A";
            siguiente = anterior = NULL;
        }
        void imprimir (){

            cout << "<-|" << nombre << "|-> ";
        }
};
#endif // NODO_H
