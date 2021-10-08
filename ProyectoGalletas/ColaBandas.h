#ifndef COLABANDAS_H
#define COLABANDAS_H
#include "Estructuras.h"

struct ColaBandas {//Cola de masa o galletas
       NodoBandas * frente; // ERROR sin ultimo nodo <- eso lo escribio el profe
       double maximaCapacidad;//Ejemplo: 5000000 gramos o 10000 galletas HAY que calcularlo
       double actual;//cantidad de nodos actuales, revisar cuanta cantidad tiene los nodos
       ColaBandas();
       NodoBandas * verFrente(void);
       void imprimir(void);
       void modificarMaximaCapacidada(double);
       void encolar(double);
       NodoBandas * desencolar(void);
       bool vacia (void);
       bool puedeEncolar();
       void calcularMaxActual();
};
#endif // COLABANDAS_H
