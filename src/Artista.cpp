#include "Artista.h"

//Constructores
Artista::Artista(){
};

Artista::Artista(string nombre, string country, int seguidores){

}

Artista::Artista(const Artista & artista){

}

//Getters
string Artista::getNombre() const{
	return "";
}

string Artista::getCountry() const{
	return "";
}

int Artista::getSeguidores() const{
	return -1;
}

void Artista::setNombre(string nombre){

}

void Artista::setCountry(string country){

}

void Artista::setSeguidores(int seguidores){

}

bool Artista::operator==(const Artista &artista) const{
	return false;
}

bool Artista::operator<(const Artista &artista) const{
	return false;
}

