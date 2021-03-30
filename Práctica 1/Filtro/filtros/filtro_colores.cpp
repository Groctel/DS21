#include "filtro_colores.hpp"

bool FiltroColores :: ContieneColor (std::string & mensaje) const noexcept
{
	return std::regex_search(mensaje, std::regex("^.*:"));
}

void FiltroColores :: EliminarColor (std::string & mensaje) noexcept
{
	mensaje = std::regex_replace(mensaje, std::regex("^.*:"), "");
}

void FiltroColores :: SustituirPorColor (std::string & mensaje) noexcept
{
	const std::string mensaje_sin_modificar = mensaje;

	mensaje = std::regex_replace(mensaje, std::regex("^red:"),     TermRojo);
	mensaje = std::regex_replace(mensaje, std::regex("^green:"),   TermVerde);
	mensaje = std::regex_replace(mensaje, std::regex("^yellow:"),  TermAmarillo);
	mensaje = std::regex_replace(mensaje, std::regex("^blue:"),    TermAzul);
	mensaje = std::regex_replace(mensaje, std::regex("^magenta:"), TermMagenta);
	mensaje = std::regex_replace(mensaje, std::regex("^cyan:"),    TermCian);

	if (mensaje == mensaje_sin_modificar)
		mensaje = std::regex_replace(mensaje, std::regex("^.*:"), "");
	else
		mensaje += TermNormal;
}

bool FiltroColores :: Coloreado () const noexcept
{
	return coloreado;
}

void FiltroColores :: NuevoColoreado (const bool nuevo_estado) noexcept
{
	coloreado = nuevo_estado;
}

void FiltroColores :: Filtrar (std::string & mensaje) noexcept
{
	if (ContieneColor(mensaje))
	{
		if (coloreado)
			SustituirPorColor(mensaje);
		else
			EliminarColor(mensaje);
	}
}
