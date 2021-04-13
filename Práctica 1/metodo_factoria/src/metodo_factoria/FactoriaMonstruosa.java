package metodo_factoria;

public class FactoriaMonstruosa {
	public GranjaMonstruosa crearGranja() {
		GranjaMonstruosa granjita = new GranjaMonstruosa();
		granjita.ProducirGranja();
		
		return granjita;
	}
	public OvejaMonstruosa crearOveja() {
		OvejaMonstruosa ovejita = new OvejaMonstruosa();
		ovejita.ProducirAnimal();
		
		return ovejita;
	}
	public PerroMonstruoso crearPerro() {
		PerroMonstruoso perrito = new PerroMonstruoso();
		perrito.ProducirAnimal();
		
		return perrito;
	}
}
