#inlcude "operaciones.h"
#include "coord.h"
#include <iostream>
#include <fstream>
#include <direct.h>
#include <sstream>

using namespace std;

int main(){
	string archivo;
	string carpeta="Principal//";
	string extencion= "txt";
	string cedula;
	string vision;
	string linea;
	
	int contador=0;
	bool encontrado=false; 
	bool eliminado=false;
	
	mkdir(carpeta.c_str());
	
	cout<<"Ingrese el nombre del archivo a modificar"<<endl;
	
	getline(cin,archivo);
	
	
	def=carpeta+archivo+extencion;
	
	
	ifstream leer;
	ofstream temp;
	
	leer.open(def,ios::in);
	temp.open("temoral.txt",ios::out);
	
	if(leer.fail()){
		cout<<"Error al abrir el archivo"<<endl;
		exit(1);
	}
	
	cout<<"Ingrese el numero de cedula "
	
	
	getline(cin,cedula);//clave de cedula
	
	if(temp.is_open() && leer.is_open() ){
		
		while(getline(leer,vision){
		
		stringstream stream;
    		
			string valor;
    		
			stream<<linea;
    		
    		while(getline(stream,valor,',')){
    		
    			if(atol(valor.c_str())==auxClave||encontrado==true){
    				encontrado=true;
					contador++;
					
						switch(contador){
	    					case 0:{
	    					cout<<"Clave: "<<valor<<endl;	
							break;
							}
				
							case 1:{
							cout<<"Nombre: "<<valor<<endl;
							break;
							}
				
							case 2:{
							cout<<"Semestre: "<<valor<<endl;
							break;
							}
					
							case 3:{
							cout<<"Grupo: "<<valor<<endl;
							break;
							}
				
							case 4:{
							cout<<"Edad: "<<valor<<endl<<endl;
							break;
							}
						}
						
						if(contador>4){
							encontrado=false;
							eliminado=true;
						}
					
				}else{
					auxiliar<<linea<<endl;
					break;
				}
    		}
		}
		if(eliminado==true){
    		cout<<"---> Registro Eliminado <---"<<endl<<endl;
		}else{
			cout<<"---> Registro No encontrado <---"<<endl<<endl;	
		}
		
	}else{
		cout<<"Error, el archivo no se abrió correctamente"<<endl<<endl;
		exit(1);
	}    
	
	temp.close();
    leer.close();
    
    remove(def);
    rename("fileStudentsAux.txt","fileStudents.txt");
		
}
		
	

