import DiaismResources.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Diaism extends JApplet {
	
	private DiaismBoard playField;
	private DiaismBot opponent;
	private int turn; //Player's move = 1, opponent's move = 2
	private int columnMove, blocksMove;
	
	private JLabel columns, blocks, one, two, three, four, five, six, seven;
	private JTextField columnsField, blocksField, statusField;
	private JButton moveButton;
	private DrawPanel gameBoardArea;
	private Container container;
	
	private Image boardImages[] = new Image[22];
 	private String imageResources[] = { "0.gif", "1.gif", "2.gif", "3.gif", "4.gif", "5.gif",
 	 "6.gif", "7.gif", "8.gif", "9.gif", "10.gif", "11.gif", "12.gif", "13.gif", "14.gif", "15.gif",
 	  "16.gif", "17.gif", "18.gif", "19.gif", "20.gif", "21.gif" };
	
		
	public Diaism() {
	
		opponent = new DiaismBot();
		playField = new DiaismBoard();
		
		container = getContentPane();
		container.setBackground(Color.lightGray);
		container.setLayout(null);
		
		columns = new JLabel("Column Number:");
		addComponent(container,columns,80,425,95,15);
		blocks = new JLabel("Number of Blocks:");
		addComponent(container,blocks,290,425,110,15);
		one = new JLabel("1");
		addComponent(container,one,38,370,7,15);
		two = new JLabel("2");
		addComponent(container,two,107,370,7,15);
		three = new JLabel("3");
		addComponent(container,three,173,370,7,15);
		four = new JLabel("4");
		addComponent(container,four,241,370,7,15);
		five = new JLabel("5");
		addComponent(container,five,307,370,7,15);
		six = new JLabel("6");
		addComponent(container,six,374,370,7,15);
		seven = new JLabel("7");
		addComponent(container,seven,441,370,7,15);
		
		columnsField = new JTextField();
		columnsField.setHorizontalAlignment(JTextField.CENTER);
		addComponent(container,columnsField,68,445,115,23);
		blocksField = new JTextField();
		blocksField.setHorizontalAlignment(JTextField.CENTER);
		addComponent(container,blocksField,280,445,125,23);
		statusField = new JTextField("Input your move.");
		statusField.setHorizontalAlignment(JTextField.CENTER);
		statusField.setEditable(false);
		addComponent(container,statusField,10,520,470,25);
		
		moveButton = new JButton("Move");
		ButtonHandler moveHandler = new ButtonHandler();
		moveButton.addActionListener(moveHandler);
		addComponent(container,moveButton,35,485,420,25);
		
		gameBoardArea = new DrawPanel();
		gameBoardArea.setBackground(Color.black);
		addComponent(container,gameBoardArea,10,10,470,360);
		
		newGame();
	}
	
	public void init() {
		 
		for(int i = 0; i < 22; i++)
			boardImages[i] = getImage(getCodeBase(), "ColumnPics/" + imageResources[i]);
	}
	
	private void addComponent(Container container,Component c,int x,int y,int width,int height) {
		 
 		c.setBounds(x,y,width,height);
 		container.add(c); 
 	}
	
	private void newGame() {
	
		playField.generateRandomBoard();
		turn = 1 + (int) (Math.random() * 2);
		gameBoardArea.draw();
		
		if(turn == 2)
			computerMove();
	}
	
	private void checkGameOver() {
		
		if(playField.gameOver()) {
			
			if(turn == 2)
				JOptionPane.showMessageDialog(null,"Sorry, you lose!","Game Over!",JOptionPane.INFORMATION_MESSAGE);
			else
				JOptionPane.showMessageDialog(null,"Contragulations, you win!","Game Over!",JOptionPane.INFORMATION_MESSAGE);
			newGame();
		}
	}
 	
 	private void computerMove() {
 		
 		columnMove = opponent.makeMove(playField);
		blocksMove = columnMove % 100;
		columnMove /= 100;
		
		while(!playField.makeMove(columnMove,blocksMove)) {
			
			columnMove = opponent.makeMove(playField);
			blocksMove = columnMove % 100;
			columnMove /= 100;
		}
		
		statusField.setText("Computer removes " + blocksMove + " blocks from column " + columnMove + ".");
		gameBoardArea.draw();
		//System.out.println(playField.toString());		
		turn = 1;	
 	}
 	
 	private class DrawPanel extends JPanel{
 		
 		public void paintComponent(Graphics g) {
 			
 			int i;
 			
 			super.paintComponent(g);

 			for(i = 0; i < 7; i++)
 				g.drawImage(boardImages[playField.getBlocks(i+1)],(1 + (i * 67)),0,this);
 		}
 		
 		public void draw() {
 			repaint();
 		}	
 	}
 	
 	private class ButtonHandler implements ActionListener {
 	
 		public void actionPerformed(ActionEvent event) {
 		
	 		if(turn != 1) {} //It's not your turn!
	 		
	 		else {
	 		
	 			try {
	
		 			columnMove = Integer.parseInt(columnsField.getText());	// Will throw an exception if integers
		 			blocksMove = Integer.parseInt(blocksField.getText());	// not entered in text fields.
	 			
		 			if(playField.makeMove(columnMove,blocksMove)) {
		 			
		 				//statusField.setText("Removing " + blocksMove + " blocks from column " + columnMove + ".");
		 				//System.out.println(playField.toString());
		 				turn = 2;
		 				gameBoardArea.draw();
		 				checkGameOver();
		 				//statusField.setText("Computer is thinking...");
		 				computerMove();
		 				checkGameOver();
		 			}
		 			
		 			else {
		 				
		 				statusField.setText("Invalid move!");
		 			}
	 			}
	 			
	 			catch(Exception x) {
	 			
	 				statusField.setText("Invalid Input!");
	 			}
	 		}
	 		
	 		columnsField.setText(null);
		 	blocksField.setText(null);
	 	}
 	}
}