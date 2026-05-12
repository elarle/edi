/*
 * Usuario.h
 *
 *  Created on: 9 feb 2026
 *      Author: usuario
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include <iostream>
using namespace std;

#include "Fecha.h"
#include "PlayList.h"
#include "Artista.h"
#include "ListaDPI.h"
#include "Cancion.h"

class Usuario {
private:
	string idUsuario;
	string apellidosNombre;
	string email;
	string contraseña;

	Fecha* fecha_nacimiento;

	ListaDPI<PlayList*>* playlists;
	ListaDPI<Artista*>* artistas_favoritos;

public:
	Usuario();
	Usuario(string id, string nombre, string email, string contraseña, Fecha* fecha);
	Usuario(const Usuario & otro_usuario);
	~Usuario();

	//Setters
	//Todos los setters tienen complejidad O(1).
	void setApellidosNombre(string apellidos_nombre);
	void setIdUsuario(string id);
	void setEmail(string email);
	void setContraseña(string contraseña);

	//TODO: implementar pruebas de esto
	void setFecha(const Fecha & fecha);

	//Getters
	//Todos los getters tienen complejidad O(1).
	string getApellidosNombre() const;
	string getIdUsuario() const;
	string getEmail() const;
	string getContraseña() const;

	void getFecha(Fecha & fecha) const;
	void getFecha(int &dia, int &mes, int &año) const;

	//Métodos
	
	/**
	 * DESC={Crea una playlist del usuario si no existe una con ese nombre}
	 * COMP={O(n)}
	 */
	void crearPlayList(string nombre);

	/**
	 * PRE={cancion debe ser un puntero válido (no nullptr)}
	 * DESC={Si la playlist existe se le añade la canción}
	 * COMP={O(n)}
	 */
	void addCancionPlaylist(string nombre_playlist, Cancion * cancion);

	/**
	 * DESC={Muestra las canciones de la playlist}
	 * COMP={O(n)}
	 */
	void reproducirPlayList(string nombre) const;
	/**
	 * PRE={La playlist debe ser un nullptr / no estar reservada}
	 * DESC={Crea una copia de la lista de este usuario en playlist. La memoria es responsabilidad del usuario}
	 * COMP={O(n)}
	 */
	void compartirPlaylist(string nombre, PlayList* &playlist) const;

	/**
	 * DESC={Elimina una playlist del usuario si existe}
	 * COMP={O(n)}
	 */
	bool eliminarPlayList(string nombre);

	/**
	 * PRE={playlist debe ser un puntero válido (no nullptr)}
	 * DESC={Añade a las listas de usuario una copia de la playlist}
	 * COMP={O(n)}
	 */
	void addPlaylistCompartida(const PlayList* playlist);

	/**
	 * PRE={artista debe ser un puntero válido (no nullptr)}
	 * DESC={Inserta un artista favorito en el usuario si NO está ya en favoritos}
	 * COMP={O(n)}
	 */
	void addArtistaFavorito(Artista* artista);

	/**
	 * DESC={Elimina un artista favorito del usuario si existe}
	 * COMP={O(n)}
	 */
	void borrarArtistaFavorito(string nombre);

	/**
	 * DESC={Busca un artista favorito por nombre}
	 * POST={Si no se encuentra el artista, no se modifica el puntero}
	 * COMP={O(n)}
	 */
	bool buscarArtistaFavorito(string nombre, Artista *&artista) const;

	/**
	 * DESC={Busca una playlist por nombre}
	 * POST={Si no se encuentra la playlist, no se modifica el puntero}
	 * COMP={O(n)}
	 */
	bool buscarPlaylist (string nombre, PlayList *&p) const;

	/**
	 * DESC={Muestra a cout el usuario}
	 * COMP={O(1)}
	 */
	void mostrar() const;
	/**
	 * DESC={Pasa el usuario a cadena.}
	 * COMP={O(1)}
	 */
	string pasarACadena() const;

};

#endif /* USUARIO_H_ */
