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

void move(int n, char source, char destination, char spare) {
    if (n <= 1)
        cout << "Move the top disk from " << source << " to " << destination << endl;
    else {
        move(n-1, source, spare, destination);
        move(1, source, destination, spare);
        move(n-1, spare, destination, source);
    }
}

int main() {
    const char PEG1 = 'A', PEG2 = 'B', PEG3 = 'C';
    int numdisks;
    
    cout << "This program solves the Hanoi Towers puzzle.\n\n";
    
    cout << "Enter the number of disks: ";
    cin >> numdisks;
    cout << endl;
    
    move(numdisks, PEG1, PEG3, PEG2);
    pause();
}
