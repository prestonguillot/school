/* Assignment 2 - PrintShapes
 * A program to accept user input from a dialogue and print shapes according to
 * input in a Java applet.
 * 	
 * CSS 444 - Preston Guillot
 * September 29, 2004 */
 
 /*Known Bugs:
  *
  * 1. If anything other than an integer is input for shapestring or sizestring
  *    applet fails to initialize. I'm unsure how to check input for error if it
  *    is not first converted into a integer, and apparently if the string 
  *    paramenter for parseInt is not a valid integer it returns an error,
  *    causing the applet to fail initialization.
  *
  * 2. Output of triangle and diamond is off centered due to differences in 
  *	   character width between a space and an asterix. Unsure how/if it's 
  *    possible to change the output in an applet window to a fixed width font.*/
 
 
 //Java Packages
 import javax.swing.*;		//import package javax.swing
 import java.awt.Graphics;	//import class Graphics
 
 public class PrintShapes extends JApplet {
 	
 	int shapeinput,sizeinput; //global variables to hold user input
 	
 	
 	public void init() {	//initialize applet by obtaining values from user
 			
 			String shapestring,sizestring; //strings to hold user input obtained from dialogues
 			
 			shapestring = JOptionPane.showInputDialog("Select a shape to draw:\n1 - Square\n2 - Triangle\n3 - Diamond");	//obtain first user input
 			shapeinput = Integer.parseInt(shapestring);			//convert string into integer
 			
 			while((shapeinput < 1) || (shapeinput > 3)) {		//check if user input is 1,2, or 3
 																//if not, obtain user input again
 				JOptionPane.showMessageDialog(null, "Please select using 1,2, or 3.", "Error!", JOptionPane.ERROR_MESSAGE);
 				shapestring = JOptionPane.showInputDialog("Select a shape to draw:\n1 - Square\n2 - Triangle\n3 - Diamond");
 				shapeinput = Integer.parseInt(shapestring);
 				
 			}
 			
 			
 			sizestring = JOptionPane.showInputDialog("Select an odd integer greater than five for the size of the shape");	//obtain second user input			
 			sizeinput = Integer.parseInt(sizestring);			//convert string into integer
 			
 			while((sizeinput < 7) || ((sizeinput % 2) != 1)) { //check if user input is greater than five and odd
 															   //if not, obtain user input again
 				JOptionPane.showMessageDialog(null, "Input is out of bounds!", "Error!", JOptionPane.ERROR_MESSAGE);
 				sizestring = JOptionPane.showInputDialog("Select an odd integer greater than five for the size of the shape");				
 				sizeinput = Integer.parseInt(sizestring); 				
 			}
 	} //end method init
 	
 	public void paint(Graphics g) { 			//draw text on applet's background
 		
 		super.paint(g);							//call superclass version of method paint
 		
 		if(shapeinput == 1) {					//draw a square if shapeinput is a 1
 			
 			String thestring = "";				//initialize an empty string to contain output
 			
 			for(int x = 0; x < sizeinput;x++)	//add asterixs to the string until string is
 				thestring = thestring + "* ";	//as large as user inputed
 				
 			for(int x = 1; x <= sizeinput;x++)	//draw the string as many times as the user
 				g.drawString(thestring,0,x*10);	//inputed
 		
 		}										//end square code
 		
 		else if(shapeinput == 2) {				//draw an inverted triange if shapeinput is 2
 			
 			int spacecounter = 0, starcounter = sizeinput;	//local variables to format output for triangle
 			
 			for(int x = 1; x <= sizeinput; x++) {		//loop as many times as the user input the size
 				
 				String thestring = "";					//initialize an empty string on every loop iteration
 				
 				for(int y = 0; y < spacecounter; y++)	//add spaces to the string, starting with none and
 					thestring = thestring + " ";		//adding one more each iteration
 				
 				for(int y = 0; y < starcounter; y++)	//add asterixs to the string, starting with as many as
 					thestring = thestring + "* ";		//the user input, and subtracting one with each iteration
 				
 				spacecounter++;							//bump the space counter
 				starcounter--;							//bump the asterix counter
 				g.drawString(thestring,0,x*10);			//draw the current string to the applet window
 				
 			}
 		}										//end triangle code
 		
 		else if(shapeinput == 3) {			//draw a diamond if shapeinput is 3
 			
 			int spacecounter = sizeinput / 2, starcounter = 1; //local variables to format output for diamond
 															   
 			for(int x = 1; x <= sizeinput / 2; x++) {		//start by drawing first half of the diamond
 															//as a triangle
 				String thestring = "";
 				
 				for(int y = 0; y < spacecounter; y++)
 					thestring = thestring + " ";
 					
 				for(int y = 0; y < starcounter; y++)
 					thestring = thestring + "* ";
 				
 				spacecounter--;
 				starcounter += 2;
 				g.drawString(thestring,0,x*10);
 			}												//done with first triangle
 			
 			spacecounter = 0;								//re-initialize local vars to format output
 			starcounter = sizeinput;						//for second triangle
 			
 			for(int x = sizeinput / 2 + 1; x <= sizeinput; x++) { //draw second half o the diamond
 																  //as an inverted triangle
 				String thestring = "";
 				
 				for(int y = 0; y < spacecounter; y++)
 					thestring = thestring + " ";
 					
 				for(int y = 0; y < starcounter; y++)
 					thestring = thestring + "* ";
 				
 				spacecounter++;
 				starcounter -= 2;
 				g.drawString(thestring,0,x*10);
 			}												//done with second triangle
 		}									//end diamond code	
 		
 			
 	}	//end method paint
 }	//end class PrintShapes