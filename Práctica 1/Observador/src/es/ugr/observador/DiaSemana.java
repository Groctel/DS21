package es.ugr.observador;

import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class DiaSemana extends JPanel {
	private int indice_dia;
	private JTextField textField;
	private double pos_anterior;

	/**
	 * Create the panel.
	 */
	public DiaSemana(AlturaSol alt) {
		setLayout(null);
		
		JLabel lblDia = new JLabel("Dia");
		lblDia.setBounds(58, 33, 70, 15);
		add(lblDia);
		
		textField = new JTextField();
		textField.setEditable(false);
		textField.setBounds(38, 75, 114, 19);
		add(textField);
		textField.setColumns(10);
		
		indice_dia = 0;
		pos_anterior = 0;
		
		this.comprobarPosicion(alt);
	}
	
	private void comprobarPosicion(final AlturaSol alt) {
		(new Thread(new Runnable() {
			@Override
			public void run() {
				while(true) {
					update(alt.getPosition());
					try {
						Thread.sleep(100);
					}
					catch (InterruptedException e){}
				}
			}
		})).start();
	}
	
	private void update(double pos) {
		if (pos_anterior < 0 && pos > 0)
		{
			indice_dia = ((indice_dia + 1) % 7);
		}
		
		pos_anterior = pos;
		
		if (indice_dia == 0)
			this.textField.setText("Lunes");
		else if (indice_dia == 1)
			this.textField.setText("Martes");
		else if (indice_dia == 2)
			this.textField.setText("Miércoles");
		else if (indice_dia == 3)
			this.textField.setText("Jueves");
		else if (indice_dia == 4)
			this.textField.setText("Viernes");
		else if (indice_dia == 5)
			this.textField.setText("Sábado");
		else if (indice_dia == 6)
			this.textField.setText("Domingo");
		else
			this.textField.setText("ERROR");
	}

}
