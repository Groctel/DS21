package es.ugr.observador;

import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class DiaSemana extends JPanel
{
	final String [] dias_semana = {
		"Lunes",
		"Martes",
		"Miércoles",
		"Jueves",
		"Viernes",
		"Sábado",
		"Domingo"
	};

	private int indice_dia;
	private JTextField textField;
	private double pos_anterior;

	public DiaSemana (AlturaSol alt)
	{
		setLayout(null);

		JLabel lblDia = new JLabel("Dia de la semana");
		lblDia.setBounds(12, 12, 128, 15);
		add(lblDia);

		textField = new JTextField();
		textField.setEditable(false);
		textField.setBounds(12, 39, 114, 19);
		add(textField);
		textField.setColumns(10);

		indice_dia = 0;
		pos_anterior = 0;

		this.comprobarPosicion(alt);
	}

	private void comprobarPosicion (final AlturaSol alt)
	{
		(new Thread(new Runnable() {
			@Override
			public void run()
			{
				while (true)
				{
					update(alt.getPosition());
					try
					{
						Thread.sleep(100);
					}
					catch (InterruptedException e)
					{ }
				}
			}
		})).start();
	}

	private void update (double pos)
	{
		if (pos_anterior < 0 && pos > 0)
			indice_dia = ((indice_dia + 1) % 7);

		pos_anterior = pos;
		this.textField.setText(dias_semana[indice_dia]);
	}
}
