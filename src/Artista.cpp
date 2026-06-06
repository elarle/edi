#include "Artista.h"

//Constructores
Artista::Artista(){
	this->nombre = " ";
	this->country = " ";
	this->seguidores = 0;
	this->numero_canciones = 0;

	this->canciones = new ListaDPI<Cancion*>;
};

Artista::Artista(string nombre, string country, int seguidores){
	this->nombre = nombre;
	this->country = country;
	this->seguidores = seguidores;
	this->numero_canciones = 0;

	this->canciones = new ListaDPI<Cancion*>;
}

Artista::Artista(const Artista & a){
	this->nombre = a.nombre;
	this->country = a.country;
	this->seguidores = a.seguidores;
	this->numero_canciones = a.numero_canciones;
	Cancion *c;
	this->canciones = new ListaDPI<Cancion*>;
	a.canciones->moverPrimero();

	while (!a.canciones->alFinal()){
		c = a.canciones->consultar();
		this->canciones->insertar(new Cancion (*c));
		a.canciones->avanzar();
	}
}

Artista::~Artista(){
	//En principio no se reserva memoria por lo que el destructor da igual.
}

//Getters
string Artista::getNombre() const{
	return this->nombre;
}

string Artista::getCountry() const{
	return this->country;
}

int Artista::getSeguidores() const{
	return this->seguidores;
}

void Artista::setNombre(string nombre){
	this->nombre = nombre;
}

void Artista::setCountry(string country){
	this->country = country;
}

void Artista::setSeguidores(int seguidores){
	this->seguidores = seguidores;
}

bool Artista::operator==(const Artista &artista) const{
	return  this->nombre == artista.nombre;
}

bool Artista::operator<(const Artista &artista) const{
	return  this->nombre < artista.nombre;
}

bool Artista::buscarCancion(string titulo, Cancion* &cancion) const{
	Cancion *c;
	bool enc = false;

	this->canciones->moverPrimero();

	while(!this->canciones->alFinal() && !enc){
		c = this->canciones->consultar();
		if(c->getTitulo() == titulo){
			enc = true;
			cancion = c;
		}
		else
			this->canciones->avanzar();
	}

	return enc;
}

void Artista::insertarCancion(string titulo, string genero, int duracion){
	Cancion *c;

	if(!buscarCancion(titulo, c)){
		this->canciones->moverUltimo();
		this->canciones->avanzar();
		this->canciones->insertar(new Cancion(titulo, genero, duracion));
		this->numero_canciones++;
	}
}

void Artista::mostrar() const{
	cout << "Artista {" << endl;
	cout << "	Nombre: " << this->nombre << endl;
	cout << "	País: " << this->country << endl;
	cout << "	Seguidores: " << this->seguidores << endl;
	cout << "	Canciones: ("<< this->numero_canciones << ") [" << endl;
	//Mostrar canciones
	this->canciones->moverPrimero();
	while(!this->canciones->alFinal()){
		cout << "		- " ; //Para que quede bonito
		this->canciones->consultar()->mostrar();
		this->canciones->avanzar();
	}
	cout << "	]" << endl;

	cout << "}" << endl;
}

void Artista::addSeguidor(){
	this->seguidores++;
}

void Artista::delSeguidor(){
	if(this->seguidores > 0)
		this->seguidores--;
}
