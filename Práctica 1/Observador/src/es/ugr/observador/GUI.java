package es.ugr.observador;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Font;
import javax.swing.JTextField;

import java.util.Observer;
import java.util.Observable;

public class GUI extends JFrame implements Observer
{
	private JPanel contentPane;
	private JTextField textField;

	public static void main (String[] args)
	{
		final AlturaSol alt = new AlturaSol();

		EventQueue.invokeLater(new Runnable()
		{
			public void run ()
			{
				try
				{
					GUI frame = new GUI(alt);
					frame.setVisible(true);
				}
				catch (Exception e)
				{
					e.printStackTrace();
				}
			}
		});
	}

	public GUI (AlturaSol alt)
	{
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);

		JLabel lblPatrnObservador = new JLabel("PATRÓN OBSERVADOR");
		lblPatrnObservador.setFont(new Font("Dialog", Font.BOLD, 24));
		lblPatrnObservador.setHorizontalAlignment(SwingConstants.CENTER);
		lblPatrnObservador.setBounds(12, 0, 426, 27);
		contentPane.add(lblPatrnObservador);

		JPanel panel = new FranjaHoraria(alt);
		panel.setBounds(22, 86, 190, 173);
		contentPane.add(panel);

		JPanel panel_1 = new DiaSemana(alt);
		panel_1.setBounds(248, 86, 190, 173);
		contentPane.add(panel_1);

		JLabel lblAlturaDelSol = new JLabel("Altura del sol");
		lblAlturaDelSol.setBounds(92, 43, 107, 15);
		contentPane.add(lblAlturaDelSol);

		textField = new JTextField();
		textField.setEditable(false);
		textField.setBounds(217, 41, 114, 19);
		contentPane.add(textField);
		textField.setColumns(10);

		this.init(alt);
	}

	private void init (AlturaSol alt)
	{
		alt.addObserver(this);
		this.textField.setText("Started listening");
	}

	@Override
	public void update (Observable o, Object arg)
	{
		this.textField.setText(((AlturaSol) o).getPosition()+"");
	}
}
