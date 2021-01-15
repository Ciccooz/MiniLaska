#include "../Headers/validation.h"

#include <math.h>
#include "../Headers/rules.h"
#include "../Headers/tower.h"
#include "../Headers/input.h"
#include "../Headers/playableBoard.h"
#include "../../UI/Headers/laskaBoard.h"

int isValidMove(int from[2], int to[2], PlayableBoard board, int oTurn)
{
    int errors = errorFill(from, to, board, oTurn);

    return  errors;
}

int coordinatesWithinBounds(int from[2], int to[2])
{
	int validRows = (from[0] >= 0 && from[0] < GRID_SIZE) && (to[0] >= 0 && to[0] < GRID_SIZE);
	int validCols = (from[1] >= 0 && from[1] < GRID_SIZE) && (to[1] >= 0 && to[1] < GRID_SIZE);

	return validRows && validCols;
}

int movesFromPlayableCell(int from[2])
{
    return (from[0] % 2) == (from[1] % 2);
}

int movesDiagonally(int from[2], int to[2])
{
	return abs(from[0] - to[0]) == abs(from[1] - to[1]);
}

int isGoingUp(int from[2], int to[2])
{
    return from[0] > to[0];
}

int isGoingDown(int from[2], int to[2])
{
    return from[0] < to[0];
}

int canGoUp(Tower tower)
{
    return getTop(tower) != SOLDIER1;
}

int canGoDown(Tower tower)
{
    return getTop(tower) != SOLDIER2;
}

int isInSamePosition(int from[2], int to[2])
{
    int movingRow = from[0] == to[0];
    int movingCol = from[1] == to[1];

    return movingRow && movingCol;
}

int isMovingTooMuch(int from[2], int to[2])
{
    int row = abs(from[0] - to[0]);
    int col = abs(from[1] - to[1]);

    int movingRow = (row > 2);
    int movingCol = (col > 2);

    return movingRow || movingCol;
}

int isSingleMove(int from[2], int to[2])
{
    int singleRow = (abs(from[0] - to[0]) == 1);
    int singleCol = (abs(from[1] - to[1]) == 1);

    return singleRow && singleCol;
}

int isDoubleMove(int from[2], int to[2])
{
    int doubleRow = (abs(from[0] - to[0]) == 2);
    int doubleCol = (abs(from[1] - to[1]) == 2);

    return doubleRow && doubleCol;
}

int topIsNull(Tower tower)
{
    return getTop(tower) == NULL_PAWN;
}

int canConquer(int from[2], int to[2], PlayableBoard board)
{
	Tower fromTower = UICoordinatesToTower(board, from);
	Tower previous  = getPrevious(from, to, board);

	char fromTop 	 = getTop(fromTower);
	char previousTop = getTop(previous);

    return (fromTop == SOLDIER1 || fromTop == OFFICER1) &&
           (previousTop == SOLDIER2 || previousTop == OFFICER2) ||
           (fromTop == SOLDIER2 || fromTop == OFFICER2) &&
           (previousTop == SOLDIER1 || previousTop == OFFICER1);
}

int isYourPawn(int from[2], PlayableBoard board, int oTurn)
{
	Tower fromTower = UICoordinatesToTower(board, from);
	
	char top = getTop(fromTower);
	
	return ((top == SOLDIER1 || top == OFFICER1) && !oTurn) ||
		   ((top == SOLDIER2 || top == OFFICER2) && oTurn);
}

int mustConquer(PlayableBoard board, int oTurn)
{
	int row, col;
	int fromBoard[2], toBoard[2];
	Tower fromTower, toTower;
	int xCounter = 0, oCounter = 0;
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
				fromTop   = getTop(fromTower);
				
				if(oTurn)
				{
					if(fromTop == SOLDIER2)
					{
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
									oCounter++;
							}
							
							/*RIGHT*/
							if(fromBoard[1] + 2 < GRID_SIZE)
							{
								toBoard[1] = fromBoard[1] + 2;
								toTower = UICoordinatesToTower(board, toBoard);
								if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
									oCounter++;
							}
						}
					}
					
					if(fromTop == OFFICER2)
					{						
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
									oCounter++;
							}
							
							/*RIGHT*/
							if(fromBoard[1] + 2 < GRID_SIZE)
							{
								toBoard[1] = fromBoard[1] + 2;
								toTower = UICoordinatesToTower(board, toBoard);
								if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
									oCounter++;
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
									oCounter++;
							}
							
							/*RIGHT*/
							if(fromBoard[1] + 2 < GRID_SIZE)
							{
								toBoard[1] = fromBoard[1] + 2;
								toTower = UICoordinatesToTower(board, toBoard);
								if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
									oCounter++;
							}
						}
					}
				}
				
				else
				{
					if(fromTop == SOLDIER1)
					{
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
									xCounter++;
							}
							
							/*RIGHT*/
							if(fromBoard[1] + 2 < GRID_SIZE)
							{
								toBoard[1] = fromBoard[1] + 2;
								toTower = UICoordinatesToTower(board, toBoard);
								if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
									xCounter++;
							}
						}
					}
					
					if(fromTop == OFFICER1)
					{
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
									xCounter++;
							}
							
							/*RIGHT*/
							if(fromBoard[1] + 2 < GRID_SIZE)
							{
								toBoard[1] = fromBoard[1] + 2;
								toTower = UICoordinatesToTower(board, toBoard);
								if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
									xCounter++;
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
									xCounter++;
							}
							
							/*RIGHT*/
							if(fromBoard[1] + 2 < GRID_SIZE)
							{
								toBoard[1] = fromBoard[1] + 2;
								toTower = UICoordinatesToTower(board, toBoard);
								if(canConquer(fromBoard, toBoard, board) && topIsNull(toTower))
									xCounter++;
							}
						}
					}
				}
			}
		}
	}
	
	if(oTurn)
		return oCounter != 0;
	else
		return xCounter != 0;
}