/* Preston Guillot
 * CSS 333 - Programming Assignment #5
 * Due Date - April 5, 2005
 * Value - 26 points */

#include <stdio.h>

//GLOBAL DEFINITIONS
//a table to store step 4 values for months
const int monthsHash[12] = { 1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6 };
       	
//BEGIN FUNCTION isLeapYear(int)
//Returns 1 if year is leap year, 0 otherwise.
int isLeapYear(int year) {
	
	if(year % 400 == 0)
		return 1;
	else if((year % 4 == 0) && (year % 100 != 0))
		return 1;
	else
		return 0;
}
//END FUNCTIONS isLeapYear(int)

//BEGIN FUNCTION dayOfWeek(int, int, int)
//Returns the day of week of any given month/day/year
//as a value 0-6, starting at 0 = Saturday.
int dayOfWeek(int month, int day, int year) {
	
	int result; 			

	result = year % 100;   			//Step 1
	if(year >= 2000)			//Handle special case when
		result += 100; 			//year is after 20th century.
						
	result += (result / 4); 		//Steps 2 and 3.
	
	if(isLeapYear(year) && (month == 1)); 	// Step 4 - Handle special case of
	else if (isLeapYear(year) && (month == 2)) // Jan and Feb of leap years
		result += 3;
	else
		result += monthsHash[month-1];	// Handle normal case, index
						// of array is one less than month #

	result += day;				//Step 5.

	result %= 7;				//Step 6.

	return result;
}
//END FUNCTION dayOfWeek(int, int, int)

//BEGIN main()
int main() {

	int day, month, year;

	printf("Enter the month number (0 to quit): ");
	scanf("%d", &month);

	while(month != 0) { 	//0 sentinal
		
		printf("Enter the day number: ");
		scanf("%d", &day);
		printf("Enter the year of the date: ");
		scanf("%d", &year);		
		
		printf("	This date occurs on a ");
		
		switch(dayOfWeek(month,day,year)) { //Call dayOfWeek() to get value

			case 0: //Saturday
				printf("Saturday\n\n");
				break;
			case 1: //Sunday
				printf("Sunday\n\n");
				break;
			case 2: //Monday
				printf("Monday\n\n");
				break;
			case 3: //Tuesday
				printf("Tuesday\n\n");
				break;
			case 4: //Wednesday
				printf("Wednesday\n\n");
				break;
			case 5: //Thursday
				printf("Thursday\n\n");
				break;
			case 6: //Friday
				printf("Friday\n\n");
		}
	
	
		printf("Enter the month number (0 to quit): ");
		scanf("%d", &month); //Exit loop on input 0.
	}

	return 0;		
}
//END main()
