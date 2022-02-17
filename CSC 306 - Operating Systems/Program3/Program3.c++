//Preston Guillot
//CSC 306
//Assignmnet #3 - pipe()
//10-12-2004


#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream.h>
#include <ctime>
#include <cstdlib>

int int2char(int number, int size, char *numberary) {
	int i;

        for (i = 0; i < size; i++)
                numberary[i] = '0';

        for (i = 0; (number > 10) && (i < size); i++) {
                numberary[i] = char(number % 10 + 48);
                number /= 10;
        }

	numberary[i] = char(number + 48);
	
	return 1;
}

int char2int(int size, char *numberary) {
	int tempnum, number = 0;	

	for (int i = 0; i < size; i++) {
		tempnum = int(numberary[i] - 48);
                
                for (int y = 0; y < i; y++)
                        tempnum *= 10;
                
                number += tempnum;
        }
	
	return number;
}

int main() {

        int NumbersArray[50000], john  = 0, ringo = 0, george = 0,  paul = 0,  PID1, PID2;
	int pipe1[2], pipe2[2], total;
	srand(time(0))


	char first3rd[10],second3rd[10];

        for( int x = 0; x <  50000; x++ )
                NumbersArray[x] = (rand() % 10) + 1;

        for ( int x = 0; x < 50000; x++ )
                john  += NumbersArray[x];

        cout << "The sum is: " << john << endl;

	pipe(pipe1);
	pipe(pipe2);

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
			
			int2char(george,10,first3rd);
			write(pipe1[1],first3rd,10);
                }

                else {
			wait();

                        for ( int x = 16667; x < 33333; x++ )
                                ringo += NumbersArray[x];

                        cout << "Second third of the array sum: " << ringo << endl;
                	
			int2char(ringo,10,second3rd);
			write(pipe2[1],second3rd,10);
		}
        }

        else {

		wait();

                for ( int x = 33333; x < 50000; x++ )
                        paul += NumbersArray[x];

                cout << "Last third of the array sum: " << paul << endl;
		
		read(pipe1[0],first3rd,10);
		read(pipe2[0],second3rd,10);
		
		cout << "Total of the array: " << paul + char2int(10,first3rd) + char2int(10,second3rd) << endl;
                exit(0);
        }


        return 0;
}
