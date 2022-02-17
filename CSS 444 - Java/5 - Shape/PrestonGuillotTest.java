/*Assignment 5 - Shape interface and OOP exercises
 *A class - Test - to test the Shape interface.
 *J2SE v 1.4.2_05 - Windows 2000 Professional
 *
 *CSS 444 - Preston Guillot
 *November 8, 2004 */
 
 import PrestonGuillotShape.PrestonGuillotShape;
 import PrestonGuillotShape.PrestonGuillotPoint;
 import PrestonGuillotShape.PrestonGuillotRectangle;
 import PrestonGuillotShape.PrestonGuillotRectangularSolid;
 import java.text.DecimalFormat;
 import javax.swing.JOptionPane;
 
 public class PrestonGuillotTest {
 	
 	public static void main(String args[]) {
 		
 		DecimalFormat twoDigits = new DecimalFormat("0.00");
 		String output = "";
 	
 		PrestonGuillotPoint point = new PrestonGuillotPoint(10,10);
 		PrestonGuillotRectangle rectangle = new PrestonGuillotRectangle(3,4);
 		PrestonGuillotRectangularSolid solid = new PrestonGuillotRectangularSolid(3,4,5);
 		PrestonGuillotShape array[] = new PrestonGuillotShape[3];
 		
 		array[0] = point;
 		array[1] = rectangle;
 		array[2] = solid;
 		
 		for(int i = 0; i < 3; i++) {
 			
 			output += array[i].getName() + ": " + array[i].toString();
 			output += "\nArea: " + twoDigits.format(array[i].area());
 			output += "\nVolume: " + twoDigits.format(array[i].volume());
 			output += "\n\n";
 			
 		}
 		
 		JOptionPane.showMessageDialog(null,output,"Program Output",JOptionPane.INFORMATION_MESSAGE);
 		
 	}
 }
 		
 		
 			
 			
 		