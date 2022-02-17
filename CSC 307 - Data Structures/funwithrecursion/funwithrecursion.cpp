//Preston Guillot

#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

void pause() {
    char dummy;
    cout << "\nPress any key to continue.\n";
    dummy = getch();
}

unsigned numdigits(unsigned x) {
    if (x < 10)
        return 1;
    return 1 + numdigits(x / 10);
}

void printreverse(int x) {
    if (x < 10) {
        cout << x;
        return;
    }
    cout << x % 10;
    printreverse(x / 10);
}

void reversearray(int ary[], int first, int last) {
    int temp;
    char b;
    if(first >= last)
        return;
    temp = ary[first];
    ary[first] = ary[last];
    ary[last] = temp;
    reversearray(ary,++first,--last);
}

int sumarray(int *ary, int size) {
    if(size == 0)
        return 0;
    return *ary + sumarray(++ary,--size);
}

int location(int ary[], int first, int last, int elm) {
    if(ary[first] == elm)
        return first;
    if(first == last)
        return 0;
    return location(ary,++first,last,elm);
}

int GCD(int a,int b) {
    int r;
    if(a < 0)
        return GCD(-a,b);
    if(b < 0)
        return GCD(a,-b);  
    r = a % b;
    if(r == 0)
        return b;
    return GCD(b,r);
}

int main() {
    int ary[35];
    for(int i = 0; i < 35; i++)
        ary[i] = i;
    
    cout << "numdigits(12345):   " << numdigits(12345) << endl
         << "numdigits(1):       " << numdigits(1)     << endl << endl;
         
    cout << "printreverse(12345):"; printreverse(12345);
    cout << endl << "printreverse(1):    "; printreverse(1); cout << endl;
    
    
    cout << endl << "ary = ";
    for(int i = 0; i < 35; i++)
        cout << ary[i] << " ";
        
    cout << endl << "\nsumarray(ary,35):      " << sumarray(ary,35) << endl
         << "location(ary,0,34,23): " << location(ary,0,34,23) << endl
         << "location(ary,0,34,33): " << location(ary,0,34,33) << endl << endl;
    
    reversearray(ary,0,34);
    cout << "After reversearray(ary,0,34) ary = ";
    for(int i = 0; i < 35; i++)
        cout << ary[i] << " ";
    
    cout << endl << endl << "GCD(1260,198):  " << GCD(1260,198) << endl
         << "GCD(13877,643): " << GCD(13877,643) << endl;
    
    
    
    
    pause();
    return EXIT_SUCCESS;
}
