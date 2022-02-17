#include "list.h" // prev() had to be modified to decrement arysize when
                  // called rather than just back up curnode and leave
                  // arysize alone
#include <iostream>
#include <cstdlib>
using namespace std;
using namespace LIST_CLASS_CSC307;

#ifndef STACK_CLASS_CSC307_H
#define STACK_CLASS_CSC307_H


namespace STACK_CLASS_CSC307 {

//BEGIN CLASS STACK
//_____________________________________________________________________________

template<class Item,int MAX>
class stack {

public:

    //TYPEDEFS
    
    typedef Item basedata;
    typedef int sizetype;
    static const sizetype CAPACITY = MAX;
    
    //CONSTRUCTORS
    
    stack(){}
    stack(const stack<Item,MAX>& x) {
        thestack = x.thestack;
    }
    
    //OVERLOADED OPERATORS
    
    friend ostream& operator<<(ostream& out, const stack<Item,MAX>& x) {
    out << x.thestack;
    return out;
    }
    
    void operator=(const stack<Item,MAX>& x) {
        thestack = x.thestack;
    }
    
    stack<Item,MAX> operator+(const stack<Item,MAX>& x) {
        stack<Item,MAX> tempstack;
        tempstack.thestack = thestack + x.thestack;
        return tempstack;
    }
    
    void operator+=(const stack<Item,MAX>& x) {
        thestack += x.thestack;
    }
    
    int operator==(const stack<Item,MAX>& x) {
        if (thestack == x.thestack)
                return 1;
        else
                return 0;
    }
    
    //CONSTANT MEMBER FUNCTIONS
    
    sizetype size() const {
        return thestack.size();
    }
    
    int full() const {
        return thestack.isfull();
    }
    
    int empty() const {
        return thestack.isempty();
    }
    
    //MODIFICATION MEMBER FUNCTIONS
    
    int push(basedata x) {
        thestack.last();
        return thestack.insertafter(x);
    }
    
    int pop() {
        thestack.last();
        return thestack.prevs();
    }
    
    basedata popx() {
        basedata x;
        thestack.last();
        x = thestack.examine();
        thestack.prevs();
        return x;
    }
    
    basedata top() {
        thestack.last();
        return thestack.examine();
    }

    
private:

    list<Item,CAPACITY> thestack;
};
//END CLASS STACK
//_____________________________________________________________________________
}
#endif



