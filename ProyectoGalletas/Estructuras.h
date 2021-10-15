#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <iostream>
#include <stdlib.h>
#include<QtCore>
#include <QDebug>
#include <QLabel>
using namespace std;

struct MaquinaEmpacadora;
struct Horno;
struct MaquinaMezclaMasaChocolate;
struct MaquinaEnsambladora;
struct Carrito;
struct Almacen;
struct Receta;
struct ListaPaquetes;
struct Supervisor;
struct Planificador;
struct ColaAlmacen;
struct ColaBandas;
struct NodoBandas;
struct ListaBandejas;
struct Transportador;
struct Nodo;
struct Transportadores;
struct NodoBandeja;
struct NodoColaPeticiones;
class hilo_planificador;
class hilo_maquinaMasa1;

#include "Almacen.h"
#include "Carrito.h"
#include "ColaAlmacen.h"
#include "ColaBandas.h"
#include "Horno.h"
#include "ListaBandejas.h"
#include "ListaPaquetes.h"
#include "MaquinaEmpacadora.h"
#include "MaquinaEnsambladora.h"
#include "MaquinaMezclaMasaChocolate.h"
#include "Nodo.h"
#include "NodoBandas.h"
#include "NodoBandeja.h"
#include "NodoColaPeticiones.h"
#include "Planificador.h"
#include "Receta.h"
#include "Supervisor.h"
#include "Transportador.h"
#include "Transportadores.h"
#include "hilo_planificador.h"
#include "hilo_maquinamasa1.h"
#endif // ESTRUCTURAS_H
