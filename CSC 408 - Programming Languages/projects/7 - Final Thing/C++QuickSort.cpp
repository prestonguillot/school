#include <fstream.h>
#include <stdlib.h>
#include <iomanip.h>

void quickSort(int num[], int lowerBound, int upperBound);
int partition(int num[], int left, int right);

int main() {
    
    const int SIZE = 1000;
    const char dataName[9] = "data.dat";
    const char outName[21] = "C++2.dat";
    int count, array[SIZE];
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
    quickSort(array,0,(SIZE - 1));
    
    for(count = 0; count < SIZE; count++)
         outFile << array[count] << endl;
    outFile.close();
    
    return 0;
}

void quickSort(int num[], int lowerBound, int upperBound) {
     
     int i, j, pivot;
     
     pivot = partition(num,lowerBound,upperBound);
     
     if(lowerBound < pivot)
          quickSort(num,lowerBound,(pivot - 1));
     if(upperBound > pivot)
          quickSort(num,(pivot + 1),upperBound);
     
     return;
}

int partition(int num[], int left, int right) {
    
    int pivot, temp;
    
    pivot = num[left];
    while(left < right) {
    
         while((num[right] >= pivot) && (left < right))
              right--;
         if(right != left) {
              num[left] = num[right];
              left++;
         }
         while((num[left] <= pivot) && (left < right))
              left++;
         if(right != left) {
              num[right] = num[left];
              right--;
         }
    }
    
    num[left] = pivot;
    
    return left;
    	   			  	   			   		   
}