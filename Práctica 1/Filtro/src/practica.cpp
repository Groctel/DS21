#include <iostream>
#include <vector>
#include "jugador.hpp"

size_t LeerNumeroJugadores ()
{
	size_t num_jugadores;

	std::cout << "Indique el número de jugadores [2-5]: ";
	std::cin  >> num_jugadores;

	return std::min(num_jugadores, (size_t) 5);
}

void CrearJugadores (std::vector<Jugador *> & jugadores)
{
	for (size_t i = 0; i < jugadores.size(); i++)
	{
		std::string nombre;

		std::cout << "Indique el nombre del jugador " << i+1 << ": ";
		std::cin  >> nombre;

		jugadores[i] = new Jugador(nombre);

		PrefFiltro * preferencias = jugadores[i]->Preferencias();

		std::cout
			<< "Indique las preferencias de " << nombre << ":" << std::endl
			<< "- Filtro de colores [0/1]: ";
		std::cin  >> preferencias->colores;
		std::cout << "- Filtro de mayúsculas [0/1]: ";
		std::cin  >> preferencias->mayus;

		if (preferencias->mayus)
		{
			std::cout << "  - Tolerancia: ";
			std::cin  >> preferencias->pref_mayus.tolerancia;
		}
	}
}

void ConectarJugadores (std::vector<Jugador *> & jugadores)
{
	for (auto it = jugadores.begin(); it != jugadores.end(); ++it)
		(*it)->Conectar();
}

void DesconectarJugadores (std::vector<Jugador *> & jugadores)
{
	for (auto it = jugadores.begin(); it != jugadores.end(); ++it)
		(*it)->Desconectar();
}

void ReproducirChat (std::vector<Jugador *> & jugadores)
{
	std::string mensaje;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout
		<< "Escriba un mensaje para que lo mande " << jugadores[0]->Nombre()
		<< ". Escriba \".\" para acabar." << std::endl << "> ";
	std::getline(std::cin, mensaje);

	while (mensaje != ".")
	{
		jugadores[0]->EnviarMensaje(mensaje);

		std::cout << std::endl;
		for (size_t i = 1; i < jugadores.size() ; i++)
			std::cout
				<< jugadores[i]->Nombre() << ": "
				<< jugadores[i]->SiguienteMensaje() << std::endl;

		std::cout << std::endl << "Escriba otro mensaje." << std::endl << "> ";
		std::getline(std::cin, mensaje);
	}
}

int main ()
{
	std::vector<Jugador *> jugadores(LeerNumeroJugadores());

	CrearJugadores(jugadores);
	ConectarJugadores(jugadores);
	ReproducirChat(jugadores);
	DesconectarJugadores(jugadores);

	for (auto it = jugadores.begin(); it != jugadores.end(); ++it)
		delete *it;

	return 0;
}
