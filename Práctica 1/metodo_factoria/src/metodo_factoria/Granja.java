package metodo_factoria;

import java.util.ArrayList;

public interface Granja {
	public ArrayList<Animal> animalicos = new ArrayList<Animal>();

	public void AddOveja (Oveja oveja);
	public void AddPerro (Perro perro);
}
