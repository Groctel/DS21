#ifndef DS_CADENA_FILTROS
#define DS_CADENA_FILTROS

#include <stack>
#include "filtro_colores.hpp"
#include "filtro_mayus.hpp"

struct PrefFiltro
{
	bool colores;
	bool mayus;

	struct PrefMayus {
		unsigned short tolerancia;
		FiltroMayus::TipoTransformacion transformacion;
	};
	PrefMayus pref_mayus;
};

class GestorFiltros
{
private:
	std::stack<Filtro *> cadena;

	void ActivarFiltroMayusculas () noexcept;

public:
	GestorFiltros (const PrefFiltro * preferencias = nullptr) noexcept;

	void Filtrar (std::string & mensaje) noexcept;
};

#endif
