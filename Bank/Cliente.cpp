#include "Cliente.hpp"
#include<string>

bool ColaCliente::colaVacia() {
    return inicio == -1;
}

void ColaCliente::insertar(Cliente cliente) {
    if (colaVacia()) inicio++;
    cola[++fin] = cliente;
}

void ColaCliente::eliminar() {
    if (!colaVacia()) {
        if (inicio == fin) {
            fin - inicio + 1;
        }
        else {
            inicio++;
        }
    }
}

void ColaCliente::mostrar() {
    if (!colaVacia()) {
        for (int i = inicio;i <= fin;i++) {
            cout << " " << cola[i].nombre;
        }
    }
}

Cliente ColaCliente::obtener() {
    if (!colaVacia()) {
        return cola[inicio];
    }
}

void Banco::ingresar(Cliente cliente) {
    cola.insertar(cliente);
}

void Banco::atender() {
    Cliente cliente = cola.obtener();
    if (cliente.tipoTrans == "consignar") {
        acumuladoConsig += cliente.valor;
    }
    else if (cliente.tipoTrans == "retirar") {
        acumuladoRetiro += cliente.valor;
    }
    cola.eliminar();
}

Cliente Banco::proximoCliente() {
    return cola.obtener();
}

void Banco::eliminarporid(int id) {
    ColaCliente temp;
    
    while(!cola.colaVacia()) {
        if(cola.obtener().id == id) {
            break;
        }
        temp.insertar(cola.obtener());
        cola.eliminar();
    }
    
    cola.eliminar();

    while(!temp.colaVacia()) {
        cola.insertar(temp.obtener());
        temp.eliminar();
    }
}

void Banco::mostrar()
{
	cola.mostrar();
}

int main() {
	
	Banco banco;
	
	Cliente c1 = {1, "nametest", "estado", "consignar", 10000};
	Cliente c2 = {2, "nametest2", "estado", "retirar", 10000};
	Cliente c3 = {3, "nametest3", "estado", "retirar", 10000};
	
	banco.ingresar(c1);
	banco.ingresar(c2);
	banco.ingresar(c3);
	
	banco.mostrar();
	
	banco.atender();
	banco.atender();
	banco.atender();
	
	cout << "\nconsig: " << banco.acumuladoConsig << endl;
	cout << "retiro: " << banco.acumuladoRetiro << endl;
	
	return 0;
}
