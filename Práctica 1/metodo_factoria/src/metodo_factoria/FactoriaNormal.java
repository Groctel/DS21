package metodo_factoria;

public class FactoriaNormal implements AnimalFactory {
	public GranjaNormal crearGranja() {
		GranjaNormal granjita = new GranjaNormal();
		granjita.ProducirGranja();
		
		return granjita;
	}
	public OvejaNormal crearOveja() {
		OvejaNormal ovejita = new OvejaNormal();
		ovejita.ProducirAnimal();
		
		return ovejita;
	}
	public PerroNormal crearPerro() {
		PerroNormal perrito = new PerroNormal();
		perrito.ProducirAnimal();
		
		return perrito;
	}
}
