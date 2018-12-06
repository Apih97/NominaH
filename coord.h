#include <iostream>
#include <windows.h>
#include <ctime>
#include <vector>
#define a "u"
#define b "x"

using namespace std;

void gotoxy( int x, int y )
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
	);
	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
}

void tiempo (){
	
time_t now = time(0);

/* Objeto de una estructura tm con fecha/hora local */
tm * time = localtime(&now);

vector<string> dia_semana; // vector dias
dia_semana.push_back("Domingo");
dia_semana.push_back("Lunes");
dia_semana.push_back("Martes");
dia_semana.push_back("Miercoles");
dia_semana.push_back("Jueves");
dia_semana.push_back("Viernes");
dia_semana.push_back("Sabado");

vector<string> mes;// vector meses
mes.push_back("Enero");
mes.push_back("Febrero");
mes.push_back("Marzo");
mes.push_back("Abril");
mes.push_back("Mayo");
mes.push_back("Junio");
mes.push_back("Julio");
mes.push_back("Agosto");
mes.push_back("Septiembre");
mes.push_back("Octubre");
mes.push_back("Noviembre");
mes.push_back("Diciembre");

int year = 1900 + time->tm_year;

cout << "Hoy " << dia_semana[time->tm_wday] << ", ";
cout << time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
		
}

void inicio(){
	
	system ("color e");
	gotoxy(86,3);cout<<"======================================================================"<<endl;
	gotoxy(95,4);cout<<"<<---------------SISTEMA DE NOMINA--------------->>"<<endl;
	gotoxy(112,5);cout<<"SALUD SIN LIMITES"<<endl;
	gotoxy(112,6);cout<<"RUC:0810000173071"<<endl;
	gotoxy(110,7);cout<<"Tipo de moneda:Cordobas"<<endl;
	gotoxy(105,8);cout<<"Copyright 2018"<<" || "<<"Grupo Nomina"<<endl;
	gotoxy(86,9);cout<<"======================================================================="<<endl;
	gotoxy(86,10);cout<<endl;
	
	/* fecha/hora actual basado en el sistema actual */
}

