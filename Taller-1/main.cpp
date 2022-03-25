#include "Empresa.hpp"

using namespace std;

int main() {

	Empresa empresa;
	
	Tarea t1 = {1, "Lava los platos", ingenieria, 1};
 	Tarea t2 = {2, "Dormir", direccion, 3};
	Tarea t3 = {3, "Estafar", marketing, 9999};
	
	Empleado e1 = {1, "Juan", ingenieria};
	Empleado e2 = {2, "Juan2", direccion};
	Empleado e3 = {3, "Juan3", marketing};
	
	empresa.agregarTarea(t1);
	empresa.agregarTarea(t2);
	empresa.agregarTarea(t3);
	
	empresa.ingresarEmpleado(e1);
	empresa.ingresarEmpleado(e2);
	empresa.ingresarEmpleado(e3);
	
	empresa.mostrarEmpleados();
	empresa.mostrarTareas();
	
	empresa.quitarEmpleadoCodigo(2);
	
	empresa.mostrarEmpleados();
	
	return 0;
}

