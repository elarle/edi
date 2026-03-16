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

Artista::Artista(const Artista & artista){
	this->nombre = artista.nombre;
	this->country = artista.country;
	this->seguidores = artista.seguidores;

	this->numero_canciones = artista.numero_canciones;
	//TODO: Hacer algoritmo para copiar todas las canciones
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

