#ifndef LISTABANDEJAS_H
#define LISTABANDEJAS_H
#include "Estructuras.h"

struct ListaBandejas{//usar lista simple o doble
    NodoBandeja * primeraBandeja;
    NodoBandeja * ultimaBandeja;
    int cantidadActual;
    int maximoBandejas;
    ListaBandejas();
    bool estaVacia();
    void insertarAlFinal(NodoBandeja *);
    NodoBandeja *  borrarAlFinal();
    void imprimir();
};
#endif // LISTABANDEJAS_H
