#include "coord.h"

using namespace std;

int main(){
	
		string p,u;
	char caracter;
	int c=0;
	bool intento=false;
	
	do{
	
	inicio();
	
	gotoxy(80,9);cout<<"Acceso del usuario"<<endl;
	
	gotoxy(80,14);cout<<"Ingrese su id de usuario: "<<endl;

	gotoxy(106,14);getline(cin,u);
	
	gotoxy(80,17);cout<<"Ingrese su Contraseña: "<<endl;
		
	caracter= getch();
	
	p="";
	
	gotoxy(103,17);while (caracter != 13) {
 
				p.push_back(caracter);
				cout << "*";
				caracter = getch();
		}
 	
	if(u==a && p==b){
		gotoxy(103,20);cout<<"Bienvenido al programa"<<endl;
		intento=true;
		cin.ignore();
		system("cls");
		system("Loading.exe");//llama al ejecutable que alamacena el loading screen
		principal();
		
	}
	
	else{
		c++;
		gotoxy(103,20);cout<<"Acceseso denegado"<<endl;
		gotoxy(103,22);cout<<"Quedan "<<3-c<<" Intentos"<<endl;
		cin.ignore();
		system("cls");
		
	}
		
	}while(intento==false && c<3);

	if(c==3){
		gotoxy(103,20);cout<<"Numero de intentos agotados"<<endl;
		gotoxy(103,22);cout<<"Programa terminado"<<endl;
	}
	
}
