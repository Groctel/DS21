package metodo_factoria;

public class FactoriaMonstruosa {
	public void crearGranja() {
		GranjaMonstruosa granjita = new GranjaMonstruosa();
		granjita.ProducirGranja();
	}
	public void crearOveja() {
		OvejaMonstruosa ovejita = new OvejaMonstruosa();
		ovejita.ProducirAnimal();
	}
	public void crearPerro() {
		PerroMonstruoso perrito = new PerroMonstruoso();
		perrito.ProducirAnimal();
	}
}
