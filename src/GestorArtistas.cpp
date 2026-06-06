#include "GestorArtistas.h"

#if defined LISTA_ARTISTAS

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
#else

#include "Cola.h"
KeyValue<string, Artista*> copiarKV(KeyValue<string, Artista*> kv){
	return KeyValue<string, Artista*>(kv.getKey(), new Artista(*kv.getValue()));
}

void copiarArbol(BSTree<KeyValue<string, Artista*>> *arbol, BSTree<KeyValue<string, Artista*>> *arbol2){
	KeyValue <string, Artista*> a;
	if(arbol != nullptr && !arbol->estaVacio()){
		arbol2->insertar(copiarKV(arbol->getDato()));
		copiarArbol(arbol->getIzq(), arbol2);
		copiarArbol(arbol->getDer(), arbol2);
	}
}

GestorArtistas::GestorArtistas(){
	this->artistas = new BSTree<KeyValue<string, Artista*>>;
	this->numero_artistas = 0;
}

GestorArtistas::GestorArtistas(const GestorArtistas &g){
	artistas = new BSTree<KeyValue<string, Artista*>>;
	numero_artistas = g.numero_artistas;
	copiarArbol(g.artistas, this->artistas);
}

GestorArtistas::~GestorArtistas(){
	destruirArtistas(this->artistas);
}

void GestorArtistas::destruirArtistas(BSTree<KeyValue<string, Artista*>> *arbol){
    if(arbol != nullptr && !arbol->estaVacio()){
        destruirArtistas(arbol->getIzq());
        destruirArtistas(arbol->getDer());
        delete arbol->getDato().getValue();
    }
}

int GestorArtistas::numElementos() const{
	return this->numero_artistas;
}

bool GestorArtistas::buscar(string nombre, Artista *&a) const{
	bool enc = buscarAux(this->artistas, nombre, a);
	return enc;
}

bool GestorArtistas::buscarAux(BSTree<KeyValue<string, Artista*>> *arbol, string nombre, Artista* &a) const{
    bool enc = false;

    if(arbol != nullptr && !arbol->estaVacio()){
    	Artista *aux = arbol->getDato().getValue();

		if(aux->getNombre() == nombre){
			a = aux;
			enc = true;
		}
		if(!enc)
			enc = buscarAux(arbol->getIzq(), nombre, a);

        if(!enc)
            enc = buscarAux(arbol->getDer(), nombre, a);
    }
    return enc;
}

void GestorArtistas::insertar(string nombre, string country, int seguidores){
	Artista *a = nullptr;

	bool existe = buscar(nombre, a);

	if (!existe){
		Artista *nuevo = new Artista(nombre, country, seguidores);
		this->artistas->insertar(KeyValue <string, Artista*> (nombre, nuevo));
		this->numero_artistas++;
	}
}

void GestorArtistas::mostrarAux(BSTree<KeyValue<string, Artista*>> *arbol) const{
	if(arbol != nullptr && !arbol->estaVacio()){
		mostrarAux(arbol->getIzq());
		Artista *a = arbol->getDato().getValue();
		a->mostrar();
		mostrarAux(arbol->getDer());
	}
}
void GestorArtistas::mostrar() const{
	mostrarAux(this->artistas);
}

//No puede ser recursivo por que peta
Artista* GestorArtistas::mayorSeguidoresAux(BSTree<KeyValue<string, Artista*>>* arbol) const{
	Cola<BSTree<KeyValue<string, Artista*>>*>* pendientes = new Cola<BSTree<KeyValue<string, Artista*>>*>();
	BSTree<KeyValue<string, Artista*>>* aux = nullptr;

	Artista* mayor = nullptr;

	if(!arbol->estaVacio()){

		mayor = arbol->getDato().getValue();
		pendientes->encolar(arbol->getIzq());
		pendientes->encolar(arbol->getDer());

		while(!pendientes->estaVacia()){
			aux = pendientes->getPrimero();
			pendientes->desencolar();

			if(!aux->estaVacio()){
				if(aux->getDato().getValue()->getSeguidores() > mayor->getSeguidores())
					mayor = aux->getDato().getValue();

				if(!aux->getIzq()->estaVacio())
					pendientes->encolar(aux->getIzq());

				if(!aux->getDer()->estaVacio())
					pendientes->encolar(aux->getDer());

			}
		}
	}

	delete pendientes;
	return mayor;
}

Artista* GestorArtistas::mayorSeguidores() const{
	return mayorSeguidoresAux(this->artistas);
}

#endif /* LISTA_ARTISTAS */
