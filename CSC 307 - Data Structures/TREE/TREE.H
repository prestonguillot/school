//Preston Guillot
//CSC 307
//Tree Class for use with Molecular Weights Program
//11-26-03

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string.h>
using namespace std;

#ifndef TREE_CLASS_CSC307_H
#define TREE_CLASS_CSC307_H


namespace TREE_CLASS_CSC307 {

class tree {

private:
       
    struct node {
        char element[3];
        float weight;
        node *left;
        node *right;
    };

    node *root;

//HELPER FUNCTIONS

    node* getnewnode() {
      node* tempnode;
      
      tempnode = new node;
      tempnode->element[0] = 'Z';
      tempnode->weight = 0.0;
      tempnode->left = NULL;
      tempnode->right = NULL;
      return tempnode;
   }
   
   void printtree(const node *ptr, int depth) {
      if(ptr != NULL) {
            printtree(ptr->right,depth + 1);
            std::cout << std::setw(4*depth) << "";
            std::cout << ptr->element[0] << ptr->element[1] << std::endl;
            printtree(ptr->left,depth + 1);
      }
   }

   public:

//CONSTRUCTORS

    tree() {
        root = NULL;
    }
    
    node* insert(char element[], float weight) {
        node *ptr = root, *prev = NULL, *temp;
        
        while(ptr != NULL) {
            prev = ptr;
            if(strcmp(element,ptr->element) > 0)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }
        
        temp = getnewnode();
        strcpy(temp->element,element);
        temp->weight = weight;
        
        if(prev != NULL) {
            if(strcmp(element,prev->element) > 0)
                prev->right = temp;
            else
                prev->left = temp;
        }
        else
            root = temp;
    }
    
    float search4weight(char element[]) {
        node *temp = root;
        
        while((temp != NULL) && (strcmp(element,temp->element) != 0)) {
            if(strcmp(element,temp->element) > 0)
                temp = temp->right;
            else
               temp = temp->left;
        }
        
        if(temp)
            return temp->weight;
        //else
            return 0.0;
    }
    
    void print() {
        printtree(root,0);
    }
            
   
};
//END CLASS TREE
//_____________________________________________________________________________
}

#endif
