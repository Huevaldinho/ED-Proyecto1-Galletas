 #include "Estructuras.h"

Transportadores::Transportadores(){
    this->largo=0;
    this->pn=NULL;
    this->un=NULL;
}
void Transportadores::insertarTransportedor(string _tipoPaquete,int _maximo, int _tiempoTransporte,int _actuales){
    if (this->pn == NULL){
        this->pn = new Transportador();
        this->pn->siguiente= pn;
        this->pn->anterior = pn;
    }else{
        Transportador * nuevo = new Transportador (_maximo,_tiempoTransporte,0,_tipoPaquete);
        nuevo->siguiente = this->pn;
        nuevo->anterior = this->pn->anterior;
        this->pn->anterior->siguiente = nuevo;
        this->pn->anterior = nuevo;
    }
}
