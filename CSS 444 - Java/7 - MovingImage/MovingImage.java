import java.awt.Graphics;
import java.awt.Image;
import java.awt.Color;
import javax.swing.*;

public class MovingImage extends JApplet implements Runnable {

    Image circleImages[] = new Image[10];
    Image onScreen;
    Thread runner;

    public void init() {
        String circleResources[] = { "1.gif", "2.gif",
            "3.gif", "4.gif", "5.gif",
            "6.gif","7.gif", "8.gif",
            "9.gif","10.gif" };

        for (int i=0; i < circleResources.length; i++) {
            circleImages[i] = getImage(getCodeBase(),
                "images/" + circleResources[i]);
        }
    }

    public void start() {
        if (runner == null) {
            runner = new Thread(this);
            runner.start();
        }
    }

    public void stop() {
        runner = null;
    }

    public void run() {
    	
        setBackground(Color.white);
        while(true) {
        	
	        for (int i = 0; i < 10; i++) {
	        		
	        		onScreen = circleImages[i];
	        		repaint();
	        		pause(100);
	        		
	        }
	        
	        for (int j = 9; j >= 0; j--) {
	        	
	        	onScreen = circleImages[j];
	        	repaint();
	        	pause(100);
	        	
	        }
	     }
	   }
        


    void pause(int time) {
        try {
            Thread.sleep(time);
        } catch (InterruptedException e) { }
    }

    public void paint(Graphics screen) {
        if (onScreen != null)
            screen.drawImage(onScreen, 5, 10, this);
    }
}