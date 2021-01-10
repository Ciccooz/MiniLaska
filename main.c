#include "main.h"

#include <stdio.h>
#include "BACKEND/Headers/input.h"
#include "BACKEND/Headers/rules.h"
#include "BACKEND/Headers/errors.h"
#include "BACKEND/Headers/tower.h"
#include "BACKEND/Headers/playableBoard.h"

#include "UI/Headers/laskaBoard.h"



int main()
{
	int gameMode = getGameMode();
	Names names = getNames(gameMode);
	
	int oTurn = 1;
	int UIFrom[2];
	int UITo[2];
	int fromIsRight;
	int toIsRight;
	
	int won = 0;
	
	int errorsOccurred;
	
	PlayableBoard board = newBoard();
	if(board == NULL)
		return 1;

	printf("Memory for board successfully allocated\n");
	printBoard(board, 6);
	
	while(won == 0)
	{	
		if(oTurn)
			printf("\n%s's TURN (o)\n", names[0]);
		else
			printf("\n%s's TURN (x)\n", names[1]);
		
		fromIsRight = getCoordinates("\nFROM", UIFrom, board);
		if(fromIsRight)
			toIsRight = getCoordinates("\nTO", UITo, board);
		else
			toIsRight = fromIsRight;
		
		if(fromIsRight && toIsRight)
		{
			errorsOccurred = isValidMove(UIFrom, UITo, board, oTurn);
			if(!errorsOccurred)
			{
				oTurn = !oTurn;
				move(board, UIFrom, UITo);
				checkPromotion(board, UITo);
				refreshTerminal();
				printBoard(board, 6);
				
				if(!oTurn)
					printf("\n%s moved from (%d, %c) to (%d, %c)", names[0], GRID_SIZE - UIFrom[0], UIFrom[1] + 97, GRID_SIZE - UITo[0], UITo[1] + 97);
				else
					printf("\n%s moved from (%d, %c) to (%d, %c)\n", names[1], GRID_SIZE - UIFrom[0], UIFrom[1] + 97, GRID_SIZE - UITo[0], UITo[1] + 97);
			
				won = hasWon(board, names);
			}
			
			else
			{
				refreshTerminal();
				printBoard(board, 6);
				printf("\nTried to move from (%d, %c) to (%d, %c)\n\n", GRID_SIZE - UIFrom[0], UIFrom[1] + 97, GRID_SIZE - UITo[0], UITo[1] + 97);
				printf("Move error/s occurred:\n");
				errorCheck(errorsOccurred);
			}
		}
			
		else {
            refreshTerminal();
            printBoard(board, 6);
            printf("The input is INVALID\n");
        }
	}
	
	freeBoard(board);
	printf("\nBoard successfully freed\n");
}

int hasWon(PlayableBoard board, Names names)
{
	int xPawns = countPawns(board, SOLDIER1, OFFICER1);
	int oPawns = countPawns(board, SOLDIER2, OFFICER2);
	
	int xMoves = countMoves(board, SOLDIER1, OFFICER1);
	int oMoves = countMoves(board, SOLDIER2, OFFICER2);
	
	printf("\nxPawns: %d\n", xPawns);
	printf("oPawns: %d\n", oPawns);
	
	printf("xMoves: %d\n", xMoves);
	printf("oMoves: %d\n", oMoves);
	
	if((xPawns == 0) || (xMoves == 0))
	{
		printf("%s HAS WON", names[0]);
		return 1;
	}
	
	if((oPawns == 0) || (oMoves == 0))
	{
		printf("%s HAS WON", names[1]);
		return 1;
	}

	return 0;
}

int countPawns(PlayableBoard board, char soldierTop, char officerTop)
{
	int row, col;
	int counter = 0;
	
	int coord[2];
	Tower tower;
	char top;
	
	for(row = 0; row < GRID_SIZE; row++)
	{
		coord[0] = row;

		for(col = 0; col < GRID_SIZE; col++)
		{
			if((row + col) % 2 == 0)
			{
				coord[1] = col;
				tower = UICoordinatesToTower(board, coord);
				top = getTop(tower);
				
				if((top == soldierTop) || (top == officerTop))
					counter++;
			}
		}
	}
	
	return counter;
}

int countMoves(PlayableBoard board, char soldierTop, char officerTop)
{
	int row, col;
	int fromBoard[2], toBoard[2];
	int counter = 0;
	Tower fromTower, toTower;
	char fromTop;
	
	for(row = 0; row < GRID_SIZE; row++)
	{
		fromBoard[0] = row;
		
		for(col = 0; col < GRID_SIZE; col++)
		{
			if((row + col) % 2 == 0)
			{
				fromBoard[1] = col;
				fromTower = UICoordinatesToTower(board, fromBoard);
				fromTop = getTop(fromTower);

				if(fromTop == soldierTop && soldierTop == SOLDIER2)
				{
					/*CONQUER*/
					/*UP*/
					if(fromBoard[0] - 2 >= 0)
					{
						toBoard[0] = fromBoard[0] - 2;
						
						/*LEFT*/
						if(fromBoard[1] - 2 >= 0)
						{
							toBoard[1] = fromBoard[1] - 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
							
						/*RIGHT*/
						if(fromBoard[1] + 2 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
					}
					
					/*SINGLE MOVE*/
					/*UP*/
					if(fromBoard[0] - 1 >= 0)
					{
						toBoard[0] = fromBoard[0] - 1;
						
						/*LEFT*/
						if(fromBoard[1] - 1 >= 0)
						{
							toBoard[1] = fromBoard[1] - 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
							
						/*RIGHT*/
						if(fromBoard[1] + 1 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
					}
				}
					
				if(fromTop == officerTop && officerTop == OFFICER2)
				{		
					/*CONQUER*/
					/*DOWN*/
					if(fromBoard[0] + 2 < GRID_SIZE)
					{
						toBoard[0] = fromBoard[0] + 2;
					
						/*LEFT*/
						if(fromBoard[1] - 2 >= 0)
						{
							toBoard[1] = fromBoard[1] - 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
							
						/*RIGHT*/
						if(fromBoard[1] + 2 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
					}
						
						
					/*UP*/
					if(fromBoard[0] - 2 >= 0)
					{
						toBoard[0] = fromBoard[0] - 2;
					
						/*LEFT*/
						if(fromBoard[1] - 2 >= 0)
						{
							toBoard[1] = fromBoard[1] - 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
							
						/*RIGHT*/
						if(fromBoard[1] + 2 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
					}
					
					/*SINGLE MOVE*/
					/*DOWN*/
					{
						toBoard[0] = fromBoard[0] + 1;
						
						/*LEFT*/
						if(fromBoard[1] - 1 >= 0)
						{
							toBoard[1] = fromBoard[1] - 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
							
						/*RIGHT*/
						if(fromBoard[1] + 1 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
					}
					
					/*UP*/
					if(fromBoard[0] - 1 >= 0)
					{
						toBoard[0] = fromBoard[0] - 1;
						
						/*LEFT*/
						if(fromBoard[1] - 1 >= 0)
						{
							toBoard[1] = fromBoard[1] - 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
							
						/*RIGHT*/
						if(fromBoard[1] + 1 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
					}
				}
				
				if(fromTop == soldierTop && soldierTop == SOLDIER1)
				{
					/*CONQUER*/
					/*DOWN*/
					if(fromBoard[0] + 2 < GRID_SIZE)
					{
						toBoard[0] = fromBoard[0] + 2;
						
						/*LEFT*/
						if(fromBoard[1] - 2 >= 0)
						{
							toBoard[1] = fromBoard[1] - 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
							
						/*RIGHT*/
						if(fromBoard[1] + 2 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
					}
					
					/*SINGLE MOVE*/
					/*DOWN*/
					if(fromBoard[0] + 1 < GRID_SIZE)
					{
						toBoard[0] = fromBoard[0] + 1;
						
						/*LEFT*/
						if(fromBoard[1] - 1 >= 0)
						{
							toBoard[1] = fromBoard[1] - 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
							
						/*RIGHT*/
						if(fromBoard[1] + 1 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
					}
				}
					
				if(fromTop == officerTop && officerTop == OFFICER1)
				{
					/*CONQUER*/
					/*DOWN*/
					if(fromBoard[0] + 2 < GRID_SIZE)
					{
						toBoard[0] = fromBoard[0] + 2;
						
						/*LEFT*/
						if(fromBoard[1] - 2 >= 0)
						{
							toBoard[1] = fromBoard[1] - 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
							
						/*RIGHT*/
						if(fromBoard[1] + 2 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
					}
						
						
					/*UP*/
					if(fromBoard[0] - 2 >= 0)
					{
						toBoard[0] = fromBoard[0] - 2;
						
						/*LEFT*/
						if(fromBoard[1] - 2 >= 0)
						{
							toBoard[1] = fromBoard[1] - 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
							
						/*RIGHT*/
						if(fromBoard[1] + 2 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 2;
							toTower = UICoordinatesToTower(board, toBoard);
							if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
								counter++;
						}
					}
					
					/*SINGLE MOVE*/
					/*DOWN*/
					if(fromBoard[0] + 1 < GRID_SIZE)
					{
						toBoard[0] = fromBoard[0] + 1;
						
						/*LEFT*/
						if(fromBoard[1] - 1 >= 0)
						{
							toBoard[1] = fromBoard[1] - 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
							
						/*RIGHT*/
						if(fromBoard[1] + 1 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
					}
						
						
					/*UP*/
					if(fromBoard[0] - 1 >= 0)
					{
						toBoard[0] = fromBoard[0] - 1;
						
						/*LEFT*/
						if(fromBoard[1] - 1 >= 0)
						{
							toBoard[1] = fromBoard[1] - 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
							
						/*RIGHT*/
						if(fromBoard[1] + 1 < GRID_SIZE)
						{
							toBoard[1] = fromBoard[1] + 1;
							toTower = UICoordinatesToTower(board, toBoard);
							if(topIsNull(toTower))
								counter++;
						}
					}
				}
			}
		}
	}
	
	return counter;
}

static void checkPromotion(PlayableBoard board, int UITo[2])
{
	Tower promoted = UICoordinatesToTower(board, UITo);
	Pawn promotedTop = getTop(promoted);
	
	if((UITo[0] == 6 && promotedTop == SOLDIER1) || (UITo[0] == 0 && promotedTop == SOLDIER2))
		if(promotedTop != OFFICER1 || promotedTop != OFFICER2)
			promote(promoted);
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