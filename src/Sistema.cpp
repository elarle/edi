#include "Sistema.h"
#include "archivos.h"

Sistema::Sistema(){
	this->gestorUsuarios = new GestorUsuarios();
	this->gestorArtistas = new GestorArtistas();
}

Sistema::Sistema(const Sistema& sistema){
	this->gestorUsuarios = new GestorUsuarios(*(sistema.gestorUsuarios));
	this->gestorUsuarios = new GestorUsuarios(*(sistema.gestorUsuarios));
}

Sistema::~Sistema(){
	delete this->gestorUsuarios;
	delete this->gestorArtistas;
}

void Sistema::cargarUsuarios(string archivo){
	ifstream file;
	int contador;
	
	string id_usuario;
	string apellidos_nombre;
	string email;
	string contraseña;

	string dia;
	string mes;
	string año;

	Fecha* fecha;
	fecha = new Fecha();

	contador = 0;

	file.open(archivo);

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

				fecha->setDia(stoi(dia));
				fecha->setAño(stoi(mes));
				fecha->setAño(stoi(año));

				contador++;
				//cout << contador << " ID: " << id_usuario << endl;
				//cout << contador << " NA: " << apellidos_nombre << endl;
				//cout << contador << " EMAIL: " << email << endl;
				//cout << contador << " PASS: " << contraseña << endl;

				this->gestorUsuarios->insertar(
					id_usuario,
					apellidos_nombre,
					email,
					contraseña,
					fecha
				);
			}
		}
		cout << "Cargados: " << contador << " usuarios." << endl;
		file.close();

	} else cerr << "Error abriendo el archivo usuario.csv. No existe" << endl;

	delete fecha;
}

void Sistema::cargarArtistas(string archivo){
	ifstream file;
	int contador;
	
	string nombre;
	string pais;
	
	Fecha* fecha;
	fecha = new Fecha();

	contador = 0;

	file.open(archivo);

	if(file.is_open()){
		getline(file, nombre); //Se hace getline aquí para descartar la primera línea que no la usamos.

		while(!file.eof()){
			getline(file, nombre, ';'); //Leer hasta el primer para el id;
						
			cout << nombre << endl;
			//Descartamos la última lina para no tener usuarios de más
			if(!file.eof()){
				getline(file, pais);

				contador++;

				this->gestorArtistas->insertar(
					nombre,
					pais,
					0
				);
			}
		}
		cout << "Cargados: " << contador << " artistas." << endl;
		file.close();

	} else cerr << "Error abriendo el archivo: " << archivo << " No existe" << endl;

	delete fecha;
}


void Sistema::mostrarUsuarios() const{
	this->gestorUsuarios->mostrar();
}

void Sistema::mostrarArtistas() const{
	this->gestorArtistas->mostrar();
}

