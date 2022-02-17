/* Assignment 1 - SimpleJavaProgram
 * A simple program to demonstrate coding structure in the Java language
 * J2SE v 1.4.2_05 - Mac OS X
 * CSS 444 - Preston Guillot
 * September 13, 2004 */

// Java packages for GUI
import javax.swing.*; 

public class SimpleJavaProgram {

	//main method begins execution of Java application
	public static void main(String args[]) {
		
		String firstnum; //first number entered by the user
		String secnum;   //second number entered by the user
		String thirdnum; //third number entered by the user
		String results;  //string to contain output

		int number1;     //first number to work on
		int number2;	 //second number to work on
		int number3;     //third number to work on
		int sum;         //sum of number1, number2, number3
		int product;     //product of number1, number2, number3
		int avg;         //average of number1, number2, number3

		//read first number from user as a string
		firstnum = JOptionPane.showInputDialog("Enter first integer:");
		//read second number from user as a string
		secnum = JOptionPane.showInputDialog("Enter second integer:");
		//read third number from user as a string
		thirdnum = JOptionPane.showInputDialog("Enter third integer:");
	
		//convert numbers from type String to type int
		number1 = Integer.parseInt(firstnum);
		number2 = Integer.parseInt(secnum);
		number3 = Integer.parseInt(thirdnum);

		//find sum, product, and average
		sum = number1 + number2 + number3;
		product = number1 * number2 * number3;
		avg = sum / 3;
	
		//initialize results to empty String
		results = "";
		//insert sum, product, and avg into results String
		results = results + "Sum: " + sum + "\nProduct: " + product + "\nAverage: " + avg;
	        
	 	//find smallest number and insert into results String
		if ((number1 < number2) && (number1 < number3))
			results = results + "\nSmallest: " + number1;
		else if (number2 < number3)
			results = results + "\nSmallest: " + number2;
		else
			results = results + "\nSmallest: " + number3;

		//find largest number and insert into results String
		if ((number1 > number2) && (number1 > number3))
 			results = results + "\nLargest: " + number1;
		else if (number2 > number3)
			results = results + "\nLargest: " + number2;
		else
			results = results + "\nLargest: " + number3;

		//display results
		JOptionPane.showMessageDialog(null, results, "Results", JOptionPane.INFORMATION_MESSAGE);

		System.exit(0); //terminate application
	} //end method main
} //end class SimpleJavaProgram	





