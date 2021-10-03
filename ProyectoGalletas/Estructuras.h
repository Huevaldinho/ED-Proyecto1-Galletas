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
struct Supervisores;
struct Planificador;



struct Supervisores{

};
struct BandaTransportadora{
    //son colas
    double capacidadMaxima;//puede ser mezcla o galleta, debe ser modificable
    double actual;
    //se debe mostrar la cantidad de galletas o mezcla que hay en cada cola y el máximo seteado.
    //pausar la maquina que la alimenta cuando se alcance la capacidadMaxima.
    Cola * cola;
};
struct MaquinaEmpacadora{
    //Antes de ella tiene dos inspectores
    //Si se llena la banda el horno se apaga
    //Se manejan paquetes
};
struct Horno{
    //Tiene dos bandejas por defecto, se puede agregar hasta 6.
    //Se hornea hasta que la cantidad de bandejas que tiene esten llenas
    //Se puede modificar la cantidad de galletas por bandejas
    //Tiene un tiempo de horneado
    //Las bandejas tienen contadores de cuantas han horneado y cuantas tienen actualmente
    //encendido/apagado
};
struct MaquinaMezclaMasaChocolate{//se usan 2 de masa y 1 de chocolate
    int id;
    int cantidadProcesada;//tipo, cantidad solicitada, cantidad entregada
    int cantidadEnProceso;
    double tiempoProceso;//segundos
    double minimaCapacidad;
    double maximaCapacidad;
    double capacidadActual;//cambia conforme crea la mazcla
    MaquinaMezclaMasaChocolate(){
        minimaCapacidad=50;
        maximaCapacidad=100;
        tiempoProceso=10;
        cantidadProcesada=0;
        cantidadEnProceso=0;
        capacidadActual=0;
    }
    MaquinaMezclaMasaChocolate(int _id,double _minimaCapacidad,double _maximaCapacidad, double _tiempoProceso){
        id=_id;
        minimaCapacidad=_minimaCapacidad;
        maximaCapacidad=_maximaCapacidad;
        tiempoProceso=_tiempoProceso;
        cantidadProcesada=0;
        cantidadEnProceso=0;
        capacidadActual=0;
    }

    //Cada vez que llega por debajo del minimo pedir al almacen lo que falte para completar el maximo(van a una cola del almacen)
    double pedirMaterial();//le pide al carrito que le traiga maximaCapacidad-capacidadActual
};
struct MaquinaEnsambladora{
    int galletasHechas;
    int galletasEnProceso;
    //Recibe materia prima y retorna deliciosas galletas
};
struct Carrito{
    double capacidadTransporteMezcla;
    double capacidadTransporteChocolate;
    double duracion;
    bool estado;
    Carrito(){
        capacidadTransporteMezcla=0;
        capacidadTransporteChocolate=0;
        duracion=0;
        estado=true;
    }
    Carrito(double _capacidadTransporteMezcla,double _capacidadTransporteChocolate,double _duracion, bool _estado){
        capacidadTransporteMezcla=_capacidadTransporteMezcla;
        capacidadTransporteChocolate=_capacidadTransporteChocolate;
        duracion=_duracion;
        estado=_estado;
    }
    void setEstado(bool _estado){estado=_estado;}
    void setCapacidadTransporteMezcla(double _capacidadTransporteMezcla){capacidadTransporteMezcla=_capacidadTransporteMezcla;}
    void setCapacidadTransporteChocolate(double _capacidadTransporteChocolate){capacidadTransporteChocolate=_capacidadTransporteChocolate;}
};
struct Almacen{
    //Cantidad iliminada de mezcla y chocolate.
    //Cola de peticiones debe poder verse y tambien las peticiones procesadas
    Carrito * carrito;
    Cola * colaPeticiones;
    int peticionesProcesadas;
    int peticionesActuales;
    Almacen(){
        carrito = NULL;
        peticionesProcesadas=0;
        peticionesActuales=0;
    }
    Almacen(double capacidadTransporteCarritoMasa, double capacidadTransporteCarritoChocolate,double duracionCarrito){
        carrito = new Carrito(capacidadTransporteCarritoMasa,capacidadTransporteCarritoChocolate,duracionCarrito,true);
    }
    double darCantidades(double _solicitud){return _solicitud;}
    double verPeticiones();//ver peticiones en cola pendientes y las que ha procesado
};

/*struct Nodo{
    int cantidadGalletas;
    string nombre;
    Nodo * siguiente;
    Nodo * anterior;

    Nodo(){
        cantidadGalletas = 0;
        nombre="";
        siguiente = anterior = NULL;
    }
    Nodo(int _cantidadGalletas,string _nombre){
        cantidadGalletas = _cantidadGalletas;
        nombre=_nombre;
        siguiente = anterior = NULL;
    }
    void imprimir(){
        cout <<" <-"<< cantidadGalletas<<"|" <<nombre<< "-> ";
    }
};*/
/*
struct ListaPaquetes{
    Paquete * primerNodo;
    Paquete * ultimoNodo;
    int largo;

    ListaPaquetes(){
        primerNodo = ultimoNodo = NULL;
        largo = 0;
    }
    bool estaVacia();
    void insertarAlInicio(int,string);
    void insertarAlFinal(int,string);
    void imprimir();
    void imprimirDesdeElFinal();
    Paquete * borrarAlInicio();
    Paquete * borrarAlFinal();
    Paquete * buscar(int,string);
    void insertarEnPosicion(int,string);
    int getLargo();
};*/


struct Nodo{
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
        cantidadPaquetes=1;
        cantidadGalletas = 0;
        nombre="N/A";
        siguiente = anterior = NULL;
    }
    void imprimir (){
        cout << "<-|" << cantidadGalletas << "|-> ";
    }
};

struct ListaPaquetes{
    Nodo * primerNodo;

    int largo;
    ListaPaquetes();

    bool estaVacia();
    void insertar(int,string,int);
    void imprimir();
    Nodo * buscar(int,string);
    Nodo * eliminar(int,string);
    double getCantidadGalletas();

};
struct Cola{
    Nodo * primerNodo;//creo que se llaman diferente xd
    Nodo * ultimoNodo;
    Cola(){
        primerNodo = ultimoNodo =  NULL;
    }
    bool estaVacia();
    bool estaLlena();
    void insertarAlFinal(string);
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
