#pragma once

#include <iostream>
#include <exception>
#include "Tareas.hpp"

struct Empleado {
	int codigo;
	std::string nombre;
	Departamento departamento;
};

class ColaEmpleados {
	Empleado cola[100];
	int inicio = -1;
	int fin = -1;
	
public:
	void insertarEmpleado(Empleado);
	void mostrarEmpleados();
	void eliminar();
	Empleado obtener();
	bool vacio();
};

