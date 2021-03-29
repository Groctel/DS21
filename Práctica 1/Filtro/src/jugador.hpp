#ifndef DS_JUGADOR
#define DS_JUGADOR

#include <queue>
#include <set>
#include <stdexcept>
#include <string>

class Jugador
{
private:
	static std::set<Jugador *> conectados;

	std::queue<std::string> mensajes_pendientes;
	std::string nombre = "Player";

public:
	 Jugador () noexcept;
	 Jugador (const std::string nom) noexcept;
	~Jugador () noexcept;

	bool        Conectado          () noexcept;
	bool        MensajesPendientes () const noexcept;
	std::string Nombre             () const noexcept;
	std::string SiguienteMensaje   ();

	void Conectar       ()                               noexcept;
	void Desconectar    ()                               noexcept;
	void EnviarMensaje  (const std::string mensaje)      noexcept;
	void RecibirMensaje (const std::string mensaje)      noexcept;
	void Renombrar      (const std::string nuevo_nombre) noexcept;
};

#endif
