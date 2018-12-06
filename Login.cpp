#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <unistd.h>//Uso de la funcion sleep o usleep
#include <fstream>//flujo de archivos
#include "coord.h"//libreria personal
#include "operaciones.h"//libreria para realizar operaciones y donde se encuntra la estructura
#include <string>
//#include "registro.h"

#define TECLA_ARRIBA 72 // se define mediante el codigo ASCII la tecla arriba
#define TECLA_ABAJO 80 // se define mediante el codigo ASCII la tecla abajo
#define ENTER 13 // se define mediante el codigo ASCII la tecla enter,,

void quitar();
void inicio();
void usuario();
void nomina();
int menu(const char titulo[],const char*opciones[],int x);
void principal();
void eliminar();
void leer ();
void auxiliar();
void respaldos();
float salarioprima(int q);
float horasextra(int q2);
float vacaciones(int q3);
float subsidioINSS(int q4);
float aguinaldo(int q5);
float feriados(int q6);
float IngresosTotal(int q7);
float INSS_deduccion(int q8);
float IR(int q9);
float deduccionesTotal(int q10);
float aPagar(int q11);

using namespace std;



int main(){

	setlocale(LC_ALL,"spanish");
	inicio();
        for(int i=0; i<100; i++){
        dat[i].llave = -1;
        }
	usuario();
	system("pause>null");

	return 0;
}


void lecturaDatosMaestro(){

	  ifstream maestro;
	  maestro.open("Principal//Datos maestros.txt",ios::in);//archivo estatico o maestro(datos que no se van a mover)
	  if(maestro.fail()){
	 	system("cls");
	 	gotoxy(50,50);cout<<"No se pudo abrir el archivo maestro"<<endl;
	 	return;
		}

    int i=-1; //primera linea encabezado
    string linea;
	while ( getline(maestro,linea,'\n') ){
         int llave;
         istringstream lineastream(linea);
         string llavestr, nombre, apellido, cedula, numINSS, fechaIng;
         getline(lineastream,llavestr,';');
         getline(lineastream,nombre,';');
         getline(lineastream,apellido,';');
         getline(lineastream,cedula,';');
         getline(lineastream,numINSS,';');
         lineastream>>fechaIng;

         llave = atoi(llavestr.c_str());

         if (i>=0)
         {
			 dat[i].llave=llave;
			 dat[i].nombre=nombre;
			 dat[i].apellido=apellido;
			 dat[i].cedula=cedula;
			 dat[i].numinss=numINSS;
			 dat[i].fechaing=fechaIng;
         }
        i++;
	 }

	  maestro.close();
}
void lecturaDatosVariantes(){

	  ifstream variantes;
	  variantes.open(nuevo.c_str(),ios::in);
	  if(variantes.fail()){
	 	system("cls");
	 	gotoxy(50,50);cout<<"No se pudo abrir el archivo variantes"<<endl;
	 	return;
		}

    int i=-1; //primera linea encabezado
    string linea;
	while ( getline(variantes,linea,'\n') ){
         int llave, dias, salariobruto, salarioing, horascantidad, horasmonto, vacacionesdias, vacacionestotal, subsidiodia,
                aguinaldo, antiguedad, feriados, totalingresos, INSS_deu, IR_deu, otrosDescuentos, anticiposS, totaldeducciones,
                PagaTotal;
         istringstream lineastream(linea);
         string llavestr, cargo, area, diasstr, salariobrutostr, salarioingstr, horascantidadstr, horasmontostr, vacacionesdiasstr,
                vacacionestotalstr, subsidiodiastr, aguinaldostr, antiguedadstr, feriadosstr, totalingresosstr, INSS_deustr, IR_deustr,
                otrosDescuentosstr, anticiposSstr, totaldeduccionesstr, PagaTotalstr;

         getline(lineastream,llavestr,';');
         getline(lineastream,cargo,';');
         getline(lineastream,area,';');
         getline(lineastream,diasstr,';');              //a int
         getline(lineastream,salariobrutostr,';');
         getline(lineastream,salarioingstr,';');
         getline(lineastream,horascantidadstr,';');
         getline(lineastream,horasmontostr,';');
         getline(lineastream,vacacionesdiasstr,';');
         getline(lineastream,vacacionestotalstr,';');
         getline(lineastream,subsidiodiastr,';');
         getline(lineastream,aguinaldostr,';');
         getline(lineastream,antiguedadstr,';');
         getline(lineastream,feriadosstr,';');
         getline(lineastream,totalingresosstr,';');
         getline(lineastream,INSS_deustr,';');
         getline(lineastream,IR_deustr,';');
         getline(lineastream,otrosDescuentosstr,';');
         getline(lineastream,anticiposSstr,';');
         getline(lineastream,totaldeduccionesstr,';');
         lineastream>>PagaTotalstr;

         llave = atoi(llavestr.c_str());
         dias = atoi(diasstr.c_str());
         salariobruto = atoi(salariobrutostr.c_str());
         salarioing = atoi(salarioingstr.c_str());
         horascantidad = atoi(horascantidadstr.c_str());
         horasmonto = atoi(horasmontostr.c_str());
         vacacionesdias = atoi(vacacionesdiasstr.c_str());
         vacacionestotal = atoi(vacacionestotalstr.c_str());
         subsidiodia = atoi(subsidiodiastr.c_str());
         aguinaldo = atoi(aguinaldostr.c_str());
         antiguedad = atoi(antiguedadstr.c_str());
         feriados = atoi(feriadosstr.c_str());
         totalingresos = atoi(totalingresosstr.c_str());
         INSS_deu = atoi(INSS_deustr.c_str());
         IR_deu = atoi(IR_deustr.c_str());
         otrosDescuentos = atoi(otrosDescuentosstr.c_str());
         anticiposS = atoi(anticiposSstr.c_str());
         totaldeducciones = atoi(totaldeduccionesstr.c_str());
         PagaTotal = atoi(PagaTotalstr.c_str());

         if (i>=0){
            dat[i].llave=llave;
            dat[i].cargo= cargo;
			dat[i].area=area;
			dat[i].dias=dias;
            dat[i].aux2.salariobruto=salariobruto;
            dat[i].aux2.salarioing= salarioing;
            dat[i].aux2.horascantidad= horascantidad;
            dat[i].aux2.horasmonto= horasmonto;
            dat[i].aux2.vacacionesdias= vacacionesdias;
            dat[i].aux2.vacacionestotal= vacacionestotal;
            dat[i].aux2.subsidio= subsidiodia;
            dat[i].aux2.aguinaldo = aguinaldo;
            dat[i].aux2.antiguedad = antiguedad;
            dat[i].aux2.feriados= feriados;
            dat[i].aux2.totalingresos= totalingresos;
            dat[i].aux2.aux1.INSS_deu=INSS_deu;
            dat[i].aux2.aux1.IR_deu= IR_deu;
            dat[i].aux2.aux1.otrosDescuentos= otrosDescuentos;
            dat[i].aux2.aux1.anticiposS = anticiposS;
            dat[i].aux2.aux1.totaldeducciones = totaldeducciones;
            dat[i].aux2.aux1.PagaTotal = PagaTotal;

         }
        i++;
	 }
	  variantes.close();
}
void usuario(){

	string p,u;

	char caracter;

	int c=0;

	bool intento=false;

	do{

	inicio();

	gotoxy(80,12);cout<<"Acceso del usuario"<<endl;

	gotoxy(80,14);cout<<"Ingrese su id de usuario: "<<endl;

	gotoxy(106,14);getline(cin,u);

	gotoxy(80,17);cout<<"Ingrese su Contraseña: "<<endl;

	caracter= getch();

	p="";

	gotoxy(103,17);while (caracter != 13 ) {

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
		lecturaDatosMaestro();
		lecturaDatosVariantes();
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
		ShellExecute(0,"open","Apagar.bat",NULL,NULL,1);
	}
}

int obtenerLlave()
{
    int llaveNueva=0;
    while(1){
        bool llaveUsada=false;
        for (int i=0; i<100; i++){
            if (dat[i].llave==llaveNueva)
            {
                llaveUsada=true;
                break;
            }
        }
        if (llaveUsada){
            llaveNueva++;
        }
        else {
            return llaveNueva;
        }
        //no toma en cuenta si hay mas de 100 empleados agregado!
    }
}


void nomina (){

	time_t rawtime;
  	struct tm * timeinfo;
  	char buffer[80];

  	time (&rawtime);
  	timeinfo = localtime(&rawtime);

  	strftime(buffer,sizeof(buffer),"%d-%m-%Y",timeinfo);

	string str(buffer);

	nombre=str;

	mkdir(carp.c_str());
	mkdir(carp2.c_str());//Carpeta de respaldo
	mkdir(carp3.c_str());//Carpeta donde se guarda el excel;

    nuevo=carp+nombre+aux2;//carpeta variantes +nombre del archivo con la fecha
    nuevocopia=carp2+nombre+backup+aux;//carpeta con nombre Respaldo + Nombre del archivo original
    //+Variable string que almacena la palabra copia + la extension o tipo del archivo
	Excel=carp3+nombre+aux;//carpeta excel+nombre del archivo con la fecha + Extension

	 system("cls");

	 inicio();

	 string nombre,apellido;
	 ofstream maestro;
	 ofstream copia;
	 ofstream excel;
	 ofstream variantes;

	 mkdir("Principal");

	 maestro.open("Principal//Datos maestros.txt",ios::out);//archivo estatico o maestro(datos que no se van a mover)
	 if(maestro.fail()){
	 	system("cls");
	 	gotoxy(50,50);cout<<"No se pudo abrir el archivo"<<endl;
	 	exit(1);
		}
	 copia.open(nuevocopia.c_str(),ios::out);

	 if(copia.fail()){
	 	system("cls");
	 	gotoxy(50,50);cout<<"No se pudo abrir el archivo"<<endl;
	 	exit(1);
	 }

	 excel.open(Excel.c_str(),ios::out);
	 if(excel.fail()){
	 	system("cls");
	 	gotoxy(50,50);cout<<"No se pudo abrir el archivo"<<endl;
	 	exit(1);
	 }

	variantes.open(nuevo.c_str(),ios::out);//archivo variante
	 if(variantes.fail()){
	 	system("cls");
	 	gotoxy(50,50);cout<<"No se pudo abrir el archivo"<<endl;
	 	exit(1);
		}

	  cout<<endl;

	  gotoxy(1,10);cout<<"ID";
	  gotoxy(1,10);maestro<<"ID"<<" ; ";

	  gotoxy(6,10);cout<<"Nombre(s)";
	  gotoxy(6,10);maestro<<"Nombre(s)"<<" ; ";

	  gotoxy(40,10);cout<<"Apellidos";
	  gotoxy(40,10);maestro<<"Apellidos"<<" ; ";

	  gotoxy(80,10);cout<<"Cedula de identidad";
	  gotoxy(80,10);maestro<<"Cedula de identidad"<<" ; ";

	  gotoxy(120,10);cout<<"Numero del INSS";
	  gotoxy(120,10);maestro<<"Numero del INSS"<<" ; ";

	  gotoxy(150,10);cout<<"Fecha de ingreso";
	  gotoxy(150,10);maestro<<"Fecha de ingreso"<<" ; "<<endl;

	  maestro.close();

	  //guardar los nombres de los campos en la copia
	  copia<<"ID"<<" ; ";
	  copia<<"Nombre(s)"<<" ; ";
	  copia<<"Apellidos"<<" ; ";
	  copia<<"Cedula de identidad"<<" ; ";
	  copia<<"Numero del INSS"<<" ; ";
	  copia<<"Fecha de ingreso"<<" ; ";
	  copia<<"Cargo"<< " ; ";
	  copia<<"Area"<<" ; ";
	  copia<<"Dias trabajados"<<" ; ";
	  copia<<"Salario bruto"<<" ; ";
	  copia<<"Salario "<<" ; ";
	  copia<<"Cantidad horas extras"<<" ; ";
	  copia<<"Monto horas extras"<<" ; ";
	  copia<<"Dias de vacaciones"<<" ; ";
	  copia<<"Monto vacaciones"<<" ; ";
	  copia<<"Subsidio INSS"<<" ; ";
	  copia<<"Aguinaldo"<<" ; ";
	  copia<<"Antiguedad"<<" ; ";
	  copia<<"Feriados"<<" ; ";
	  copia<<"Total ingresos"<<" ; ";
	  copia<<"INSS "<<" ; ";
	  copia<<"IR"<<" ; ";
	  copia<<"Otros descuentos"<<" ; ";
	  copia<<"Anticipo salarial"<<" ; ";
	  copia<<"Total deducciones"<<" ; ";
	  copia<<"Total a pagar"<<" ; "<<endl;

	  //Guardar los nombres de los registros en el reporte excel
	  /*excel<<"ID"<<" ; ";
	  excel<<"Nombre(s)"<<" ; ";
	  excel<<"Apellidos"<<" ; ";
	  excel<<"Cedula de identidad"<<" ; ";
	  excel<<"Numero del INSS"<<" ; ";
	  excel<<"Fecha de ingreso"<<" ; ";
	  excel<<"Cargo"<< " ; ";
	  excel<<"Area"<<" ; ";
	  excel<<"Dias trabajados"<<" ; ";
	  excel<<"Salario bruto"<<" ; ";
	  excel<<"Salario "<<" ; ";
	  excel<<"Cantidad horas extras"<<" ; ";
	  excel<<"Monto horas extras"<<" ; ";
	  excel<<"Dias de vacaciones"<<" ; ";
	  excel<<"Monto vacaciones"<<" ; ";
	  excel<<"Subsidio INSS"<<" ; ";
	  excel<<"Aguinaldo"<<" ; ";
	  excel<<"Antiguedad"<<" ; ";
	  excel<<"Feriados"<<" ; ";
	  excel<<"Total ingresos"<<" ; ";
	  excel<<"INSS "<<" ; ";
	  excel<<"IR"<<" ; ";
	  excel<<"Otros descuentos"<<" ; ";
	  excel<<"Anticipo salarial"<<" ; ";
	  excel<<"Total deducciones"<<" ; ";
	  excel<<"Total a pagar"<<" ; "<<endl;
	  */

	  ofstream maestro1;
	  maestro1.open("Principal//Datos maestros.txt",ios::app);//archivo estatico o maestro(datos que no se van a mover)
	  if(maestro1.fail()){
	 	system("cls");
	 	gotoxy(50,50);cout<<"No se pudo abrir el archivo"<<endl;
	 	exit(1);
		}


      	for(int i=0;i<2;i++){

			 fflush(stdin);

			 gotoxy(1,11+i);cout<<i+1<<".-";

			 dat[i].llave=obtenerLlave();

			 maestro1<<dat[i].llave<<" ; ";

			 copia<<dat[i].llave<<" ; ";

			 variantes<<dat[i].llave<<" ; ";

			 excel<<dat[i].llave<<" ; ";

			 fflush(stdin);//limpiar buffer

			  do{
			  	j=0;
			  	valido=true;
	 		    gotoxy(6,11+i);getline(cin,dat[i].nombre);//nombre
			    longitud = dat[i].nombre.length();

				  while(j<longitud){

					 if(!isalpha(dat[i].nombre.at(j))&& !isspace(dat[i].nombre.at(j))){
			 			ShellExecute(0,"open","Error.vbs",NULL,NULL,1);
						valido=false;
			 			break;
					 }
					 j++;
				 }

			  }while(!valido);

			    maestro1<<dat[i].nombre<<" ; ";
	 		    copia<<dat[i].nombre<<" ; ";
	 		    excel<<dat[i].nombre<<" ; ";

			 do{
			 	j=0;
			 	valido=true;
			    gotoxy(40,11+i);getline(cin,dat[i].apellido);//apellidos
	 		    fflush(stdin);//limpiar buffer
			    longitud = dat[i].apellido.length();

			 	while(j<longitud){
			 		if(!isalpha(dat[i].apellido.at(j))&& !isspace(dat[i].apellido.at(j))){
			 			Beep(2000,1000);
						ShellExecute(0,"open","Error.vbs",NULL,NULL,1);
			 			valido=false;
			 			break;
					 }
					 j++;
				 }

			 }while(!valido);

			 maestro1<<dat[i].apellido<<" ; ";
			 copia<<dat[i].apellido<<" ; ";
			 excel<<dat[i].apellido<<" ; ";


			 gotoxy(80,11+i);getline(cin,dat[i].cedula);//numero de cedula
			 maestro1<<dat[i].cedula<<" ; ";
			 copia<<dat[i].cedula<<" ; ";
			 excel<<dat[i].cedula<<" ; ";


			 gotoxy(120,11+i);getline(cin,dat[i].numinss);//numero del inss
			 maestro1<<dat[i].numinss<<" ; ";
			 copia<<dat[i].numinss<<" ; ";
			 excel<<dat[i].numinss<<" ; ";

			 dat[i].fechaing=str;

			 gotoxy(150,11+i);cout<<dat[i].fechaing;//fecha de ingreso
			 maestro1<<dat[i].fechaing<<" ; "<<endl;
			 copia<<dat[i].fechaing<<" ; "<<endl;
			 excel<<dat[i].fechaing<<" ; "<<endl;

			 dat[i].anioing=dat[i].fechaing.substr(6,4);//años
			 dat[i].mesing=dat[i].fechaing.substr(3,2);//meses
			 dat[i].diasing=dat[i].fechaing.substr(0,2);//dias

			 getch();

			 }

	system("cls");

	inicio();

	auxiliar();

	  gotoxy(90,10);cout<<"Cargo";

	  gotoxy(120,10);cout<<"Area";

	  gotoxy(160,10);cout<<"Dias trabajados";

      gotoxy(190,10);cout<<"Salario bruto";


      for(int i=0;i<2;i++){
			fflush(stdin);//limpiar buffer
      		do{
      			j=0;
      			valido=true;
      			gotoxy(90,11+i);getline(cin,dat[i].cargo);//cargo
      			longitud=dat[i].cargo.length();
      			while(j<longitud){
      				if(!isalpha(dat[i].cargo.at(j)) &&!isspace(dat[i].cargo.at(j))){
      					Beep(2000,1000);
      					ShellExecute(0,"open","Error.vbs",NULL,NULL,1);
      					valido=false;
      					break;
					  }
      				j++;
				  }

			  }while(!valido);

      		variantes<<dat[i].cargo<<" ; ";
      		copia<<dat[i].cargo<<" ; ";
      		excel<<dat[i].cargo<<" ; ";

      		do{
      			j=0;
      			valido=true;
      			gotoxy(120,11+i);getline(cin,dat[i].area);//area
      			longitud=dat[i].area.length();
      			while(j<longitud){
      				if(!isalpha(dat[i].area.at(j))&&!isspace(dat[i].area.at(j))){
      					Beep(2000,1000);
      					ShellExecute(0,"open","Error.vbs",NULL,NULL,1);
      				    valido=false;
      				    break;
					  }
					  j++;
				  }

			  }while(!valido);

      		variantes<<dat[i].area<<" ; ";
      		copia<<dat[i].area<<" ; ";
      		excel<<dat[i].area<<" ; ";

			fflush(stdin);//limpiar buffer
      		do{

      		   gotoxy(160,11+i);cin>>dat[i].dias;//dias trabajados

			   if(dat[i].dias<0 || dat[i].dias>30){
			   	  Beep(2000,1000);
				  ShellExecute(0,"open","msgbox.vbs",NULL,NULL,1);
			   }

			  }while(dat[i].dias>30 || dat[i].dias<0);

			variantes<<dat[i].dias<<" ; ";
      		copia<<dat[i].dias<<" ; ";
      		excel<<dat[i].dias<<" ; ";

      		do{

				gotoxy(190,11+i);cin>>dat[i].aux2.salariobruto;//salario bruto

				if(dat[i].aux2.salariobruto<=0){
      		    	ShellExecute(0,"open","msgbox.vbs",NULL,NULL,1);
				  }

			  }while(dat[i].aux2.salariobruto<=0);


			variantes<<dat[i].aux2.salariobruto<<";"<<endl;
      		copia<<dat[i].aux2.salariobruto<<";"<<endl;
      		excel<<dat[i].aux2.salariobruto<<";"<<endl;

      		fflush(stdin);//limpiar buffer

	  }

	  system("cls");

	  inicio();
	  auxiliar();//funcion que almacena el nombre y apellido

	  gotoxy(80,10);cout<<"Salario ";

	  gotoxy(110,10);cout<<"Cantidad horas extras";

	  gotoxy(150,10);cout<<"Monto horas extras";

	  gotoxy(180,10);cout<<"Dias de vacaciones";

	  gotoxy(210,10);cout<<"Monto vacaciones";

	 fflush(stdin);//limpiar buffer

	 for(int i=0;i<2;i++){

		salarioprima(i);

		gotoxy(80,11+i);cout<<dat[i].aux2.salarioing;
	 	variantes<<dat[i].aux2.salarioing<<" ; ";
	 	copia<<dat[i].aux2.salarioing<<" ; ";
	 	excel<<dat[i].aux2.salarioing<<" ; ";

	 	do{
	 		fflush(stdin);
	 		gotoxy(110,11+i);cin>>dat[i].aux2.horascantidad;
	 		if(dat[i].aux2.horascantidad<0){
	 			ShellExecute(0,"open","msgbox.vbs",NULL,NULL,1);
	 		}

			if(dat[i].aux2.horascantidad>36){
	 			ShellExecute(0,"open","Ehoras.vbs",NULL,NULL,1);
			}


		 }while(dat[i].aux2.horascantidad<0 || dat[i].aux2.horascantidad>36);


		variantes<<dat[i].aux2.horascantidad<<" ; ";
	 	copia<<dat[i].aux2.horascantidad<<" ; ";
	 	excel<<dat[i].aux2.horascantidad<<" ; ";

	 	horasextra(i);

	 	fflush(stdin);//limpiar buffer

	 	gotoxy(150,11+i);cout<<dat[i].aux2.horasmonto;
	 	variantes<<dat[i].aux2.horasmonto<<" ; ";
	 	copia<<dat[i].aux2.horasmonto<<" ; ";
	 	excel<<dat[i].aux2.horasmonto<<" ; ";

	 	do{
	 		fflush(stdin);
	 		 gotoxy(180,11+i);cin>>dat[i].aux2.vacacionesdias;

			 if(dat[i].aux2.vacacionesdias>30 || dat[i].aux2.vacacionesdias<0){
	 		 ShellExecute(0,"open","msgbox.vbs",NULL,NULL,1);

			 }

		 }while(dat[i].aux2.vacacionesdias>30 || dat[i].aux2.vacacionesdias<0);


		variantes<<dat[i].aux2.vacacionesdias<<" ; ";
	 	copia<<dat[i].aux2.vacacionesdias<<" ; ";

	 	vacaciones(i);

	 	gotoxy(210,11+i);cout<<dat[i].aux2.vacacionestotal;

		fflush(stdin);//limpiar buffer

		variantes<<dat[i].aux2.vacacionestotal<<" ; ";
	 	copia<<dat[i].aux2.vacacionestotal<<" ; ";
	 	excel<<dat[i].aux2.vacacionestotal<<" ; ";

	 }

    getch();
	system("cls");

	inicio();
    auxiliar();

    gotoxy(80,10);cout<<"Dias Subsidio";

    gotoxy(110,10);cout<<"Subsidio INSS ";

    gotoxy(140,10);cout<<"Aguinaldo";

    gotoxy(165,10);cout<<"Feriados";

    gotoxy(190,10);cout<<"Total ingresos";


    for(int i=0;i<2;i++){

    do{
    fflush(stdin);
	gotoxy(80,11+i);cin>>dat[i].aux2.subsidiodia;

	if(dat[i].aux2.subsidiodia<0 || dat[i].aux2.subsidiodia>30){
		ShellExecute(0,"open","msgbox.vbs",NULL,NULL,1);
	}

	}while(dat[i].aux2.subsidiodia<0 || dat[i].aux2.subsidiodia>30);

	fflush(stdin);

	subsidioINSS(i);


	gotoxy(110,11+i);cout<<dat[i].aux2.subsidio;
    variantes<<dat[i].aux2.subsidio<<" ; ";
    copia<<dat[i].aux2.subsidio<<" ; ";
    excel<<dat[i].aux2.subsidio<<" ; ";

    aguinaldo(i);

    fflush(stdin);

    gotoxy(140,11+i);cout<<dat[i].aux2.aguinaldo;
    variantes<<dat[i].aux2.aguinaldo<<" ; ";
    copia<<dat[i].aux2.aguinaldo<<" ; ";
    excel<<dat[i].aux2.aguinaldo<<" ; ";

	feriados(i);

	fflush(stdin);
	gotoxy(165,11+i);cout<<dat[i].aux2.feriados;
	variantes<<dat[i].aux2.feriados<<" ; ";
	copia<<dat[i].aux2.feriados<<" ; ";
	excel<<dat[i].aux2.feriados<<" ; ";

	IngresosTotal(i);

	fflush(stdin);
	gotoxy(190,11+i);cout<<dat[i].aux2.totalingresos<<endl;
	variantes<<dat[i].aux2.totalingresos<<" ; ";
	copia<<dat[i].aux2.totalingresos<<" ; ";
	excel<<dat[i].aux2.totalingresos<<" ; ";


	getch();

	}

	system("cls");

	inicio();

	auxiliar();


	  gotoxy(80,10);cout<<"INSS ";

	  gotoxy(110,10);cout<<"IR";

	  gotoxy(130,10);cout<<"Otros descuentos";

	  gotoxy(155,10);cout<<"Anticipo salarial";

	  gotoxy(180,10);cout<<"Total deducciones";

	  gotoxy(210,10);cout<<"Total a pagar";


	 for(int i=0;i<2;i++){

	 	fflush(stdin);

		INSS_deduccion(i);

		gotoxy(80,11+i);cout<<dat[i].aux2.aux1.INSS_deu;
	 	variantes<<dat[i].aux2.aux1.INSS_deu<<" ; ";
	 	copia<<dat[i].aux2.aux1.INSS_deu<<" ; ";

	 	IR(i);

	 	fflush(stdin);

		gotoxy(110,11+i);cout<<dat[i].aux2.aux1.IR_deu;
	 	variantes<<dat[i].aux2.aux1.IR_deu<<" ; ";
	 	copia<<dat[i].aux2.aux1.IR_deu<<" ; ";
	 	excel<<dat[i].aux2.aux1.IR_deu<<" ; ";

		 do{
		 	fflush(stdin);
	 		gotoxy(130,11+i);cin>>dat[i].aux2.aux1.otrosDescuentos;

			 if(dat[i].aux2.aux1.otrosDescuentos<0){
	 			ShellExecute(0,"open","msgbox.vbs",NULL,NULL,1);
			 }

		 }while(dat[i].aux2.aux1.otrosDescuentos<0);

	 	variantes<<dat[i].aux2.aux1.otrosDescuentos<<" ; ";
	 	copia<<dat[i].aux2.aux1.otrosDescuentos<<" ; ";
	 	excel<<dat[i].aux2.aux1.otrosDescuentos<<" ; ";

	 	do{
	 		fflush(stdin);
	 		gotoxy(155,11+i);cin>>dat[i].aux2.aux1.anticiposS;
	 		if(dat[i].aux2.aux1.anticiposS<0){
	 			ShellExecute(0,"open","msgbox.vbs",NULL,NULL,1);
			 }

			if(dat[i].aux2.aux1.anticiposS>dat[i].aux2.salariobruto){
				ShellExecute(0,"open","descuentoError.vbs",NULL,NULL,1);
			}

		 }while(dat[i].aux2.aux1.anticiposS<0 || dat[i].aux2.aux1.anticiposS>dat[i].aux2.salariobruto);


	 	variantes<<dat[i].aux2.aux1.anticiposS<<" ; ";
	 	copia<<dat[i].aux2.aux1.anticiposS<<" ; ";
	 	excel<<dat[i].aux2.aux1.anticiposS<<" ; ";

	 	fflush(stdin);

		deduccionesTotal(i);

	 	gotoxy(180,11+i);cout<<dat[i].aux2.aux1.totaldeducciones;
	 	variantes<<dat[i].aux2.aux1.totaldeducciones<<" ; ";
	 	copia<<dat[i].aux2.aux1.totaldeducciones<<" ; ";
	 	excel<<dat[i].aux2.aux1.totaldeducciones<<" ; ";

	 	fflush(stdin);
	 	aPagar(i);

	 	gotoxy(210,11+i);cout<<dat[i].aux2.aux1.PagaTotal<<endl;
	 	variantes<<dat[i].aux2.aux1.PagaTotal<<" ; "<<endl;
	 	copia<<dat[i].aux2.aux1.PagaTotal<<" ; "<<endl;
	 	excel<<dat[i].aux2.aux1.PagaTotal<<" ; "<<endl;

		getch();

	 	fflush(stdin);
	}


	variantes.close();

	maestro1.close();

	copia.close();

	excel.close();
}

void principal(){
	system("cls");
    system("color e");
	const char*titulo ="Menu Registro"; //Cadena constante
	const char*opciones[]={"Ingresar datos del empleado","Trabajar con datos existentes","Modificar registro","Eliminar registro",
	"Listado de archivos creados","Reporte en Excel","Salir"};//arreglo constante de caracteres
	int x=7;//dimension de la cadena de caracteres
	bool frecuencia=true;

	do{

	opcion = menu(titulo,opciones,x);//retorna la opcion escogida por el usuario y es almacenada en la variable opciones

	   switch (opcion){

   		case 1: {

   			nomina();
			break;
		   }

   		case 2:{
   			system("cls");
   			ShellExecute(0,"open","Work.exe",NULL,NULL,1);
			break;
		   }


		case 3:{
			system("cls");
			system("Modificar.exe");
			break;
		}


	  	case 4:{
            quitar();
	  		//ShellExecute(0,"open","Eliminar.exe",NULL,NULL,1);
			break;

		  }

		case 5:{
			system("cls");
			system("Excel\\respaldo.bat");
			system("pause");
			break;

		}
		case 6:{
			system("ReporteEx.exe");
			break;

		}
		case 7:{
			system("cls");
			cout<<"Salio del programa"<<endl;
			frecuencia=false;
			system("pause>null");
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

void leer(){

	system("cls");

	inicio();

	string lectura;//cadena para almacenar el contenido del archivo

	ifstream maestro;//flujo de salida, en este caso llamado archivo

	maestro.open("Datos maestros.txt",ios::in);//abirendo el archivo en modo de lectura

	if(maestro.fail()){//en caso de que no se pueda leer
		gotoxy(50,50);cout<<"El archivo no se pudo leer el archivo"<<endl;
		exit(1);
	}

	while(!maestro.eof()){//mientras que no sea el final del archivo
		getline(maestro,lectura);{
		cout<<lectura<<endl;//leer el archivo a traves de la variable string definida como lectura
		}
	}

	maestro.close();

	system("pause");

}
void auxiliar(){

	gotoxy(6,10);cout<<"Nombre(s)";
	gotoxy(40,10);cout<<"Apellidos";

	for(int i=0;i<2;i++){//ciclo for para visualizar nuevamente los nombres y apellidos para su post ingreso de datos faltantes
      	gotoxy(1,11+i);cout<<i+1<<".-";
		gotoxy(6,11+i);cout<<dat[i].nombre<<endl;
      	gotoxy(40,11+i);cout<<dat[i].apellido<<endl;
	  }

}
struct datos{
	int diaDesp, mesDesp, anioDesp, fechadespido;
	int mesBase = 30, anioBase = 360;
	float totalInicio, totalActual;
	int TotalDias,cantidadAnios, cantidadMeses, CantidadDias;
	int indemnizacion;
}ant[100];

int articulo();
int DespInjust();
int DespJust();
int calculo();
int menuIn();

void quitar(){

    system("cls");

	int clavelec;
	for(int i=0; i<100; i++){
         if(dat[i].llave >= 0){
                cout<<"clave : "<<dat[i].llave<<" Nombre: "<<dat[i].nombre<<endl;
        }
    }
    int indiceParaEliminar=-1;
    do{
        cout<<"Introdusca la clave de la persona a eliminar"<<endl;
        cin>>clavelec;
         for(int i=0; i<100; i++){
             if(dat[i].llave >= 0){
                if (dat[i].llave == clavelec){
                    indiceParaEliminar=i;
                    break;
                }
            }
        }
    }while(indiceParaEliminar== -1);

    system("cls");
    cout<<"Nombre: "<<dat[indiceParaEliminar].nombre<<endl;
    cout<<"Cargo:"<<dat[indiceParaEliminar].cargo<<endl;
    cout<<"Area: "<<dat[indiceParaEliminar].area<<endl;
    cout<<"Salario:"<<dat[indiceParaEliminar].aux2.salariobruto<<endl;
    cout <<"Esta seguro? (s/n)" << endl;
    char c;
    cin >> c;
    if (c!='s')
        return;

    dat[indiceParaEliminar].anioing=dat[indiceParaEliminar].fechaing.substr(6,4);//años
	dat[indiceParaEliminar].mesing=dat[indiceParaEliminar].fechaing.substr(3,2);//meses
	dat[indiceParaEliminar].diasing=dat[indiceParaEliminar].fechaing.substr(0,2);//dias

    int diaIngreso = atoi(dat[indiceParaEliminar].diasing.c_str());
    int MesIngreso = atoi(dat[indiceParaEliminar].mesing.c_str());
    int AnioIngreso = atoi(dat[indiceParaEliminar].anioing.c_str());

    cout<<"Calcular anios y mes para"<<dat[indiceParaEliminar].nombre<<endl;
	cout<<"Dia de ingreso: "; cout<<dat[indiceParaEliminar].diasing<<endl;
	cout<<"Mes de ingreso: "; cout<<dat[indiceParaEliminar].mesing<<endl;
	cout<<"Año de ingreso: "; cout<<dat[indiceParaEliminar].anioing<<endl;
	cout<<"------------------------------------\n";
	cout<<"Dia de salida: "; cin>>ant[indiceParaEliminar].diaDesp;
	cout<<"Mes de salida: "; cin>>ant[indiceParaEliminar].mesDesp;
	cout<<"Año de salida: "; cin>>ant[indiceParaEliminar].anioDesp;
	cout<<"------------------------------------\n";

	ant[indiceParaEliminar].totalInicio = AnioIngreso * ant[indiceParaEliminar].anioBase + MesIngreso * ant[indiceParaEliminar].mesBase + diaIngreso;
	ant[indiceParaEliminar].totalActual = ant[indiceParaEliminar].anioDesp * ant[indiceParaEliminar].anioBase + ant[indiceParaEliminar].mesDesp * ant[indiceParaEliminar].mesBase + ant[indiceParaEliminar].diaDesp;
	ant[indiceParaEliminar].TotalDias = ant[indiceParaEliminar].totalActual - ant[indiceParaEliminar].totalInicio;
    ant[indiceParaEliminar].cantidadAnios = ant[indiceParaEliminar].TotalDias/ant[indiceParaEliminar].anioBase;
    ant[indiceParaEliminar].cantidadMeses = (ant[indiceParaEliminar].TotalDias-ant[indiceParaEliminar].cantidadAnios*ant[indiceParaEliminar].anioBase)/ant[indiceParaEliminar].mesBase;
    ant[indiceParaEliminar].CantidadDias = ant[indiceParaEliminar].TotalDias-(ant[indiceParaEliminar].cantidadAnios*ant[indiceParaEliminar].anioBase+ant[indiceParaEliminar].cantidadMeses*ant[indiceParaEliminar].mesBase);
    Sleep(1000);

    string diaDespido= to_string(ant[indiceParaEliminar].diaDesp);
    string mesdespido= to_string(ant[indiceParaEliminar].mesDesp);
    string aniodespido= to_string(ant[indiceParaEliminar].anioDesp);

    cout<<ant[indiceParaEliminar].cantidadAnios<<" Anios, "<<ant[indiceParaEliminar].cantidadMeses<<" meses, "<<endl;
    system("pause");
    system("cls");

    dat[indiceParaEliminar].llave= -1;

    ofstream borrado;

    mkdir("Eliminado");
    borrado.open("Eliminado//Borrado.csv",ios::app);

    borrado<<"Llave"<<";";
    borrado<<"Nombre"<<";";
    borrado<<"Apellido: "<<";";
    borrado<<"Cedula: "<<";";
    borrado<<"Numero INSS: "<<";";
    borrado<<"Fecha de ingreso: "<<";";
    borrado<<"Fecha despido: "<<";";
    borrado<<"Cargo: "<<";";
    borrado<<"Area: "<<";";
    borrado<<"Salario: "<<";"<<endl;
    borrado<<dat[indiceParaEliminar].llave<<";";
    borrado<<dat[indiceParaEliminar].nombre<<";";
    borrado<<dat[indiceParaEliminar].apellido<<";";
    borrado<<dat[indiceParaEliminar].cedula<<";";
    borrado<<dat[indiceParaEliminar].numinss<<";";
    borrado<<dat[indiceParaEliminar].fechaing<<";";
    borrado<<diaDespido<<"-"<<mesdespido<<"-"<<aniodespido<<";";
    borrado<<dat[indiceParaEliminar].cargo<<";";
    borrado<<dat[indiceParaEliminar].area<<";";
    borrado<<dat[indiceParaEliminar].aux2.salariobruto<<";"<<endl;

    EscribirDatosMaestro();

    Sleep(1000);
    cout<<"Registro eliminado"<<endl;
    Sleep(1000);
    system("cls");
    borrado.close();

	system("pause > 0");
	system("cls");
}
