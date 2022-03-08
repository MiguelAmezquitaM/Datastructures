#pragma once

#include <iostream>

using namespace std;


struct Cliente {
    // datos del usuario
    int id;
    string nombre;
    
    string estado;
    string tipoTrans;
    int valor;
};
class ColaCliente {
    Cliente cola[100];
    int inicio = -1;
    int fin = -1;
    public:
        void eliminar();
        void insertar(Cliente cliente);
        bool colaVacia();
        void mostrar();
        Cliente obtener();
};

class Banco {
    ColaCliente cola;
    
    public:
    	int acumuladoConsig=0;
    	int acumuladoRetiro=0;
        void ingresar(Cliente cliente);
        void atender();
        Cliente proximoCliente();
        void eliminarporid(int id);
        void mostrar();
};

