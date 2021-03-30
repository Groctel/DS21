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
	unsigned short     tolerancia     = 90;
	TipoTransformacion transformacion = MayusculasIniciales;

	bool RequiereFiltrado (const std::string & mensaje) const noexcept;

	inline std::string ExtraerComandos  (const std::string & mensaje) const noexcept;
	inline std::string ExtraerContenido (const std::string & mensaje) const noexcept;

	inline void TransformarAMayusculasIniciales (std::string & mensaje) noexcept;
	inline void TransformarATodoEnMinusculas    (std::string & mensaje) noexcept;
	inline void TransformarAAnulacionTotal      (std::string & mensaje) noexcept;

public:
	FiltroMayus (
		const unsigned short     m_tolerancia     = 90,
		const TipoTransformacion m_transformacion = MayusculasIniciales
	) noexcept;

	unsigned short     Tolerancia     () const noexcept;
	TipoTransformacion Transformacion () const noexcept;

	void Filtrar (std::string & mensaje) noexcept override;
};

#endif
