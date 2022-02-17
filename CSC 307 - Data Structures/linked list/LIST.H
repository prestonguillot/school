//Preston Guillot

#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef LIST_CLASS_CSC307_H
#define LIST_CLASS_CSC307_H


namespace LIST_CLASS_CSC307 {
//BEGIN CLASS LIST
//_____________________________________________________________________________

template <class Item>
class list {


//TYPEDEFS

typedef Item basedata;
typedef int sizetype;

private:
       
struct node{
    basedata data;
    node* linky;
};

node *head,*current;

//HELPER FUNCTIONS

   node* getprevnode() {
        node *tempptr = head;
    
        if((tempptr == NULL) || (tempptr->linky == NULL))
            return NULL;
    
        else {
            while(tempptr->linky != current)
                tempptr = tempptr->linky;
        }
        return tempptr;
    }
    
   node* getnewnode() {
      node* tempnode;
      
      tempnode = new node;
      tempnode->data = 0;
      tempnode->linky = NULL;
      return tempnode;
   }
   
   node* getheadptr() {
      return head;
   }
   
public:

    //CONSTRUCTORS
    
    list() {
        head = NULL;
        current = NULL;
    }
    
    list(list<Item> &x) {
    
        if(x.isempty()) {
            head = NULL;
            current = NULL;
        }
        
        else { 
            assign(x);
        }
    }
    
    //CONSTANT MEMBER FUNCTIONS
    
    basedata examine() const {
        if(head == NULL)
            return 0;
            
        else
            return current->data;
    }
    
    sizetype size() const {
        node *tempptr = head;
        sizetype count = 0;
        
        if(tempptr == NULL)
          return 0;
        
        while(tempptr != NULL) {
          count++;
          tempptr = tempptr->linky;
        }
        return count;
    }
    
    sizetype getcurnode() const {
        node *tempptr = head;
        sizetype count = 1;
        
        if(tempptr == NULL)
          return 0;
        
        while(current->data != tempptr->data) {
          count++;
          tempptr = tempptr->linky;
        }
        return count;
    }
    
    int isempty() const {
        if(head == NULL)
            return 1;
            
        else
            return 0;
    }
    
    //MODIFICATION MEMBER FUNCTIONS
    
    void destroy() {
        node *tempptr = head, *delptr;
        while(tempptr != NULL) {
            delptr = tempptr;
            tempptr = tempptr->linky;
            delete delptr;
        }
        head = NULL;
        current = NULL;    
    }
    
    void assign(list<Item> &x) {
        node *tempptr = x.getheadptr();
        destroy();
        
        while(tempptr != NULL) {
            insertafter(tempptr->data);
            tempptr = tempptr->linky;
        }
    }
    
    int first() {
        if(head == NULL)
            return 0;
            
        else {
            current = head;
            return 1;
        }
    }
    
    int last() {
        node *tempptr = head;
        
        if(tempptr == NULL)
            return 0;
            
        else {
            while(tempptr->linky != NULL)
               tempptr = tempptr->linky;
            current = tempptr;
        }
    }
    
    int makecurrent(sizetype pos) {
        node *tempptr = head;
        int count = 1;
        
        if((pos > size()) || (pos < 1))
            return 0;
            
        else {
            while(count != pos) {
                count++;
                tempptr = tempptr->linky;
            }
            current = tempptr;
        }
    }
    
    
    int prev() {
        node *tempptr = head;
        
        if((tempptr == NULL) || (tempptr->linky == NULL))
            return 0;
            
        else {
           current = getprevnode();
           return 1;
        }
    }
    
    int prevx() {
        node *tempptr = head;
        if(tempptr == NULL) 
            return 0;
        
        else {
            current = getprevnode();
            remove();
            return 1;
        }
    }
    
    int next() {
        if((head == NULL) || (current->linky == NULL))
            return 0;
        
        else {
            current = current->linky;
            return 1;
        }
    }
    
    int insertbefore(basedata x) {
        node *newnode = getnewnode(), *prevnode, *tempnode = head;
        newnode->data = x;
        
        if(tempnode == NULL) {
            head = newnode;
            newnode->linky = NULL;
            current = newnode;
            return 1;
        }
        
        else if(tempnode == current) {
            head = newnode;
            newnode->linky = tempnode;
            current = newnode;
            return 1;
        }
        
        else {
            prevnode = getprevnode();
            newnode->linky = prevnode->linky;
            prevnode->linky = newnode;
            current = newnode;
            return 1;
        }
    }
    
    int insertafter(basedata x) {
        node *newnode = getnewnode(), *tempnode = head;
        newnode->data = x;
        
        if(tempnode == NULL) {
            head = newnode;
            newnode->linky = NULL;
            current = newnode;
            return 1;
        }
             
        else {
            newnode->linky = current->linky;
            current->linky = newnode;
            current = newnode;
            return 1;
        }
    }
    
    int remove() {
        node *tempptr = head, *prevptr;
        
        if(tempptr == NULL)
            return 0;
            
        else if(tempptr->linky == NULL) {
            head = NULL;
            current = NULL;
            delete tempptr;
            return 1;
        }
        
        else {
        
           if(current == tempptr) {
              head = current->linky;
              current = current->linky;
              delete tempptr;
              return 1;
           }
      
           else {
              prevptr = getprevnode();
              prevptr->linky = current->linky;
              delete current;
              if(prevptr->linky == NULL)
                  current = prevptr;
              else
                  current = prevptr->linky;
              return 1;
           }
        }
    }
    

    int replace(basedata x) {
        if(head == NULL)
            return 0;
        else {
            current->data = x;
            return 1;
        }
    }
    
    //OVERLOADED OPERATORS
    friend ostream& operator<<(ostream& out, list<Item> &x) {
        if(!x.isempty()) {
            node *tempptr = x.getheadptr();
        
            while(tempptr != NULL) {
                out << tempptr->data << " ";
                tempptr = tempptr->linky;
            }
        
        }
        
        return out;
    }
    
    int operator==(list<Item> &x) {
        if(size() != x.size())
                return 0;
        else {
                node *tempptr = head, *tempptr2 = x.getheadptr();
                while(tempptr != NULL) {
                    if (tempptr->data != tempptr2->data) 
                        return 0;
                    tempptr = tempptr->linky;
                    tempptr2 = tempptr2->linky;
                }
        }         
        return 1;
    }
    
    void operator=(list<Item> &x) {
        assign(x);
    }
    
    list<Item> operator+(list<Item> &x) {
        list<Item> sum;
        node *tempptr = head;
        
        while(tempptr != NULL) {
            sum.insertafter(tempptr->data);
            tempptr = tempptr->linky;
        }
        
        tempptr = x.getheadptr();
        
        while(tempptr != NULL) {
            sum.insertafter(tempptr->data);
            tempptr = tempptr->linky;
        }
             
        return sum;
    }
    
    void operator+=(list<Item> &x) {
        last();
        node *tempptr = x.getheadptr();
        
        while(tempptr != NULL) {
            insertafter(tempptr->data);
            tempptr = tempptr->linky;
        }        
    }
    
};
//END CLASS LIST
//____________________________________________________________________________
}

#endif

