//============================================================================
// Name        : Pila.h
// Author      : Profesores de EDI
// Version     : 1.0
// Description : Template Pila (implementación basada en punteros)
//============================================================================

#ifndef PILA_H_
#define PILA_H_

#include <iostream>
using namespace std;

template <class TipoDato> class Pila {

private:
	/**
	* Clase genérica Nodo (sólo accesible para el template Pila).
	* Modela los nodos que se almacenan en la Pila.
	* Cada Nodo contiene un dato de tipo TipoDato y un puntero al siguiente nodo.
	*/
	class Nodo {
	public:
		TipoDato  dato;
		Nodo     *sig;
		Nodo (const TipoDato &dato) {
			this->dato = dato;
			this->sig= nullptr;
		}

	};

	typedef Nodo *PtrNodo;
	PtrNodo cima;

public:
	// PRE: ---
	// DES: Constructor por defecto. Crea una pila vacía
	// COM: O(1)
	Pila ( );

	// PRE: this->estaVacia () = false
	// DES: Devuelve el elemento en la cima de la pila.
	// COM: O(1)
	TipoDato getCima ( ) const;

	// PRE: this->estaVacia () = false
	// DES: Devuelve en d el elemento en la cima de la pila.
	// COM: O(1)
	void getCima ( TipoDato &d ) const;

	// PRE: ---
	// DES: Devuelve true si la pila está vacía; false en caso contrario.
	// COM: O(1)
	bool estaVacia ( ) const;

	// PRE: ---
	// DES: Inserta el elemento d en la cima de la pila
	// COM: O(1)
	void apilar	( const TipoDato &d );

	// PRE: ---
	// DES: Elimina el elemento en la cima de la pila.
	//		Si la pila está vacía no hace nada.
	// COM: O(1)
	void desapilar ( );

	// PRE: ---
	// DES: Destructor. Vacía la pila desapilando todos los elementos.
	// COM: O(1)
	~Pila ( );
};

template <class TipoDato>
Pila<TipoDato>::Pila ( ) {
	cima = nullptr;
}

template <class TipoDato>
TipoDato Pila<TipoDato>::getCima ( ) const {
	return cima->dato;
}

template <class TipoDato>
void Pila<TipoDato>::getCima ( TipoDato &d ) const {
	d = cima->dato;
}

template <class TipoDato>
bool Pila<TipoDato>::estaVacia ( ) const {
	return cima == nullptr;
}

template <class TipoDato>
void Pila<TipoDato>::apilar ( const TipoDato &d ) {
	PtrNodo p = new Nodo ( d );
	p->sig = cima;
	cima = p;
}

template <class TipoDato>
void Pila<TipoDato>::desapilar ( ) {
	PtrNodo p;
	if ( ! estaVacia ( ) ) {
		p = cima;
		cima = cima->sig;
		delete p;
	}
}


template <class TipoDato>
Pila<TipoDato>::~Pila ( ) {
	while ( !estaVacia() ) {
		desapilar ( );
	}
}

#endif /* PILA_H_ */
