package DiaismResources;

public class DiaismBot extends Object {

	//public DiaismBot() {}
	
	
	/*Returns a single integer which represents both the column number and
	/*number of blocks to be moved.*/
	public int makeMove(DiaismBoard theBoard) {
	
		int playable = getPlayable(theBoard);
		int column, blocks, move, playableOne, playableTwo, playableThree, i;
		
		switch (playable) {
			
			case 1:
				
				column = playableColumn(1,theBoard);
				blocks = theBoard.getBlocks(column) - 1;
				if(blocks == 0)
					break;
				move = (column * 100) + blocks;
				return(move);
				
			case 2:
				
				playableOne = playableColumn(1,theBoard);
				playableTwo = playableColumn(playableOne + 1,theBoard);
				
				if((theBoard.getBlocks(playableOne) != 2) || (theBoard.getBlocks(playableTwo) != 2)) {
					
					if(theBoard.getBlocks(playableOne) == 1) {
						
						column = playableTwo;
						blocks = theBoard.getBlocks(playableTwo);
						move = (column * 100) + blocks;
						return move;
					}
						
					if(theBoard.getBlocks(playableTwo) == 1) {
						
						column = playableOne;
						blocks = theBoard.getBlocks(playableOne);
						move = (column * 100) + blocks;
						return move;
					}
					
					if((theBoard.getBlocks(playableTwo) == 2) && (theBoard.getBlocks(playableOne) > 2)) {
					
						column = playableOne;
						blocks = theBoard.getBlocks(playableOne) - 2;
						move = (column * 100) + blocks;
						return move;
					}
					
					if((theBoard.getBlocks(playableOne) == 2) && (theBoard.getBlocks(playableTwo) > 2)) {
					
						column = playableTwo;
						blocks = theBoard.getBlocks(playableTwo) - 2;
						move = (column * 100) + blocks;
						return move;
					}
					
					if(theBoard.getBlocks(playableOne) > theBoard.getBlocks(playableTwo)) {
						
						column = playableOne;
						blocks = theBoard.getBlocks(playableOne) - theBoard.getBlocks(playableTwo);
						move = (column * 100) + blocks;
						return move;
					}
					
					if(theBoard.getBlocks(playableTwo) > theBoard.getBlocks(playableOne)) {
						
						column = playableTwo;
						blocks = theBoard.getBlocks(playableTwo) - theBoard.getBlocks(playableOne);
						move = (column * 100) + blocks;
						return move;
					}
					
					if(theBoard.getBlocks(playableOne) == theBoard.getBlocks(playableTwo)) {
						
						column = playableOne;
						blocks = 1;
						move = (column * 100) + blocks;
						return move;
					}					
				}
				
				break;
			
			case 3:
			
				playableOne = playableColumn(1,theBoard);
				playableTwo = playableColumn(playableOne + 1,theBoard);
				playableThree = playableColumn(playableTwo + 1,theBoard);
				
				if((theBoard.getBlocks(playableOne) == 1) && (theBoard.getBlocks(playableTwo)) == 1) {
					
					column = playableThree;
					blocks = theBoard.getBlocks(playableThree) - 1;
					move = (column * 100) + blocks;
				}
				
				if((theBoard.getBlocks(playableOne) == 1) && (theBoard.getBlocks(playableTwo)) == 1) {
					
					column = playableThree;
					blocks = theBoard.getBlocks(playableThree) - 1;
					move = (column * 100) + blocks;
				}
				
				if((theBoard.getBlocks(playableTwo) == 1) && (theBoard.getBlocks(playableThree)) == 1) {
					
					column = playableOne;
					blocks = theBoard.getBlocks(playableOne) - 1;
					move = (column * 100) + blocks;
				}
				
				break; 
		}
		
		if(playable != 2) {
		
			for(i = 1; i <= theBoard.getColumns(); i++) {
				if((theBoard.getBlocks(i) > 0) && (theBoard.getBlocks(i) <= 4)) {
					column = i;
					blocks = theBoard.getBlocks(i);
					move = (column * 100) + blocks;
					return move;
				}
			}
		}
				
		return makeRandomMove(theBoard);
	}
	
	private int makeRandomMove(DiaismBoard theBoard) {
	
		int move;
		
		move = (1 + (int) (Math.random() * theBoard.getColumns())) * 100; //genrates a number from 1 to size of board
		move += 1 + (int) (Math.random() * theBoard.getBlocks(move / 100)); //generates a number from 1 to number of blocks in column
		
		return move;
	}
	
	private int getPlayable(DiaismBoard theBoard) {
	
		int i, playable = 0;
		
		for(i = 1; i <= theBoard.getColumns(); i++) {
			if(theBoard.getBlocks(i) > 0)
				playable++;
		}
		
		return playable;
	}
	
	private int playableColumn(int offSet, DiaismBoard theBoard) {
		
		int column = offSet;
		
		while(column <= theBoard.getColumns()) {
			
			if(theBoard.getBlocks(column) > 0)
				return column;
			
			column++;
		}
		
		return 0;
	}
}