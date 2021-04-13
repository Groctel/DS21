package metodo_factoria;

public class GranjaNormal implements Granja {
	public int num_ovejas;
	public int num_perros;

	public GranjaNormal () {
		num_ovejas = 0;
		num_perros = 0;
	}

	public void AddOveja (Oveja oveja) {
		animalicos.add(oveja);
		System.out.println("\u001B[32m" + "\tIntroducida oveja normal" + "\u001B[0m");
		num_ovejas++;
		Recuento();
	}

	public void AddPerro (Perro perro) {
		animalicos.add(perro);
		System.out.println("\u001B[32m" + "\tIntroducido perro normal" + "\u001B[0m");
		num_perros++;
		Recuento();
	}

	public void Recuento () {
		System.out.println(
			"\u001B[32m" + "Perros normales: "   + num_perros +
			"\nOvejas normales: " + num_ovejas + "\u001B[0m"
		);
	}
}
