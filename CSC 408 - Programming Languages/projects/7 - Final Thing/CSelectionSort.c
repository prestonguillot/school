#include <stdio.h>

void selectionSort(int num[], int size);

int main() {
	
	const int MAX = 20, SIZE = 1000;
	int count, array[SIZE];
	FILE *dataPtr, *outPtr;
	
	if((dataPtr = fopen("data.dat","r")) == NULL) {
	     printf("File data.dat could not be opened. Aborting execution");
	     exit(1);
    }
    
    if((outPtr = fopen("CSelectionSort.dat","w")) == NULL) {
         printf("File CSelecitonSort.dat could not be opened. Aborting execution");
         exit(1);
    }
    
    for(count = 0; count < SIZE; count++)
 	     fscanf(dataPtr,"%d",&array[count]);
    fclose(dataPtr);
    selectionSort(array,SIZE);
    
    for(count = 0; count < SIZE; count++)
         fprintf(outPtr,"%d\n",array[count]);
    fclose(outPtr);     
    
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