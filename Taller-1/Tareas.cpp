#include "Tareas.hpp"

using namespace std;

bool PilaTareas::vacia() {
	return tope == -1;
}

void PilaTareas::insertarTarea(Tarea tarea) {
	pila[++tope] = tarea;
}

void PilaTareas::mostrarTareas() {
	if(vacia()) return;
	
	for(int i = 0; i <= tope; i++) {
		cout << "Referencia: " << pila[i].referencia << "\tDescripcion: " << pila[i].descripcion << "\tDepartamento: " << departamentos[pila[i].departamento] << "\tTiempo: "<<pila[i].tiempo << "\n\n"; 
	}
}

void PilaTareas::eliminar() {
	if(!vacia()) {
		tope--;
	}
}

Tarea PilaTareas::obtener() {
	if(!vacia())
		return pila[tope--];
}

