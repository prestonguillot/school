import java.io.*;
import java.util.Vector;

class MemoryAllocation {

   public static void main(String args[]) {
   
      final int SIZE = 262144;
      Vector vector = new Vector();
      int x[] = new int[SIZE], i = 1;

      for(i = 1;; x = new int[SIZE], ++i) {

         vector.addElement(x);
         System.out.println(i);
      }
   }
};