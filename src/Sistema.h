#ifndef SISTEMA_H_
#define SISTEMA_H_

#include "GestorUsuarios.h"
#include "GestorArtistas.h"

class Sistema{
	private:
		GestorUsuarios* gestorUsuarios;
		GestorArtistas* gestorArtistas;

		/**
		 * DESC={Carga todos los usuarios del archivo indicado en el gestor}
		 * COMP={O(n)}
		 */
		void cargarUsuarios(string archivo);
		/**
		 * DESC={Carga todos los artistas del archivo indicado en el gestor}
		 * COMP={O(n)}
		 */
		void cargarArtistas(string archivo);
		/**
		 * DESC={Carga las playlists y sus canciones del archivo .csv}
		 * COMP={O(n)}
		 */
		void cargarPlayLists(string archivo);
		/**
		 * DESC={Carga las canciones de cada artista del archivo .csv}
		 * COMP={O(n)}
		 */
		void cargarCanciones(string archivo);
	
	public:
		Sistema();
		Sistema(const Sistema& sistema);
		~Sistema();



		/*
		 * DESC={
		 *		Muestra los usuarios registrados por orden alfabético.
		 * }
		 * COMP={O(n)}
		 */
		void mostrarUsuarios() const;

		/*
		 * DESC={
		 *		Devuelve un puntero al Usuario.
		 *		En caso de no existir dicho usuario se devuelve nullptr.
		 * }
		 * COMP={O(n)}
		 */
		Usuario* buscarUsuario(string nombreApellidos) const;

		/**
		 * DESC={
		 *		Muestra todos los artistas del sistema junto con sus canciones.
		 * }
		 * COMP={O(n)}
		 */
		void mostrarArtistas() const;

		/*
		 * DESC={
		 *		Devuelve un puntero al Artista.
		 *		En caso de no existir dicho artista se devuelve nullptr.
		 * }
		 * COMP={O(n)}
		 */
		Artista* buscarArtista(string nombre) const;


		/*
		 * DESC={
		 *		Reproduce la playlist del usuario solicitado y devuelve true.
		 *		En caso de no existir el usuario la función devuelve false.
		 * }
		 * COMP={O(n)}
		 */
		bool reproducirPlaylistUsuario(string usuario, string playlist);

		/**
		 * DESC={
		 *		Crea una copia de la playlist seleccionada del usuario src al usuario dest.
		 *		Devuelve true si se completa correctamente, false si algún parámetro no es válido.
		 * }
		 * COMP={O(n)}
		 */
		bool compartirPlaylist(string usrc, string udst, string playlist);

		/**
		 * DESC={
		 *		Elimina la playlist indicada del usuario.
		 *		Devuelve true si se elimina correctamente, false si el usuario o la playlist no existen.
		 * }
		 * COMP={O(n)}
		 */
		bool eliminarPlaylistUsuario(string usuario, string playlist);

		/*
		 * DESC={
		 *		Añade a favoritos del usuario el artista indicado.
		 *		Devuelve true si se completa correctamente, false si el usuario o el artista no existen.
		 * }
		 * COMP={O(n)}
		 */
		bool addFavorito(string usuario, string artista);

		/*
		 * DESC={
		 *		Elimina de favoritos del usuario el artista indicado.
		 *		Devuelve true si se completa correctamente, false si el usuario o el artista no existen.
		 * }
		 * COMP={O(n)}
		 */
		bool borrarFavorito(string usuario, string artista);

		/**
		 * DESC={
		 *		Devuelve el artista con mayor número de seguidores.
		 *		Si no hay artistas devuelve nullptr.
		 * }
		 * COMP={O(n)}
		 **/
		Artista* buscarMayorArtista() const;

};

#endif /* SISTEMA_H_ */
