#include "Estructuras.h"

ColaBandas::ColaBandas(){
     this->frente = NULL;
    this->actual=0;
    this->maximaCapacidad=1000;//por esto es que la ejecucion se cicla en la interfaz grafica, esta cola lo pone en pausa,
}                               // se soluciona desencolando esta cola
void ColaBandas::calcularMaxActual(){
         NodoBandas *tmp = this->frente;
         while (tmp != NULL){
               this->actual+=tmp->dato;
               tmp = tmp->siguiente;
         }
}
void ColaBandas::encolar(double cantidad){
     if (vacia()){
         this->frente = new NodoBandas (cantidad);
         this->actual+=this->frente->dato;
     }else{
             // referencia al primero para recorrer la lista
             NodoBandas * actual = this->frente;
             // recorre la lista hasta llegar al penultimo nodo
             while (actual->siguiente != NULL)
                           actual = actual->siguiente;

             // Crea nuevo nodo, lo apunta con uN
             NodoBandas * nuevo = new NodoBandas (cantidad);
             //le quita el enlace al que era ultimo
             actual->siguiente = nuevo;
             this->actual+=nuevo->dato;
     }
}
NodoBandas * ColaBandas::desencolar(void){
      // si no hay elementos, no borra nada, retorna null
      if (vacia()){
         return NULL;
      }else{
          NodoBandas* borrado = this->frente;
          this->frente = this->frente->siguiente;
          borrado->siguiente = NULL;
          this->actual-=borrado->dato;
          return borrado;
      }
}
void ColaBandas::imprimir(){
    NodoBandas *tmp = frente;
    while (tmp != NULL){
          tmp->imprimir();
          tmp = tmp->siguiente;
    }
    cout <<"fin metodo imprimir"<< endl;
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
double ColaBandas::contarGalletas(){
    NodoBandas * tmp=this->frente;
    double galletas=0;
    while(tmp!=NULL){
        galletas+=tmp->dato;
        tmp=tmp->siguiente;
    }
    return galletas;
}

