#include "Empleados.hpp"

class Empresa {
	ColaEmpleados cola_empleados;
	PilaTareas pila_tareas;
	int tiempo = 0;
	
public:
	void ingresarEmpleado(Empleado);
	void agregarTarea(Tarea);
	void asignarTareaAEmpleado();
	void eliminarTareasDeDepartamento(Departamento);
	void mostrarTiempoTotal();
	void mostrarTareas();
	void mostrarEmpleados();
	void quitarEmpleadoCodigo(int);
};

