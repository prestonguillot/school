//Preston Guillot

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <iomanip.h>

using namespace std;

void pause() {
    char dummy;
    cout << "\nPress any key to continue.\n";
    dummy = getch();
}

int lcf(int n, int m) {
    if(m == 0)
        return n;
    return lcf(m, (n % m));
}

int partition(int n, int m) {
    if(((n == 1) && (m >= 1)) || (m == 0) || (m ==1))
        return 1;
    if(m < 0)
        return 0;
    return partition((n - 1),m) + partition(n,(m - n));
}

void triangle(char start, char end) { //it prints the last line anyway....
        
    if (start == end) {
        cout << start; 
        return;
    }
    
    cout << start;
    triangle((start + 1), end);
    cout << start;

}
    
int main() {
    
    cout << "lcf(36,90): " << lcf(36,90)
         << endl << "lcf(243,1577): " << lcf(243,1577) << endl;
         
    cout << endl << "      1   2   3   4   5   6   7  8   9   10  11  12  13  14  15  16  17  18  19  20" << endl
                 << "____________________________________________________________________________________" << endl;
    for(int i = 1; i <= 20; i++) {
        cout << setw(2) << i << "|";
        for(int j = 1; j <= 20; j++)
            cout << setw(4) << partition(i,j);
        cout << endl;
    }
    
    cout << endl;
    triangle('a','m');
    
    pause();
    return EXIT_SUCCESS;
}


