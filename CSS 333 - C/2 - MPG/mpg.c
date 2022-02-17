/* Preston Guillot
 * CSS 333 - Programming Assignment #2
 * Due Date - February 17, 2005
 * Value - 20 points */

#include <stdio.h>

int main() {

	float begin, end, gals;

	printf("CALCULATING MILES PER GALLON\n\n");
	printf("Enter the odometer readings:\n");
	printf("Beginning?  ");
	scanf("%f", &begin);
	printf("Ending?     ");
	scanf("%f", &end);
	printf("\nEnter the number of gallons of gasoline used:  ");
	scanf("%f", &gals);
	printf("\nYour car averaged %.3f miles per gallon\n", (end - begin)/gals);

	return 0;
}
