/*Assignment 5 - Shape interface and OOP exercises
 *A class - Rectangle - which extends the Point class
 *J2SE v 1.4.2_05 - Windows 2000 Professional
 *
 *CSS 444 - Preston Guillot
 *November 8, 2004 */
 
 package PrestonGuillotShape;
 
 public class PrestonGuillotRectangle extends PrestonGuillotPoint {
 	
 	private int length;
 	private int width;
 	
 	public PrestonGuillotRectangle() {
 		
 		setX(0);
 		setY(0);
 		length = 0;
 		width = 0;
 		
 	}
 	
 	public PrestonGuillotRectangle(int lengthVal, int widthVal) {
 		
 		setX(0);
 		setY(0);
 		length = lengthVal;
 		width = widthVal;
 		
 	}
 	
 	public PrestonGuillotRectangle(int lengthVal, int widthVal, int xVal, int yVal) {
 		
 		setX(xVal);
 		setY(yVal);
 		length = lengthVal;
 		width = widthVal;
 		
 	}
 	
 	public void setLength(int lengthVal) {
 		
 		length = lengthVal;
 		
 	}
 	
 	public void setWidth(int widthVal) {
 		
 		width = widthVal;
 		
 	}
 	
 	public int getLength() {
 		
 		return length;
 		
 	}
 	
 	public int getWidth() {
 		
 		return width;
 		
 	}
 	
 	public String toString() {
 		
 		return super.toString() + " Length: " + Integer.toString(length) + " Width: " + Integer.toString(width);
 		
 	}
 	
 	public double area() {
 		
 		return length * width;
 		
 	}
 	
 	public String getName() {
 		
 		return "Rectangle";
 		
 	}
 }
 