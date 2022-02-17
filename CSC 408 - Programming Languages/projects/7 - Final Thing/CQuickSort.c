#include <stdio.h>

void quickSort(int num[], int lowerBound, int upperBound);
int partition(int num[], int left, int right);

int main() {
	
	const int MAX = 20, SIZE = 1000;
	int count, array[SIZE];
	FILE *dataPtr, *outPtr;
	
	if((dataPtr = fopen("data.dat","r")) == NULL) {
	     printf("File data.dat could not be opened. Aborting execution");
	     exit(1);
    }
    
    if((outPtr = fopen("CQuickSort.dat","w")) == NULL) {
         printf("File CQuickSort.dat could not be opened. Aborting execution");
         exit(1);
    }
    
    for(count = 0; count < SIZE; count++)
 	     fscanf(dataPtr,"%d",&array[count]);
    fclose(dataPtr);
    quickSort(array,0,(SIZE - 1));
    
    for(count = 0; count < SIZE; count++)
         fprintf(outPtr,"%d\n",array[count]);
    fclose(outPtr);     
    
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