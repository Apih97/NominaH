#ifndef REGISTRO_H
#define REGISTRO_H

struct datosEmpleadoT{

    int llave;
   	std::string cargo;
	std::string area;
	std::string nombre;
	std::string apellido;
	std::string cedula;
	std::string numinss;
	std::string fechaing;
	float salariobruto;
};

int agregarEmpleado(const datosEmpleadoT& EmpleadoNuevo);
/*
Agregar nuevo empleado al archivo
EmpleadoNuevo: Estructura con los datos del empleado a agregar, elemento llave no se usa
resultado: llave asignada y -1 si hubo un error

*/
int BorrarEmpleado(int llave);
/*
Elimina un empleado ya registrado de los archivos
Resultado: 1 si fue exitoso y -1 su hubo un error

*/

void EscribirDatosMaestro();

#endif // REGISTRO_H
