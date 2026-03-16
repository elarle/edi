#include "GestorUsuarios.h"

GestorUsuarios::GestorUsuarios(){
	usuarios = new ListaDPI<Usuario *> ();
}

GestorUsuarios::GestorUsuarios(const GestorUsuarios & gestor){
	usuarios = new ListaDPI <Usuario *>();
	Usuario *u = nullptr;

	while (!usuarios->alFinal()){
		u = gestor.usuarios->consultar();
		Usuario *nu = new Usuario *(u);
		usuarios->insertar(u);
		usuarios->avanzar();
	}
	delete u;
	this->numero_usuarios = 0;
}

GestorUsuarios::~GestorUsuarios(){
	usuarios->moverPrimero();
	Usuario *u = nullptr;

	while(!usuarios->estaVacia()){
		u = usuarios->consultar();
		delete u;
		usuarios->eliminar();
	}
	delete usuarios;
}

int GestorUsuarios::numElementos() const{
	int n = 0;
	usuarios->moverPrimero();
	while(!usuarios->alFinal()){
		n++;
		usuarios->avanzar();
	}
	return n;
}

bool GestorUsuarios::buscar(string nombre, Usuario* &usuario) const{
	Usuario *u = nullptr;
	usuarios->moverPrimero();
	bool enc = false;
	bool mayor = false;

	while(!usuarios->alFinal() && !enc && !mayor){
		u = usuarios->consultar();
		if (u->getApellidosNombre == nombre){
			enc = true;
			usuario = u;
		}
		else {
			if(u->getApellidosNombre < nombre){
				mayor = true;
			}
			else usuarios->avanzar();
		}
	}
	delete u;
	return enc;
}

void GestorUsuarios::insertar(string id, string nombre, string email, string contraseña){
	Usuario *u = nullptr;
	usuarios->moverPrimero();
	bool igual = false;
	bool enc = false;

	while (!usuarios->alFinal() && !enc && !igual){
		u = usuarios->consultar();
		if (u->getApellidosNombre() == nombre){
			igual = true;
		}
		else {
			if (u->getApellidosNombre > nombre){
				enc = true;
			}
			else {
				usuarios->avanzar();
			}
		}
		if (!igual){
			Usuario *nuevo = new Usuario(id, nombre, email, contraseña);
			usuarios->insertar(nuevo);
		}
	}
	delete u;
}

void GestorUsuarios::mostrar() const{
	Usuario *u = nullptr;
	usuarios->moverPrimero();

	while(!usuarios->alFinal()){
		u = usuarios->consultar();
		u->mostrar();
	}
	delete u;
}



