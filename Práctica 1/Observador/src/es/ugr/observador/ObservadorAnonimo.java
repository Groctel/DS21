package es.ugr.observador;
import java.util.Observer;

public abstract class ObservadorAnonimo<T> implements Observer {
	T ref;
	
	public ObservadorAnonimo (T ref)
	{
		this.ref = ref;
	}
}