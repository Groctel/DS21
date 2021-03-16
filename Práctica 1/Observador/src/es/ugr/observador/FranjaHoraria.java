package es.ugr.observador;

import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JTextField;
import java.util.Observable;
import java.util.Observer;

public class FranjaHoraria extends JPanel implements Observer
{
	private JTextField textField;

	/**
	 * Create the panel.
	 */
	public FranjaHoraria (AlturaSol alt)
	{
		setLayout(null);

		JLabel lblFranja = new JLabel("Momento del día");
		lblFranja.setBounds(12, 12, 126, 15);
		add(lblFranja);

		textField = new JTextField();
		textField.setEditable(false);
		textField.setBounds(12, 39, 114, 19);
		add(textField);
		textField.setColumns(10);

		alt.addObserver(this);
	}

	@Override
	public void update(Observable o, Object arg)
	{
		double altura = ((AlturaSol) o).getPosition();

		if (altura > 0)
			this.textField.setText("Día");
		else
			this.textField.setText("Noche");
	}
}
