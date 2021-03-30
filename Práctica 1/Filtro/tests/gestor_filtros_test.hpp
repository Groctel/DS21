#include <gtest/gtest.h>
#include "gestor_filtros.hpp"

class GestorFiltrosTest : public testing::Test
{
protected:
	GestorFiltros gestor;

	std::string roja      = "red:Esta cadena se muestra en color rojo";
	std::string roja_mayus= "red:ESTA CADENA SE MUESTRA EN COLOR ROJO";
};

TEST_F (GestorFiltrosTest, EjecucionPorDefecto_SustituyeLosColores)
{
	gestor.Filtrar(roja);
	EXPECT_EQ(roja, "\x1B[31mEsta cadena se muestra en color rojo\x1B[0m");
}

TEST_F (GestorFiltrosTest, ActivarFiltroMayusculas_SustituyeMayusculasYColores)
{
	PrefFiltro preferencias = {
		true,
		true,
		{
			90,
			FiltroMayus::MayusculasIniciales
		}
	};

	gestor = GestorFiltros(&preferencias);

	gestor.Filtrar(roja_mayus);
	EXPECT_EQ(roja_mayus, "\x1B[31mEsta Cadena Se Muestra En Color Rojo\x1B[0m");
}
