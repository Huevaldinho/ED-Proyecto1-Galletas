#include "Estructuras.h"



ListaPaquetes::ListaPaquetes(){
    this->primerNodo = NULL;
}
bool ListaPaquetes::estaVacia(){
    return this->primerNodo==NULL;
}
void ListaPaquetes::insertar(int cantidadGalletasPorPaquete,string _nombre,int _cantidadPaquetes){
    if (this->primerNodo == NULL){
        this->primerNodo = new Nodo(cantidadGalletasPorPaquete, _nombre,_cantidadPaquetes);
        this->primerNodo->siguiente= primerNodo;
        this->primerNodo->anterior = primerNodo;
        this->listaTransportadores->insertarTransportador(_nombre,100,0,5);
    }else{
        Nodo * buscado=buscar(cantidadGalletasPorPaquete,_nombre);
        if (buscado!=NULL){
            buscado->cantidadPaquetes=buscado->cantidadPaquetes+_cantidadPaquetes;
        }else{Nodo * nuevo = new Nodo (cantidadGalletasPorPaquete, _nombre,_cantidadPaquetes);
            nuevo->siguiente = primerNodo;
            nuevo->anterior = primerNodo->anterior;
            this->primerNodo->anterior->siguiente = nuevo;
            this->primerNodo->anterior = nuevo;
            this->listaTransportadores->insertarTransportador(_nombre,100,0,5);
        }
    }

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
