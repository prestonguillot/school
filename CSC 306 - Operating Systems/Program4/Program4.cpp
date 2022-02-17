#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream.h>
#include <pthread.h>


void *partialsum(void *ptr);

const int SIZE = 50000;
int NumbersArray[SIZE];

int main() {
	
	int sum  = 0, arg1 = 0, arg2 = 1, arg3 = 2, total = 0;
	void **threadreturn;
	int *returnedsum;
	pthread_t first, second, third;

        for( int x = 0; x <  SIZE; x++ )
                NumbersArray[x] = rand() % 10;

        for ( int x = 0; x < SIZE; x++ )
                sum  += NumbersArray[x];

        cout << "The sum is: " << sum << endl;

	pthread_create(&first,NULL,partialsum,(void *) &arg1);
 	pthread_create(&second,NULL,partialsum,(void *) &arg2);
  	pthread_create(&third,NULL,partialsum,(void *) &arg3);

	pthread_join(first,threadreturn);
	returnedsum = (int *) *threadreturn;
	cout << "First third sum: " << *returnedsum << endl;
	total += *returnedsum;

    pthread_join(second,threadreturn);
    returnedsum = (int *) *threadreturn;
    cout << "Second third sum: " << *returnedsum << endl;
	total += *returnedsum;

    pthread_join(third,threadreturn);
    returnedsum = (int *) *threadreturn;
    cout << "Last third sum: " << *returnedsum << endl;
	total += *returnedsum;

	cout << "The total of returned parts is: " << total << endl;

        return 0;
}

void *partialsum(void *ptr) {

	int *index = (int *) ptr;
        int sum = 0, loopcounter;

        for(loopcounter = *index; loopcounter < SIZE; loopcounter += 3)
                sum += NumbersArray[loopcounter];

        pthread_exit((void *) &sum);
        return NULL;
}


