 #include "Estructuras.h"

Transportadores::Transportadores(){
    this->largo=0;
    this->pn=NULL;
    this->un=NULL;
}
void Transportadores::insertarTransportador(string _tipoPaquete,int _maximo, int _tiempoTransporte,int _actuales){
    if (this->pn == NULL){
        this->pn = new Transportador(_maximo,_tiempoTransporte,_actuales,_tipoPaquete);
        this->pn->siguiente= pn;
        this->pn->anterior = pn;
    }else{
        Transportador * nuevo = new Transportador (_maximo,_tiempoTransporte,_actuales,_tipoPaquete);
        nuevo->siguiente = this->pn;
        nuevo->anterior = this->pn->anterior;
        this->pn->anterior->siguiente = nuevo;
        this->pn->anterior = nuevo;
    }
}
Transportador * Transportadores::transporteParaEnviar(string _nombre){
    Transportador * tmp= this->pn;
    while (tmp!=NULL){
        if (tmp->tipoPaquete.compare(_nombre)==0)
            return tmp;
        tmp=tmp->siguiente;
    }
    return tmp;
}
