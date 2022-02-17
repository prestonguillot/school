/* Preston Guillot
 * March 14, 2005
 * CSC 412*/

/* Assignment 10
 * Write a program which, when given a unique 8 queens solution will produce
 * all other variations of this solution */
 
/* Future improvements:
 * - Define board as an object.
 * - Generalize mirror() and rotate() to work with any board configuration.
 * - Improve getboard() to check for diagonal conflicts instead of simply
 *   vertical and horizontal.
 * - Over load equals operator to easily test for equality of
 *   board states.
 */

#include <iostream.h>
#include <conio.h>

const int SIZE = 8;

void pause() {
    
    char dummy;
    
    cout << "\nPress any key to continue.\n";
    dummy = getch();
}

void rotate(int input[], int output[]) {
     
     int out, in;
     
     for(out = 0; out < SIZE; out++) {
           for(in = 0; in < SIZE; in++) {
                 if(input[in] == out) {
                      output[out] = (SIZE - 1) - in;
                      break;
                 }
           }
     }
     
}

void mirror(int input[], int output[]) {

     int out, in;
     
     for(out = 0; out < SIZE; out++) {
             for(in = 0; in < SIZE; in++) {
                    if(input[in] == out) {
                       output[(SIZE - 1) - in] = out;
                       break;
                    }
             }
     }
}

void getboard(int board[]) {
    
     int i, input, taken[SIZE];
     
     for(i = 0; i < SIZE; i++)
           taken[i] = 0;
           
     for(i = 0; i < SIZE; i++) {
           
           cout << "Enter queen's position (0-7) on column " << i << ": ";
           cin >> input;
           
           while((input < 0) || (input > 7) || (taken[input])) {
                if((input < 0) || (input > 7)) {
                    cout << "Invalid input, try again: ";
                    cin >> input;
                }
                else {
                    cout << "There is already a queen on row " << input << ", try again: ";
                    cin >> input;
                }
           }
           
           board[i] = input;
           taken[input] = 1;
     }
}

void showboard(int board[]) {
     
     char output[SIZE][SIZE];
     int i,j;
     
     for(i = 0;  i < SIZE; i++)
           for (j = 0; j < SIZE; j++)
               output[i][j] = '-';
     
     for(i = 0; i < SIZE; i++)
           output[board[i]][i] = 'Q';
     
     for(i = 0;  i < SIZE; i++) {
           for (j = 0; j < SIZE; j++) 
               cout << output[i][j] << " ";
           cout << endl << endl;
     }
}

int main() {
    
    int board[SIZE], one[SIZE], two[SIZE];
    
    getboard(board);
    cout << endl << "Original Board:" << endl;
    showboard(board);
    cout << endl;
    
    mirror(board,one);
    cout << "Mirrored:" << endl;
    showboard(one);
    cout << endl;
    
    rotate(board,one);
    cout << "Rotated 90 degrees clockwise:" << endl;
    showboard(one);
    cout << endl;
    
    mirror(one,two);
    cout << "Rotated 90 degrees clockwise and mirrored:" << endl;
    showboard(two);
    cout << endl;
    
    rotate(one,two);
    cout << "Rotated 180 degrees:" << endl;
    showboard(two);
    cout << endl;
    
    mirror(two,one);
    cout << "Rotated 180 degrees and mirrored:" << endl;
    showboard(one);
    cout << endl;
    
    rotate(two, one);
    cout << "Rotated 90 degrees counter-clockwise:" << endl;
    showboard(one);
    cout << endl;
    
    mirror(one,two);
    cout << "Rotated 90 degrees counter-clockwise and mirrored:" << endl;
    showboard(two);
    cout << endl;

    pause();
}
