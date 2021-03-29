#include "jugador.hpp"

std::set<Jugador *> Jugador :: conectados;

Jugador :: Jugador () noexcept
{ }

Jugador :: Jugador (const std::string nom) noexcept
:
	nombre (nom)
{ }

Jugador :: ~Jugador () noexcept
{ }

bool Jugador :: Conectado () noexcept
{
	return conectados.find(this) != conectados.cend();
}

bool Jugador :: MensajesPendientes () const noexcept
{
	return !mensajes_pendientes.empty();
}

std::string Jugador :: Nombre () const noexcept
{
	return nombre;
}

std::string Jugador :: SiguienteMensaje ()
{
	if (mensajes_pendientes.empty())
		throw std::runtime_error("Intentado mostrar mensaje con cola vacía.");

	std::string mensaje = mensajes_pendientes.front();
	mensajes_pendientes.pop();

	return mensaje;
}

void Jugador :: Conectar () noexcept
{
	conectados.insert(this);
}

void Jugador :: Desconectar () noexcept
{
	conectados.erase(this);
}

void Jugador :: EnviarMensaje (const std::string mensaje) noexcept
{
	for (auto it = conectados.begin(); it != conectados.end(); ++it)
		(*it)->RecibirMensaje(mensaje);
}

void Jugador :: RecibirMensaje (const std::string mensaje) noexcept
{
	mensajes_pendientes.push(mensaje);
}

void Jugador :: Renombrar (const std::string nuevo_nombre) noexcept
{
	nombre = nuevo_nombre;
}
