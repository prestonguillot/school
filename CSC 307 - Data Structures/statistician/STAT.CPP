//Preston Guillot

#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

//BEGIN CLASS 'STATS'
class stats {
    
 public:
    //CONSTRUCTORS
    stats(int setlength, double setsum);
    stats(const stats& x);
    //MODIFICATION MEMBER FUNCTIONS
    void next_number(double x);
    void erase();
    //CONSTANT MEMBER FUNCTIONS
    int getlength() const;
    double getlast() const;
    double getsum() const;       //hehe funny function names make me giggle
    double getavg() const;
    double getsmall() const;
    double getlarge() const;
    //OVERLOADED OPERATORS
    friend ostream& operator<<(ostream& out, const stats& x) {
        out << x.sum << "  " << x.length << "   " << x.last << "  " 
            << x.avg << "  " << x.smallest << "  " << x.largest;
        return out;
    }
    stats operator+(const stats& x) const {
        int lengthsum;
        double sumsum;
        
        lengthsum = x.getlength() + length;
        sumsum = x.getsum() + sum;
        stats temp(lengthsum,sumsum);
        return temp;
    }
    void operator+=(const stats& x) {
        int lengthsum;
        double sumsum;
        
        lengthsum = x.getlength() + length;
        sumsum = x.getsum() + sum;
        length = lengthsum;
        sum = sumsum;
    }
    
    /* when adding stats the smallest WILL be wrong, the largest can be wrong,
       and the last will not be correct unless next_number is called */
 
 private:
    //OBJECT VARIABLES
    int length;
    double last;
    double sum;
    double avg;
    double smallest;
    double largest;
    //PRIVATE MODIFICATION FUNCTIONS
    void computesum(double x);
    void computeavg();
    void computesmall(double x);
    void computelarge(double x);

};

//CONSTRUCTORS
stats::stats(int setlength = 0, double setsum = 0.0) {
    length = setlength;
    sum = setsum;
}

stats::stats(const stats& x) {
    length = x.getlength();
    last = x.getlast();
    sum = x.getsum();
    avg = x.getavg();
    smallest = x.getsmall();
    largest = x.getlarge();
}

//MODIFICATION MEMBER FUNCTIONS
void stats::next_number(double x) {
    length++;
    last = x;
    computesum(x);
    computeavg();
    computesmall(x);
    computelarge(x);
}

void stats::erase() {
    length = 0;
    sum = 0;
}

//CONSTANT MEMBER FUNCTIONS
int stats::getlength() const {
    return length;
}

double stats::getlast() const {
    assert(length > 0);
    return last;
}

double stats::getsum() const {
    return sum;
}

double stats::getavg() const {
    assert(length > 0);
    return avg;
}

double stats::getsmall() const {
    assert(length > 0);
    return smallest;
}

double stats::getlarge() const {
    assert(length > 0);
    return largest;
}

//PRIVATE FUNCTIONS
void stats::computesum(double x) {
    sum += x;
}

void stats::computeavg() {
    avg = sum / double(length);
}

void stats::computesmall(double x) {
    if (length == 1)
        smallest = x;
    else {
        if (x < smallest)
                smallest = x;
    }
}

void stats::computelarge(double x) {
    if (length == 1) 
        largest = x;
    else {
        if (x > largest) 
                largest = x;
    }
}
//END CLASS 'STATS'

void pause() {
    char dummy;
    cout << "\nPress any key to continue.\n";
    dummy = getch();
}

int main() {

    pause();
    
    return EXIT_SUCCESS;
}
