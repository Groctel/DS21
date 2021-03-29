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

	return ((total_mayusculas / total_letras) * 100) > tolerancia;
}

unsigned short FiltroMayus :: Tolerancia () const noexcept
{
	return tolerancia;
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

TipoTransformacion FiltroMayus :: Transformacion () const noexcept
{
	return trasformacion;
}

void FiltroMayus :: CambiarTolerancia (const unsigned short nueva) noexcept
{
	tolerancia = std::min(nueva, (unsigned short) 100);
}

void FiltroMayus :: CambiarTransformacion (const TipoTransformacion nueva) noexcept
{
	trasformacion = nueva;
}

void FiltroMayus :: Filtrar (std::string & mensaje) noexcept
{
	if (RequiereFiltrado(mensaje))
	{
		switch (trasformacion)
		{
			case MayusculasIniciales:
				TransformarAMayusculasIniciales(mensaje);
			break;

			case TodoEnMinusculas:
				TransformarATodoEnMinusculas(mensaje);
			break;

			case AnulacionTotal:
				TransformarAAnulacionTotal(mensaje);
			break;
		}
	}
}
