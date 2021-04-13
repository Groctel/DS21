package metodo_factoria;

import java.lang.Math;
import java.lang.Runnable;

import metodo_factoria.FactoriaMonstruosa;
import metodo_factoria.FactoriaNormal;

public class GestorEntidades {
	
	public GestorEntidades(){
		Jugar();
	}
	
	public void Jugar() {
		//Creamos las granjas
        FactoriaNormal fact_nrml = new FactoriaNormal();
        GranjaNormal granja_nrml = fact_nrml.crearGranja();
        
        FactoriaMonstruosa fact_mnstr = new FactoriaMonstruosa();
        GranjaMonstruosa granja_mnstr = fact_mnstr.crearGranja();
		
        
		//Hebra granja normal
        new Thread(new Runnable() {
            public void run() {
		        for(int i = 0; i < 10; i++) {
		        	//Seleccionamos aleatoriamente si se mete una oveja o un perro
		        	if(Math.random() < 0.5) {
				        System.out.println("\t\tProduciendo oveja normal...");
			            OvejaNormal ovj = fact_nrml.crearOveja();
				        System.out.println("\tIntroduciendo oveja a granja normal...");
				        granja_nrml.AddOveja(ovj);
			            
			        } else {
			        	System.out.println("\t\tProduciendo perro normal...");
			            PerroNormal prr = fact_nrml.crearPerro();
			            System.out.println("\tIntroduciendo perro a granja normal...");
			            granja_nrml.AddPerro(prr);
			        }
		        }
            }
        }).start();

      //Hebra granja monstruosa
        new Thread(new Runnable() {
            public void run() {
            	for(int i = 0; i < 10; i++) {
                	//Seleccionamos aleatoriamente si se mete una oveja o un perro
            		if(Math.random() < 0.5) {
    			        System.out.println("\t\tProduciendo oveja monstruosa...");
    		            OvejaMonstruosa ovj = fact_mnstr.crearOveja();
    			        System.out.println("\tIntroduciendo oveja a granja monstruosa...");
    			        granja_mnstr.AddOveja(ovj);
    		            
    		        } else {
    		        	System.out.println("\t\tProduciendo perro monstruoso...");
    		            PerroMonstruoso prr = fact_mnstr.crearPerro();
    		            System.out.println("\tIntroduciendo perro a granja monstruosa...");
    		            granja_mnstr.AddPerro(prr);
    		            
    		        }
            	}
            }
        }).start();

		
	}
}
