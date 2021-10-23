#include "Estructuras.h"



ListaPaquetes::ListaPaquetes(){
    this->primerNodo = NULL;
    this->largo=0;
}
bool ListaPaquetes::estaVacia(){
    return this->primerNodo==NULL;
}
void ListaPaquetes::insertar(int cantidadGalletasPorPaquete,string _nombre,int _cantidadPaquetes,int procesoPaquetes,int duracionPaquetes,int probabilidad){
    if (this->primerNodo == NULL){
        this->primerNodo = new Nodo(cantidadGalletasPorPaquete, _nombre,_cantidadPaquetes,procesoPaquetes,duracionPaquetes,probabilidad);
        this->primerNodo->siguiente= primerNodo;
        this->primerNodo->anterior = primerNodo;
        this->listaTransportadores->insertarTransportador(_nombre,100,0,0);
    }else{
        Nodo * buscado=buscar(cantidadGalletasPorPaquete,_nombre);
        if (buscado!=NULL){
            buscado->cantidadPaquetes=buscado->cantidadPaquetes+_cantidadPaquetes;
        }else{Nodo * nuevo = new Nodo (cantidadGalletasPorPaquete, _nombre,_cantidadPaquetes,procesoPaquetes,duracionPaquetes,probabilidad);
            nuevo->siguiente = primerNodo;
            nuevo->anterior = primerNodo->anterior;
            this->primerNodo->anterior->siguiente = nuevo;
            this->primerNodo->anterior = nuevo;
            this->listaTransportadores->insertarTransportador(_nombre,100,0,0);
        }
    }
    this->largo++;

}
Nodo * ListaPaquetes::buscar(int _dato,string _nombre){
    if (this->primerNodo != NULL){

        Nodo * tmp = this->primerNodo;
        do{
            if ((tmp->cantidadGalletas == _dato) &(tmp->nombre.compare(_nombre)==0))
                return tmp;
            tmp = tmp->siguiente;
        }while(tmp!=this->primerNodo);

    }
    return NULL;
}
Nodo * ListaPaquetes::eliminar(int _dato,string _nombre){
    Nodo * eliminado = buscar(_dato, _nombre);

    if (eliminado != NULL){ // sí lo encontró
        if (this->primerNodo->siguiente == this->primerNodo) // solo un elemento
            this->primerNodo = eliminado->siguiente = eliminado->anterior = NULL;
        else{
            if (eliminado == this->primerNodo)
                this->primerNodo = this->primerNodo->siguiente;

            Nodo * tmp = eliminado->anterior;
            tmp->siguiente = tmp->siguiente->siguiente;
            tmp->siguiente->anterior = tmp;
            eliminado->siguiente = eliminado->anterior = NULL;
        }
    }
    this->largo--;
    return eliminado;
}
void ListaPaquetes::imprimir(){
    cout <<"Inicia imprimir metodo"<< endl;//si quito esto el programa crashea, wtf
    if (this->primerNodo != NULL){
        Nodo * tmp = this->primerNodo;
        do{
            tmp->imprimir();
            tmp = tmp->siguiente;
        }while(tmp!=this->primerNodo);
    }
    cout <<"Fin metodo"<< endl;//si quito esto el programa crashea, wtf
}
double ListaPaquetes::getCantidadGalletas(){
    double galletas=0;
    if (this->primerNodo != NULL){
        Nodo * tmp = this->primerNodo;
        do{
            galletas=galletas+(tmp->cantidadGalletas * tmp->cantidadPaquetes);

            tmp = tmp->siguiente;
        }while(tmp!=this->primerNodo);
    }
    return galletas;
}
Transportadores * ListaPaquetes::getTransportadores(){
    return this->listaTransportadores;
}
void ListaPaquetes::setTransportadores(Transportadores * trans){
    this->listaTransportadores=trans;
}
void ListaPaquetes::setProbabilidades(){
    Nodo * tmp = this->primerNodo;
    int i=0;
    int proba=0;
    int probaAnterior=90;
    while (i<this->largo){
        srand(time(0));
        int probaGenerada=1 + rand() % probaAnterior;
        if (probaGenerada<0)
            probaGenerada*=(-1);
        if ((i+1)==this->largo){
            tmp->probabilidad=100-proba;

        }
        else{
            tmp->probabilidad=probaGenerada;
            proba+=probaGenerada;
            probaAnterior=probaGenerada;
        }
        if (tmp->probabilidad<0)
            tmp->probabilidad*=(-1);
        qDebug()<<"Proba de "<<i<<": "<<tmp->probabilidad;
        tmp=tmp->siguiente;
        i++;
    }
}
