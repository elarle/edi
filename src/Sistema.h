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
		 * COMP={O(n). n = número de usuarios}
		 */
		void cargarUsuarios(string archivo);
		/**
		 * DESC={Carga todos los artistas del archivo indicado en el gestor}
		 * COMP={O(n). n = númeor de artistas}
		 */
		void cargarArtistas(string archivo);	

		/**
		 * DESC={Carga las canciones de cada artista del archivo .csv}
		 * COMP={
		 *		Listas: O(c*a). c = número de canciones, a = número de artistas
		 *		Ártboles: O(c*log(a)). c = número de canciones, a = número de artistas
		 *	}
		 */
		void cargarCanciones(string archivo);

		/**
		 * DESC={Carga las playlists y sus canciones del archivo .csv}
		 * COMP={
		 *		Listas: O(u*(a*ca+p*cp)).
		 *		Árboles: O(log(u)*(log(a)*ca+p*cp)).
		 *		
		 *		Parámetros:
		 *		- u = número de usuarios. 
		 *		- a = número de artistas. 
		 *		- c = número de canciones. 
		 *		- ca = número de canciones del artista.
		 *		- p = número de playlists del usuario. 
		 *		- cp = canciones por playlist del usuario
		 *	}
		 */
		void cargarPlayLists(string archivo);
	
	public:

		/**
		 * DESC={Constructor default. Carga toda la info necesaria.}
		 * COMP={
		 *		Listas: O(u*(a*ca+p*cp)).
		 *		Árboles: O(log(u)*(log(a)*ca+p*cp)).
		 *		
		 *		Parámetros:
		 *		- u = número de usuarios. 
		 *		- a = número de artistas. 
		 *		- c = número de canciones. 
		 *		- ca = número de canciones del artista.
		 *		- p = número de playlists del usuario. 
		 *		- cp = canciones por playlist del usuario
		 *	}
		 */
		Sistema();
		
		/**
		 * DESC={Constructor default. Copia toda la info necesaria.}
		 * COMP={
		 *		Listas: O(u*(a*ca+p*cp)).
		 *		Árboles: O(u*(a*ca+p*cp)).
		 *		
		 *		Parámetros:
		 *		- u = número de usuarios. 
		 *		- a = número de artistas. 
		 *		- c = número de canciones. 
		 *		- ca = número de canciones del artista.
		 *		- p = número de playlists del usuario. 
		 *		- cp = canciones por playlist del usuario
		 *	}
		 */
		Sistema(const Sistema& sistema);

		//Destructor
		//COMP={O(u*p*c). u = número de usuarios, p = playlists de usuarios, c = canciones de playlists}
		~Sistema();

		/*
		 * DESC={
		 *		Muestra los usuarios registrados por orden alfabético.
		 * }
		 * COMP={O(u*n). u = número de usuarios. n = número de playlists y favoritos de usuarios.}
		 */
		void mostrarUsuarios() const;

		/*
		 * DESC={
		 *		Devuelve un puntero al Usuario.
		 *		En caso de no existir dicho usuario se devuelve nullptr.
		 * }
		 * COMP={
		 *		Listas: O(n). n = número de usuarios
		 *		Árboles: O(log(n)). n = número de usuarios.
		 *	}
		 */
		Usuario* buscarUsuario(string nombreApellidos) const;

		/**
		 * DESC={
		 *		Muestra todos los artistas del sistema junto con sus canciones.
		 * }
		 * COMP={O(a*n). a = número de artistas. n = número de canciones de artistas.}
		 */
		void mostrarArtistas() const;

		/*
		 * DESC={
		 *		Devuelve un puntero al Artista.
		 *		En caso de no existir dicho artista se devuelve nullptr.
		 * }
		 * COMP={
		 *		Listas: O(n). n = número de artistas
		 *		Árboles: O(log(n)). n = número de artistas.
		 *	}
		 */
		Artista* buscarArtista(string nombre) const;


		/*
		 * DESC={
		 *		Reproduce la playlist del usuario solicitado y devuelve true.
		 *		En caso de no existir el usuario la función devuelve false.
		 * }
		 * COMP={
		 *		Listas: O(u+p+c). u = número de usuarios, p = playlists por usuario, c = número de canciones de playlist
		 *		Árboles: O(log(u)+p+c). u = número de usuarios, p = playlists por usuario, c = número de canciones de playlist
		 *	}
		 */
		bool reproducirPlaylistUsuario(string usuario, string playlist);

		/**
		 * DESC={
		 *		Crea una copia de la playlist seleccionada del usuario src al usuario dest.
		 *		Devuelve true si se completa correctamente, false si algún parámetro no es válido.
		 * }
		 * COMP={
		 *		Listas: O(u+p+c). u = número de usuarios, p = playlists por usuario, c = número de canciones de playlist
		 *		Árboles: O(log(u)+p+c). u = número de usuarios, p = playlists por usuario, c = número de canciones de playlist
		 *	} 
		 */
		bool compartirPlaylist(string usrc, string udst, string playlist);

		/**
		 * DESC={
		 *		Elimina la playlist indicada del usuario.
		 *		Devuelve true si se elimina correctamente, false si el usuario o la playlist no existen.
		 * }
		 * COMP={
		 *		Listas: O(u+p+c). u = número de usuarios, p = playlists por usuario, c = número de canciones de playlist
		 *		Árboles: O(log(u)+p+c). u = número de usuarios, p = playlists por usuario, c = número de canciones de playlist
		 *	} 
		 */
		bool eliminarPlaylistUsuario(string usuario, string playlist);

		/*
		 * DESC={
		 *		Añade a favoritos del usuario el artista indicado.
		 *		Devuelve true si se completa correctamente, false si el usuario o el artista no existen.
		 * }
		 * COMP={
		 *		Listas: O(u+a+f). u = número de usuarios, a = número de artistas, f = número de favoritos.
		 *		Árboles: O(log(u)+log(a)+f). u = número de usuarios, a = número de artistas, f = número de favoritos.
		 *	} 
		 */
		bool addFavorito(string usuario, string artista);

		/*
		 * DESC={
		 *		Elimina de favoritos del usuario el artista indicado.
		 *		Devuelve true si se completa correctamente, false si el usuario o el artista no existen.
		 * }
		 * COMP={
		 *		Listas: O(u+a+f). u = número de usuarios, a = número de artistas, f = número de favoritos.
		 *		Árboles: O(log(u)+log(a)+f). u = número de usuarios, a = número de artistas, f = número de favoritos.
		 * }
		 */
		bool borrarFavorito(string usuario, string artista);

		/**
		 * DESC={
		 *		Devuelve el artista con mayor número de seguidores.
		 *		Si no hay artistas devuelve nullptr.
		 * }
		 * COMP={O(n). n = número de artistas}
		 **/
		Artista* buscarMayorArtista() const;

};

#endif /* SISTEMA_H_ */
