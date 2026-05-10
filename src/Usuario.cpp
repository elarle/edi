/*
 * Usuario.cpp
 *
 *  Created on: 9 feb 2026
 *      Author: usuario
 */

#include "Usuario.h"

//Constructores
Usuario::Usuario() {
	// TODO Auto-generated constructor stub
	this->idUsuario = "";
	this->apellidosNombre = "";
	this->contraseña = "";
	this->email = "";

	this->fecha_nacimiento = new Fecha();
	this->artistas_favoritos = new ListaDPI<Artista*>();
	this->playlists = new ListaDPI<PlayList*>();
}

Usuario::Usuario(string id, string nombre, string email, string contraseña, Fecha* fecha) {
	this->idUsuario = id;
	this->apellidosNombre = nombre;
	this->email = email;
	this->contraseña = contraseña;

	this->fecha_nacimiento = new Fecha(*fecha);
	this->artistas_favoritos = new ListaDPI<Artista*>();
	this->playlists = new ListaDPI<PlayList*>();
}

Usuario::Usuario(const Usuario & otro_usuario){
	this->idUsuario = otro_usuario.idUsuario;
	this->apellidosNombre = otro_usuario.apellidosNombre;
	this->email = otro_usuario.email;
	this->contraseña = otro_usuario.contraseña;

	this->fecha_nacimiento = new Fecha(*otro_usuario.fecha_nacimiento);

	//NO SE PUEDE COPIAR ASÍ. Hay que hacerlas independientes.
	//this->artistas_favoritos = new ListaDPI<Artista*>(*otro_usuario.artistas_favoritos);
	//this->playlists = new ListaDPI<PlayList*>(*otro_usuario.playlists);
	
	this->artistas_favoritos = new ListaDPI<Artista*>;
	otro_usuario.artistas_favoritos->moverPrimero();
	while(!otro_usuario.artistas_favoritos->alFinal()){
		artistas_favoritos->insertar(
			new Artista(*otro_usuario.artistas_favoritos->consultar())
		);
		otro_usuario.artistas_favoritos->avanzar();
	}

	this->playlists = new ListaDPI<PlayList*>;
	otro_usuario.playlists->moverPrimero();
	while(!otro_usuario.playlists->alFinal()){
		playlists->insertar(
			new PlayList(*otro_usuario.playlists->consultar())
		);
		otro_usuario.playlists->avanzar();
	}
}

Usuario::~Usuario() {
	delete this->fecha_nacimiento;

	this->playlists->moverPrimero();
	while(!this->playlists->estaVacia()){
		this->playlists->eliminar();
		this->playlists->avanzar();
	}
	delete this->playlists;
}

//Setters
void Usuario::setApellidosNombre(string apellidos_nombre) {
	this->apellidosNombre = apellidos_nombre;
}

void Usuario::setIdUsuario(string id) {
	this->idUsuario = id;
}

void Usuario::setEmail(string email) {
	this->email = email;
}

void Usuario::setContraseña(string contraseña) {
	this->contraseña = contraseña;
}

void Usuario::setFecha(const Fecha & fecha) {
	this->fecha_nacimiento->asignarFecha(
		fecha.getDia(), 
		fecha.getMes(), 
		fecha.getAño()
	);
}

//Getters
string Usuario::getApellidosNombre() const {
	return this->apellidosNombre;
}

string Usuario::getIdUsuario() const {
	return this->idUsuario;
}

string Usuario::getEmail() const {
	return this->email;
}

string Usuario::getContraseña() const {
	return this->contraseña;
}

void Usuario::getFecha(Fecha & fecha) const{
	fecha.setDia(this->fecha_nacimiento->getDia());
	fecha.setMes(this->fecha_nacimiento->getMes());
	fecha.setAño(this->fecha_nacimiento->getAño());
}
void Usuario::getFecha(int &dia, int &mes, int &año) const{
	dia = (this->fecha_nacimiento->getDia());
	mes = (this->fecha_nacimiento->getMes());
	año = (this->fecha_nacimiento->getAño());
}

//Métodos
void Usuario::mostrar() const {
	cout << "Usuario{" << endl;
	cout << "\tid: " << this->idUsuario << endl;
	cout << "\tnombre: " << this->apellidosNombre << endl;
	cout << "\tfecha: " << this->fecha_nacimiento->pasarACadena() << endl;
	cout << "}" << endl;
}

string Usuario::pasarACadena() const {
	return this->idUsuario + " " + this->apellidosNombre;
}

//NO SE MODIFICA EL PUNTERO SI NO SE ENCUENTRA
bool Usuario::buscarPlaylist (string nombre, PlayList *&p ) const{
	this->playlists->moverPrimero();
	bool enc = false;
	PlayList* aux;

	while(!this->playlists->alFinal() && !enc){
		aux = this->playlists->consultar();

		if (aux->getNombre() == nombre)
			enc = true;
		else
			this->playlists->avanzar();
	}
	if(enc)
		p = aux;

	return enc;
}

void Usuario::crearPlayList(string nombre){
	PlayList *p;
	if (!buscarPlaylist(nombre, p)){
	    p = new PlayList (nombre);
		this->playlists->alFinal();
		this->playlists->avanzar();
		this->playlists->insertar(p);
	}
}

void Usuario::addCancionPlaylist(string nombre_playlist, Cancion* cancion){
	PlayList *p;
	if(buscarPlaylist(nombre_playlist, p)){
		p->agregarCancion(cancion);
	}
}

void Usuario::reproducirPlayList(string nombre) const{
	PlayList *p;
	this->playlists->moverPrimero();
	while(!this->playlists->alFinal()){
		p = this->playlists->consultar();
		p->reproducir();
		this->playlists->avanzar();
	}
}

void Usuario::compartirPlaylist(string nombre, PlayList* &playlist) const{
	PlayList *pl;
	if(buscarPlaylist(nombre, pl)){
		playlist = new PlayList (*pl);
	}
}

void Usuario::addPlaylistCompartida(const PlayList* &p){
	PlayList* aux;

	if (!buscarPlaylist(p->getNombre(), aux)){
		this->playlists->moverUltimo();
		this->playlists->avanzar();
		this->playlists->insertar(new PlayList (*p));
	}
}

void Usuario::eliminarPlayList(string nombre){
	PlayList *p;
	bool enc = false;

	this->playlists->moverPrimero();
	while(!this->playlists->alFinal() && !enc){
		p = this->playlists->consultar();
		if(p->getNombre() == nombre){
			delete p;
			this->playlists->eliminar();
			enc = true;
		}
		else
			this->playlists->avanzar();
	}
}

bool Usuario::buscarArtistaFavorito(string nombre, Artista *&artista) const{
	Artista *a;
	bool enc = false;

	artista = nullptr;
	this->artistas_favoritos->moverPrimero();

	while(!this->artistas_favoritos->alFinal() && !enc){
		a = this->artistas_favoritos->consultar();
		if(a->getNombre() == nombre){
			enc = true;
			artista = a;
		}
		else
			this->artistas_favoritos->avanzar();
	}

	return enc;
}

void Usuario::addArtistaFavorito(const Artista* artista){
	Artista *a;

	if(artista != nullptr && !buscarArtistaFavorito(artista->getNombre(), a)){
		this->artistas_favoritos->moverUltimo();
		this->artistas_favoritos->avanzar();
		this->artistas_favoritos->insertar(new Artista(*artista));
	}
}

void Usuario::borrarArtistaFavorito(string nombre){
	Artista *a;
	bool enc = false;

	this->artistas_favoritos->moverPrimero();
	while(!this->artistas_favoritos->alFinal() && !enc){
		a = this->artistas_favoritos->consultar();
		if(a->getNombre() == nombre){
			delete a;
			this->artistas_favoritos->eliminar();
			enc = true;
		}
		else
			this->artistas_favoritos->avanzar();
	}
}
