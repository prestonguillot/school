/*Assignment 5 - Shape interface and OOP exercises
 *A class - RectangularSolid - which extends the Rectangle class
 *J2SE v 1.4.2_05 - Windows 2000 Professional
 *
 *CSS 444 - Preston Guillot
 *November 8, 2004 */
 
 package PrestonGuillotShape;
 
 public class PrestonGuillotRectangularSolid extends PrestonGuillotRectangle {
 	
 	private int z;
 	private int height;
 	
 	public PrestonGuillotRectangularSolid() {
 		
 		setX(0);
 		setY(0);
 		z = 0;
 		setLength(0);
 		setWidth(0);
 		height = 0;
 			
 	}
 	
 	public PrestonGuillotRectangularSolid(int lengthVal, int widthVal, int heightVal) {
 		
 		setX(0);
 		setY(0);
 		z = 0;
 		setLength(lengthVal);
 		setWidth(widthVal);
 		height = heightVal;
 		
 	}
 	
 	public PrestonGuillotRectangularSolid(int lengthVal, int widthVal, int heightVal, int xVal, int yVal, int zVal) {
 		
 		setX(xVal);
 		setY(yVal);
 		z = zVal;
 		setLength(lengthVal);
 		setWidth(widthVal);
 		height = heightVal;
 		
 	}
 	
 	public void setZ(int zVal) {
 		
 		z = zVal;
 		
 	}
 	
 	public void setHeight(int heightVal) {
 		
 		height = heightVal;
 		
 	}
 	
 	public int getZ() {
 		
 		return z;
 		
 	}
 	
 	public int getHeight() {
 		
 		return height;
 		
 	}
 	
 	public String toString() {
 		
 		return '[' + Integer.toString(getX()) + ',' + Integer.toString(getY()) + ',' + Integer.toString(z) + ']' + " Length: " + Integer.toString(getLength()) + " Width: " + Integer.toString(getWidth()) + " Height: " + Integer.toString(height);
 		
 	}
 	
 	public double area() {
 		
 		return  2.0 * getLength() * getWidth() + 2.0 * getLength() * height + 2.0 * getWidth() * height;
 		
 	}
 	
 	public double volume() {
 		
 		return getLength() * getWidth() * height;
 		
 	}
 	
 	public String getName() {
 		
 		return "Rectangular Solid";
 		
 	}
 }
 