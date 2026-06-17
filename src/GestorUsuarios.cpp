#include "GestorUsuarios.h"
#if defined LISTA_USUARIOS

GestorUsuarios::GestorUsuarios(){
	usuarios = new ListaDPI<Usuario *> ();
	numero_usuarios = 0;
}

GestorUsuarios::GestorUsuarios(const GestorUsuarios & gestor){
	usuarios = new ListaDPI <Usuario *>();
	Usuario *u = nullptr;
	
	//Primero hay que moverlo a la primera 
	//posición para poder copiarlo entero.
	gestor.usuarios->moverPrimero();

	//Lo pone al final para que se inserte así:
	//						<1> ,nullptr
	//				 <1>, <2> ,nullptr
	//		  <1>, <2>, <3> ,nullptr
	this->usuarios->moverUltimo();
	this->usuarios->avanzar();

	//Se itera sobre el GESTOR pq el nuestro puede estar al final
	while (!gestor.usuarios->alFinal()){
		u = gestor.usuarios->consultar();
		Usuario * nu = new Usuario(*u);
		usuarios->insertar(nu);
		usuarios->avanzar();

		gestor.usuarios->avanzar();
	}

	//Ni se te ocurra borrarlo que no es tuyo
	//delete u;
	this->numero_usuarios = gestor.numero_usuarios;
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
	//Tenemos una variable que los cuenta ya
	/*
	int n = 0;
	usuarios->moverPrimero();
	while(!usuarios->alFinal()){
		n++;
		usuarios->avanzar();
	}
	return n;
	*/
	return this->numero_usuarios;
}

bool GestorUsuarios::buscar(string nombre, Usuario* &usuario) const{
	Usuario *u = nullptr;
	bool enc = false;
	bool mayor = false;

	this->usuarios->moverPrimero();

	while(!this->usuarios->alFinal() && !enc && !mayor){
		u = usuarios->consultar();
		if (u->getApellidosNombre() == nombre){
			enc = true;
			usuario = u;
		} else {
			if(u->getApellidosNombre() > nombre){
				mayor = true;
			}
			else usuarios->avanzar();
		}
	}
	//NO BORRES NADA SI NO ES AUXILIAR A LO QUE HAYAS HECHO NEW
	//delete u;
	return enc;
}

void GestorUsuarios::insertar(string id, string nombre, string email, string contraseña, Fecha* fecha){
	Usuario *u = nullptr;
	bool igual = false;
	bool enc = false;

	usuarios->moverPrimero();

	while (!usuarios->alFinal() && !enc && !igual){
		u = usuarios->consultar();

		if (u->getApellidosNombre() == nombre){
			//Ya está. No se inserta
			igual = true;
		} else {
			//En la lista se apunta a '2' y nombre es '1'
			if (u->getApellidosNombre() > nombre){
				enc = true;
			}
			else {
				usuarios->avanzar();
			}
		}

	}
	if (!igual){
		Usuario *nuevo = new Usuario(id, nombre, email, contraseña, fecha);
		//nuevo->mostrar();
		usuarios->insertar(nuevo);
		this->numero_usuarios++;
	}

	//PERO QUE NO BORRES U QUE NO LE HAS HECHO NEW
	//delete u;
}

void GestorUsuarios::mostrar() const{
	Usuario *u = nullptr;

	this->usuarios->moverPrimero();

	while(!this->usuarios->alFinal()){
		u = this->usuarios->consultar();
		u->mostrar();
		this->usuarios->avanzar();
	}
}

#else

KeyValue<string, Usuario*> copiarKV(KeyValue<string, Usuario*> kv){
	return KeyValue<string, Usuario*>(kv.getKey(), new Usuario(*kv.getValue()));
}
void copiarArbol(BSTree<KeyValue<string, Usuario*>> *arbol, BSTree<KeyValue<string, Usuario*>> *arbol2){
	KeyValue<string, Usuario*> u;
	if(arbol != nullptr && !arbol->estaVacio()){
		arbol2->insertar(copiarKV(arbol->getDato()));
		copiarArbol(arbol->getIzq(), arbol2);
		copiarArbol(arbol->getDer(), arbol2);
	}
}

GestorUsuarios::GestorUsuarios(){
	this->numero_usuarios = 0;
	this->usuarios = new BSTree<KeyValue<string, Usuario*>>;
}

GestorUsuarios::GestorUsuarios(const GestorUsuarios &g){
	usuarios = new BSTree<KeyValue<string, Usuario*>>;
	this->numero_usuarios = g.numero_usuarios;
	copiarArbol(g.usuarios, this->usuarios);
}

GestorUsuarios::~GestorUsuarios(){
	destruirUsuarios(this->usuarios);
	delete this->usuarios;
}

void GestorUsuarios::destruirUsuarios(BSTree<KeyValue<string, Usuario*>> *arbol){
	if(arbol != nullptr && !arbol->estaVacio()){
		destruirUsuarios(arbol->getIzq());
		destruirUsuarios(arbol->getDer());
		//Destruimos solo el usuario
		delete arbol->getDato().getValue();
	}
}

int GestorUsuarios::numElementos() const{
	return this->numero_usuarios;
}

bool buscarAux(BSTree<KeyValue<string, Usuario*>> *arbol, string nombre, Usuario *&u){
	bool enc = false;
	string nom;
	KeyValue<string, Usuario*> kv;

	if(arbol != nullptr && !arbol->estaVacio()){
		kv = arbol->getDato();
		nom = kv.getKey();

		if(nom == nombre){
			u = kv.getValue();
			enc = true;
		}
		else 
			if(arbol->getDato().getKey() > nombre)
				enc = buscarAux(arbol->getIzq(), nombre, u);
			else
				enc = buscarAux(arbol->getDer(), nombre, u);
	}

	return enc;
}
bool GestorUsuarios::buscar(string nombre, Usuario *&a) const{
	bool enc = buscarAux(this->usuarios, nombre, a);
	return enc;
}

void GestorUsuarios::insertar(string id, string nombre, string email, string contraseña, Fecha* fecha){
	Usuario *u = nullptr;

	bool existe = buscar(nombre, u);

	if (!existe){
		Usuario *nuevo = new Usuario(id, nombre, email, contraseña, fecha);
		this->usuarios->insertar(KeyValue<string, Usuario*>(nombre, nuevo));
		this->numero_usuarios++;
	}
}

void mostrarAux(BSTree<KeyValue<string, Usuario*>>* arbol){
	if(arbol != nullptr && !arbol->estaVacio()){
		mostrarAux(arbol->getIzq());
		Usuario *u = arbol->getDato().getValue();
		u->mostrar();
		mostrarAux(arbol->getDer());
	}
}
void GestorUsuarios::mostrar() const{
	mostrarAux(this->usuarios);
}


#endif
