/*Assignment 4 - Date class and implementation class
 *A class Date with the ability to calculate a person's age and an implementation
 *of the Date class, DateTest.
 *J2SE v 1.4.2_05 - Windows 2000 Professional
 *
 *CSS 444 - Preston Guillot
 *October 27, 2004 */
 
import MyClasses.MyDate;
import javax.swing.JOptionPane;

public class TestDate {
	
	public static void main(String args[]) {
		
		int month, day, year;
		MyDate birthday;
		String output, inputerror = "Invalid input, program halting.";
		
		month = Integer.parseInt(JOptionPane.showInputDialog("Please enter the month of your birth."));
		day = Integer.parseInt(JOptionPane.showInputDialog("Please enter the day of your birth."));
		year = Integer.parseInt(JOptionPane.showInputDialog("Please enter the year of your birth."));
		
		birthday = new MyDate(month, day, year);
		
		if(!birthday.dateCheck())
		
			JOptionPane.showMessageDialog(null,inputerror,"Program Output",JOptionPane.INFORMATION_MESSAGE);
		
		else {
				
		output = "Birthday: " + birthday.displayDate() + "\n\nYou are " + birthday.calculateAge() + " years old.";
		JOptionPane.showMessageDialog(null,output,"Program Output",JOptionPane.INFORMATION_MESSAGE);
		
		}
		
	}
}