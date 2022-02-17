/*Assignment 4 - Date class and implementation class
 *A class Date with the ability to calculate a person's age and an implementation
 *of the Date class, DateTest.
 *J2SE v 1.4.2_05 - Windows 2000 Professional
 *
 *CSS 444 - Preston Guillot
 *October 27, 2004 */
 
 
package MyClasses;

//Java Packages  
import java.util.GregorianCalendar; //import GregorianCalendar class


//Begin Date class.
  
  public class MyDate extends Object {
  	
  	static GregorianCalendar todaysDate = new GregorianCalendar(); 			//static field contains system date information
  	
  	//declare private fields for Date class
  	private int month;
  	private int day;
  	private int year;
  	//end private field declaraton
  	
  
//Begin constructor definitions.

	//Begin default constructor definition.
	//Creates a Date object that contains today's date.
  	public MyDate() {
  	
  		month = (todaysDate.get(todaysDate.MONTH)) + 1;
  		day = (todaysDate.get(todaysDate.DAY_OF_MONTH));
  		year = (todaysDate.get(todaysDate.YEAR));
  	
  	}
  	
  	//End default constructor definition.
  	
  	//Begin first constructor definition.
  	/*Constructor is passed three integer values, representing month, day of
  	 *month, and year. If the parameters are valid a Date object is created
  	 *initialized to their values; if the parameters are invalid, a Date object
  	 *with all values initialized to zero is created.*/
 
  	public MyDate(int m, int d, int y) {
  		
  			month = m;
  			day = d;
  			year = y;
  		
	  	if (!dateCheck()) {
	  			
	  		month = 0;
	  		day = 0;
	  		year = 0;
	  		
	  	}
	}
	//End first constructor definition.
	
//End constructor definitions.

//Begin public method definitions.

	//Begin method displayDate().
	//Method returns the date object in form m/d/yyyy as a String.
	public String displayDate() {
		
		return Integer.toString(month) + '/' + Integer.toString(day) + '/' + Integer.toString(year);
				
	}
	//End method displayDate()
	
	
	//Begin method calculateAge();
	/*Method returns an integer value representing the age of a person
	 *whose birthday occurs on the Date object's date.*/	
	public int calculateAge() {
		
		int age = todaysDate.get(todaysDate.YEAR) - year;					//Calculate age, disregarding month and date.
		int thisMonth = todaysDate.get(todaysDate.MONTH) + 1;
		
		
		if(month > thisMonth)												//Has the birthday month already occured?
			
			return age - 1;													//If not, bithday hasn't passed this year, decrement and return age.													
	
		else if(month < thisMonth)											
		
			return age;														//If so, bitday has passed this year, return age.
			
		else																//If the birthday month is the current month, check the exact day.
			
			if(day > todaysDate.get(todaysDate.DAY_OF_MONTH))				//Day hasn't passed yet, no birthday, decrement and return age.
				
				return age - 1;
			
			else
				
				return age;													//Day has passed, birthday already occured, return age.
	}
	//End method calculateAge().

	//Begin method dateCheck().
	/*Method checks if month and day of month are valid values and returns
	 *true/false accordingly.*/
	public boolean dateCheck() {
		
		int feb;
		
		if (todaysDate.isLeapYear(year)) 									//Check if year of Date object is a leap year and set the number
			feb = 29;														//of days in February accordingly. 
		else
			feb = 28;
			
		final int months_hash[] = {0,31,feb,31,30,31,30,31,31,30,31,30,31};	//Table containing number of days in each month.
		
		if ((month < 1) || (month > 12))									//Is the month a valid number?
			
			return false;
				
		else if ((day < 1) || (day > months_hash[month]))					//If so, is the day a valid day of the month?
			
			return false;
			
		return true;
	
	}
	//End method dateCheck().

//End public method definitions

}
//End MyDate class.
  		
  		
  	 