#include <gtest/gtest.h>
#include "filtro_mayus.hpp"

class FiltroMayusTest : public testing::Test
{
protected:
	std::string minusculas = "buenos dias amigos";
	std::string mayusculas = "BUENOS DIAS AMIGOS";

	FiltroMayus filtro;
};

TEST_F (FiltroMayusTest, TransformacionPorDefecto_MayusculasIniciales)
{
	EXPECT_EQ(filtro.Transformacion(), MayusculasIniciales);
}

TEST_F (FiltroMayusTest, DiferentesTiposDeTransformacion)
{
	filtro.CambiarTransformacion(MayusculasIniciales);
	EXPECT_EQ(filtro.Transformacion(), MayusculasIniciales);

	filtro.CambiarTransformacion(TodoEnMinusculas);
	EXPECT_EQ(filtro.Transformacion(), TodoEnMinusculas);

	filtro.CambiarTransformacion(AnulacionTotal);
	EXPECT_EQ(filtro.Transformacion(), AnulacionTotal);
}

TEST_F (FiltroMayusTest, MensajeEnMinusculas_NoHayModificaciones)
{
	filtro.Filtrar(minusculas);
	EXPECT_EQ(minusculas, "buenos dias amigos");
}

TEST_F (FiltroMayusTest, MensajeEnMayusculas_MayusculasIniciales_DejaSoloLasPrimeras)
{
	filtro.Filtrar(mayusculas);
	EXPECT_EQ(mayusculas, "Buenos Dias Amigos");
}

TEST_F (FiltroMayusTest, MensajeEnMayusculas_TodoEnMinusculas_TodoEnMinusculas)
{
	filtro.CambiarTransformacion(TodoEnMinusculas);
	filtro.Filtrar(mayusculas);
	EXPECT_EQ(mayusculas, "buenos dias amigos");
}

TEST_F (FiltroMayusTest, MensajeEnMayusculas_AnulacionTotal_EliminaElMensaje)
{
	filtro.CambiarTransformacion(AnulacionTotal);
	filtro.Filtrar(mayusculas);
	EXPECT_EQ(mayusculas, "");
}

TEST_F (FiltroMayusTest, ToleranciaInicial_90)
{
	EXPECT_EQ(filtro.Tolerancia(), 90);
}

TEST_F (FiltroMayusTest, PonerLaToleranciaAl50_Devuelve50)
{
	filtro.CambiarTolerancia(50);
	EXPECT_EQ(filtro.Tolerancia(), 50);
}

TEST_F (FiltroMayusTest, MayorNumeroDeMayusculasQueTolerancia_EsTransformado)
{
	filtro.CambiarTransformacion(TodoEnMinusculas);
	filtro.Filtrar(mayusculas);

	EXPECT_EQ(mayusculas, minusculas);
}

TEST_F (FiltroMayusTest, MenorNumeroDeMayusculasQueTolerancia_EsTransformado)
{
	std::string mensaje = "BuEnOs DiAs AmIgOs";

	filtro.CambiarTransformacion(TodoEnMinusculas);
	filtro.Filtrar(mensaje);

	EXPECT_EQ(mensaje, "BuEnOs DiAs AmIgOs");
}
