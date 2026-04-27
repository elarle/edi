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

	while(!this->artistas->alFinal() && !enc && this->artistas != nullptr){
		a = this->artistas->consultar();
		if(a->getNombre() == nombre){
			enc = true;
		}
		else
			this->artistas->avanzar();
	}

	return enc;
}

void GestorArtistas::insertar(string nombre, string country, int seguidores){
	
	Artista* a = nullptr;
	bool igual = false;
	bool enc = false;

	artistas->moverPrimero();

	while (!artistas->alFinal() && !enc && !igual){
		a = artistas->consultar();

		if (a->getNombre() == nombre){
			//Ya está. No se inserta
			igual = true;
		} else {
			//En la lista se apunta a '2' y nombre es '1'
			if (a->getNombre() > nombre){
				enc = true;
			}
			else {
				artistas->avanzar();
			}
		}

	}
	if (!igual){
		Artista *nuevo = new Artista(nombre, country, seguidores);
		nuevo->mostrar();
		artistas->insertar(nuevo);
		this->numero_artistas++;
	}
}

void GestorArtistas::mostrar() const{
	Artista* a = nullptr;
	this->artistas->moverPrimero();

	while(!this->artistas->alFinal()){
		a = this->artistas->consultar();
		a->mostrar();
		this->artistas->avanzar();
	}
}
