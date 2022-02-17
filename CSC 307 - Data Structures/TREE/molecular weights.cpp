//Preston Guillot
//CSC 307
//Molecular Weights Program
//11-26-03

#include "tree.h"
#include <string.h>
#include <conio.h>
#include <fstream.h>
#include <ctype.h>
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace TREE_CLASS_CSC307;

void pause() {
    char dummy;
    cout << "\nPress any key to continue.\n";
    dummy = getch();
}


int main() {
    ifstream infile,filein;
    int ch, i;
    char element[3],compound[31],tempchar;
    float weight, tempsum, totalsum;
    tree elements;
    
    infile.open("elements.txt");
    while((ch = infile.peek()) != EOF) {
        infile >> element >> weight;
        elements.insert(element,weight);
    }
    elements.print();
    cout << endl << endl;
    
    filein.open("compounds.txt");
    while((ch = filein.peek()) != EOF) {
        filein >> compound;
        
        i = 0;
        tempsum = 0.0;
        totalsum = 0.0;
        
        while(i < strlen(compound)) {
            element[0] = compound[i];
            element[1] = 0;
            element[2] = 0;
            tempchar = compound[i+1];
            if(islower(tempchar)) {
                i++;
                element[1] = compound[i];
                tempsum += elements.search4weight(element);
                tempchar = compound[i+1];
            }
            else 
                tempsum += elements.search4weight(element);

            if(tempchar == '(') {
                i += 2;
                tempchar = compound[i+1];
                if(isdigit(tempchar)) {  //weight is used instead of creating
                    weight = tempsum;    //another float variable
                    weight *= (compound[i] - 48) * 10;
                    tempsum *= (compound[i+1] - 48);
                    tempsum += weight;
                    weight = 0;              
                }
                else
                    tempsum *= (compound[i] - 48);
                totalsum += tempsum;
                tempsum = 0;
                i++;
            }
            i++;
        }
        totalsum += tempsum;

        cout << compound << setw(40-strlen(compound))<< setiosflags(ios::fixed) 
             << setprecision(3) << totalsum << endl;
    }
    
    pause();
    return EXIT_SUCCESS;
}
