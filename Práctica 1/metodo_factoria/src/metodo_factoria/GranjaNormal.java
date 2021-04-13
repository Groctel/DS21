package metodo_factoria;

public class GranjaNormal implements Granja{
	public int num_ovejas;
	public int num_perros;
	
	public GranjaNormal() {
		num_ovejas = 0;
		num_perros = 0;
	}
	
	public Granja ProducirGranja() {
		Granja granja_normal = new GranjaNormal();
		System.out.println("\u001B[32m" + "GRANJA NORMAL CREADA" + "\u001B[0m");
		return granja_normal;
	}
	
	public void AddOveja(OvejaNormal oveja) {
		animalicos.add(oveja);
		System.out.println("\u001B[32m" + "\tIntroducida oveja normal" + "\u001B[0m");
		num_ovejas++;
		Recuento();
	}
	
	public void AddPerro(PerroNormal perro) {
		animalicos.add(perro);
		System.out.println("\u001B[32m" + "\tIntroducido perro normal" + "\u001B[0m");
		num_perros++;
		Recuento();
	}
	
	public void Recuento() {
		System.out.println("\u001B[32m" + "Perros normales: "   + num_perros 
										+ "\nOvejas normales: " + num_ovejas + "\u001B[0m");

	}
}
