#include "Estructuras.h"

ColaBandas::ColaBandas(){
     this->frente = NULL;
    this->actual=0;
    this->maximaCapacidad=500;
}
void ColaBandas::calcularMaxActual(){
         NodoBandas *tmp = this->frente;
         while (tmp != NULL){
               this->actual+=tmp->dato;
               tmp = tmp->siguiente;
         }
}
void ColaBandas::encolar(double cantidad){
     if (vacia())
         this->frente = new NodoBandas (cantidad);
     else
     {
             // referencia al primero para recorrer la lista
             NodoBandas * actual = this->frente;
             // recorre la lista hasta llegar al penultimo nodo
             while (actual->siguiente != NULL)
                           actual = actual->siguiente;

             // Crea nuevo nodo, lo apunta con uN
             NodoBandas * nuevo = new NodoBandas (cantidad);
             //le quita el enlace al que era ultimo
             actual->siguiente = nuevo;
     }
     this->actual++;
}
NodoBandas * ColaBandas::desencolar(void){
      // si no hay elementos, no borra nada, retorna null
      if (vacia()){
         return NULL;
      }else{
          // un puntero que apunta al nodo que se
          // "despegara" de la lista y se retorna
          NodoBandas* borrado = this->frente;
          // pN se pasa al segundo de la lista
          // porque el primero se eliminara
          this->frente = this->frente->siguiente;
          // el nodo borrado, se debe despegar
          // entonces siguiente apunta a null y no
          // al segundo de la lista que ahora es pN
          borrado->siguiente = NULL;
          // aca se deberia liberar la memoria si no se
          // retornara el borrado
          this->actual--;
          return borrado;
      }
}
void ColaBandas::modificarMaximaCapacidada(double _nuevoMaximo){
    this->maximaCapacidad=_nuevoMaximo;
}
bool ColaBandas::vacia(void){
     if (this->frente == NULL)
        return true;
     else
         return false;
}
bool ColaBandas::puedeEncolar(){
    if (this->actual<this->maximaCapacidad)
        return true;
    else
        return false;
}

