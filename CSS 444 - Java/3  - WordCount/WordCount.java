/*Assignment 3 - WordCount
 *A program to count words in a string and report their usage.
 *J2SE v 1.4.2_05 - Windows 2000 Professional
 *CSS 444 - Preston Guillot
 *October 13, 2004 */

 /*Known Bugs:
  *
  *1. 	If the string contains more than fifty unique words the array will overflow
  *		producing an error. It would be best to use a dynamically allocated data
  *		structure such as a linked list, or a resizeable array, but I'm unsure how
  *		to create such an object.
  *
  *2.	Occurances will not be properly lined up in output. I'm unsure how to format output
  *		using the drawString() method other than by simply concatenating spaces to the string.*/

  //Java Packages
 import javax.swing.*;		//import package javax.swing
 import java.awt.Graphics;	//import class Graphics
 import java.util.StringTokenizer; //import class StringTokenizer

 public class WordCount extends JApplet {

 		//declare globals
 		int countarray[] = new int[50], wordcount, index = 0;
 		String userinput, wordsarray[] = new String[50];

 		public void init() { //initialize applet by obtaining values from user

 			//get user input from dialog box
 			userinput = JOptionPane.showInputDialog("Enter the string.");

 			//break the user input into tokens and count the tokens
 			StringTokenizer wordtokens = new StringTokenizer(userinput);
 			wordcount = wordtokens.countTokens();

 			//label for loop to count word usage
 			loop:

 				while(wordtokens.hasMoreTokens()) {   //continue until out of tokens

 					String tempstring = wordtokens.nextToken(); //grab one token

 					for(int i = 0; i < index; i++) { //continue until at the end of the word array

 						if (tempstring.equals(wordsarray[i])) { //is the current token the same as the current string at the array position?

 							countarray[i]++;	//if so bump that word's counter
 							continue loop;		//and continue to the next token
 						}
 					}

 					wordsarray[index] = tempstring; //if not assign it to the next array position
 					countarray[index] = 1;			//and set its count to 1
 					index++;						//then bump the index of the next writable array position
 				}//end of loop:

 			//after counting occurances, sort according from high to low by number of occurances
 			wordcountsort();
 		}//end method init


 		public void paint(Graphics g) {		//draw on applet's background

 			super.paint(g); 	//call superclass version of method paint

 			g.drawString("Number of words              " + wordcount, 0, 10); //
 			g.drawString("Words                   Occurances", 0, 30);		  // output wordcount and headings
 			g.drawString("----------------------------------------", 0, 40);  //


 			for(int i = 0, x = 5; (i < 5) && (i < index); i++, x++) //loop five times, unless the array has fewer than five elements
 				g.drawString(wordsarray[i] + "                             " + countarray[i],0,x*10); //output the string and its number of occurances
 		}//end method paint

 		public void wordcountsort() { //a simple selection sort routine specific to the WordCount class

 			//declare locals
 			int maximum, maxindex, temp;
 			String tempstr, maxstr="";

 			for(int i = 0; i < (index -  1); i++) {

 				maximum = countarray[i]; //assume maximum is first array element
 				maxindex = i;			 //index of maximum element

 				for(int j = i + 1; j < index; j++) {

 					if(countarray[j] > maximum) {	//if we've located a higher value

 						maximum = countarray[j];    //
 						maxstr = wordsarray[j];		// caputre it
 						maxindex = j;				//
 					}
 				}

 				if(maximum > countarray[i]) {		//check for new maximum
 													//if there is one, swap values
 					temp = countarray[i];
 					tempstr = wordsarray[i];
 					countarray[i] = maximum;
 					wordsarray[i] = maxstr;
 					countarray[maxindex] = temp;
 					wordsarray[maxindex] = tempstr;
 				}
 			}
 		}//end method wordcountsort




 }//end class WordCount

