#include "Estructuras.h"

ColaAlmacen::ColaAlmacen(){
    this->totalPeticiones=0;
    this->pendientes=0;
    this->frente=NULL;
}
bool ColaAlmacen::estaVacia(){
    return this->frente==NULL;
}

void ColaAlmacen::encolar(double _cantidadSolicitada,int _idMaquina){
    if (estaVacia())
        this->frente = new NodoColaPeticiones (_cantidadSolicitada,_idMaquina);
    else{
        // referencia al primero para recorrer la lista
        NodoColaPeticiones * actual = this->frente;
        // recorre la lista hasta llegar al penultimo nodo
        while (actual->siguiente != NULL)
              actual = actual->siguiente;

        // Crea nuevo nodo, lo apunta con uN
        NodoColaPeticiones * nuevo = new NodoColaPeticiones (_cantidadSolicitada,_idMaquina);
        //le quita el enlace al que era ultimo
        actual->siguiente = nuevo;
        this->totalPeticiones++;
        this->pendientes++;
    }
}
NodoColaPeticiones * ColaAlmacen::desencolar(void){
      // si no hay elementos, no borra nada, retorna null
      if (estaVacia()){
         return NULL;
      }else{
          // un puntero que apunta al nodo que se
          // "despegara" de la lista y se retorna
          NodoColaPeticiones * borrado = this->frente;
          // pN se pasa al segundo de la lista
          // porque el primero se eliminara
          this->frente = this->frente->siguiente;
          // el nodo borrado, se debe despegar
          // entonces siguiente apunta a null y no
          // al segundo de la lista que ahora es pN
          borrado->siguiente = NULL;
          // aca se deberia liberar la memoria si no se
          // retornara el borrado
          this->pendientes--;
          return borrado;
      }
}
void ColaAlmacen::imprimir(){
    cout << "Frente" << endl;
     // puntero temporal que avanza
     // por toda la lista
     // apunta a los mismo que pN
     NodoColaPeticiones *tmp = this->frente;

     // mientras tmp no sea nulo, avanza
     while (tmp != NULL){
           // imprime el dato del nodo en el que esta tmp
           cout << tmp->cantidadSolicitada <<"id maquina: "<<tmp->idMaquina<< "  " << endl;
           // tmp avanza al siguiente nodo
           // esto no puede faltar porque se encicla
           tmp = tmp->siguiente;
     }
     cout << "Final" << endl;
}

