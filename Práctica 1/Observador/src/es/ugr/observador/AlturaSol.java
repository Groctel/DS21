package es.ugr.observador;
import java.util.Observable;

public class AlturaSol extends Observable
{
	private double state;
	private double INC = Math.PI/90.0;

	public AlturaSol ()
	{
		state = 0;

		(new Thread (new Runnable ()
		{
			@Override
			public void run ()
			{
				while (true)
				{
					increment();
					try {
						Thread.sleep(100);
					}
					catch (InterruptedException e){}
				}
			}
		})).start();
	}

	public double getPosition ()
	{
		return Math.sin(state);
	}

	public void increment ()
	{
		state += INC;
		setChanged();
		notifyObservers();
	}
}
