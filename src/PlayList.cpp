#include "PlayList.h"

//Auxiliares

//DESC={Copia el contenido de la primera copia en la segunda.}
//COMP={O(n)}
void copiarCola(Cola<Cancion*>* src, Cola<Cancion*>* dst){
	Cola<Cancion*>* cola_aux = new Cola<Cancion*>;
	Cancion* cancion_aux;

	//Primero copiamos los datos a un aux.
	while(!src->estaVacia()){
		cola_aux->encolar(src->getPrimero());
		src->desencolar();
	}

	//Luego los copiamos en cancion_aux para duplicarlos
	while(!cola_aux->estaVacia()){
		cancion_aux = cola_aux->getPrimero();
		src->encolar(cancion_aux);
		dst->encolar(cancion_aux);
		cola_aux->desencolar();
	}

	delete cola_aux;
}

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
	this->nombre = playlist.nombre;
	this->duracion = playlist.duracion;
	this->canciones  =playlist.canciones;

	this->cola = new Cola<Cancion*>;
	copiarCola(playlist.cola, this->cola);
}
PlayList::~PlayList(){
	while(!this->cola->estaVacia())
		this->cola->desencolar();
	delete cola;
}

//Getters
string PlayList::getNombre() const{
	return this->nombre;
}
int PlayList::getDuracion() const{
	return this->duracion;
}
int PlayList::getCanciones() const{
	return this->canciones;
}

//Getters
void PlayList::setNombre(string nombre){
	this->nombre = nombre;
}

//Métodos
void PlayList::mostrar() const{
	Cancion *c = nullptr;
	Cola<Cancion*> *aux = new Cola<Cancion*>;

	while (!cola->estaVacia()){
		c = cola->getPrimero();
		c->mostrar();
		aux->encolar(c);
		cola->desencolar();
	}
	cout << endl;

	while (!aux->estaVacia()){
		c = aux->getPrimero();
		cola->encolar (c);
		aux->desencolar();
	}
	delete aux;
}

void PlayList::agregarCancion(Cancion * cancion){
	this->duracion += cancion->getDuracion();
	this->canciones += 1;
	this->cola->encolar(cancion);
}

void PlayList::eliminarCancion(){
	if(!this->cola->estaVacia()){
		this->duracion -= cola->getPrimero()->getDuracion();
		this->canciones -= 1;
		this->cola->desencolar();
	}
}

void PlayList::reproducir(){
	int i;
	Cancion *c = nullptr;

	for (i = 0 ; i < this->canciones; i++){
		c = cola->getPrimero();
		cout << "	- "; //Para que quede bonito
		c->mostrar();
		cola->desencolar ();
		cola->encolar (c);
	}
}

void PlayList::reproducirDesde(int indice){
	int i;
	Cancion *c = nullptr;

	for (i = 0 ; i < this->canciones; i++){
		c = cola->getPrimero();

		if(i >= indice){
			cout << "	- "; //Para que quede bonito
			c->mostrar();
		}
		
		cola->desencolar();
		cola->encolar (c);
	}
}
