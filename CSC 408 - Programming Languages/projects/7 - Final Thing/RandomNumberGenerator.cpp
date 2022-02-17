#include <fstream.h>
#include <stdlib.h>
#include <iomanip.h>
#include <time.h>

int main() {
    
    int count;
    const int MAX = 20, SIZE = 1000;
    const char fileName[MAX] = "data.dat";
    ofstream outFile;
    
    //cout << "Generate how many numbers?: ";
    //cin >> SIZE;
    outFile.open(fileName);
    
    if(outFile.fail()){
    
         cout << "Coldn't open file " << fileName << endl;
         exit(1);
    }
    
    srand(time(NULL));
    
    for(count = 0; count < SIZE; count++)
         outFile << rand() % 101 << endl;
         
    outFile.close();
    
    return 0;
}