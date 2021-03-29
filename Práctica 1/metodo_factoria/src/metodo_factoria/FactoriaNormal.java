package metodo_factoria;

public class FactoriaNormal implements AnimalFactory {
	public void crearGranja() {
		GranjaNormal granjita = new GranjaNormal();
		granjita.ProducirGranja();
	}
	public void crearOveja() {
		OvejaNormal ovejita = new OvejaNormal();
		ovejita.ProducirAnimal();
	}
	public void crearPerro() {
		PerroNormal perrito = new PerroNormal();
		perrito.ProducirAnimal();
	}
}
