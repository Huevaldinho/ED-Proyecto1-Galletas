#ifndef LISTABANDEJAS_H
#define LISTABANDEJAS_H
#include "Estructuras.h"

struct ListaBandejas{//usar lista simple o doble
    NodoBandeja * primeraBandeja;
    NodoBandeja * ultimaBandeja;
    int cantidadActual;//cantidad de bandejas utilizandas
    int maximoBandejas;
    double totalCapacidadGalletas;
    double galletasActuales;
    ListaBandejas();
    bool estaVacia();
    void insertarAlFinal(NodoBandeja *);
    NodoBandeja *  borrarAlFinal();
    void imprimir();
    int contarBandejas();
    void totalCapacidad();
};
#endif // LISTABANDEJAS_H
