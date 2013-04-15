package kercar.raspberry.arduino;

import kercar.raspberry.arduino.message.GoForward;
import kercar.raspberry.arduino.message.IArduinoMessage;


public class ArduinoTest {

	public static void main(String[] args){
		
		// Initialisation de la classe de com
		SerialManager main = new SerialManager();
		main.setListener(new SerialListenerImpl());
		main.initialize();
		System.out.println("Started");
			
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		// Init du message
		//Stop msg = new Stop();
		GoForward msg = new GoForward();
		msg.setVitesse(40);
		System.out.println("ID : "+IArduinoMessage.extractID(msg.toBytes()));
		System.out.println(msg.toString());
		
		try {
			System.out.println("Envoi du message");
			main.write(msg.toBytes());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
