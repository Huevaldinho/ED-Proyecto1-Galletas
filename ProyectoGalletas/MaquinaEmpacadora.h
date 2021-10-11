#ifndef MAQUINAEMPACADORA_H
#define MAQUINAEMPACADORA_H
#include "Estructuras.h"

struct MaquinaEmpacadora{    //COMO VAMOS A PASAR LOS DATOS DE LA COLA DE SUPERVISORES A LA MAQUINA (SE DEBE TENER EN CANTIDAD DE GALLETAS)
    //Antes de ella tiene dos inspectores
    //Si se llena la banda el horno se apaga
    //Se manejan paquetes
    public:
        int cantidadDePaquetes;
        int tiempoEmpaque;
        Nodo * paqueteActual;
        int cantidadActual;
        bool estado;
        int galletasAceptadas; //tiene que recibir la cantidad de galletas aceptadas por el supervisor

        MaquinaEmpacadora();
        void setGalletasAceptadas(Supervisor*supervisorA, Supervisor*supervisorB);
        void probabilidadDeEmpaque(); //esta se usa en empacar
        void enviarAlTransportador(string tipoPaquete,int cantidadPaquetes);
        void empacar();

        //Dos supervisores

};
#endif // MAQUINAEMPACADORA_H
