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
		 * DESC={
		 *		Busca un usario por su nombre
		 *	}
		 * POST={
		 *		Si se encuentra, se asigna el puntero al usuario y devuelve true. 
		 *		Si no, no se modifica y devuelve false.
		 *	}
		 * COMP={O(n). n = número de usuarios.}
		 */
		bool buscar(string nombre, Usuario* &usuario) const;
		
		/**
		 * PRE={
		 *		fecha debe estar correctamente inicializada. No puede ser nullptr.
		 *	}
		 * DESC={
		 *		Inserta un nuevo usuario en orden si no se repite el nombre.
		 *	}
		 *	POST={
		 *		Si el nombre no se repite se inserta el usuario.
		 *		La fecha se COPIA al usuario. Se puede eliminar después de la función.
		 *	}
		 * COMP={O(n). n = número de usuarios.}
		 */
		void insertar(string id, string nombre, string email, string contraseña, Fecha* fecha);
		
		/**
		 * DESC={Muestra todos los usuarios del gestor}
		 * COMP={O(n). n = número de usuarios.}
		 */
		void mostrar() const;

};

#else /* LISTA_USUARIOS */
#include "KeyValue.h"
#include "BSTree.h"

class GestorUsuarios{
	private:
		BSTree<KeyValue<string, Usuario*>>* usuarios;
		int numero_usuarios;
	
	public:
		GestorUsuarios();
		
		//Constructor por copia.
		//COMP={O(n). n = número de usuarios de g}
		GestorUsuarios(const GestorUsuarios & g);

		//Destructor.
		//COMP={O(n). n = número de usuarios}
		~GestorUsuarios();

		/**
		 * DESC={Devuelve el número de usuarios registrados}
		 * COMP={O(1)}
		 */
		int numElementos() const;

		/**
		 * DESC={
		 *		Busca un usuario por su nombre.
		 *	}
		 * POST={
		 *		Si se encuentra, se asigna el puntero al usuario y devuelve true. 
		 *		Si no, no se modifica y devuelve false.
		 *	}
		 * COMP={O(log(n)). n = número de usuarios.}
		 */
		bool buscar(string nombre, Usuario* &usuario) const;

		/**
		 * PRE={
		 *		fecha debe estar correctamente inicializada. No puede ser nullptr.
		 *	}
		 * DESC={
		 *		Inserta un nuevo usuario en orden si no se repite el nombre.
		 *	}
		 *	POST={
		 *		Si el nombre no se repite se inserta el usuario.
		 *		La fecha se COPIA al usuario. Se puede eliminar después de la función.
		 *	}
		 * COMP={O(log(n)). n = número de usuarios.}
		 */
		void insertar(string id, string nombre, string email, string contraseña, Fecha* fecha);
		
		/**
		 * DESC={Muestra todos los usuarios del gestor}
		 * COMP={O(n). n = número de usuarios.}
		 */
		void mostrar() const;


};

#endif /* LISTA_USUARIOS */
#endif /* GESTOR_USUARIOS_H_ */
