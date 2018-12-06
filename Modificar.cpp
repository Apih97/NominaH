#include <iostream>
#include <fstream>
#include <conio.h>
#include "operaciones.h"
#include "coord.h"

#define TECLA_ARRIBA 72 // se define mediante el codigo ASCII la tecla arriba
#define TECLA_ABAJO 80 // se define mediante el codigo ASCII la tecla abajo
#define ENTER 13 // se define mediante el codigo ASCII la tecla enter,,  


using namespace std;

int menu(const char titulo[],const char*opciones[],int x);
void menuopc();
void CambioCargo();
void CambioArea();
void CambioSalarioBruto();
void CambioHorasExtra();
void CambioDiasVacaciones();
void CambioDiasSubsidio();
void CambioOtrosDescuentos();
void CambioAdelantoSalarial();
void CambioDiasTrabajados();

string name;//nombre del archivo a modificar
string carp2="Variantes//"; //nombre de la carpeta
string exte=".txt";//extencion del archivo
string finalname;//concatenacion de los string anteriores

int main(){
	system("cls");
	
	menuopc();
	
	return 0;
}

void menuopc(){
    system("color e");
	const char*titulo ="Menu de Modificaciones"; //Cadena constante
	const char*opciones[]={"CARGO","AREA","DIAS TRABAJADOS","SALARIO BRUTO","CANTIDAD HORAS EXTRAS",
	"DIAS DE VACACIONES","DIAS SUBSIDIO","OTROS DESCUENTOS","ANTICIPO SALARIAL","RETORNAR"};//arreglo constante de caracteres
	int x=10;//dimension de la cadena de caracteres
	bool frecuencia=true;
	
	do{
		
	opcion = menu(titulo,opciones,x);//retorna la opcion escogida por el usuario y es almacenada en la variable opciones 
   	
	
	   switch (opcion){
   		
   		case 1: {
   			system("cls");
   			CambioCargo();
			break;
		   }
   		
   		case 2:{
   			system("cls");
   			CambioArea();
			break;
		   }
		
		
		case 3:{
			system("cls");
			CambioDiasTrabajados();
			break;
		}
		
		case 4: {
			system("cls");
			CambioSalarioBruto();
			break;
		} 
		
	  	case 5:{
	  		system("cls");
	  		CambioHorasExtra();
			break;
			
		  }
	 	
		case 6:{
			system("cls");
			CambioDiasVacaciones();
			break;
			
		}
		
		case 7:{
			system("cls");
			CambioDiasSubsidio();
			break;
			
		}  
	 	  
		case 8:{
			system("cls");
			CambioOtrosDescuentos();
			break;
		}
		case 9:{
			CambioAdelantoSalarial();
			break;
		}
		
		case 10:{
			system("cls");
			cout<<"Fin de las modificaciones"<<endl;
			getch();
			frecuencia=false;
			break;
		}	
   		
	   }	
	}while(frecuencia);
	
	
}
int menu(const char titulo[],const char*opciones[],int x){

	int seleccion=1;//movimiento de la tecla por parte del usuario
	int intento;//enter
	bool frecuencia= true;
	
	do{
		system("cls");
		gotoxy(5, 3+seleccion);cout<<"==>";//CREACION DE LA FLECHA
		gotoxy(15, 2);cout<<titulo;//TITULO DEL MENU
		
		for(int i=0;i<x;i++){
			gotoxy(10, 4+i);cout<<i+1<<")"<<opciones[i];
			
		}
		
		do{
			intento=getch();//CAPTURA LA TECLA ENTER
			
		}while(intento!=TECLA_ARRIBA && intento!=TECLA_ABAJO && intento!=ENTER);
		
		switch(intento){ //SWITCH PARA INTENTOS DE FLECHA 
			case TECLA_ARRIBA :
				
				seleccion--;
				
				if(seleccion<1){
					seleccion=x;
				}
				
				break;
			case TECLA_ABAJO:
				
				seleccion++;
				
				if(seleccion>x){
					
					seleccion=1;
					
				}
				
				break;
			case ENTER:
				frecuencia=false;
				break;
			
			
		}
	}while(frecuencia);//bucle repetitivo para las opciones en el movimiento del objeto, sera controlado
	//por medio de un booleano 
	return seleccion;
} 

void CambioCargo(){
	
	inicio();
	 
	ofstream aux;
    
	ifstream lectura;

    char auxCargo[100];
    
    char NauxCargo[100];
    
    char nombre[100],grupo[100];
    
	int clave=0, auxClave=0;
	
	bool encontrado=false;
	
	char auxGrupo[100];
	
	mkdir(carp2.c_str());
	
	
	cout<<"Ingrese el archivo que desea modificar"<<endl;
	getline(cin,name);
	
	finalname=carp2+name+exte;
	
	system("cls");
	
	inicio();
	
    aux.open("Variantes//Temporal.txt",ios::out);//temporal
    lectura.open(finalname,ios::in);//original

    if(aux.is_open() && lectura.is_open()){
        cout<<"Ingresa la Clave del Alumno que deseas Modificar: ";
        cin>>auxClave;
        
		lectura>>datoMod.llave;
		
		//cambio del cargo
        while(!lectura.eof()){
            
			lectura>>datoMod.llave;
	
			if(auxClave==datoMod.llave){
                encontrado=true;

                /*cout<<"______________________"<<endl;
                cout<<"Clave: "<<clave<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Semestre: "<<semestre<<endl;
                cout<<"Grupo: "<<grupo<<endl;
                cout<<"Edad: "<<edad<<endl;
                cout<<"______________________"<<endl;
				*/
                fflush(stdin);
                cout<<"Ingrese el nuevo cargo del empleado: "<<datoMod.llave<<": ";
                cin.getline(auxCargo,100);
                
                aux<<datoMod.llave<<" ; "<<auxCargo<<" ; ";
                cout<<"Registro Modificado"<<endl;
            }else{
                aux<<clave<<auxCargo<<endl;
            }
            
            lectura>>clave;
        }

    }else{
        
		cout<<"No se pudoAbrir el Archivo o aun no ha sido Creado"<<endl;
   
    }

    if(encontrado==false)
    {
        cout<<"No se encontro ningun registro con clave "<<auxClave<<endl;
    }

    aux.close();

    lectura.close();

    remove("Temporal.txt");

    rename("Temporal.txt",finalname.c_str());
		
	getch();
}


void CambioArea(){
	 inicio();
	 
	 getch();
	 system("cls");
} 


void CambioDiasTrabajados(){
	inicio();
	
	getch();
	system("cls");
}



void CambioSalarioBruto(){
	inicio();
	
	getch();
	system("cls");
}


void CambioHorasExtra(){
	inicio();
	
	getch();
	system("cls");
}


void CambioDiasVacaciones(){
	inicio();
	
	getch();
	system("cls");
}


void CambioDiasSubsidio(){
	inicio();
	
	getch();
	system("cls");
}


void CambioOtrosDescuentos(){
	inicio();
	
	getch();
	system("cls");
}



void CambioAdelantoSalarial(){
	inicio();
	
	getch();
	system("cls");
}


