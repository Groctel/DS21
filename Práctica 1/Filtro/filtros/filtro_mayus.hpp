#ifndef DS_FILTRO_MAYUS
#define DS_FILTRO_MAYUS

#include <algorithm>
#include <stdexcept>
#include "filtro.hpp"

class FiltroMayus : public Filtro
{
public:
	enum TipoTransformacion
	{
		MayusculasIniciales,
		TodoEnMinusculas,
		AnulacionTotal
	};

private:
	unsigned short tolerancia = 90;
	TipoTransformacion trasformacion = MayusculasIniciales;

	bool RequiereFiltrado (const std::string & mensaje) const noexcept;

	inline void TransformarAMayusculasIniciales (std::string & mensaje) noexcept;
	inline void TransformarATodoEnMinusculas    (std::string & mensaje) noexcept;
	inline void TransformarAAnulacionTotal      (std::string & mensaje) noexcept;

public:
	unsigned short     Tolerancia     () const noexcept;
	TipoTransformacion Transformacion () const noexcept;

	void NuevaTolerancia     (const unsigned short nueva) noexcept;
	void NuevaTransformacion (const TipoTransformacion nueva) noexcept;
	void Filtrar             (std::string & mensaje) noexcept override;
};

#endif
