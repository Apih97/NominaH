#include <fstream>//flujo de archivos
#include "registro.h"

int agregarEmpleado(const datosEmpleadoT& EmpleadoNuevo){


}


int BorrarEmpleado(int llave){


}

void EscribirDatosMaestro(){

	  ofstream maestro1;
	  maestro1.open("Principal//Datos maestros.txt",ios::out);//archivo estatico o maestro(datos que no se van a mover)
	  if(maestro1.fail()){
	 	system("cls");
	 	gotoxy(50,50);cout<<"No se pudo abrir el archivo"<<endl;
	 	exit(1);
		}

	  maestro<<"ID"<<" ; ";
	  maestro<<"Nombre(s)"<<" ; ";
	  maestro<<"Apellidos"<<" ; ";
	  maestro<<"Cedula de identidad"<<" ; ";
    maestro<<"Numero del INSS"<<" ; ";
    maestro<<"Fecha de ingreso"<<" ; "<<endl;

   	for(int i=0;i<100;i++){

        if (dat[i].llave>=0){


			 maestro1<<dat[i].llave<<" ; ";

			    maestro1<<dat[i].nombre<<" ; ";
			 maestro1<<dat[i].apellido<<" ; ";
			 maestro1<<dat[i].cedula<<" ; ";
			 maestro1<<dat[i].numinss<<" ; ";
			 maestro1<<dat[i].fechaing<<" ; "<<endl;

	 }




        }

	  maestro.close();



}


