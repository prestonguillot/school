/*Assignment 6 - Simple GUI design using Swing components
 *A class - ShapesGUI - to demonstrate functional use of Swing components
 *J2SE v 1.4.2_05 - Windows 2000 Professional
 *
 *CSS 444 - Preston Guillot
 *November 22, 2004 */

//Java Packages 
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

//Begin Class ShapesGUI
//A Class to Demonstrate Functional Use of Swing Components
public class ShapesGUI extends JApplet {
	
	//Define Private Variables
	private final static int SQUARE = 1, CIRCLE = 2, ELIPSE = 3, SMALL =1, MEDIUM = 2, LARGE = 3;
	private int shapeChoice, sizeChoice = SMALL, xChoice, yChoice;
	private boolean fillChoice = false; 
	private JLabel shapes,size,xcoord,ycoord;
	private JRadioButton squareButton, circleButton, elipseButton;
	private ButtonGroup radioGroup;
	private JTextField xfield,yfield,statusField;
	private JComboBox sizeBox;
	private String sizes[] = { "Small", "Medium", "Large" };
	private int sizeValues[] = { SMALL, MEDIUM, LARGE };
	private JCheckBox fillBox;
	private JButton drawButton;
	private DrawPanel shapePanel;
	private Container container;
	
 //Begin Constructor Definitions
	
	//Begin Default Constructor Definition
	//Sets Up And Initializes the GUI Components
	public ShapesGUI() {
		
		//Set Look of GUI Application to Mimic Windows XP Widgets
		try {
			
        	UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
        	
    	} catch (Exception e) { }
				
		//Define Container Canvas for GUI Components		
		container = getContentPane();				//Use Applet Background as Container
		container.setBackground(Color.lightGray);
		container.setLayout(null);					//Remove Default Layout 				
													//Items Will Be Added With Absolute Coordinates
										
		//Begin Adding JLabel Components
		shapes = new JLabel("Shapes:");				//Add JLabel
		addComponent(container,shapes,25,25,55,15);	//Draw JLabel on Canvas
		xcoord = new JLabel("X Coordinate:");
		addComponent(container,xcoord,25,100,80,15);
		ycoord = new JLabel("Y Coordinate:");
		addComponent(container,ycoord,25,120,80,15);
		size = new JLabel("Size:");
		addComponent(container,size,25,150,50,15);
		//End Adding JLabel Components
		
		//Begin Adding JRadioButton Components
		squareButton = new JRadioButton("Square",false);				//Add JRadioButton
		squareButton.setBackground(Color.lightGray);
		squareButton.addItemListener(new RadioButtonHandler(SQUARE));	//Register Events for JRadioButton
		addComponent(container,squareButton,25,45,60,15);				//Draw JRadioButton on Canvas
		circleButton = new JRadioButton("Circle",false);
		circleButton.setBackground(Color.lightGray);
		circleButton.addItemListener(new RadioButtonHandler(CIRCLE));
		addComponent(container,circleButton,90,45,55,15);
		elipseButton = new JRadioButton("Elipse",false);
		elipseButton.setBackground(Color.lightGray);
		elipseButton.addItemListener(new RadioButtonHandler(ELIPSE));
		addComponent(container,elipseButton,145,45,55,15);
		radioGroup = new ButtonGroup();
		radioGroup.add(squareButton);									//Create Logical Grouping of JRadioButtons
		radioGroup.add(circleButton);
		radioGroup.add(elipseButton);
		//End Adding JRadioButton Components
		
		//Beging Adding JTextField Components
		xfield = new JTextField();								//Add JTextField
		addComponent(container,xfield,115,100,85,18);			//Draw JTextField on Canvas
		yfield = new JTextField();
		addComponent(container,yfield,115,120,85,18);
		statusField = new JTextField("                                                      MESSAGE DISPLAY");
		statusField.setEditable(false);
		addComponent(container,statusField,10,229,430,20);
		//End Adding JTextField Components
		
		//Begin Adding JComboBox Components
		sizeBox = new JComboBox(sizes);							//Add JComboBox
		ComboBoxHandler sizeHandler = new ComboBoxHandler();	//Create Event Handler for JComboBox
		sizeBox.addItemListener(sizeHandler);					//Register Events for JComboBox						
		addComponent(container,sizeBox,55,150,85,18);			//Draw JComboBox on Canvas
		//End Adding JComboBox Components
		
		//Begin Adding JCheckBox Components
		fillBox = new JCheckBox("Fill");						//Add JCheckBox
		fillBox.setBackground(Color.lightGray);	
		CheckBoxHandler fillHandler = new CheckBoxHandler();	//Create Event Handler for JCheckBox
		fillBox.addItemListener(fillHandler);					//Register Events for JCheckBox
		addComponent(container,fillBox,150,150,40,18);			//Draw JCheckBox on Canvas
		//End Adding JCheckBox Components
		
		//Begin Adding JButton Components
		drawButton = new JButton("Draw");						//Add JButton
		ButtonHandler drawHandler = new ButtonHandler();		//Create Event Handler for JButton
		drawButton.addActionListener(drawHandler);				//Register Events for JButton
		addComponent(container,drawButton,25,200,180,25);		//Draw JButton on Canvas
		//End Adding JButton Components
		
		//Begin Adding DrawPanel Components
		shapePanel = new DrawPanel();							//Add DrawPanel
		shapePanel.setBackground(Color.white);					
		addComponent(container,shapePanel,210,25,228,200);		//Draw DrawPanel on Canvas
		//End Adding DrawPanel Components
		
		setSize(450,250);
		setVisible(true);
		
	}
	//End Default Constructor Definition
	
 //End Constructor Definitions
	
 //Begin Private Method Definitions
 
	//Begin addComponent method Definiton
	//Adds a Component to the Canvas Using Absolute Coordinates
	private void addComponent(Container container,Component c,int x,int y,int width,int height) {
		 
 		c.setBounds(x,y,width,height);
 		container.add(c); 
 		
 	}
 	//End addComponent method Defintion
 	
 //End Private Method Definitions	
 
 //Begin Private Class Definitions
 
	//Begin Private Class DrawPanel
	//A Class to Define the Drawable Area of the ShapesGUI Class
 	private class DrawPanel extends JPanel {
 		
 		//Define Private Variables
		private int shape, size, x, y;
		private boolean fill;
		
	 //Begin Public Method Definitions
	 	
	 	//Begin paintComponent Method Definition
	 	//Draws the Shape Defined by User Choices
		public void paintComponent(Graphics g) {
			
			super.paintComponent(g);
			
			if(shape == SQUARE) {
				
				if(fill)
					g.fillRect(x,y,size*50,size*50);
				else
					g.drawRect(x,y,size*50,size*50);
					
			}				
			
			else if(shape == CIRCLE) {
				
				if(fill)
					g.fillOval(x,y,size*50,size*50);
				else
					g.drawOval(x,y,size*50,size*50);
					
			}				
			
			else if(shape == ELIPSE) {
				
				if(fill)
					g.fillOval(x,y,size*50,size*30);
				else
					g.drawOval(x,y,size*50,size*30);
					
			}				
		}
		//End paintComponent Method Definition
		
		//Begin draw Method Definition
		//Pass User Choices and Implicitly Calls paintComponent
		public void draw(int shapeChoice, int sizeChoice, int xChoice, int yChoice, boolean fillChoice) {
		
			shape = shapeChoice;
			size = sizeChoice;
			x = xChoice;
			y = yChoice;
			fill = fillChoice;
			repaint();
		
		}
		//End draw Methoid Definition
		
	 //End Public Method Definitions
	
	}
	//End Private Class DrawPanel
	
 	//Begin Private Class ComboBoxHandler
 	//Defines How JComboBox Events are Handled
 	private class ComboBoxHandler implements ItemListener {
 		
 		public void itemStateChanged(ItemEvent event) {
 			
			if(event.getStateChange() == ItemEvent.SELECTED) 
				sizeChoice = sizeValues[sizeBox.getSelectedIndex()]; 			
 			
 		}
 		
 	}	
 	//End Private Class ComboBoxHandler
 	
 	//Begin Private Class RadioButtonHandler	
 	//Defines How JRadioButton Events are Handled
 	private class RadioButtonHandler implements ItemListener {
 		
 		private int x;
 		
 		public RadioButtonHandler(int y) {
 			
 			x = y;
 			
 		}
 		
 		public void itemStateChanged(ItemEvent event) {
 			
 			shapeChoice = x;
 			
 		}
 	}
	//End Private Class RadioButtonHandler
	
	//Begin Private Class CheckBoxHandler
	//Defines How JCheckBox Events are Handled
	private class CheckBoxHandler implements ItemListener {
		
		public void itemStateChanged(ItemEvent event) {
			
			fillChoice = !fillChoice;
			
		}
	}
	//End Private Class CheckBoxHandler
	
	//Begin Private Class ButtonHandler
	//Defines How JButton Events are Handled
	private class ButtonHandler implements ActionListener {
		
		public void actionPerformed(ActionEvent event) {
			
			xChoice = Integer.parseInt(xfield.getText());
			yChoice = Integer.parseInt(yfield.getText());
			
			if( (xChoice < 1) || (yChoice < 1) || (xChoice >= 228 ) || (yChoice >= 200))
				
				statusField.setText("                                    COORDINATES OUT OF BOUNDS");
		
			else {
				
				if(shapeChoice == SQUARE)

					statusField.setText("                                                   DRAWING SQUARE");
				
				else if(shapeChoice == CIRCLE)
					
					statusField.setText("                                                   DRAWING CIRCLE");
				
				else if(shapeChoice == ELIPSE)
					
					statusField.setText("                                                   DRAWING ELIPSE");
				
				shapePanel.draw(shapeChoice,sizeChoice,xChoice,yChoice,fillChoice);
			}	
		}
	}
	//End Private Class ButtonHandler
	
 //End Private Class Definitions

}
//EndClass ShapesGUI