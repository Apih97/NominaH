#include <iostream>
#include <vector>
#include <fstream>
#include <direct.h>
#include <ctime>
#include <windows.h>

using namespace std;

int main (){
	
	HWND consoleWindow = GetConsoleWindow();

	SetWindowPos( consoleWindow, 0, 10, 10, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
		
	system("color B");
	system("mode con: cols=40 lines=30");
	string lectura;
	
	ifstream lista;
	cout<<"Lista de archivos"<<endl;
	lista.open("ArchivosTotal.txt",ios::in);
	
	while(!lista.eof()){
		getline(lista,lectura);
		cout<<endl;
		cout<<" + "<<lectura;
	}
	
	lista.close();
	
	system("pause");
	return 0;
	
}
