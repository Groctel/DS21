package metodo_factoria;

import java.util.ArrayList;

public interface Granja{
	public ArrayList<Animal> animalicos = new ArrayList<Animal>();
	
	Granja ProducirGranja();
}
