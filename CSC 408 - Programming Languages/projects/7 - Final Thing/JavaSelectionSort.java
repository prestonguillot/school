import java.io.*;

public class JavaSelectionSort extends Object {
	
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
				
			selectionSort(array,SIZE);	
				
			outName = new FileOutputStream("JavaSelectionSort.dat");
			outFile = new PrintStream(outName);
			for(count = 0; count < SIZE; count++)
				outFile.println(array[count]);
		}
		
		catch(Exception x) {
			System.out.println(x);
		}
		
	}
	
	private static void selectionSort(int num[], int size) {
     
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
   
	
}