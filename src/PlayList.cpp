#include "PlayList.h"

//Constructores
PlayList::PlayList(){

};
PlayList::PlayList(string nombre){

}
PlayList::PlayList(const PlayList & playlist){

}
PlayList::~PlayList(){

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

}

void PlayList::agregarCancion(Cancion * cancion){

}

void PlayList::eliminarCancion(){

}

void PlayList::reproducir(){

}

void PlayList::reproducirDesde(int indice){

}
