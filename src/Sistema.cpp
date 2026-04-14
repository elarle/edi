#include "Sistema.h"

Sistema::Sistema(){
	this->gestorUsuarios = new GestorUsuarios();
	this->gestorArtistas = new GestorArtistas();
}

Sistema::Sistema(const Sistema& sistema){
	this->gestorUsuarios = new GestorUsuarios(*(sistema.gestorUsuarios));
	this->gestorUsuarios = new GestorUsuarios(*(sistema.gestorUsuarios));
}

Sistema::~Sistema(){
	delete this->gestorUsuarios;
	delete this->gestorArtistas;
}
