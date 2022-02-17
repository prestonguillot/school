#include <iostream.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main() {
	
	int NumbersArray[50000], john  = 0, ringo = 0, george = 0,  paul = 0,  PID1, PID2;

	for( int x = 0; x <  50000; x++ ) 
		NumbersArray[x] = rand() % 10;

	for ( int x = 0; x < 50000; x++ )
		john  += NumbersArray[x];

	cout << "The sum is: " << john << endl;

	PID1 = fork();
	
	if (PID1 < 0) {
		cout << "Error occured, program aborting.\n";
		exit(-1);
	}
	
	else if (PID1 == 0) {

		PID2 = fork();
		
		if (PID2 < 0) {
			cout << "Error occured, program aborting.\n";
			exit(-1);
		}
		
		else if (PID2 == 0) {
			
			for ( int x = 0; x < 16667; x++ )
				george += NumbersArray[x];
			
			cout << "First third of the array sum: " << george << endl;
		}
		
		else {

			for ( int x = 16667; x < 33333; x++ )
				ringo += NumbersArray[x];

			cout << "Second third of the array sum: " << ringo << endl;
		}
	}
	
	else {

		for ( int x = 33333; x < 50000; x++ )
			paul += NumbersArray[x];
		
		cout << "Last third of the array sum: " << paul << endl;

		exit(0);
	}
		

	return 0;
}
