#include <iostream>
#include <windows.h>
#include <direct.h>

using namespace std;

int main(){
	
	system("cls");
	
	string ver;
	
	string tipo=".csv";
	
	string carpeta="Excel\\";
	
	string excel;
	
	mkdir(carpeta.c_str());
	
	cout<<"Que archivo desea visualizar en excel"<<endl;
	
	getline(cin,ver);
	
	excel=carpeta+ver+tipo;
	
	cout<<excel<<endl;
	
	system(excel.c_str());
	
	system("pause");
	
	return 0;
}
