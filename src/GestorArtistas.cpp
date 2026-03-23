#include "GestorArtistas.h"

GestorArtistas::GestorArtistas(){

}

GestorArtistas::GestorArtistas(const GestorArtistas & g){

}

int GestorArtistas::numElementos() const{
	return this->numero_artistas;
}

bool GestorArtistas::buscar(string nombre, Artista* &artista) const{
	return false;
}

void GestorArtistas::insertar(string nombre, string country, int seguidores){

}

void GestorArtistas::mostrar() const{

}
