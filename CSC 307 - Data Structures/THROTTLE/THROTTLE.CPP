//Preston Guillot

#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

class throttle {
 public:
        // CONSTRUCTORS
        throttle(int size, int pos);
        throttle(const throttle& x);
        // MODIFICATION MEMBER FUNCTIONS
        void shut_off();
        void shift(int amount);
        //OVERLOADED OPERATORS
        throttle operator+(const throttle& throt1) const;
        friend ostream& operator<<(ostream& out, const throttle& throt) {
            out << throt.position << "/" << throt.max;
            return out;
        }
        //CONSTANT MEMBER FUNCTIONS
        double flow() const;
        int getposition() const;
        int getmax() const;
        bool is_on() const;
        
 private:
        int position;
        int max;
};
throttle::throttle(int size = 1, int pos = 0) {
    assert(size > 0);
    max = size;
    position = pos;
}

throttle::throttle(const throttle &x) {
    max = x.getmax();
    position = x.getposition();
}

void throttle::shut_off() {
        position = 0;
}

void throttle::shift(int amount) {

        position += amount;

        if (position < 0)
           position = 0;
        else if (position > max)
           position = max;
}

throttle throttle::operator+(const throttle& throt) const {
        int positionsum, maxsum;
        
        positionsum = throt.getposition() + position;
        maxsum = throt.getmax() + max;
        throttle sum(maxsum,positionsum);
        return sum;
}



double throttle::flow() const {
        return position / double(max);
}

int throttle::getposition() const {
    return position;
}

int throttle::getmax() const {
    return max;
}

bool throttle::is_on() const {
        return (flow() > 0);
}



//END THROTTLE CLASS

void pause() {
    char dummy;
    cout << "\nPress any key to continue.\n";
    dummy = getch();
}

void throttletest(throttle& throt) {

    int user_input;

    cout << "I have a throttle with " << throt.getmax() << " positions." << endl
         << "Where would you like to set the throttle? " << endl
         << "Please type a number from 0 to " << throt.getmax() << ": ";

    cin >> user_input;
    throt.shut_off();
    throt.shift(user_input);

    while(throt.is_on()) {

          cout << "The flow is now " << throt.flow() << endl;
          throt.shift(-1);
    }
    cout << "The flow is now off." << endl;
}
    
 

int main() {

        throttle sample1(10,5),sample2(20,10),sample3;
        cout << sample1 << " " << sample2 << " " << sample3;
        pause();
        return EXIT_SUCCESS;
}

