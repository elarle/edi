#ifndef GESTOR_USUARIOS_H_
#define GESTOR_USUARIOS_H_

#include "Usuario.h"

//#define LISTA_USUARIOS

#if defined LISTA_USUARIOS
#include "ListaDPI.h"

class GestorUsuarios{
	private:
		ListaDPI<Usuario*>* usuarios;
		int numero_usuarios;
		
	public:
		GestorUsuarios();
		GestorUsuarios(const GestorUsuarios & g);
		~GestorUsuarios();

		/**
		 * DESC={Devuelve el número de usuarios registrados}
		 * COMP={O(1)}
		 */
		int numElementos() const;
		/**
		 * DESC={Devuelve true si hay algún usuario cuyo nombre coincida}
		 * COMP={O(n)}
		 */
		bool buscar(string nombre, Usuario* &usuario) const;
		
		/**
		 * TODO: Comprobar que siga el orden el test
		 * DESC={Inserta un nuevo usuario en órden si no se repite ni el id, nombre ni email}
		 * COMP={O(n)}
		 */
		void insertar(string id, string nombre, string email, string contraseña, Fecha* fecha);
		
		void mostrar() const;

};

#else /* LISTA_USUARIOS */
#include "BSTree.h"

class GestorUsuarios{
	private:
		BSTree<Usuario*>* usuarios;
		int numero_usuarios;
		
	public:
		GestorUsuarios();
		GestorUsuarios(const GestorUsuarios & g);
		~GestorUsuarios();

		void copiarArbol(BSTree<Usuario*> *a1, BSTree<Usuario*> *a2);

		void destruirUsuarios(BSTree<Usuario*> *a);

		/**
		 * DESC={Devuelve el número de usuarios registrados}
		 * COMP={O(1)}
		 */
		int numElementos() const;
		/**
		 * DESC={Devuelve true si hay algún usuario cuyo nombre coincida}
		 * COMP={O(log(n))}
		 */
		bool buscar(string nombre, Usuario* &usuario) const;
		
		bool buscarAux(BSTree<Usuario*> *a, string nombre, Usuario* &usuario) const;

		/**
		 * TODO: Comprobar que siga el orden el test
		 * DESC={Inserta un nuevo usuario en órden si no se repite ni el id, nombre ni email}
		 * COMP={O(log(n))}
		 */
		void insertar(string id, string nombre, string email, string contraseña, Fecha* fecha);
		
		void mostrar() const;

		void mostrarAux(BSTree<Usuario*> *a) const;

};

#endif /* LISTA_USUARIOS */

#endif /* GESTOR_USUARIOS_H_ */
