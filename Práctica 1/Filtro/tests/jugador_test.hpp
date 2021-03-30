#include <gtest/gtest.h>
#include "jugador.hpp"

class JugadorTest : public testing::Test
{
protected:
	const std::string mensaje1 = "Bienvenido, jugador. o7";
	const std::string mensaje2 = "Debes construir pilones adicionales.";

	Jugador jugador;
};

TEST_F (JugadorTest, PorDefectoSeLlamaPlayer)
{
	EXPECT_EQ(jugador.Nombre(), "Player");
}

TEST_F (JugadorTest, LoLlamoAntonioAlConstruirlo_SeLlamaAntonio)
{
	Jugador nuevo("Pepe");
	EXPECT_EQ(nuevo.Nombre(), "Pepe");
}

TEST_F (JugadorTest, EmpiezaSinMensajesPendientes)
{
	EXPECT_FALSE(jugador.MensajesPendientes());
}

TEST_F (JugadorTest, LePasanUnMensaje_TieneMensajesPendientes)
{
	jugador.RecibirMensaje("Bienvenido, jugador. o7");
	EXPECT_TRUE(jugador.MensajesPendientes());
}

TEST_F (JugadorTest, SinMensajesPendientes_NoMuestraNada)
{
	EXPECT_THROW(jugador.SiguienteMensaje(), std::runtime_error);
}

TEST_F (JugadorTest, LePasanUnMensaje_MuestraElMismoMensaje)
{
	jugador.RecibirMensaje(mensaje1);
	EXPECT_EQ(jugador.SiguienteMensaje(), mensaje1);
}

TEST_F (JugadorTest, LePasanDosMensajes_LosMuestraEnOrden)
{
	jugador.RecibirMensaje(mensaje1);
	jugador.RecibirMensaje(mensaje2);

	EXPECT_EQ(jugador.SiguienteMensaje(), mensaje1);
	EXPECT_EQ(jugador.SiguienteMensaje(), mensaje2);
}

TEST_F (JugadorTest, SeConecta_ApareceConectado)
{
	jugador.Conectar();
	EXPECT_TRUE(jugador.Conectado());
}

TEST_F (JugadorTest, PuedeConectarseVariasVecesIdempotentemente)
{
	jugador.Conectar();
	jugador.Conectar();
	jugador.Conectar();
	jugador.Conectar();
	EXPECT_TRUE(jugador.Conectado());
}

TEST_F (JugadorTest, SeDesconecta_ApareceDesconectado)
{
	jugador.Desconectar();
	EXPECT_FALSE(jugador.Conectado());
}

TEST_F (JugadorTest, PuedeDesconectarseVariasVecesIdempotentemente)
{
	jugador.Desconectar();
	jugador.Desconectar();
	jugador.Desconectar();
	jugador.Desconectar();
	EXPECT_FALSE(jugador.Conectado());
}

class JugadorBroadcastTest : public testing::Test
{
protected:
	const std::string mensaje = "Bienvenido, jugador. o7";

	Jugador jugador1;
	Jugador jugador2;
	Jugador jugador3;
	Jugador jugador4;

	void SetUp () override
	{
		jugador1.Conectar();
		jugador2.Conectar();
		jugador3.Conectar();
		jugador4.Conectar();
	}
};

TEST_F (JugadorBroadcastTest, EnviaUnMensaje_LoRecibeDeVuelta)
{
	jugador1.EnviarMensaje(mensaje);
	EXPECT_EQ(jugador1.SiguienteMensaje(), mensaje);
}

TEST_F (JugadorBroadcastTest, EnviaUnMensaje_LoRecibenElRestoDeJugadores)
{
	jugador1.EnviarMensaje(mensaje);

	EXPECT_EQ(jugador2.SiguienteMensaje(), mensaje);
	EXPECT_EQ(jugador3.SiguienteMensaje(), mensaje);
	EXPECT_EQ(jugador4.SiguienteMensaje(), mensaje);
}
