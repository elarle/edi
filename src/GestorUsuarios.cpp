#include "GestorUsuarios.h"

GestorUsuarios::GestorUsuarios(){
	
}

GestorUsuarios::GestorUsuarios(const GestorUsuarios & gestor){

}

GestorUsuarios::~GestorUsuarios(){

}

int GestorUsuarios::numElementos() const{
	return this->numero_usuarios;
}

bool GestorUsuarios::buscar(string nombre, Usuario* &usuario) const{
	usuario = new Usuario();
	return false;
}

void GestorUsuarios::insertar(string id, string nombre, string email, string contraseña){

}

void GestorUsuarios::mostrar() const{

}



