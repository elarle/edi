#include "PlayList.h"

//Constructores
PlayList::PlayList(){
	this->nombre = "";
	this->canciones = 0;
	this->duracion = 0;

	cola = new Cola<Cancion*>;

};

PlayList::PlayList(string nombre){
	this->nombre = nombre;
	this->canciones = 0;
	this->duracion = 0;

	cola = new Cola<Cancion*>;

}
PlayList::PlayList(const PlayList & playlist){

}
PlayList::~PlayList(){
	delete cola;
}

//Getters
string PlayList::getNombre() const{
	return "";
}
int PlayList::getDuracion() const{
	return -1;
}
int PlayList::getCanciones() const{
	return -1;
}

//Getters
void PlayList::setNombre(string nombre){

}

//Métodos
void PlayList::mostrar() const{
	Cancion *c = nullptr;
	Cola<Cancion*> *aux = new Cola<Cancion*>;

	while (!cola->estaVacia()){
		c = cola->getPrimero (c);
		c->mostrar ();
		aux->encolar(c);
		cola->desencolar ();
	}

}

void PlayList::agregarCancion(Cancion * cancion){

}

void PlayList::eliminarCancion(){

}

void PlayList::reproducir(){
	int i;
	Cancion *c = nullptr;

	for (i = 0 ; i < this->canciones; i++){
		c = cola->getPrimero (c);
		c->mostrar();
		cola->desencolar ();
		cola->encolar (c);
	}
}

void PlayList::reproducirDesde(int indice){
	int i;
	Cancion *c = nullptr;
	for (i = 0 ; i < indice ; i++){
		c = cola->getPrimero (c);
		cola->desencolar ();
		cola->encolar (c);
	}
	reproducir();
}
