//Preston Guillot

#include "list.h"
#include <iostream>
#include <cstdlib>
using namespace std;
using namespace LIST_CLASS_CSC307;

#ifndef QUEUE_CLASS_CSC307_H
#define QUEUE_CLASS_CSC307_H


namespace QUEUE_CLASS_CSC307 {

//BEGIN CLASS QUEUE
//______________________________________________________________________________

template<class Item, int MAX>
class queue {

public:

    //TYPEDEFS
    typedef Item basedata;
    typedef int sizetype;
    static const sizetype CAPACITY = MAX;
    
    //CONSTRUCTORS
    
    queue() {}
    
    queue(const queue<Item,MAX>& x) {
        thequeue = x.thequeue;
    }
    
    //OVERLOADED OPERATORS
    friend ostream& operator<<(ostream& out, const queue<Item,MAX>& x) {
    out << x.thequeue;
    return out;
    }
    
    void operator=(const queue<Item,MAX>& x) {
        thequeue = x.thequeue;
    }
    
    queue<Item,MAX> operator+(const queue<Item,MAX>& x) {
        queue<Item,MAX> tempqueue;
        tempqueue.thequeue = thequeue + x.thequeue;
        return tempqueue;
    }
    
    void operator+=(const queue<Item,MAX>& x) {
        thequeue += x.thequeue;
    }
    
    int operator==(const queue<Item,MAX>& x) {
        if (thequeue == x.thequeue)
                return 1;
        else
                return 0;
    }

    //CONSTANT MEMBER FUNCTIONS
    
    sizetype size() const {
        return thequeue.size();
    }
    
    int full() const {
        return thequeue.isfull();
    }
    
    int empty() const {
        return thequeue.isempty();
    }
    
    //MODIFICATION MEMBER FUNCTIONS
    
    int enqueue(basedata x) {
        thequeue.last();
        return thequeue.insertafter(x);
    }
    
    int dequeue() {
        thequeue.first();
        return thequeue.remove();
    }
    
    basedata dequeuex() {
        basedata x;
        thequeue.first();
        x = thequeue.examine();
        thequeue.remove();
        return x;
    }

    basedata front() {
        thequeue.first();
        return thequeue.examine();
    }
    
    private:
    
    list<Item,CAPACITY> thequeue;
};
//END CLASS QUEUE
//______________________________________________________________________________
}
#endif
