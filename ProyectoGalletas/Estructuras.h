#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H


#include <iostream>
using namespace std;

struct BandaTransportadora;
struct MaquinaEmpacadora;
struct Horno;
struct MaquinaMezclaMasaChocolate;
struct MaquinaEnsambladora;
struct Carrito;
struct Almacen;
struct Receta;
struct Paquete;
struct ListaPaquetes;
struct Cola;
struct NodoCola;
struct Supervisores;
struct Planificador;
struct Cola;
struct ColaAlmacen;
struct ColaBandas;
struct NodoBandas;
struct ListaBandejas;

struct NodoBandas {//Guarda la cantidad de masa o galletas
       double dato; //cantidad de masa, chocolate o galletas
       NodoBandas * siguiente;// puntero para enlazar nodos
       NodoBandas(double d){
                dato = d; // asigna los datos
                siguiente = NULL; // sig es null
       }
      void imprimir();
};
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

struct Supervisores{
    public:

};

struct MaquinaEmpacadora{
    //Antes de ella tiene dos inspectores
    //Si se llena la banda el horno se apaga
    //Se manejan paquetes
    public:
        //Dos supervisores


};
struct NodoBandeja{
    int horneadas;//cuantas galletas ha horneado
    int actual;//son las galletas en espera, o sea, las que se estan horneando en ese momento
    bool estado;
    NodoBandeja * siguienteBandeja;
    NodoBandeja * anteriorBandeja;


    NodoBandeja(){
        horneadas = 0;
        actual = 0;
        estado=true;
        siguienteBandeja = NULL;
        anteriorBandeja=NULL;
    }

    NodoBandeja(int galletas){
        estado=true;
        actual += galletas;
        horneadas += galletas;

    }
    void setEstado(bool _estado){
        estado=_estado;
    }
    void imprimir(){
        cout << " | " << actual << " | -> ";
    }

};
struct ListaBandejas{//usar lista simple o doble
    NodoBandeja * primeraBandeja;
    NodoBandeja * ultimaBandeja;
    int cantidadActual;
    int maximoBandejas;
    ListaBandejas();
    bool estaVacia();
    void insertarAlFinal(int);
    NodoBandeja *  borrarAlFinal();
    void imprimir();

};
struct Horno{
    //El horneado se empiza cuando se llenen las bandejas activas
    public:
        int bandejasFuncionando;
        int maximoBandejas;
        int capacidadBandeja;
        int duracionHorneado;
        bool estado;
        ListaBandejas * bandejas;
        ColaBandas * colaEntrada;
        ColaBandas * colaSalida;
        Horno();
        void HornearGalletas();

};
struct MaquinaMezclaMasaChocolate{//se usan 2 de masa y 1 de chocolate
    public:
        //Como me comunico con el  almacen para encolar?
        int id;
        bool estado;
        int cantidadProcesada;//tipo, cantidad solicitada, cantidad entregada
        int cantidadEnProceso;
        int tiempoProceso;//segundos
        double minimaCapacidad;
        double maximaCapacidad;
        double capacidadActual;//cambia conforme crea la mazcla
        ColaBandas * cola;
        MaquinaMezclaMasaChocolate();
        MaquinaMezclaMasaChocolate(int,double,double, int,bool,ColaBandas *);
        void setCola(ColaBandas *);
        void setCapacidades(double,double);
        //Cada vez que llega por debajo del minimo pedir al almacen lo que falte para completar el maximo(van a una cola del almacen)
        double pedirMaterial();//le pide al carrito que le traiga maximaCapacidad-capacidadActual
        void procesar();
};
struct MaquinaEnsambladora{
    public:
        int galletasHechas;
        int galletasEnProceso;
        int duracion;
        bool estado;
        ColaBandas * colaEntradaMasa;
        ColaBandas * colaEntradaChocolate;
        ColaBandas * colaSalida;


        //Recibe materia prima y retorna deliciosas galletas
        MaquinaEnsambladora();
        MaquinaEnsambladora(ColaBandas *,ColaBandas *,ColaBandas *);
        void setEstado(bool);


};
struct Carrito{
    public:
        double capacidadTransporteMezcla;
        double capacidadTransporteChocolate;
        int duracion;
        bool estado;
        Carrito();
        Carrito(double,double,int,bool);
        void setEstado(bool );
        void setCapacidades(double,double);
        void setCapacidadTransporteMezcla(double);
        void setCapacidadTransporteChocolate(double);
};
struct Almacen{//Falta
    //Cantidad iliminada de mezcla y chocolate.
    //Cola de peticiones debe poder verse y tambien las peticiones procesadas
    public:
        Carrito * carrito;
        ColaAlmacen * colaPeticiones;
        int peticionesProcesadas;
        int peticionesActuales;
        Almacen();
        Almacen(double,double,int,ColaAlmacen *);
        void setColaPeticiones(ColaAlmacen * _colaPeticiones);
        double darCantidades(double);
        double verPeticiones();//ver peticiones en cola pendientes y las que ha procesado

};
struct Nodo{//Nodo de la lista doblemente enlazada
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
struct ListaPaquetes{//Doblemente enlazada circular, son los paquetes
    public:
        Nodo * primerNodo;
        ListaPaquetes();
        bool estaVacia();
        void insertar(int,string,int);
        void imprimir();
        Nodo * buscar(int,string);
        Nodo * eliminar(int,string);
        double getCantidadGalletas();
};
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
struct ColaAlmacen{//No podemos usar la misma cola para bandas porque la del almacen no tiene limite
    public:
        NodoColaPeticiones * frente;
        int totalPeticiones;
        int pendientes;

        ColaAlmacen();
        bool estaVacia();
        void encolar(double _cantidadSolicitada, int _idMaquina);
        NodoColaPeticiones * desencolar(void);
        void imprimir();
};
struct Receta{
    public:
        double cantidadMasa;
        double cantidadChocolate;
        string unidad;
        Receta();
        Receta(double,double);
        void setCantidadMasa(double);
        void setCantidadChocolate(double);

};
struct Planificador{
    public:
        //Recibe paquetes de x cantidad.
        ListaPaquetes * listaPaquetes;//Guarda las ordenes de paquetes en la lista
        double cantidadSolicitadaGalletas;
        double cantidadNecesariaMasa;
        double cantidadNecesariaChocolate;
        Receta * receta;//Cantidad de masa y chocolate por galleta
        Planificador();
        void leerListaPaquetes(ListaPaquetes * lista);
        double calcularCantidadGalletasSolicitadas();//(paquete1*cantidadDeGalletas) + (paquete2*cantidadDeGalletas). se guarda en cantidadSolicitada
        void modificarReceta(double, double);//Cambia la cantidad de masa y chocolate
};
#endif // ESTRUCTURAS_H
