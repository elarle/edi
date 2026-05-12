#ifndef SISTEMA_H_
#define SISTEMA_H_

#include "GestorUsuarios.h"
#include "GestorArtistas.h"

class Sistema{
	private:
		GestorUsuarios* gestorUsuarios;
		GestorArtistas* gestorArtistas;

		/**
		 * Carga todos los usuarios del archivo indicado en el gestor.
		 */
		void cargarUsuarios(string archivo);
		void cargarArtistas(string archivo);
		void cargarPlayLists(string archivo);
		void cargarCanciones(string archivo);
	
	public:
		Sistema();
		Sistema(const Sistema& sistema);
		~Sistema();



		/*
		 * DESC={
		 *		Muestra los usuarios registrados por órden alfabético.
		 * }
		 */
		void mostrarUsuarios() const;

		/*
		 * DESC={
		 *		Devuelve un puntero a una copia del Usuario solicitado.
		 *		En caso de no existir dicho usuario se devuelve nullptr.
		 * }
		 *	POST={La memoria la gestiona quien llama a la función.}
		 */
		Usuario* buscarUsuario(string nombreApellidos) const;

		/**
		 * DESC={
		 *		Muestra todos los artistas del sistema junto con sus canciones.
		 * }
		 */
		void mostrarArtistas() const;

		/*
		 * DESC={
		 *		Devuelve un puntero a una copia del Artista solicitado.
		 *		En caso de no existir dicho artista se devuelve nullptr.
		 * }
		 *	POST={La memoria la gestiona quien llama a la función.}
		 */
		Artista* buscarArtista(string nombre) const;


		/*
		 * DESC={
		 *		Reproduce la playlist del usuario solicitado y devuelve true.
		 *		En caso de no existir el usuario la función devuelve false.
		 * }
		 */
		bool reproducirPlaylistUsuario(string usuario, string playlist);

		/**
		 * PRE={
		 *		usrc: Debe ser un usuario válido.
		 *		udst: Debe ser un usuario válido.
		 *		playlist: Debe ser una playlist válida del usuario usrc.
		 *	}
		 * DESC = {
		 *		Crea una copia de la playlist seleccionada del usuario src al usuario dest.
		 * }
		 */
		bool compartirPlaylist(string usrc, string udst, string playlist);

		/**
		 * PRE={
		 *		usuario: Debe ser un usuario válido.
		 *		playlist: Debe ser una playlist válida de usuario.
		 * }
		 * DESC={
		 *		Elimina la playlist indicada del usuario.Elimina la playlist indicada del usuario.
		 * }
		 */
		bool eliminarPlaylistUsuario(string usuario, string playlist);

		/*
		 * PRE={
		 *		usuario: Debe ser un usuario válido.
		 *		artista: Debe ser un artista válido.
		 * }
		 * DESC={
		 *		Añade a favoritos del usuario el artista indicado.
		 * }
		 */
		bool addFavorito(string usuario, string artista);

		/*
		 * PRE={
		 *		usuario: Debe ser un usuario válido.
		 *		artista: Debe ser un artista válido.
		 * }
		 * DESC={
		 *		 Elimina de favoritos del usuario el artista indicado.
		 * }
		 */
		bool borrarFavorito(string usuario, string artista);

		/**
		 * PRE={
		 *			
		 * }
		 * DESC={
		 *
		 * }
		 **/
		Artista* buscarMayorArtista() const;

};

#endif /* SISTEMA_H_ */
