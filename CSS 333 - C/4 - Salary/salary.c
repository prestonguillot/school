/* Preston Guillot
 * CSS 333 - Programming Assignment #3
 * Due Date - March 24, 2005
 * Value - 20 Points */

#include <stdio.h>

int main() {

	float sales;

	printf("Enter sales in dollars (-1 to end): ");
	scanf("%f", &sales);

	while(sales != -1) {
		
		printf("Salary is: $%.2f\n\n", 200 + sales * .09);
		printf("Enter sales in dollars (-1 to end): ");
		scanf("%f", &sales);

	}

	return 0;
}
