//Preston Guillot

#include "queue.h"
#include <conio.h>
#include <cctype>
#include <cassert>
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace QUEUE_CLASS_CSC307;

//BEGIN CLASS BOOL_SOURCE
//______________________________________________________________________________
class bool_source {
public:

    //CONSTRUCTORS
    bool_source(double p = 0.5);
    //CONSTANT MEMBER FUNCTIONS
    bool query() const;

private:
  
    double probability;
};

bool_source::bool_source(double p) {
    assert(p >= 0);
    assert(p <= 1);
    probability = p;
}

bool bool_source::query() const {
    return (rand() < probability * RAND_MAX);
}

//END CLASS BOOL_SOURCE
//______________________________________________________________________________

//BEGIN CLASS AVERAGER
//______________________________________________________________________________
class averager {
public:
    //CONSTRUCTORS
    averager();
    //MODIFICATION MEMBER FUNCTIONS
    void next_number(double value);
    //CONSTANT MEMBER FUNCTIONS
    std::size_t how_many_numbers() const { return count; }
    double average() const;

private:
    std::size_t count;
    double sum;
};

averager::averager() {
    count = 0;
    sum = 0;
}

void averager::next_number(double value) {
    ++count;
    sum += value;
}

double averager::average() const {
    assert(how_many_numbers() > 0);
    return sum/count;
}
//END CLASS AVERAGER
//______________________________________________________________________________

//BEGIN CLASS WASHER
//______________________________________________________________________________
class washer {

public:
    //CONSTRUCTORS
    washer(int s = 60);
    //MODIFICATION MEMBER FUNCTIONS
    void one_second();
    void start_washing();
    //CONSTANT MEMBER FUNCTIONS
    bool is_busy() const { return (wash_time_left > 0); }

private:
    int seconds_for_wash;
    int wash_time_left;
};

washer::washer(int s) {
    seconds_for_wash = s;
    wash_time_left = 0;
}

void washer::one_second() {
    if (is_busy())
        --wash_time_left;
}

void washer::start_washing() {
    assert(!is_busy());
    wash_time_left = seconds_for_wash;
}
//END CLASS WASHER
//______________________________________________________________________________


void car_wash_simulate(int wash_time, double arrival_prob, int total_time) {
    queue<int,30> arrival_times;
    int next;
    bool_source arrival(arrival_prob);
    washer machine(wash_time);
    averager wait_times;
    int current_second;
    
    cout << "Seconds to wash one car: " << wash_time << endl
         << "Probability of customer arrival in a second: "
         << arrival_prob << endl
         << "Total simulation seconds: " << total_time << endl;
         
    for (current_second = 1; current_second <= total_time; ++current_second) {
        if (arrival.query())
                arrival_times.enqueue(current_second);
        
        if ((!machine.is_busy()) && (!arrival_times.empty())) {
                next = arrival_times.front();
                arrival_times.dequeue();
                wait_times.next_number(current_second - next);
                machine.start_washing();
        }
        
        machine.one_second();
    }
    
    cout << "Customers served: " << wait_times.how_many_numbers() << endl;
    if (wait_times.how_many_numbers() > 0)
        cout << "Average wait: " << wait_times.average() << " sec" << endl;
}
    
    

void pause() {
    char dummy;
    cout << "\nPress any key to continue.\n";
    dummy = getch();
}

int main() {
    car_wash_simulate(240,0.0025,6000);
    pause();
    return EXIT_SUCCESS;
}
