package DiaismResources;


public class DiaismBoard extends Object {
	
	//private field declarations
	
	private int boardSize, minBlocks, maxBlocks;
	private int theBoard[];
	
	//constructor definitions
	
	//default constructor
	public DiaismBoard() {
		
		boardSize = 7;
		minBlocks = 4;
		maxBlocks = 21;
		theBoard = new int[boardSize];
		generateRandomBoard();
	}
	
	//constructor defines size of board, minimum/maximum blocks per column
	public DiaismBoard(int size, int min, int max) {
		

		boardSize = size;
		minBlocks = min;
		maxBlocks = max;
		
		if(!boardCheck()) { //this should throw an exception, I am lazy
		
			boardSize = 7;
			minBlocks = 4;
			maxBlocks = 21;
		}
		
		theBoard = new int[boardSize];
		generateRandomBoard();
	}
	
	//returns false if there aren't enough columns, else true
	private boolean boardCheck() {
	
		if(boardSize < (maxBlocks - minBlocks))
			return false;
		return true;
	}

	//randomly fills each column of board with a unique value between
	//minblocks and maxblocks
	public boolean generateRandomBoard() {
		
		boolean used[] = new boolean[maxBlocks-minBlocks+1];
		int i, randomValue;
		
		for(i = 0; i < boardSize; i++)
			used[i] = false;
			
		for(i = 0; i < boardSize; i++) {
		
			do 
				randomValue = minBlocks  + (int) (Math.random() * (maxBlocks-minBlocks+1));
					
			while(used[randomValue-minBlocks]);
			
			theBoard[i] = randomValue;
			used[randomValue-minBlocks] = true;	
		}
		
		return true;
	}

	//removes blocks from a column
	public boolean makeMove(int column, int numBlocks) {
		
		if((column < 1) || (column > boardSize))
			
			return false;
		
		else if((numBlocks > theBoard[column-1]) || (numBlocks < 1))
			
			return false;
		
		else {
			
			theBoard[column-1] -= numBlocks;
			return true;
		}
	}
	
	//returns true is board is empty, otherwise false
	public boolean gameOver() {
		
		int i;
		
		for(i = 0; i < boardSize; i++) {
			
			if(theBoard[i] > 0)
				return false;
		}
		
		return true;
	}
	
	//generates string representation of theBoard
	public String toString() {
		
		String outputString = new String();
		int i;
		
		outputString = "[";
		for(i = 0; i < boardSize; i++) {
			
			outputString += Integer.toString(theBoard[i]) + " ";
		}
		outputString += "]";
				
		return outputString;
	}
	
	//getter functions
	//returns number of blocks on a particular column
	public int getBlocks(int column) {
	
		if((column < 1) || (column > boardSize)) 
		
			return -1;		//also should throw an exception
		
		else
			
			return theBoard[column-1];
	}
	
	//returns number of columns
	public int getColumns() {
	
		return boardSize;	
	}
}