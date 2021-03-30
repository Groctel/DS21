#include <gtest/gtest.h>
#include "filtro_colores.hpp"
#include "filtro_mayus.hpp"

class FiltroMayusTest : public testing::Test
{
protected:
	FiltroMayus filtro;

	std::string minusculas = "buenos dias amigos";
	std::string mayusculas = "BUENOS DIAS AMIGOS";
};

TEST_F (FiltroMayusTest, TransformacionPorDefecto_MayusculasIniciales)
{
	EXPECT_EQ(filtro.Transformacion(), FiltroMayus::MayusculasIniciales);
}

TEST_F (FiltroMayusTest, DiferentesTiposDeTransformacion)
{
	filtro.NuevaTransformacion(FiltroMayus::MayusculasIniciales);
	EXPECT_EQ(filtro.Transformacion(), FiltroMayus::MayusculasIniciales);

	filtro.NuevaTransformacion(FiltroMayus::TodoEnMinusculas);
	EXPECT_EQ(filtro.Transformacion(), FiltroMayus::TodoEnMinusculas);

	filtro.NuevaTransformacion(FiltroMayus::AnulacionTotal);
	EXPECT_EQ(filtro.Transformacion(), FiltroMayus::AnulacionTotal);
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
	filtro.NuevaTransformacion(FiltroMayus::TodoEnMinusculas);
	filtro.Filtrar(mayusculas);
	EXPECT_EQ(mayusculas, "buenos dias amigos");
}

TEST_F (FiltroMayusTest, MensajeEnMayusculas_AnulacionTotal_EliminaElMensaje)
{
	filtro.NuevaTransformacion(FiltroMayus::AnulacionTotal);
	filtro.Filtrar(mayusculas);
	EXPECT_EQ(mayusculas, "");
}

TEST_F (FiltroMayusTest, ToleranciaInicial_90)
{
	EXPECT_EQ(filtro.Tolerancia(), 90);
}

TEST_F (FiltroMayusTest, PonerLaToleranciaAl50_Devuelve50)
{
	filtro.NuevaTolerancia(50);
	EXPECT_EQ(filtro.Tolerancia(), 50);
}

TEST_F (FiltroMayusTest, MayorNumeroDeMayusculasQueTolerancia_EsTransformado)
{
	filtro.NuevaTransformacion(FiltroMayus::TodoEnMinusculas);
	filtro.Filtrar(mayusculas);

	EXPECT_EQ(mayusculas, minusculas);
}

TEST_F (FiltroMayusTest, MenorNumeroDeMayusculasQueTolerancia_EsTransformado)
{
	std::string mensaje = "BuEnOs DiAs AmIgOs";

	filtro.NuevaTransformacion(FiltroMayus::TodoEnMinusculas);
	filtro.Filtrar(mensaje);

	EXPECT_EQ(mensaje, "BuEnOs DiAs AmIgOs");
}

class FiltroColoresTest : public testing::Test
{
protected:
	FiltroColores filtro;

	std::string incolora = "Esta cadena no tiene colores";
	std::string roja     = "red:Esta cadena se muestra en rojo";
	std::string verde    = "green:Esta cadena se muestra en verde";
	std::string amarilla = "yellow:Esta cadena se muestra en amarillo";
	std::string azul     = "blue:Esta cadena se muestra en azul";
	std::string magenta  = "magenta:Esta cadena se muestra en magenta";
	std::string cian     = "cyan:Esta cadena se muestra en cian";
	std::string invalida = "fdhsklf:Esta cadena es inválida";
};

TEST_F (FiltroColoresTest, PorDefectoSiempreColorea)
{
	EXPECT_TRUE(filtro.Coloreado());
}

TEST_F (FiltroColoresTest, PuedeDejarDeColorear)
{
	filtro.NuevoColoreado(false);
	EXPECT_FALSE(filtro.Coloreado());
}

TEST_F (FiltroColoresTest, LasCadenasIncolorasNoSeModifican)
{
	filtro.Filtrar(incolora);
	EXPECT_EQ(incolora, "Esta cadena no tiene colores");
}

TEST_F (FiltroColoresTest, IndicadorDeColor_CambiaAColorTerminal)
{
	filtro.Filtrar(roja);
	filtro.Filtrar(verde);
	filtro.Filtrar(amarilla);
	filtro.Filtrar(azul);
	filtro.Filtrar(magenta);
	filtro.Filtrar(cian);

	EXPECT_EQ(roja,     "\x1B[31mEsta cadena se muestra en rojo\x1B[0m");
	EXPECT_EQ(verde,    "\x1B[32mEsta cadena se muestra en verde\x1B[0m");
	EXPECT_EQ(amarilla, "\x1B[33mEsta cadena se muestra en amarillo\x1B[0m");
	EXPECT_EQ(azul,     "\x1B[34mEsta cadena se muestra en azul\x1B[0m");
	EXPECT_EQ(magenta,  "\x1B[35mEsta cadena se muestra en magenta\x1B[0m");
	EXPECT_EQ(cian,     "\x1B[36mEsta cadena se muestra en cian\x1B[0m");
}

TEST_F (FiltroColoresTest, MensajeConColorInvalido_SeElimina)
{
	filtro.Filtrar(invalida);
	EXPECT_EQ(invalida, "Esta cadena es inválida");
}
