#include "../Headers/validation.h"


int isValidMove(int from[2], int to[2], PlayableBoard board)
{
    int errors = errorFill(from, to, board);
    errorCheck(errors);

    return  !errors;
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