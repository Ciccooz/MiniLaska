#include "main.h"

int main()
{
	int UIFrom[2];
	int UITo[2];
	int fromIsRight;
	int toIsRight;
	
	int won = 0;
	
	int gameMode = getGameMode();
	int oTurn = 1;
	Names names = getNames(gameMode);
	
	
	int errorsOccurred;
	
	PlayableBoard board = newBoard();
	if(board == NULL)
		return 1;

	printf("Memory for board successfully allocated\n");
	printBoard(board, 6);
	
	while(won == 0){
		if(oTurn)
			printf("\n%s's TURN (o)\n", names[0]);
		else
			printf("\n%s's TURN (x)\n", names[1]);
		
		fromIsRight = getCoordinates("\nFROM", UIFrom, board);
		if(fromIsRight)
			toIsRight = getCoordinates("\nTO", UITo, board);
		else
			toIsRight = fromIsRight;
		
		if(fromIsRight && toIsRight){
			errorsOccurred = isValidMove(UIFrom, UITo, board, oTurn);
			if(!errorsOccurred){
				oTurn = !oTurn;
				move(board, UIFrom, UITo);
				checkPromotion(board, UITo);
				refreshTerminal();
				printBoard(board, 6);
				
				if(!oTurn)
					printf("\n%s moved from (%d, %c) to (%d, %c)", names[0], GRID_SIZE - UIFrom[0], UIFrom[1] + 97, GRID_SIZE - UITo[0], UITo[1] + 97);
				else
					printf("\n%s moved from (%d, %c) to (%d, %c)\n", names[1], GRID_SIZE - UIFrom[0], UIFrom[1] + 97, GRID_SIZE - UITo[0], UITo[1] + 97);
			}
			
			else{
				refreshTerminal();
				printBoard(board, 6);
				printf("\nTried to move from (%d, %c) to (%d, %c)\n\n", GRID_SIZE - UIFrom[0], UIFrom[1] + 97, GRID_SIZE - UITo[0], UITo[1] + 97);
				printf("Move error/s occurred:\n");
				errorCheck(errorsOccurred);
			}
		}
			
		else{
			refreshTerminal();
			printBoard(board, 6);
			printf("The input is INVALID\n");
		}
		
		won = hasWon(board, names);
	}
	
	freeBoard(board);
	printf("\nBoard successfully freed\n");
}

/*
do
	{
		refreshTerminal();
		printBoard(board, 6);
	
		do{
			do
			{
				fromIsRight = getCoordinates("\nFROM", UIFrom, board);
				
				if(fromIsRight)
					toIsRight   = getCoordinates("\nTO", UITo, board);
				else{
					toIsRight = fromIsRight;
					refreshTerminal();
					printBoard(board, 6);
				}
			} while(!fromIsRight || !toIsRight);
		} while(!isValidMove(UIFrom, UITo, board));
		
		move(board, UIFrom, UITo);
		checkPromotion(board, UITo);
	} while(1);
*/
int hasWon(PlayableBoard board, Names names){
	int row, col;
	int rowSize;
	
	int xCounter = 0;
	int oCounter = 0;
	
	int coord[2];
	Tower tower;
	char top;
	
	
	for(row = 0; row < GRID_SIZE; row++){
		coord[0] = row;
		rowSize = getRowSize(row);
		
		for(col = 0; col < rowSize; col++){
			coord[1] = col;
			tower = UICoordinatesToTower(board, coord);
			top = getTop(tower);
			
			if(top == SOLDIER1 || top == OFFICER1)
				xCounter++;
			
			if(top == SOLDIER2 || top == OFFICER2)
				oCounter++;
		}
		
		if(oCounter == 0){
			printf("\n%s HAS WON\n", names[0]);
			return 1;
		}
		
		if(xCounter == 0){
			printf("\n%s HAS WON\n", names[1]);
			return 1;
		}
	
		return 0;
	}
}

static void checkPromotion(PlayableBoard board, int UITo[2]){
	Tower promoted = UICoordinatesToTower(board, UITo);
	Pawn promotedTop = getTop(promoted);
	
	if((UITo[0] == 6 && promotedTop == SOLDIER1) || (UITo[0] == 0 && promotedTop == SOLDIER2))
		if(promotedTop != OFFICER1 || promotedTop != OFFICER2)
			promote(promoted);
}

static int getCoordinates(const char* title, int UICoords[2], PlayableBoard board)
{
	UserInput input;
	char move[5];
	int row;
	char col;
	
	printf("%s: ", title);
	fgets(move, 4, stdin);
	
	printf("\nMove: %s", move);
	printf("Length:%d\n\n", strlen(move));
	
	if(atoi(&move[0]) != 0)
		printf("'%d' is an integer\n", atoi(&move[0]));
	
	else
		printf("'%d' is NOT an integer\n", atoi(&move[0]));
	
	if(isalpha(move[1]))
		printf("'%c' is a char\n\n", move[1]);
	
	else
		printf("'%c' is NOT a char\n\n", move[1]);
	
	if((atoi(&move[0]) != 0) && isalpha(move[1]))
	{
		row = atoi(&move[0]);
		col = tolower(move[1]);
	
		printf("Row: %d\n", row);
		printf("Col: %c\n", col);
	
		input.row = row;
		input.column = col;
		UserInputToUICoords(input, UICoords);
		return 1;
	}
	
	else
		return 0;
}

void refreshTerminal()
{
  #ifdef __unix__
  system("clear");
  #endif
  
  #ifdef _WIN32
  system("cls");
  #endif
}