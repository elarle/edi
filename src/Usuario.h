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
	Usuario(string id, string nombre, string email, string contraseña);
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
	 */
	void crearPlayList(string nombre);

	/**
	 * DESC={Si la playlist existe se le añade la canción}
	 */
	void addCancionPlaylist(string nombre_playlist, Cancion * cancion);

	/**
	 * DESC={Muestra las canciones de la playlist}
	 */
	void reproducirPlayList(string nombre) const;
	/**
	 * PRE={La playlist debe ser un nullptr / no estar reservada}
	 * DESC={Crea una copia de la lista de este usuario en playlist. La memoria es responsabilidad del usuario}
	 */
	void compartirPlaylist(PlayList* &playlist) const;

	/**
	 * DESC={Añade a las listas de usuario una copia de la playlist COPIADA.}
	 */
	void addPlaylistCompartida(const PlayList* &playlist);

	/**
	 * DESC={Inserta un artista favorito en el usuario si NO está ya en favoritos}
	 */
	void addArtistaFavorito(const Artista* artista);

	/**
	 * DESC={Muestra a cout el usuario}
	 * COMP={O(?)}
	 */
	void mostrar() const;
	/**
	 * DESC={Pasa el usuario a cadena.}
	 * COMP={O(?)}
	 */
	string pasarACadena() const;

};

#endif /* USUARIO_H_ */
