#include <fstream.h>
#include <stdlib.h>
#include <iomanip.h>

void selectionSort(int num[], int size);

int main() {
    
    const int SIZE = 1000;
    const char dataName[9] = "data.dat";
    const char outName[21] = "C++SelectionSort.dat";
    int count, read, array[SIZE];
    ifstream dataFile;
    ofstream outFile;
    
    dataFile.open(dataName);
    if(dataFile.fail()) {
         cout << "File " << dataName << " not opened. Aborting execution." << endl;
         exit(1);
    }
    
    outFile.open(outName);
    if(outFile.fail()) {
         cout << "File " << outName << " not opened. Aborting execution." << endl;
         exit(1);
    }
    
    for(count = 0; count < SIZE; count++)
         dataFile >> array[count];          
    dataFile.close();
    selectionSort(array,SIZE);
    
    for(count = 0; count < SIZE; count++)
         outFile << array[count] << endl;
    outFile.close();
    
    return 0;
}

void selectionSort(int num[], int size) {
     
     int i, j, min, minidx, temp;
     
     for(i = 0; i < (size - 1); i++) {
           
           min = num[i];
           minidx = i;
           for(j = i + 1; j < size; j++) {      
                 if(num[j] < min) {
                      min = num[j];
                      minidx = j;
                 }
           }
           
           if(min < num[i]) {
                  temp = num[i];
                  num[i] = min;
                  num[minidx] = temp;
           }
     }
}