#include "gestor_filtros.hpp"

GestorFiltros :: GestorFiltros (const PrefFiltro * preferencias) noexcept
{
	if (preferencias != nullptr)
	{
		cadena.push(new FiltroColores(preferencias->colores));

		if (preferencias->mayus)
			cadena.push(new FiltroMayus(
				preferencias->pref_mayus.tolerancia,
				preferencias->pref_mayus.transformacion
			));
	}
	else
	{
		cadena.push(new FiltroColores);
	}
}

void GestorFiltros :: ActivarFiltroMayusculas () noexcept
{
	cadena.push(new FiltroMayus);
}

void GestorFiltros :: Filtrar (std::string & mensaje) noexcept
{
	while (!cadena.empty())
	{
		cadena.top()->Filtrar(mensaje);
		delete cadena.top();
		cadena.pop();
	}
}
