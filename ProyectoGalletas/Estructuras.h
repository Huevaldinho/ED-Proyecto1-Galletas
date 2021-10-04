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


// estructura nodo para lista simple
struct NodoBandaT {
       int dato; // parte de datos

       NodoBandaT* siguiente;// puntero para enlazar nodos
       // constructor

       NodoBandaT(int d)
       {
                dato = d; // asigna los datos
                siguiente = NULL; // sig es null
       }

      void imprimir();

};

struct ColaBandaT {
       // solo con pN es suficiente
       NodoBandaT * frente; // ERROR sin ultimo nodo
       int maximaCapacidad;

       ColaBandaT(){
            frente = NULL;
       }
       NodoBandaT* verFrente(void);
       void imprimir(void);

       void encolar(int cantidad){
            if (vacia())
                frente = new NodoBandaT (cantidad);
            else
            {
                    // referencia al primero para recorrer la lista
                    NodoBandaT * actual = frente;
                    // recorre la lista hasta llegar al penultimo nodo
                    while (actual->siguiente != NULL)
                                  actual = actual->siguiente;

                    // Crea nuevo nodo, lo apunta con uN
                    NodoBandaT * nuevo = new NodoBandaT (cantidad);
                    //le quita el enlace al que era ultimo
                    actual->siguiente = nuevo;
            }
       }
       NodoBandaT * desencolar(void){
             // si no hay elementos, no borra nada, retorna null
             if (vacia()){
                return NULL;
             }else{
                 // un puntero que apunta al nodo que se
                 // "despegara" de la lista y se retorna
                 NodoBandaT* borrado = frente;
                 // pN se pasa al segundo de la lista
                 // porque el primero se eliminara
                 frente = frente->siguiente;
                 // el nodo borrado, se debe despegar
                 // entonces siguiente apunta a null y no
                 // al segundo de la lista que ahora es pN
                 borrado->siguiente = NULL;
                 // aca se deberia liberar la memoria si no se
                 // retornara el borrado
                 return borrado;
             }
       }
       bool vacia (void){
            if (frente == NULL)
               return true;
            else
                return false;
       }
};

struct Supervisores{
    public:

};
struct TransportadoraMezcladoraEnsambladora{
    public:
        //son colas
        int id;
        bool estado;
        double capacidadMaxima;//puede ser mezcla o galleta, debe ser modificable
        double actual;//Cuanto tiene la banda en el  momento
        //se debe mostrar la cantidad de galletas o mezcla que hay en cada cola y el máximo seteado.
        //pausar la maquina que la alimenta cuando se alcance la capacidadMaxima.
        ColaBandaT * cola;
        MaquinaEmpacadora * salida;//No necesita saber quien es su entrada, solo le entran datos a la cola.
        TransportadoraMezcladoraEnsambladora();
        TransportadoraMezcladoraEnsambladora(int,bool,int,int,ColaBandaT *,MaquinaEmpacadora *);
        bool estaLlena();
        void setCapacidadMaxima(int);
        void setEstado(bool);
        void setSalida(MaquinaEmpacadora * );
        double cantidadMezclaEnBanda();
        double cantidadChocolateEnBanda();

};
struct MaquinaEmpacadora{
    //Antes de ella tiene dos inspectores
    //Si se llena la banda el horno se apaga
    //Se manejan paquetes
    public:


};
struct Horno{
    //Tiene dos bandejas por defecto, se puede agregar hasta 6.
    //Se hornea hasta que la cantidad de bandejas que tiene esten llenas
    //Se puede modificar la cantidad de galletas por bandejas
    //Tiene un tiempo de horneado
    //Las bandejas tienen contadores de cuantas han horneado y cuantas tienen actualmente
    //encendido/apagado
    public:
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
        TransportadoraMezcladoraEnsambladora * banda;
        MaquinaMezclaMasaChocolate();
        MaquinaMezclaMasaChocolate(int,double,double, int,bool);
        void setCapacidades(double,double);
        //Cada vez que llega por debajo del minimo pedir al almacen lo que falte para completar el maximo(van a una cola del almacen)
        double pedirMaterial();//le pide al carrito que le traiga maximaCapacidad-capacidadActual
        void procesar();
};
struct MaquinaEnsambladora{
    public:
        int galletasHechas;
        int galletasEnProceso;
        TransportadoraMezcladoraEnsambladora * entradaMasa;
        TransportadoraMezcladoraEnsambladora * entradaChocolate;
        //falta una transportadora TransportadoraEnsambladoraHorno

        //Recibe materia prima y retorna deliciosas galletas
        MaquinaEnsambladora();
        MaquinaEnsambladora(TransportadoraMezcladoraEnsambladora * ,TransportadoraMezcladoraEnsambladora * );

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
struct Nodo{//Un nodo es un paquete con nombre, galletas, cantidad paquetes de ese tipo
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
struct ListaPaquetes{//Doblemente enlazada circular
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
