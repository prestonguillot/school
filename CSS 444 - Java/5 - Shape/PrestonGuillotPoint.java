/*Assignment 5 - Shape interface and OOP exercises
 *A class - Point - which implements the Shape interface.
 *J2SE v 1.4.2_05 - Windows 2000 Professional
 *
 *CSS 444 - Preston Guillot
 *November 8, 2004 */
 
 package PrestonGuillotShape;
 
 public class PrestonGuillotPoint extends Object implements PrestonGuillotShape {
 	
 	private int x;
 	private int y;
 	
 	public PrestonGuillotPoint() {
 		
 		x = 0;
 		y = 0;
 		
 	}
 
 	public PrestonGuillotPoint(int xVal, int yVal) {
 		
 		x = xVal;
 		y = yVal;
 		
 	}
 	
 	public void setX(int xVal) {
 		
 		x = xVal;
 		
 	}
 	
 	public void setY(int yVal) {
 		
 		y = yVal;
 		
 	}
 	
 	public int getX() {
 		
 		return x;
 		
 	}
 	
 	public int getY() {
 		
 		return y;
 		
 	}
 	
 	public String toString() {
 		
 		return '[' + Integer.toString(x) + ',' + Integer.toString(y) + ']';
 		
 	}
 	
 	public double area() {
 		
 		return 0.0;
 		
 	}
 	
 	public double volume() {
 		
 		return 0.0;
 		
 	}
 	
 	public String getName() {
 		
 		return "Point";
 		
 	}
 }
 	