//Preston Guillot

#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef LIST_CLASS_CSC307_H
#define LIST_CLASS_CSC307_H


namespace LIST_CLASS_CSC307 {
//BEGIN CLASS LIST
//_____________________________________________________________________________

template <class Item, int MAX>
class list {

public:
    
    //TYPEDEFS

    typedef Item basedata;
    typedef int sizetype;
    static const sizetype CAPACITY = MAX;

    //CONSTRUCTORS
    
    list() {
        curnode = 1;
        arysize = 0;
        int i;
        for (i = 1; i <= CAPACITY; i++)
            data[i] = 0;
    }
    
    list(const list<Item,MAX> &x) {
        int i;
        for (i = 1; i <= x.getarysize(); i++)
            data[i] = x.data[i];
        curnode = x.getcurnode();
        arysize = x.getarysize();
    }
    
    //CONSTANT MEMBER FUNCTIONS
    
    basedata examine() const {
        if(arysize == 0)
            return 0;
        else
            return data[curnode];
    }
    
    sizetype size() const {
        return arysize;
    }
    
    sizetype getcurnode() const {
        return curnode;
    }
    
    sizetype getarysize() const {
        return arysize;
    }
    
    int isfull() const {
        if(arysize == CAPACITY)
            return 1;
        else
            return 0;
    }

    int isempty() const {
        if(arysize == 0)
            return 1;
        else
            return 0;
    }
    
    //MODIFICATION MEMBER FUNCTIONS
    
    void destroy() {
        int i;
        for(i = 1; i <= CAPACITY; i++)
            data[i] = 0;
        arysize = 0;
        curnode = 1;
    }
    
    void assign(const list<Item,MAX> &x) {
        destroy();
        int i;
        for (i = 1; i <= x.getarysize(); i++)
            data[i] = x.data[i];
        curnode = x.getcurnode();
        arysize = x.getarysize();
    }
    
    int first() {
        if(arysize == 0)
            return 0;
        else
            curnode = 1;
            return 1;
    }
    
    int last() {
        if(arysize == 0)
            return 0;
        else
            curnode = arysize;
            return 1;
    }
    
    int makecurrent(sizetype pos) {
        if((pos > arysize) || (pos < 1))
            return 0;
        else
            curnode = pos;
            return 1;
    }
    
    int prev() {
        if(arysize == 0)
            return 0;
        else
            curnode--;
            return 1;
    }
    
    int prevs() {
        if(arysize == 0)
            return 0;
        else
            curnode--;
            arysize--;
            return 1;
    }
    
    int next() {
        if((arysize == 0) || (curnode == arysize))
            return 0;
        else
            curnode++;
            return 1;
    }
    
    int insertbefore(basedata x) {
        if(arysize == 0) {
            data[1] = x;
            arysize++;
            return 1;
        }
        else if(arysize == CAPACITY)
            return 0;
        else {
            int i;
            for(i = arysize; i >= curnode; i--)
                data[i+1] = data[i];
            data[curnode] = x;
            arysize++;
            return 1;
        }
    }
    
    int insertafter(basedata x) {
        if(arysize == 0) {
            data[1] = x;
            arysize++;
            return 1;
        }
        else if(arysize == CAPACITY)
            return 0;
        else {
            int i;
            for (i = arysize; i > curnode; i--)
                data[i+1] = data[i];
            curnode++;
            data[curnode] = x;
            arysize++;
            return 1;
        }
    }
    
    int remove() {
        if(arysize == 0)
            return 0;
        else if(arysize == 1) {
            data[1] = 0;
            arysize = 0;
        }
        else if(curnode == CAPACITY) {
            data[CAPACITY] = 0;
            curnode--;
            arysize--;
        }
        else {
            int i;
            for(i = curnode; i <= arysize; i++)
                data[i] = data[i+1];
            arysize--;
        }
    }
    

    int replace(basedata x) {
        if(arysize == 0)
            return 0;
        else {
            data[curnode] = x;
            return 1;
        }
    }
    
    //OVERLOADED OPERATORS
    friend ostream& operator<<(ostream& out, const list<Item,MAX>& x) {
        int i;
        for (i = 1; i <= x.getarysize(); i++)
                out << x.data[i];
        return out;
    }
    
    int operator==(const list<Item,MAX>& x) {
        if(arysize != x.getarysize())
                return 0;
        else {
                int i;
                for(i = 1; i <= arysize; i++) {
                        if (data[i] != x.data[i])
                            return 0;
                }
        }         
                
        return 1;
    }
    
    void operator=(const list<Item,MAX> &x) {
        destroy();
        int i;
        for (i = 1; i <= x.getarysize(); i++)
                data[i] = x.data[i];
        curnode = x.getcurnode();
        arysize = x.getarysize();
    }
    
    list<Item,MAX> operator+(const list<Item,MAX> &x) {
        list<Item,MAX> sum;
        int i, j;
        for (i = 1; i <= arysize; i++)
                sum.data[i] = data[i];
        i = 1;
        j = arysize + 1;
        while ((j <= CAPACITY) && (i <= x.getarysize())) {
                sum.data[j] = x.data[i];
                j++;
                i++;
        }
        j--;
        sum.arysize = j;
        sum.curnode = j;
        return sum;
    }
    
    void operator+=(const list<Item,MAX>& x) {
        int i = 1, j = arysize + 1;
        while ((j <= CAPACITY) && (i <= x.getarysize())) {
                data[j] = x.data[i];
                j++;
                i++;
        }
        j--;
        arysize = j;
        curnode = j;
    }
   
private:
       
    Item data[CAPACITY + 1];
    sizetype curnode;
    sizetype arysize;
    
};
//END CLASS LIST
//____________________________________________________________________________
}

#endif

