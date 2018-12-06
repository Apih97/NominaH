#include "coord.h"

using namespace std;

int main(){
	 int x,i;
 	 system("color e");
 	
 	 gotoxy(30,100);for(i=0;i<=100;i++){
 	
 	 gotoxy(110,29);cout<<"CARGANDO..."<<endl;
 	 gotoxy(60+i,30);cout<<char(219);
 	 Sleep(10);
	 gotoxy(100,29);cout<<i<<"%";
	 if(i==100){
		system("cls");
		gotoxy(110,30);cout<<"Carga completada"<<endl;
		Beep(2100,1000);
	  }

 	}
	 gotoxy(100,40);system("pause");
	
}
