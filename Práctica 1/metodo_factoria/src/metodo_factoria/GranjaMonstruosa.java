package metodo_factoria;

public class GranjaMonstruosa implements Granja{
	public int num_ovejas;
	public int num_perros;
	
	public GranjaMonstruosa() {
		num_ovejas = 0;
		num_perros = 0;
	}
	
	public Granja ProducirGranja() {
		Granja granja_monstruosa = new GranjaMonstruosa();
		System.out.println("\u001B[31m" + "GRANJA MONSTRUOSA CREADA" + "\u001B[0m");
		
		return granja_monstruosa;
	}

	public void AddOveja(OvejaMonstruosa oveja) {
		animalicos.add(oveja);
		System.out.println("\u001B[31m" + "\tIntroducida oveja monstruosa" + "\u001B[0m");
		num_ovejas++;
		Recuento();
	}
	
	public void AddPerro(PerroMonstruoso perro) {
		animalicos.add(perro);
		System.out.println("\u001B[31m" + "\tIntroducido perro monstruoso" + "\u001B[0m");
		num_perros++;
		Recuento();
	}
	
	public void Recuento() {
		System.out.println("\u001B[31m" + "Perros monstruosos: "   + num_perros 
										+ "\nOvejas monstruosas: " + num_ovejas + "\u001B[0m");

	}
}
