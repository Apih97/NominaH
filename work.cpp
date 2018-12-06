#include <iostream>
#include "operaciones.h"
#include "coord.h"
#include <fstream>

using namespace std;

int main(){
	ifstream r;
	string lineas;
	
	r.open("Principal//Datos maestros.csv");
	if(r.fail()){
		cout<<"El archivo no se pudo leer"<<endl;
		exit(1);
	}
	
	while(!r.eof()){
		getline(r,lineas);
		cout<<lineas<<endl;
	}
	
	
	getch();
	return 0;
}
