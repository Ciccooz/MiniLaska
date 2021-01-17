#include "../Headers/validation.h"

#include <math.h>
#include "../Headers/rules.h"
#include "../Headers/tower.h"
#include "../../UI/Headers/laskaBoard.h"

/**
*@brief				 Controlla se la pedina può conquistare
*@details			 Prende le pedine appartenenti ad un giocatore e, in base al tipo di
*					 pedina, controlla nelle giuste direzioni se può essere conquistata una
*					 pedina.
*
*@param board 		 La griglia contenente le pedine
*@param playerPos[2] Le coordinate della pedina 
*@param player 		 Il giocatore da controllare
**/
static int canConquerInSurroundingArea(PlayableBoard board, int playerPos[2], int player);


int invalidMove(int from[2], int to[2], PlayableBoard board, int playerTurn)
{
		return errorFill(from, to, board, playerTurn);
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
		return getTop(tower) != SOLDIER0;
}

int canGoDown(Tower tower)
{
		return getTop(tower) != SOLDIER1;
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
	Tower midTower  = getTowerInBetween(board, from, to);

	Pawn fromTop 	 = getTop(fromTower);
	Pawn midTowerTop = getTop(midTower);
	
	if(getTop(UICoordinatesToTower(board, to)) != NULL_PAWN)
        return 0;

	if(getTop(UICoordinatesToTower(board, to)) != NULL_PAWN)
		return 0;

	return (fromTop == SOLDIER0 || fromTop == OFFICER0) &&
				 (midTowerTop == SOLDIER1 || midTowerTop == OFFICER1) ||
				 (fromTop == SOLDIER1 || fromTop == OFFICER1) &&
				 (midTowerTop == SOLDIER0 || midTowerTop == OFFICER0);
}

int isYourPawn(int from[2], PlayableBoard board, int player)
{
	Tower fromTower = UICoordinatesToTower(board, from);
	Pawn top = getTop(fromTower);

	return ((top == SOLDIER0 || top == OFFICER0) && player == 0) ||
		   ((top == SOLDIER1 || top == OFFICER1) && player == 1);
}

int mustConquer(PlayableBoard board, int player)
{
  int destinationCoords[2];
  int row, col;

	for(row = 0; row < GRID_SIZE; row++)
		for(col = 0; col < GRID_SIZE; col++)
		{
			if(row % 2 != col % 2)
				continue;

      destinationCoords[0] = row;
      destinationCoords[1] = col;

      if(!isYourPawn(destinationCoords, board, player))
        continue;

      if(canConquerInSurroundingArea(board, destinationCoords, player))
        return 1;
    }

	return 0;
}

static int canConquerInSurroundingArea(PlayableBoard board, int playerPos[2], int player)
{
	Pawn playerPawn = getTop(UICoordinatesToTower(board, playerPos));
	int verticalDir = player ? -1 : 1;
	int horizontalDir = 1;
	int destinationCoords[2];
	int i, j;

	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			destinationCoords[0] = playerPos[0] + verticalDir * 2;
			destinationCoords[1] = playerPos[1] + horizontalDir * 2;

			if(coordinatesWithinBounds(playerPos, destinationCoords) && canConquer(playerPos, destinationCoords, board))
				return 1;

			horizontalDir *= -1;
		}

		if(playerPawn == OFFICER0 || playerPawn == OFFICER1)
			verticalDir *= -1;
		else
			break;
	}
	return 0;
}