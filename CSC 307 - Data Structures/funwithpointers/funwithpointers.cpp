//Preston Guillot
//Works with any square array.

#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

void pause() {
    char dummy;
    cout << "\nPress any key to continue.\n";
    dummy = getch();
}

int main() {
    const int ARYSIZE = 100;
    int ary[ARYSIZE][ARYSIZE],x,y,count = 1;
    int *ptr;
    
    for(x = 0; x < ARYSIZE; x++) {
        for(y = 0; y < ARYSIZE; y++,count++)
            ary[x][y] = count;
    }
    
    for(ptr = ary[0], count = 0; ptr < &ary[1][0]; ptr++)
        count += *ptr;
    cout << "Top Row Sum: " << count << endl;
        
    for(ptr = &ary[ARYSIZE-1][0], count = 0; ptr <= &ary[ARYSIZE-1][ARYSIZE-1]; 
        ptr++)
        count += *ptr;
    cout << "Bottom Row Sum: " << count << endl;
    
    for(ptr = ary[0], count = 0; ptr <= &ary[ARYSIZE-1][0]; ptr += ARYSIZE)
        count += *ptr;
    cout << "Left Column Sum: " << count << endl;
    
    for(ptr = &ary[0][ARYSIZE-1], count = 0; ptr <= &ary[ARYSIZE-1][ARYSIZE-1]; 
        ptr += ARYSIZE)
        count += *ptr;
    cout << "Right Column Sum: " << count << endl;

    for(ptr = ary[0], count = 0; ptr <= &ary[ARYSIZE-1][ARYSIZE-1]; ptr += 
        ARYSIZE+1)
        count += *ptr;
    cout << "Diagonal Sum: " << count << endl;
    
    pause();
}
