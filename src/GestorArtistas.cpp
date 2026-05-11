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
	
	Artista* aux;

	while(!this->artistas->alFinal() && !enc && this->artistas != nullptr){
		aux = this->artistas->consultar();
		if(aux->getNombre() == nombre){
			enc = true;
		}
		else
			this->artistas->avanzar();
	}

	//Si no se encuentra no se modifica el puntero
	if(enc)
		a = aux;

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
		//nuevo->mostrar();
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

Artista* GestorArtistas::mayorSeguidores() const{
	Artista* aux;
	Artista* mayor = nullptr;

	int max;
	int actual;

	if(!this->artistas->estaVacia()){
		this->artistas->moverPrimero();
		mayor = this->artistas->consultar();
		max = mayor->getSeguidores();
		this->artistas->avanzar();

		while(!this->artistas->alFinal()){
			aux = this->artistas->consultar();
			actual = aux->getSeguidores();
			if(actual > max){
				mayor = aux;
				max = actual;
			}
			this->artistas->avanzar();
		}
	}

	return mayor;
}
