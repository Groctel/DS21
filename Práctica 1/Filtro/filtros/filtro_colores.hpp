#ifndef DS_FILTRO_COLORES
#define DS_FILTRO_COLORES

#include <regex>
#include "filtro.hpp"

#define TermNormal   "\x1B[0m"
#define TermRojo     "\x1B[31m"
#define TermVerde    "\x1B[32m"
#define TermAmarillo "\x1B[33m"
#define TermAzul     "\x1B[34m"
#define TermMagenta  "\x1B[35m"
#define TermCian     "\x1B[36m"
#define TermBlanco   "\x1B[37m"

class FiltroColores : public Filtro
{
private:
	bool coloreado = true;

	bool ContieneColor (std::string & mensaje) const noexcept;

	void EliminarColor     (std::string & mensaje) noexcept;
	void SustituirPorColor (std::string & mensaje) noexcept;

public:
	bool Coloreado () const noexcept;

	void NuevoColoreado (const bool nuevo_estado) noexcept;
	void Filtrar          (std::string & mensaje) noexcept override;
};

#endif
