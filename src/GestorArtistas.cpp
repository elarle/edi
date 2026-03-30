#include "GestorArtistas.h"

GestorArtistas::GestorArtistas(){
	artistas = new ListaDPI<Artista*>;
	numero_artistas = 0;
}

GestorArtistas::GestorArtistas(const GestorArtistas & g){
	Artista *a;
	numero_artistas = g.numero_artistas;
	artistas = new ListaDPI<Artista*>;
	g.artistas->moverPrimero();

	while(!g.artistas->alFinal()){
		a = g.artistas->consultar();
		this->artistas->insertar(new Artista (*a));
		g.artistas->avanzar();
	}

}
GestorArtistas::~GestorArtistas(){
	Artista *a;
	this->artistas->moverPrimero();

	while(!this->artistas->estaVacia()){
		a = this->artistas->consultar();
		delete a;
		this->artistas->eliminar();
	}
	delete artistas;
}

int GestorArtistas::numElementos() const{
	return this->numero_artistas;
}

bool GestorArtistas::buscar(string nombre, Artista* &a) const{
	bool enc = false;
	this->artistas->moverPrimero();

	while(!this->artistas->alFinal() && !enc){
		a = this->artistas->consultar();
		if(a->getNombre == nombre){
			enc = true;
		}
		else
			this->artistas->avanzar();
	}

	return enc;
}

void GestorArtistas::insertar(string nombre, string country, int seguidores){
	Artista *aux;
	this->artistas->moverPrimero();

	while(!this->artistas->alFinal() && !buscar(nombre, aux)){
		aux = this->artistas->consultar();
		if(aux->getNombre > nombre){
			this->artistas->insertar(new Artista (nombre, country, seguidores));
		}
		else
			this->artistas->avanzar();
	}
}

void GestorArtistas::mostrar() const{

}
