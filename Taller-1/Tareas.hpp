#pragma once

#include <iostream>

enum Departamento {
	financias,
	marketing,
	direccion,
	ingenieria
};

const std::string departamentos[4] = {"financias", "marketing", "direccion", "ingenieria"};

struct Tarea {
	int referencia;
	std::string descripcion;
	Departamento departamento;
	int tiempo;
};


class PilaTareas {
	Tarea pila[100];
	int tope = -1;
	
	public:
	void insertarTarea(Tarea);
	void mostrarTareas();
	void eliminar();
	bool vacia();
	Tarea obtener();
};



