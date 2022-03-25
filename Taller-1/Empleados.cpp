#include "Empleados.hpp"

using namespace std;

bool ColaEmpleados::vacio() {
	return inicio == -1;
	 
}

void ColaEmpleados::insertarEmpleado(Empleado empleado) {
	if(vacio()) 
		inicio++;
	
	cola[++fin] = empleado;
}


void ColaEmpleados::mostrarEmpleados() {
	if(vacio()) return;
	
	for(int i = inicio; i <= fin; i++) {
		cout << "Nombre: " << cola[i].nombre << "\tCodigo: " << cola[i].codigo << "\tDepartamento: " << departamentos[cola[i].departamento] << "\n\n";
	}
}

void ColaEmpleados::eliminar() {
	if(!vacio()) {
		inicio++;
	}
	else if(inicio == fin) {
		inicio = fin = -1;
	}
}

Empleado ColaEmpleados::obtener() {
	if(!vacio())
		return cola[inicio];

}



