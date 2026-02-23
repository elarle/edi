#ifndef ARCHIVOS_H_
#define ARCHIVOS_H_

#include<fstream>
#include<iostream>

using namespace std;

inline void leerFichero1(){
	ifstream file;
	string linea;
	int contador;

	contador = 0;

	file.open("usuarios.csv");

	if(file.is_open()){
		getline(file, linea); //Se hace getline aquí para descartar la primera línea que no la usamos.

		while(!file.eof()){
			getline(file, linea); 
			contador++;
			cout << contador << " " << linea << endl;
		}
		file.close();

	} else cerr << "Error abriendo el archivo usuario.csv. No existe" << endl;
}

inline void leerFichero2(){
	ifstream file;
	int contador;
	
	string id_usuario;
	string apellidos_nombre;
	string email;
	string contraseña;

	string dia;
	string mes;
	string año;

	contador = 0;

	file.open("usuarios.csv");

	if(file.is_open()){
		getline(file, id_usuario); //Se hace getline aquí para descartar la primera línea que no la usamos.

		while(!file.eof()){
			getline(file, id_usuario, ';'); //Leer hasta el primer para el id;
								
			//Descartamos la última lina para no tener usuarios de más
			if(!file.eof()){
				getline(file, apellidos_nombre, ';'); //Leer hasta la segunda ;
				getline(file, email, ';'); //Leer hasta la tercera ;
				getline(file, contraseña, ';'); //Leer hasta la cuarta ;
				
				//Leer fecha
				getline(file, dia, '/');
				getline(file, mes, '/');
				getline(file, año);

				contador++;
				cout << contador << " ID: " << id_usuario << endl;
				cout << contador << " NA: " << apellidos_nombre << endl;
				cout << contador << " EMAIL: " << email << endl;
				cout << contador << " PASS: " << contraseña << endl;
				cout << endl;
			}
		}
		file.close();

	} else cerr << "Error abriendo el archivo usuario.csv. No existe" << endl;
}

inline void leerFicheroSeleccionarAño(int año_selección){
	ifstream file;
	ofstream salida;

	int contador;
	
	string id_usuario;
	string apellidos_nombre;
	string email;
	string contraseña;

	string dia;
	string mes;
	string año;

	contador = 0;

	file.open("usuarios.csv");
	salida.open("usuarios_" + to_string(año_selección) + ".csv");

	if(file.is_open()){
		getline(file, id_usuario); //Se hace getline aquí para descartar la primera línea que no la usamos.

		while(!file.eof()){
			getline(file, id_usuario, ';'); //Leer hasta el primer para el id;
								
			//Descartamos la última lina para no tener usuarios de más
			if(!file.eof()){
				getline(file, apellidos_nombre, ';'); //Leer hasta la segunda ;
				getline(file, email, ';'); //Leer hasta la tercera ;
				getline(file, contraseña, ';'); //Leer hasta la cuarta ;
				
				//Leer fecha
				getline(file, dia, '/');
				getline(file, mes, '/');
				getline(file, año);
				
				contador++;

				//Sólo escribimos los seleccionados
				if(stoi(año) == año_selección){
					salida << contador << " id: " << id_usuario << endl;
					salida << contador << " an: " << apellidos_nombre << endl;
					salida << contador << " email: " << email << endl;
					salida << contador << " pass: " << contraseña << endl;
					salida << endl;
				}


			}
		}
		file.close();

	} else cerr << "Error abriendo el archivo usuario.csv. No existe" << endl;
}


#endif /* ARCHIVOS_H_ */
