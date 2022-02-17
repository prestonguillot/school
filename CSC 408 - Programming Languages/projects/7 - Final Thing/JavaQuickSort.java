import java.io.*;

public class JavaQuickSort extends Object {
	
	public static void main(String args[]) {
	
		final int SIZE = 1000;
		FileInputStream fileName;
		DataInputStream dataFile;
		FileOutputStream outName;
		PrintStream outFile;
		int array[] = new int[SIZE], count;
		
		try{
		
			fileName = new FileInputStream("data.dat");
			dataFile = new DataInputStream(fileName);
			for(count = 0; count < SIZE; count++)	
				array[count] = Integer.parseInt(dataFile.readLine());
				
			quickSort(array,0,(SIZE - 1));
				
			outName = new FileOutputStream("JavaQuickSort.dat");
			outFile = new PrintStream(outName);
			for(count = 0; count < SIZE; count++)
				outFile.println(array[count]);
		}
		
		catch(Exception x) {
			System.out.println(x);
		}
		
	}
	
	private static void quickSort(int num[], int lowerBound, int upperBound) {
     
	     int i, j, pivot;
	     
	     pivot = partition(num,lowerBound,upperBound);
	     
	     if(lowerBound < pivot)
	          quickSort(num,lowerBound,(pivot - 1));
	     if(upperBound > pivot)
	          quickSort(num,(pivot + 1),upperBound);
	     
	     return;
	}

	private static int partition(int num[], int left, int right) {
	    
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
}