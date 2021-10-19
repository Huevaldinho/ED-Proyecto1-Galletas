#ifndef NODOBANDAS_H
#define NODOBANDAS_H
#include "Estructuras.h"
#include <QDebug>

struct NodoBandas {//Guarda la cantidad de masa o galletas
       double dato; //cantidad de galletas
       NodoBandas * siguiente;// puntero para enlazar nodos
       NodoBandas(double d){
                dato = d; // asigna los datos
                siguiente = NULL; // sig es null
       }
       void imprimir(){
           qDebug()<<"|"<< dato << "|-> ";
       }
};
#endif // NODOBANDAS_H
