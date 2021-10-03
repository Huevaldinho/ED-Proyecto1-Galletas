#include "Estructuras.h"



ListaPaquetes::ListaPaquetes(){
    this->primerNodo = NULL;
}
bool ListaPaquetes::estaVacia(){
    return this->primerNodo==NULL;
}
void ListaPaquetes::insertar(int d,string _nombre,int _cantidadPaquetes){
    if (this->primerNodo == NULL){
        this->primerNodo = new Nodo(d, _nombre,_cantidadPaquetes);
        this->primerNodo->siguiente= primerNodo;
        this->primerNodo->anterior = primerNodo;
    }else{
        Nodo * nuevo = new Nodo (d, _nombre,_cantidadPaquetes);
        nuevo->siguiente = primerNodo;
        nuevo->anterior = primerNodo->anterior;
        this->primerNodo->anterior->siguiente = nuevo;
        this->primerNodo->anterior = nuevo;
    }
}
void ListaPaquetes::imprimir(){
    if (this->primerNodo != NULL){
        Nodo * tmp = this->primerNodo;
        do{
            tmp->imprimir();
            tmp = tmp->siguiente;
        }while(tmp!=this->primerNodo);
        cout << endl;
    }
}
Nodo * ListaPaquetes::buscar(int _dato,string _nombre){
    if (this->primerNodo != NULL){

        Nodo * tmp = this->primerNodo;
        do{
            if (tmp->cantidadGalletas == _dato &tmp->nombre.compare(_nombre)==0)
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
