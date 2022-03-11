#include "Empresa.hpp"

using namespace std;

void Empresa::ingresarEmpleado(Empleado empleado) {
	cola_empleados.insertarEmpleado(empleado);
}

void Empresa::agregarTarea(Tarea tarea) {
	pila_tareas.insertarTarea(tarea);
}

void Empresa::mostrarEmpleados() {
	cola_empleados.mostrarEmpleados();
}

void Empresa::mostrarTareas() {
	pila_tareas.mostrarTareas();
}

void Empresa::eliminarTareasDeDepartamento(Departamento departamento) {
	PilaTareas temp;
	
	while(!pila_tareas.vacia()) {
		temp.insertarTarea(pila_tareas.obtener());
		pila_tareas.eliminar();
	}
	
	while(!temp.vacia()) {
		if(temp.obtener().departamento != departamento) {
			pila_tareas.insertarTarea(temp.obtener());
		}
		temp.eliminar();
	}
}

void Empresa::asignarTareaAEmpleado() {
	Empleado empleado = cola_empleados.obtener();
	Tarea tarea = pila_tareas.obtener();
	PilaTareas temp;
	
	while(!pila_tareas.vacia() && empleado.departamento != tarea.departamento) {
		tarea = pila_tareas.obtener();
		temp.insertarTarea(tarea);
		pila_tareas.eliminar();
	}
	
	cout << "Se asigno la tarea de: " << tarea.descripcion << ". A el empleado: " << empleado.nombre << "\n";
	
	tiempo += tarea.tiempo;
	
	pila_tareas.eliminar();
	cola_empleados.eliminar();
	
	while(!temp.vacia()) {
		pila_tareas.insertarTarea(temp.obtener());
		temp.eliminar();
	}
}

void Empresa::quitarEmpleadoCodigo(int codigo) {
	ColaEmpleados temp;

	while(!cola_empleados.vacio()) {
		cout << "working--\n";
		temp.insertarEmpleado(cola_empleados.obtener());
		cola_empleados.eliminar();
		cout << "working--\n";
	}
	
	temp.mostrarEmpleados();
	
	while(!temp.vacio()) {
		if(temp.obtener().codigo == codigo) {
			temp.eliminar();
		} else {
			cola_empleados.insertarEmpleado(temp.obtener());
			temp.eliminar();
		}
	}
}


