package metodo_factoria;

public class FactoriaMonstruosa {
	public OvejaMonstruosa crearOveja () {
		OvejaMonstruosa ovejita = new OvejaMonstruosa();
		ovejita.ProducirAnimal();

		return ovejita;
	}

	public PerroMonstruoso crearPerro () {
		PerroMonstruoso perrito = new PerroMonstruoso();
		perrito.ProducirAnimal();

		return perrito;
	}
}
