/* Preston Guillot
 * CSS 333 - Programming Assignment #3
 * Due Date - March 8, 2005
 * Value - 24 points*/

#include <stdio.h>

int main() {

	int date_day, date_month, date_year,
	    bday_day, bday_month, bday_year;

	printf("Please enter today's date (mm dd yyyy):");
	scanf("%d %d %d", &date_month, &date_day, &date_year);
	printf("Please enter the date of your birth:");
	scanf("%d %d %d", &bday_month, &bday_day, &bday_year);

	if((date_month == bday_month) && (date_day == bday_day))

		printf("Congratulations! You %d years old TODAY!", date_year - bday_year);

	else if ((date_month < bday_month) || ((date_month == bday_month) && (date_day < bday_day)))
		
		printf("Congratulations! You are %d years old.", date_year - bday_year - 1);

	else
		printf("Congratulations! You are %d years old.", date_year - bday_year);

}
		       		    		
