#ifndef DS_FILTRO
#define DS_FILTRO

#include <string>

class Filtro
{
public:
	virtual ~Filtro () { };

	virtual void Filtrar (std::string & mensaje) noexcept = 0;
};

#endif
