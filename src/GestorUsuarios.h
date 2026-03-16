#ifndef GESTOR_USUARIOS_H_
#define GESTOR_USUARIOS_H_

#include "ListaDPI.h"
#include "Usuario.h"

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
		 * DESC={Inserta un nuevo usuario si no se repite ni el id, nombre ni email}
		 * COMP={O(1)}
		 */
		void insertar(string id, string nombre, string email, string contraseña);
		
		void mostrar() const;

};

#endif /* GESTOR_USUARIOS_H_ */
