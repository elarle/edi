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

GestorArtistas::GestorArtistas(){
	this->artistas = new BSTree<Artista*>;
	this->numero_artistas = 0;
}

GestorArtistas::GestorArtistas(const GestorArtistas &g){
	numero_artistas = g.numero_artistas;
	copiarArbol(g.artistas, this->artistas);
}

void GestorArtistas::copiarArbol(BSTree<Artista*> *arbol, BSTree<Artista*> *arbol2){
	Artista *a = nullptr;
	if(arbol != nullptr && !arbol->estaVacio()){
		copiarArbol(arbol->getIzq(), arbol2);
		a = arbol->getDato();
		arbol2->insertar(new Artista(*a));
		copiarArbol(arbol->getDer(), arbol2);
	}
}

GestorArtistas::~GestorArtistas(){
	destruirArtistas(this->artistas);
}

void GestorArtistas::destruirArtistas(BSTree<Artista*> *arbol){
    if(arbol != nullptr && !arbol->estaVacio()){
        destruirArtistas(arbol->getIzq());
        delete arbol->getDato();
        destruirArtistas(arbol->getDer());
    }
}

int GestorArtistas::numElementos() const{
	return this->numero_artistas;
}

bool GestorArtistas::buscar(BSTree<Artista*> *arbol, string nombre, Artista* &a) const{
    bool enc = false;

    if(arbol != nullptr && !arbol->estaVacio()){
        enc = buscar(arbol->getIzq(), nombre, a);

        if(!enc){
            Artista *aux = arbol->getDato();
            if(aux->getNombre() == nombre){
                a = aux;
                enc = true;
            }
        }

        if(!enc){
            enc = buscar(arbol->getDer(), nombre, a);
        }
    }
    return enc;
}

void GestorArtistas::insertar(string nombre, string country, int seguidores){
	Artista *a = nullptr;

	bool existe = buscar(this->artistas, nombre, a);

	if (!existe){
		Artista *nuevo = new Artista(nombre, country, seguidores);
		this->artistas->insertar(nuevo);
		this->numero_artistas++;
	}
}

void GestorArtistas::mostrar() const{
	mostrarAux(this->artistas);
}

void GestorArtistas::mostrarAux(BSTree<Artista*> *arbol) const{
	if(arbol != nullptr && !arbol->estaVacio()){
		mostrarAux(arbol->getIzq());
		Artista *a = arbol->getDato();
		a->mostrar();
		mostrarAux(arbol->getDer());
	}
}

#endif /* LISTA_ARTISTAS */
