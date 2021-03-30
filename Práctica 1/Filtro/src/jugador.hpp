#ifndef DS_JUGADOR
#define DS_JUGADOR

#include <queue>
#include <set>
#include <stdexcept>
#include <string>
#include "gestor_filtros.hpp"

class Jugador
{
private:
	static std::set<Jugador *> conectados;

	PrefFiltro * preferencias;
	std::queue<std::string> mensajes_pendientes;
	std::string nombre;

public:
	 Jugador (const std::string m_nombre = "Player") noexcept;
	~Jugador () noexcept;

	bool         Conectado          () noexcept;
	bool         MensajesPendientes () const noexcept;
	std::string  Nombre             () const noexcept;
	std::string  SiguienteMensaje   ();
	PrefFiltro * Preferencias       () noexcept;

	void Conectar       ()                               noexcept;
	void Desconectar    ()                               noexcept;
	void EnviarMensaje  (const std::string mensaje)      noexcept;
	void RecibirMensaje (const std::string mensaje)      noexcept;
};

#endif
