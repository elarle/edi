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

#endif /* ARCHIVOS_H_ */
