#include "filtro_mayus.hpp"

bool FiltroMayus :: RequiereFiltrado (const std::string & mensaje) const noexcept
{
	size_t total_letras     = 0;
	size_t total_mayusculas = 0;

	for (auto it = mensaje.cbegin(); it != mensaje.cend(); ++it)
	{
		if (isalpha(*it))
		{
			total_letras++;

			if (isupper(*it))
				total_mayusculas++;
		}
	}

	return (((double) total_mayusculas / (double) total_letras) * 100) > tolerancia;
}

std::string FiltroMayus :: ExtraerComandos (const std::string & mensaje) const noexcept
{
	std::string comandos = mensaje;
	size_t pos_separador = comandos.find_last_of(":");

	if (pos_separador != std::string::npos)
		comandos.erase(pos_separador+1, comandos.length()-pos_separador-1);
	else
		comandos = "";

	return comandos;
}

std::string FiltroMayus :: ExtraerContenido (const std::string & mensaje) const noexcept
{
	std::string contenido = mensaje;
	return contenido.erase(0, contenido.find_last_of(":")+1);
}

void FiltroMayus :: TransformarAMayusculasIniciales (std::string & mensaje) noexcept
{
	bool inicio_palabra = true;

	for (auto it = mensaje.begin(); it != mensaje.end(); ++it)
	{
		if (isspace(*it))
		{
			inicio_palabra = true;
		}
		else
		{
			if (!inicio_palabra)
				(*it) = tolower(*it);
			else
				inicio_palabra = false;
		}
	}
}

void FiltroMayus :: TransformarATodoEnMinusculas (std::string & mensaje) noexcept
{
	for (auto it = mensaje.begin(); it != mensaje.end(); ++it)
		(*it) = tolower(*it);
}

void FiltroMayus :: TransformarAAnulacionTotal (std::string & mensaje) noexcept
{
	mensaje = "";
}

FiltroMayus :: FiltroMayus (
	const unsigned short m_tolerancia,
	const TipoTransformacion m_transformacion
) noexcept
:
	tolerancia     (m_tolerancia),
	transformacion (m_transformacion)
{ }

unsigned short FiltroMayus :: Tolerancia () const noexcept
{
	return tolerancia;
}

FiltroMayus::TipoTransformacion FiltroMayus :: Transformacion () const noexcept
{
	return transformacion;
}

void FiltroMayus :: Filtrar (std::string & mensaje) noexcept
{
	std::string comandos  = ExtraerComandos(mensaje);
	std::string contenido = ExtraerContenido(mensaje);

	if (RequiereFiltrado(contenido))
	{
		switch (transformacion)
		{
			case MayusculasIniciales:
				TransformarAMayusculasIniciales(contenido);
			break;

			case TodoEnMinusculas:
				TransformarATodoEnMinusculas(contenido);
			break;

			case AnulacionTotal:
				TransformarAAnulacionTotal(contenido);
			break;
		}
	}

	mensaje = comandos + contenido;
}
